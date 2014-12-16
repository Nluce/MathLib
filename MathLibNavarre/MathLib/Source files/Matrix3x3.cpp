#include "Matrix3x3.h"
#include <math.h>


// creates a rotation matrix
Matrix3x3::Matrix3x3(float radians)
{
	float s = sin(radians);
	float c = cos(radians);

	m_afM[0][0] = c;
	m_afM[1][0] = -s;
	m_afM[2][0] = 0;
	m_afM[0][1] = s;
	m_afM[1][1] = c;
	m_afM[2][1] = 0;
	m_afM[0][2] = 0;
	m_afM[1][2] = 0;
	m_afM[2][2] = 1;
}


Matrix3x3::Matrix3x3()
{
	m_afM[0][0] = 1;
	m_afM[1][0] = 0;
	m_afM[2][0] = 0;
	m_afM[0][1] = 0;
	m_afM[1][1] = 1;
	m_afM[2][1] = 0;
	m_afM[0][2] = 0;
	m_afM[1][2] = 0;
	m_afM[2][2] = 1;
}

// sets the matrix to a scale matrix and returns a reference to it.
Matrix3x3& Matrix3x3::SetScale(float scale)
{
	m_afM[0][0] = scale;
	m_afM[1][0] = 0;
	m_afM[2][0] = 0;
	m_afM[0][1] = 0;
	m_afM[1][1] = scale;
	m_afM[2][1] = 0;
	m_afM[0][2] = 0;
	m_afM[1][2] = 0;
	m_afM[2][2] = scale;

	return *this;
}


// sets the matrix to a translate matrix and returns a reference to it.
Matrix3x3& Matrix3x3::SetTranslate(float translateX, float translateY)
{
	m_afM[0][0] = 1;
	m_afM[1][0] = 0;
	m_afM[2][0] = translateX;
	m_afM[0][1] = 0;
	m_afM[1][1] = 1;
	m_afM[2][1] = translateY;
	m_afM[0][2] = 0;
	m_afM[1][2] = 0;
	m_afM[2][2] = 1;

	return *this;
}




Matrix3x3& Matrix3x3::Transpose()
{
	float f = m_afM[1][0];
	m_afM[1][0] = m_afM[0][1];
	m_afM[0][1] = f;
	f = m_afM[0][2];
	m_afM[0][2] = m_afM[2][0];
	m_afM[2][0] = f;
	f = m_afM[2][1];
	m_afM[2][1] = m_afM[1][2];
	m_afM[1][2] = f;
	return *this;
	
}

Matrix3x3 Matrix3x3::operator *(Matrix3x3& a_RHS)
{
	Matrix3x3 out;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			float f = 0;
			for (int z = 0; z < 3; z++)
			{
				float a = this->m_afM[z][y];
				float b = a_RHS.m_afM[x][z];

				f +=  a * b;
			}
			out.m_afM[x][y] = f;
		}
	}
	return out;
}
Matrix3x3& Matrix3x3::operator *=(Matrix3x3& a_RHS)
{
	Matrix3x3 temp = *this;

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			float f = 0;
			for (int z = 0; z < 3; z++)
			{
				float a = temp.m_afM[z][y];
				float b = a_RHS.m_afM[x][z];

				f += a * b;
			}
			this->m_afM[x][y] = f;
		}
	}
	return *this;
}
Vector3 Matrix3x3::operator *(Vector3& a_RHS)
{
	Vector3 out;
	
	for (int y = 0; y < 3; y++)
	{
		float f = 0;
		for (int z = 0; z < 3; z++)
		{
			float a = this->m_afM[z][y];
			float b = a_RHS.get(z);

			f += a * b;
		}
		out.set(y, f); 
	}

	return out;
}

/* Transform a 2d point through the 3x3 matrix. */
Vector2 Matrix3x3::operator *(Vector2& a_RHS)
{
	// convert the 2d vector to a 3d vector
	Vector3 in(a_RHS.x, a_RHS.y, 1.0);

	// transform the 3d vector using this matrix
	Vector3 out = (*this) * in;

	// convert back to a 2d point and reeturn
	return Vector2(out.x, out.y);
}



Matrix3x3 Matrix3x3::GetTranspose()
{
	Matrix3x3 out = *this;
	out.Transpose();
	return out;
}

Matrix3x3::~Matrix3x3()
{
}
