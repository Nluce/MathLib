#pragma once
#include <math.h>

static const float COLOR_CONVERSION = 1.0f / 255.0f;

class Vector4
{
public:

	float x, y, z, w;

	Vector4() :x(0), y(0), z(0), w(0)
	{

	}
	Vector4(float x, float y) :x(x), y(y), z(0), w(0)
	{

	}

	/*
	Create a vector containing a color.
	Input color value can be a HTML hex color value such as 0xff0000 (red) or 0x808080 (grey).
	Resulting vector color is normalized to the range 0.0 to 1.0.
	*/
	Vector4(int colorValue) : x(COLOR_CONVERSION * ((colorValue >> 16) & 0xff)), y(COLOR_CONVERSION * ((colorValue >> 8) & 0xff)), z(COLOR_CONVERSION * (colorValue & 0xff)), w(1) {

	}

	Vector4(float x, float y, float z, float w) :x(x), y(y), z(z), w(w)
	{

	}

	~Vector4();
	
	Vector4 operator -(const Vector4& a_RHS) const
	{
		return Vector4(x - a_RHS.x, y - a_RHS.y, z - a_RHS.z, w - a_RHS.w);
	}

	Vector4 operator +(const Vector4& a_RHS) const
	{
		return Vector4(x + a_RHS.x, y + a_RHS.y, z + a_RHS.z, w + a_RHS.w);
	}

	Vector4& operator=(const Vector4 & a_RHS)
	{
		x = a_RHS.x;
		y = a_RHS.y;
		z = a_RHS.z;
		w = a_RHS.w;
		return *this;
	}

	Vector4 operator *(float scalar) const
	{
		return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	float DotProduct(const Vector4& a_RHS)
	{
		return x * a_RHS.x + y * a_RHS.y + z * a_RHS.z + w * a_RHS.w;
	}
	Vector4 LinearInterpolate(const Vector4 & rhs, float f)
	{
		float f2 = 1 - f;
		float a = x * f2 + rhs.x * f;
		float b = y * f2 + rhs.y * f;
		float c = z * f2 + rhs.z * f;
		float d = w * f2 + rhs.w * f;
		Vector4 product(a, b, c, d);
		return product;
	}
	float getMagnitude() const
	{
		return sqrtf(x*x + y*y + z*z + w*w);
	}

	void normalize()
	{
		float magnitude = sqrtf(x * x + y * y + z * z + w*w);
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
		w /= magnitude;
	}

	Vector4 getNormalized() const
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
		case 3:
			return w;
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
		case 3:
			w = f;
			break;
		}
	}
};


