#pragma once
#include <math.h>

class Vector3
{
	

public:

	float x, y, z;

	Vector3() :x(0), y(0), z(0)
	{

	}
	Vector3(float x,float y) :x(x), y(y), z(0)
	{

	}
	Vector3(float x, float y, float z) :x(x), y(y), z(z)
	{

	}

	~Vector3();
	
	Vector3 operator -(const Vector3& a_RHS) const
	{
		return Vector3(x - a_RHS.x, y - a_RHS.y, z - a_RHS.z);
	}

	Vector3 operator +(const Vector3& a_RHS) const
	{
		return Vector3(x + a_RHS.x, y + a_RHS.y, z + a_RHS.z);
	}

	Vector3& operator=(const Vector3 & a_RHS)
	{
		x = a_RHS.x;
		y = a_RHS.y;
		z = a_RHS.z;
		return *this;
	}

	Vector3 operator *(float scalar) const
	{
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	float DotProduct(const Vector3& a_RHS)
	{
		return x * a_RHS.x + y * a_RHS.y + z * a_RHS.z;
	}

	Vector3 CrossProduct(const Vector3 & rhs)
	{
		float a = y * rhs.z - z * rhs.y;
		float b = z * rhs.x - x * rhs.z;
		float c = x * rhs.y - y * rhs.x;
		Vector3 product(a, b, c);
		return product;
	}
	Vector3 LinearInterpolate(const Vector3 & rhs, float f)
	{
		float f2 = 1 - f;
		float a = x * f2 + rhs.x * f;
		float b = y * f2 + rhs.y * f;
		float c = z * f2 + rhs.z * f;
		Vector3 product(a, b, c);
		return product;
	}
	float getMagnitude() const
	{
		return sqrtf(x*x + y*y + z*z);
	}

	void normalize()
	{
		float magnitude = sqrtf(x * x + y * y + z * z);
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}

	Vector3 getNormalized() const
	{
		return (*this) * (1.0f / getMagnitude());
	}

	float get(int i)
	{
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			return 0;
		}
	}

	void set(int i, float f)
	{
		switch (i)
		{
		case 0:
			x = f;
			break;
		case 1:
			y = f;
			break;
		case 2:
			z = f;
			break;
		}
	}

};



