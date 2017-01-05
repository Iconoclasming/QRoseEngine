#include <QRoseEngine.Core/Matrix4x4.hpp>

#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

using namespace QRose;

Matrix4x4::Matrix4x4()
{
}

Matrix4x4::Matrix4x4(glm::mat4& mat4) : mat4(mat4)
{
}

Matrix4x4::~Matrix4x4()
{
}

Matrix4x4 Matrix4x4::Translate(const Vector3& vector)
{
	return glm::translate(mat4, vector.vec3);
}

Matrix4x4 Matrix4x4::Rotate(float angle, const Vector3& vector)
{
	return glm::rotate(mat4, angle, vector.vec3);
}

Matrix4x4 Matrix4x4::Rotate(const Vector4& quaternion)
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

Matrix4x4 Matrix4x4::Scale(const Vector3& vector)
{
	return glm::scale(mat4, vector.vec3);
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& rhs)
{
	return mat4 * rhs.mat4;
}

const float* Matrix4x4::GetArray() const
{
	return glm::value_ptr(mat4);
}

Matrix4x4 Matrix4x4::Projection(float fov, float aspect, float nearPlane, float farPlane)
{
	return glm::perspective(fov, aspect, nearPlane, farPlane);
}