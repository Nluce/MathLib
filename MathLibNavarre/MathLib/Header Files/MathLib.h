#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"

#include <math.h>

float LinearInterpolate(float a, float b, float f){
	return (1 - f) * a + f * b;
}

const float DEG_TO_RAD = float(3.14159265358979323846 / 180.0);
const float RAD_TO_DEG = float(180.0 / 3.14159265358979323846);

float DegreesToRadians(float degrees){
	return degrees * DEG_TO_RAD;
}

float RadiansToDegrees(float radians){
	return radians * RAD_TO_DEG;
}

unsigned int ConvertToNextPowerOfTwo(unsigned int in)
{
	if (in == 0)
	{
		return 0;
	}

	for (int b = 0; b < 32; b++)
	{
		unsigned int t = 1 << b;
		if (in <= t)
		{
			return t;
		}
	}
	// If we get to here there is no power of two greater in the unsigned int range of numbers.
	//  So this is basically an error case.
	return 0;
}

unsigned int ConvertToNearestPowerOfTwo(unsigned int in)
{
	if (in == 0)
	{
		return 0;
	}

	for (int b = 0; b < 32; b++)
	{
		unsigned int t = 1 << b;
		unsigned int t2 = t + t / 2;

		if (in <= t2)
		{
			return t;
		}
	}
	// If we get to here there is no power of two greater in the unsigned int range of numbers.
	//  So this is basically an error case.
	return 0;
}
