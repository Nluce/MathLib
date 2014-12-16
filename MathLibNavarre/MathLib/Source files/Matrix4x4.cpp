#include "Matrix4x4.h"


Matrix4x4::Matrix4x4()
{
	m_afM[0][0] = 1;
	m_afM[1][0] = 0;
	m_afM[2][0] = 0;
	m_afM[3][0] = 0;
	m_afM[0][1] = 0;
	m_afM[1][1] = 1;
	m_afM[2][1] = 0;
	m_afM[3][1] = 0;
	m_afM[0][2] = 0;
	m_afM[1][2] = 0;
	m_afM[2][2] = 1;
	m_afM[3][2] = 0;
	m_afM[0][3] = 0;
	m_afM[1][3] = 0;
	m_afM[2][3] = 0;
	m_afM[3][3] = 1;
	
}


Matrix4x4::Matrix4x4(const Vector3& axis, float theta)
{
	float c = cos(theta);
	float s = sin(theta);
	
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	// code from university of virginia web site.

	m_afM[0][0] = x * x + c * (1 - x * x);
	m_afM[1][0] = x * y * (1 - c) - z * s;
	m_afM[2][0] = x * z * (1 - c) + y * s;
	m_afM[3][0] = 0;
	m_afM[0][1] = x * y * (1 - c) + z * s;
	m_afM[1][1] = y * y + c * (1 - y * y);
	m_afM[2][1] = y * z * (1 - c) - x * s;
	m_afM[3][1] = 0;
	m_afM[0][2] = x * z * (1 - c) - y * s;
	m_afM[1][2] = y * z * (1 - c) + x * s;
	m_afM[2][2] = z * z + c * (1 - z * z);
	m_afM[3][2] = 0;
	m_afM[0][3] = 0;
	m_afM[1][3] = 0;
	m_afM[2][3] = 0;
	m_afM[3][3] = 1;
}


// sets the matrix to a scale matrix and returns a reference to it.
Matrix4x4& Matrix4x4::SetScale(float scale)
{
	m_afM[0][0] = scale;
	m_afM[1][0] = 0;
	m_afM[2][0] = 0;
	m_afM[3][0] = 0;
	m_afM[0][1] = 0;
	m_afM[1][1] = scale;
	m_afM[2][1] = 0;
	m_afM[3][1] = 0;
	m_afM[0][2] = 0;
	m_afM[1][2] = 0;
	m_afM[2][2] = scale;
	m_afM[3][2] = 0;
	m_afM[0][3] = 0;
	m_afM[1][3] = 0;
	m_afM[2][3] = 0;
	m_afM[3][3] = scale;

	return *this;
}


// sets the matrix to a translate matrix and returns a reference to it.
Matrix4x4& Matrix4x4::SetTranslate(float translateX, float translateY, float translateZ)
{
	m_afM[0][0] = 1;
	m_afM[1][0] = 0;
	m_afM[2][0] = 0;
	m_afM[3][0] = translateX;
	m_afM[0][1] = 0;
	m_afM[1][1] = 1;
	m_afM[2][1] = 0;
	m_afM[3][1] = translateY;
	m_afM[0][2] = 0;
	m_afM[1][2] = 0;
	m_afM[2][2] = 1;
	m_afM[3][2] = translateZ;
	m_afM[0][3] = 0;
	m_afM[1][3] = 0;
	m_afM[2][3] = 0;
	m_afM[3][3] = 1;

	return *this;
}



Matrix4x4& Matrix4x4::Transpose()
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

	f = m_afM[0][3];
	m_afM[0][3] = m_afM[3][0];
	m_afM[3][0] = f;

	f = m_afM[1][3];
	m_afM[1][3] = m_afM[3][1];
	m_afM[3][1] = f;

	f = m_afM[2][3];
	m_afM[2][3] = m_afM[3][2];
	m_afM[3][2] = f;

	return *this;
	
}

Matrix4x4 Matrix4x4::operator *(Matrix4x4& a_RHS)
{
	Matrix4x4 out;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			float f = 0;
			for (int z = 0; z < 4; z++)
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
Matrix4x4& Matrix4x4::operator *=(Matrix4x4& a_RHS)
{
	Matrix4x4 temp = *this;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			float f = 0;
			for (int z = 0; z < 4; z++)
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
Vector4 Matrix4x4::operator *(Vector4& a_RHS)
{
	Vector4 out;
	
	for (int y = 0; y < 4; y++)
	{
		float f = 0;
		for (int z = 0; z < 4; z++)
		{
			float a = this->m_afM[z][y];
			float b = a_RHS.get(z);

			f += a * b;
		}
		out.set(y, f); 
	}

	return out;

}

/* Transform a 3d point through the 4x4 matrix. */
Vector3 Matrix4x4::operator *(Vector3& a_RHS)
{
	// convert the 3d vector to a 4d vector
	Vector4 in(a_RHS.x, a_RHS.y, a_RHS.z, 1.0);

	// transform the 4d vector using this matrix
	Vector4 out = (*this) * in;

	// convert back to a 3d point and reeturn
	return Vector3(out.x, out.y, out.z);
}

Matrix4x4 Matrix4x4::GetTranspose()
{
	Matrix4x4 out = *this;
	out.Transpose();
	return out;
}

Matrix4x4::~Matrix4x4()
{
}
