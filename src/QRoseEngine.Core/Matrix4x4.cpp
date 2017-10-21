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

