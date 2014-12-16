#pragma once
#include "Vector2.h"
#include "Vector3.h"
#ifndef _MATRIX3X3_H_
#define _MATRIX3X3_H_
class Matrix3x3
{
public:
	// constructs the identity matrix
	Matrix3x3();

	// constructs a rotation matrix
	Matrix3x3(float radians);

	~Matrix3x3();

	//builds and returns a new identity matrix
	static Matrix3x3 Identity();

	//transposes matrix and returns *this
	Matrix3x3& Transpose();

	//builds and returns a new matrix that is the transpose of this matrix
	Matrix3x3 GetTranspose();

	// sets the matrix to a scale matrix and returns a reference to it.
	Matrix3x3& SetScale(float scale);

	// sets the matrix to a translate matrix and returns a reference to it.
	Matrix3x3& SetTranslate(float translateX, float translateY);


	Matrix3x3 operator +(Matrix3x3& a_RHS)
	{
		Matrix3x3 out = *this;
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				out.m_afM[x][y] += a_RHS.m_afM[x][y];
			}
		}
		return out;
	}
	Matrix3x3 operator -(Matrix3x3& a_RHS)
	{
		Matrix3x3 out = *this;
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				out.m_afM[x][y] -= a_RHS.m_afM[x][y];
			}
		}
		return out;
	}


	Matrix3x3 operator *(Matrix3x3& a_RHS);

	/* Transform a vector through the matrix. */
	Vector3 operator *(Vector3& a_RHS);

	/* Transform a 2d point through the 3x3 matrix. */
	Vector2 operator *(Vector2& a_RHS);

	Matrix3x3& operator +=(Matrix3x3& a_RHS)
	{
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				this->m_afM[x][y] += a_RHS.m_afM[x][y];
			}
		}
		return *this;
	}
	Matrix3x3& operator -=(Matrix3x3& a_RHS)
	{
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				this->m_afM[x][y] -= a_RHS.m_afM[x][y];
			}
		}
		return *this;
	}
	Matrix3x3& operator *=(Matrix3x3& a_RHS);

	float m_afM[3][3];
};

#endif //_MATRIX3X3_H_

