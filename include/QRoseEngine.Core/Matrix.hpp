#pragma once

#include <vector>
#include <functional>

namespace QRose
{
	template<typename T>
	class Matrix
	{
	public:
		Matrix();
		Matrix(int rows, int columns);
		Matrix(std::vector<std::vector<T>> data);
		~Matrix();

		int GetRowsCount() const;
		int GetColumnsCount() const;

		Matrix<T> operator*(const Matrix<T>& rhs) const;
		//Matrix<T>& operator*(const Matrix<T>& rhs);
		Matrix<T> operator*(T scalar) const;
		//Matrix<T>& operator*(T scalar);
		Matrix<T> operator+(const Matrix<T>& rhs) const;
		Matrix<T> operator-(const Matrix<T>& rhs) const;
		//Matrix<T>& operator-(const Matrix<T>& rhs);

		Matrix<T> Feed(std::function<T(T)> function) const;

		const std::vector<T>& operator[](int row) const;
		std::vector<T>& operator[](int row);

		static Matrix<T> Random(int rows, int columns, T minValue, T maxValue);

	private:
		std::vector<std::vector<T>> data;
	};
}