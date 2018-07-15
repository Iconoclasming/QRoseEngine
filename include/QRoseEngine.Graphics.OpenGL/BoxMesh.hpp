#include <vector>
#include <GL/glew.h>

namespace QRose
{
	class BoxMesh
	{
	public:
		static std::vector<GLfloat> CreateVertices(GLfloat sizeX, GLfloat sizeY, GLfloat sizeZ);
		static std::vector<GLushort> CreateIndices();
		static std::vector<GLfloat> CreateNormals();
	};
}