#pragma once
#include "Vector3.h"
#include "Vector4.h"
#ifndef _Matrix4x4_H_
#define _Matrix4x4_H_
class Matrix4x4
{
public:
	Matrix4x4();

	// constructs a rotation matrix
	Matrix4x4(const Vector3& axis, float theta);

	~Matrix4x4();

	//builds and returns a new identity matrix
	static Matrix4x4 Identity();

	//transposes matrix and returns *this
	Matrix4x4& Transpose();
	//builds and returns a new matrix that is the transpose of this matrix
	Matrix4x4 GetTranspose();

	// sets the matrix to a scale matrix and returns a reference to it.
	Matrix4x4& SetScale(float scale);

	// sets the matrix to a translate matrix and returns a reference to it.
	Matrix4x4& SetTranslate(float translateX, float translateY, float translateZ);



	Matrix4x4 operator +(Matrix4x4& a_RHS)
	{
		Matrix4x4 out = *this;
		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				out.m_afM[x][y] += a_RHS.m_afM[x][y];
			}
		}
		return out;
	}
	Matrix4x4 operator -(Matrix4x4& a_RHS)
	{
		Matrix4x4 out = *this;
		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				out.m_afM[x][y] -= a_RHS.m_afM[x][y];
			}
		}
		return out;
	}
	Matrix4x4 operator *(Matrix4x4& a_RHS);

	Vector4 operator *(Vector4& a_RHS);

	/* Transform a 3d point through the 4x4 matrix. */
	Vector3 operator *(Vector3& a_RHS);

	Matrix4x4& operator +=(Matrix4x4& a_RHS)
	{
		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				this->m_afM[x][y] += a_RHS.m_afM[x][y];
			}
		}
		return *this;
	}
	Matrix4x4& operator -=(Matrix4x4& a_RHS)
	{
		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				this->m_afM[x][y] -= a_RHS.m_afM[x][y];
			}
		}
		return *this;
	}
	Matrix4x4& operator *=(Matrix4x4& a_RHS);

	float m_afM[4][4];
};

#endif //_Matrix4x4_H_

