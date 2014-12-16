#pragma once
#include <math.h>

class Vector2
{
	

public:

	float x, y;
	
	Vector2() :x(0), y(0)
	{

	}
	Vector2(float x,float y) :x(x), y(y)
	{

	}

	~Vector2(){}
	
	Vector2 operator -(const Vector2& a_RHS) const
	{
		return Vector2(x - a_RHS.x, y - a_RHS.y);
	}

	Vector2 operator +(const Vector2& a_RHS) const
	{
		return Vector2(x + a_RHS.x, y + a_RHS.y);
	}

	Vector2& operator=(const Vector2 & a_RHS)
	{
		x = a_RHS.x;
		y = a_RHS.y;
		return *this;
	}

	Vector2 operator *(float scalar) const
	{
		return Vector2(x * scalar, y * scalar);
	}

	float DotProduct(const Vector2& a_RHS)
	{
		return x * a_RHS.x + y * a_RHS.y;
	}

	Vector2 LinearInterpolate(const Vector2 & rhs, float f)
	{
		float f2 = 1 - f;
		float a = x * f2 + rhs.x * f;
		float b = y * f2 + rhs.y * f;
		Vector2 product(a, b);
		return product;
	}
	float getMagnitude() const
	{
		return sqrtf(x*x + y*y);
	}

	void normalize()
	{
		float magnitude = sqrtf(x * x + y * y);
		x /= magnitude;
		y /= magnitude;
	}

	Vector2 getNormalized() const
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
		}
	}
};


