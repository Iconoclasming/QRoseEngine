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
	std::vector<OpenGlResourcesManager::Index>& indices, std::vector<GLfloat>& normals);
OpenGlMesh RegisterMesh(const std::vector<GLfloat>& vertices, const std::vector<OpenGlResourcesManager::Index>& indices,
	const std::vector<GLfloat>& normals);
std::vector<GLfloat> CalculateNormals(const std::vector<GLfloat>& vertices, int stride);

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
	std::vector<GLfloat> normals;
	::LoadMesh(pScene, pScene->mRootNode, vertices, indices, normals);
	OpenGlMesh mesh = RegisterMesh(vertices, indices, normals);
	meshes.push_back(mesh);
	return mesh.id;
}

MeshHandle OpenGlResourcesManager::LoadBoxMesh(const Vector3& size)
{
	float sizeX = size.GetX();
	float sizeY = size.GetY();
	float sizeZ = size.GetZ();
	std::vector<GLfloat> vertices = 
	{
		-sizeX, -sizeY, -sizeZ,
		-sizeX,  sizeY, -sizeZ,
		sizeX, sizeY, -sizeZ,
		sizeX, -sizeY, -sizeZ,

		-sizeX, -sizeY, sizeZ,
		sizeX, -sizeY, sizeZ,
		sizeX,  sizeY, sizeZ,
		-sizeX,  sizeY, sizeZ,

		-sizeX, sizeY, -sizeZ,
		-sizeX, sizeY,  sizeZ,
		sizeX, sizeY,  sizeZ,
		sizeX, sizeY, -sizeZ,

		-sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY,  sizeZ,
		-sizeX, -sizeY,  sizeZ,

		-sizeX, -sizeY,  sizeZ,
		-sizeX,  sizeY,  sizeZ,
		-sizeX,  sizeY, -sizeZ,
		-sizeX, -sizeY, -sizeZ,

		sizeX, -sizeY, -sizeZ,
		sizeX,  sizeY, -sizeZ,
		sizeX,  sizeY,  sizeZ,
		sizeX, -sizeY,  sizeZ,
	};
	std::vector<Index> indices =
	{ 
		0, 1, 2,
		0, 2, 3,

		4, 5, 6,
		4, 6, 7,

		8, 9, 10,
		8, 10, 11,

		12, 13, 14,
		12, 14, 15,

		16, 17, 18,
		16, 18, 19,

		20, 21, 22,
		20, 22, 23
	};
	std::vector<GLfloat> normals =
	{ 
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,
		1.0f,  1.0f, 1.0f,
		-1.0f,  1.0f, 1.0f,

		-1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f,  1.0f,
		1.0f, 1.0f,  1.0f,
		1.0f, 1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,
	};

	OpenGlMesh mesh = RegisterMesh(vertices, indices, normals);
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

OpenGlMesh RegisterMesh(const std::vector<GLfloat>& vertices, const std::vector<OpenGlResourcesManager::Index>& indices,
	const std::vector<GLfloat>& normals)
{
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(nullptr));
	glEnableVertexAttribArray(0);
	if(indices.size() > 0)
	{
		GLuint elementBuffer;
		glGenBuffers(1, &elementBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(OpenGlResourcesManager::Index),
			indices.data(), GL_STATIC_DRAW);		
	}
	GLuint normalBuffer;
	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(GLfloat), normals.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(nullptr));
	glBindVertexArray(0);
	return OpenGlMesh(Uuid::GenerateUuid(), vao, vertices.size(),indices.size());
}

void LoadMesh(const aiScene *pScene, const aiNode* pNode, std::vector<GLfloat>& vertices,
	std::vector<OpenGlResourcesManager::Index>& indices, std::vector<GLfloat>& normals)
{
	for(unsigned i = 0; i < pScene->mNumMeshes; i++)
	{
		const aiMesh* pMesh = pScene->mMeshes[i];
		for(unsigned j = 0; j < pMesh->mNumFaces; j++)
		{
			const aiFace* pFace = &pMesh->mFaces[j];
			if(pFace->mNumIndices != 3)
			{
				// TODO: log to errors channel this case
				continue;
			}
			for(int k = 0; k < 3; k++)
			{
				const aiVector3D& vertex = pMesh->mVertices[pFace->mIndices[k]];
				vertices.push_back(vertex.x);
				vertices.push_back(vertex.y);
				vertices.push_back(vertex.z);
			}
		}
		if (pMesh->HasNormals())
		{
			for (unsigned j = 0; j < pMesh->mNumVertices; j++)
			{
				normals.push_back(pMesh->mNormals[j].x);
				normals.push_back(pMesh->mNormals[j].y);
				normals.push_back(pMesh->mNormals[j].z);
			}			
		}
	}
}

std::vector<GLfloat> CalculateNormals(const std::vector<GLfloat>& vertices, int stride)
{
	std::vector<GLfloat> normals;

	return normals;
}