#include <QRoseEngine.Core/Matrix4x4.hpp>

#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

using namespace QRose;

Matrix4x4::Matrix4x4(glm::mat4&& mat4) : mat4(mat4)
{
}

Matrix4x4::Matrix4x4(glm::mat4 &mat4) : mat4(mat4)
{
}

Matrix4x4 Matrix4x4::Translate(const Vector3& vector) const
{
	return Matrix4x4(glm::translate(mat4, vector.vec3));
}

Matrix4x4 Matrix4x4::Rotate(float angle, const Vector3& vector) const
{
	return Matrix4x4(glm::rotate(mat4, angle, vector.vec3));
}

Matrix4x4 Matrix4x4::Rotate(const Vector4& quaternion) const
{
	glm::quat quat;
	quat.x = quaternion.GetX();
	quat.y = quaternion.GetY();
	quat.z = quaternion.GetZ();
	quat.w = quaternion.GetW();
	glm::vec3 axis = glm::axis(quat);
	float angle = glm::angle(quat);
	return Rotate(angle, axis);
}

Matrix4x4 Matrix4x4::Scale(const Vector3& vector) const
{
	return Matrix4x4(glm::scale(mat4, vector.vec3));
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& rhs) const
{
	return Matrix4x4(mat4 * rhs.mat4);
}

Vector3 Matrix4x4::operator*(const Vector3& rhs) const
{
	glm::vec4 result = mat4 * glm::vec4(rhs.GetX(), rhs.GetY(), rhs.GetZ(), 1.0);
	return Vector3(result.x, result.y, result.z);
}

Vector4 Matrix4x4::operator*(const Vector4& rhs) const
{
	glm::vec4 result = mat4 * glm::vec4(rhs.GetX(), rhs.GetY(), rhs.GetZ(), rhs.GetW());
	return Vector4(result.x, result.y, result.z, result.w);
}

float* Matrix4x4::operator[](int row)
{
	return glm::value_ptr(mat4[row]);
}

const float* Matrix4x4::Flatten() const
{
	return glm::value_ptr(mat4);
}

Matrix4x4 Matrix4x4::Projection(float fov, float aspect, float nearPlane, float farPlane)
{
	return Matrix4x4(glm::perspective(fov, aspect, nearPlane, farPlane));
}

Matrix4x4 Matrix4x4::CreateTranslationMatrix(float x, float y, float z)
{
	Matrix4x4 m;
	m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = x;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = y;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = z;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	return m;
}
