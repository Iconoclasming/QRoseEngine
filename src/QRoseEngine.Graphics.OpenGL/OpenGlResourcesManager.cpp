#include <QRoseEngine.Graphics.OpenGL/OpenGlResourcesManager.hpp>

#include <fstream>
#include <sstream>
#include <assimp/Importer.hpp>
#include <assimp/mesh.h>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <vector>
#include "QRoseEngine.Core/QCE.hpp"

using namespace QRose;

void LoadMesh(const aiScene *pScene, const aiNode* pNode, std::vector<GLfloat>& vertices, 
	std::vector<QRose::OpenGlResourcesManager::Index>& indices);
OpenGlMesh RegisterMesh(const std::vector<GLfloat>& vertices,
	const std::vector<QRose::OpenGlResourcesManager::Index>& indices, int numComponents = 3);

OpenGlResourcesManager::OpenGlResourcesManager() : defaultShaderProgram(-1)
{
}

OpenGlResourcesManager::~OpenGlResourcesManager()
{
	for(const auto& mesh : meshes)
	{
		glDeleteVertexArrays(1, &mesh.vao);
	}
}

MeshHandle OpenGlResourcesManager::LoadMesh(const std::string& path)
{
	Assimp::Importer importer;
	const aiScene* pScene = importer.ReadFile(path, aiProcessPreset_TargetRealtime_Fast);
	std::vector<GLfloat> vertices;
	std::vector<Index> indices;
	::LoadMesh(pScene, pScene->mRootNode, vertices, indices);
	OpenGlMesh mesh = RegisterMesh(vertices, indices);
	meshes.push_back(mesh);
	return mesh.id;
}

MeshHandle OpenGlResourcesManager::LoadBoxMesh(const Vector3& size)
{
	float sizeX = size.GetX();
	float sizeY = size.GetY();
	float sizeZ = size.GetZ();
	std::vector<GLfloat> vertices = {
		-sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY, -sizeZ,
		sizeX,  sizeY, -sizeZ,
		sizeX,  sizeY, -sizeZ,
		-sizeX,  sizeY, -sizeZ,
		-sizeX, -sizeY, -sizeZ,

		-sizeX, -sizeY,  sizeZ,
		sizeX, -sizeY,  sizeZ,
		sizeX,  sizeY,  sizeZ,
		sizeX,  sizeY,  sizeZ,
		-sizeX,  sizeY,  sizeZ,
		-sizeX, -sizeY,  sizeZ,

		-sizeX,  sizeY,  sizeZ,
		-sizeX,  sizeY, -sizeZ,
		-sizeX, -sizeY, -sizeZ,
		-sizeX, -sizeY, -sizeZ,
		-sizeX, -sizeY,  sizeZ,
		-sizeX,  sizeY,  sizeZ,

		sizeX,  sizeY,  sizeZ,
		sizeX,  sizeY, -sizeZ,
		sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY,  sizeZ,
		sizeX,  sizeY,  sizeZ,

		-sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY,  sizeZ,
		sizeX, -sizeY,  sizeZ,
		-sizeX, -sizeY,  sizeZ,
		-sizeX, -sizeY, -sizeZ,

		-sizeX,  sizeY, -sizeZ,
		sizeX,  sizeY, -sizeZ,
		sizeX,  sizeY,  sizeZ,
		sizeX,  sizeY,  sizeZ,
		-sizeX,  sizeY,  sizeZ,
		-sizeX,  sizeY, -sizeZ,
	};
	OpenGlMesh mesh = RegisterMesh(vertices, std::vector<Index>());
	meshes.push_back(mesh);
	return mesh.id;
}

void OpenGlResourcesManager::LoadDefaultShaderProgram(const std::string& pathToVertexShader, 
	const std::string& pathToFragmentShader)
{
	std::fstream vertexShaderInputStream(pathToVertexShader);
	if (!vertexShaderInputStream.is_open())
	{
		throw std::invalid_argument("vertex shader file not found: " + pathToVertexShader);
	}
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	std::stringstream vertexShaderStringStream;
	vertexShaderStringStream << vertexShaderInputStream.rdbuf();
	vertexShaderInputStream.close();
	std::string vertexShaderString = vertexShaderStringStream.str();
	const char* vertexShaderSource = vertexShaderString.c_str();
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	GLint compilationSuccess;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compilationSuccess);
	if (!compilationSuccess)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		throw std::runtime_error("failed to compile vertex shader:\n" + std::string(infoLog));
	}

	std::fstream fragmentShaderInputStream(pathToFragmentShader, std::fstream::in);
	if (!fragmentShaderInputStream.is_open())
	{
		throw std::invalid_argument("fragment shader file not found: " + pathToFragmentShader);
	}
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	std::stringstream fragmentShaderStringStream;
	fragmentShaderStringStream << fragmentShaderInputStream.rdbuf();
	std::string fragmentShaderString = fragmentShaderStringStream.str();
	fragmentShaderInputStream.close();
	const char* fragmentShaderSource = fragmentShaderString.c_str();
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compilationSuccess);
	if (!compilationSuccess)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		throw std::runtime_error("failed to compile fragment shader:\n" + std::string(infoLog));
	}

	defaultShaderProgram = glCreateProgram();
	glAttachShader(defaultShaderProgram, vertexShader);
	glAttachShader(defaultShaderProgram, fragmentShader);
	glLinkProgram(defaultShaderProgram);
	GLint programLinkSuccess;
	glGetShaderiv(defaultShaderProgram, GL_LINK_STATUS, &programLinkSuccess);
	if (!programLinkSuccess)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(defaultShaderProgram, 512, nullptr, infoLog);
		throw std::runtime_error("failed to link shader program:\n" + std::string(infoLog));
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

const OpenGlMesh* OpenGlResourcesManager::GetMeshVertexArrayObject(MeshHandle meshId) const
{	
	if (!QCE::ContainsAny(meshes, [&meshId](auto& mesh) { return mesh.id == meshId; }))
	{
		throw std::invalid_argument("mesh with id " + meshId.ToString() + " not found");
	}
	const OpenGlMesh* pMesh = nullptr;
	for(const auto& mesh : meshes)
	{
		if(mesh.id == meshId)
		{
			pMesh = &mesh;
			break;
		}
	}
	return pMesh;
}

GLuint OpenGlResourcesManager::GetDefaultShaderProgram() const
{
	return defaultShaderProgram;
}

OpenGlMesh RegisterMesh(const std::vector<GLfloat>& vertices, 
	const std::vector<OpenGlResourcesManager::Index>& indices, int numComponents)
{
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
	GLuint elementBuffer;
	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(OpenGlResourcesManager::Index), 
		indices.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, numComponents, GL_FLOAT, GL_FALSE, 0, static_cast<GLvoid*>(nullptr));
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	return OpenGlMesh(Uuid::GenerateUuid(), vao, vertexBuffer, elementBuffer, vertices.size(),
		indices.size());
}

void LoadMesh(const aiScene *pScene, const aiNode* pNode, std::vector<GLfloat>& vertices,
	std::vector<OpenGlResourcesManager::Index>& indices)
{
	for(unsigned i = 0; i < pScene->mNumMeshes; i++)
	{
		const aiMesh* pMesh = pScene->mMeshes[i];
		vertices.reserve(3 * pMesh->mNumVertices);
		for(unsigned j = 0; j < pMesh->mNumVertices; j++)
		{
			if(pMesh->HasPositions())
			{
				const aiVector3D* vp = &pMesh->mVertices[j];
				vertices.push_back(vp->x);
				vertices.push_back(vp->y);
				vertices.push_back(vp->z);
			}			
		}
		for(unsigned j = 0; j < pMesh->mNumFaces; j++)
		{
			const aiFace* pFace = &pMesh->mFaces[j];
			for(unsigned k = 0; k < pFace->mNumIndices; k++)
			{
				indices.push_back(pFace->mIndices[k]);
			}
		}
	}
}