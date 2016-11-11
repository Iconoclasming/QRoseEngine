#include "QRoseEngine.Core/Matrix.hpp"

#include "QRoseEngine.Core/RNDGen.hpp"

using namespace QRose;

template <typename T>
Matrix<T>::Matrix() : Matrix(0, 0)
{
}

template<typename T> 
Matrix<T>::Matrix(int rows, int columns)
{
	if(rows < 0 || columns < 0)
	{
		throw std::invalid_argument("rows and columns count must be greater then or equal to 0");
	}
	data.resize(rows);
	for(std::vector<T>& row : data)
	{
		row.resize(columns);
	}
}

template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> data)
{
	if(data.size() < 1)
	{
		throw std::invalid_argument("rows count must be greater then 0");
	}
	int columnsCount = data[0].size();
	for(auto& row : data)
	{
		if(row.size() != columnsCount)
		{
			throw std::invalid_argument("columns size must be equal across the matrix");
		}
	}
	this->data = data;
}

template <typename T>
int Matrix<T>::GetRowsCount() const
{
	return data.size();
}

template <typename T>
int Matrix<T>::GetColumnsCount() const
{
	return data.size() > 0 ? data[0].size() : 0;
}

template <typename T>
Matrix<T>::~Matrix()
{
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) const
{
	if (GetColumnsCount() != rhs.GetRowsCount())
	{
		throw std::invalid_argument("rhs rows count must be the same as lhs columns count");
	}

	Matrix<T> result(GetRowsCount(), rhs.GetColumnsCount());
	for (int i = 0; i < result.GetRowsCount(); i++)
	{
		for (int j = 0; j < result.GetColumnsCount(); j++)
		{
			T sum = 0;
			for (int k = 0; k < rhs.GetRowsCount(); k++)
			{
				sum += (*this)[i][k] * rhs[k][j];
			}
			result[i][j] = sum;
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(T scalar) const
{
	Matrix<T> result(GetRowsCount(), GetColumnsCount());
	for (int i = 0; i < result.GetRowsCount(); i++)
	{
		for (int j = 0; j < result.GetColumnsCount(); j++)
		{
			result[i][j] = scalar * (*this)[i][j];
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const
{
	if (GetRowsCount() != rhs.GetRowsCount() || GetColumnsCount() != rhs.GetColumnsCount())
	{
		throw std::invalid_argument("rows and columns counts for both matrices must be equal");
	}

	Matrix<T> result(GetRowsCount(), GetColumnsCount());
	for (int i = 0; i < result.GetRowsCount(); i++)
	{
		for (int j = 0; j < GetColumnsCount(); j++)
		{
			result[i][j] = (*this)[i][j] + rhs[i][j];
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) const
{
	if (GetRowsCount() != rhs.GetRowsCount() || GetColumnsCount() != rhs.GetColumnsCount())
	{
		throw std::invalid_argument("rows and columns counts for both matrices must be equal");
	}

	Matrix<T> result(GetRowsCount(), GetColumnsCount());
	for (int i = 0; i < result.GetRowsCount(); i++)
	{
		for (int j = 0; j < GetColumnsCount(); j++)
		{
			result[i][j] = (*this)[i][j] - rhs[i][j];
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::Feed(std::function<T(T)> function) const
{
	Matrix<T> matrix(GetRowsCount(), GetColumnsCount());
	for (int i = 0; i < matrix.GetRowsCount(); i++)
	{
		for (int j = 0; j < matrix.GetColumnsCount(); j++)
		{
			T value = function((*this)[i][j]);
			matrix[i][j] = value;
		}
	}
	return matrix;
}

template <typename T>
const std::vector<T>& Matrix<T>::operator[](int row) const
{
	return data.at(row);
}

template <typename T>
Matrix<T> Matrix<T>::Random(int rows, int columns, T minValue, T maxValue)
{
	RNDGen<T> rnd(minValue, maxValue);
	std::function<T(T)> randomFeedClosure = [&rnd](T value)
	{
		return rnd.Next();
	};
	return Matrix<T>(rows, columns).Feed(randomFeedClosure);
}

template <typename T>
std::vector<T>& Matrix<T>::operator[](int row)
{
	return data[row];
}

template class Matrix<double>;
template class Matrix<float>;
template class Matrix<int>;