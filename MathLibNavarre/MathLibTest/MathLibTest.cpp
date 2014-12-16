#include "MathLib.h"
#include <iostream>
#include <assert.h>


using namespace std;

static int testsRun = 0;
static int testsFailed = 0;


ostream& operator<< (ostream &out, Vector2 &v)
{
	out << "(" << v.x << ", " <<v.y << ")";
	return out;
}

ostream& operator<< (ostream &out, Vector3 &v)
{
	out << "(" << v.x << ", " <<
		v.y << ", " <<
		v.z << ")";
	return out;
}

ostream& operator<< (ostream &out, Matrix3x3 &m)
{
	out << "Matrix3x3(";

	for (int y = 0; y < 3; y++)
	{
		if (y != 0)
		{
			out << ", ";
		}
		out << "(";
		for (int x = 0; x < 3; x++)
		{
			if (x != 0)
			{
				out << ", ";
			}
			out << m.m_afM[x][y];
		}
		out << ")";
	}

	out << ")";

	return out;
}

ostream& operator<< (ostream &out, Matrix4x4 &m)
{
	out << "Matrix4x4(";

	for (int y = 0; y < 4; y++)
	{
		if (y != 0)
		{
			out << ", ";
		}
		out << "(";
		for (int x = 0; x < 4; x++)
		{
			if (x != 0)
			{
				out << ", ";
			}
			out << m.m_afM[x][y];
		}
		out << ")";
	}

	out << ")";

	return out;
}


void TestValues(float err, const char * v1, const char * v2)
{
	testsRun++;
	if (err > 0.0001){
		cout << "TestFailed " << v1 << " differs from " << v2 << " by " << err << endl;
		testsFailed++;
	}
}

#define LOG(V) cout << #V << " = " << (V) << endl

#define CHECK(V1, V2) TestValues(((V1) - (V2)).getMagnitude(), #V1, #V2)

void TestMatrix3x3()
{
	cout << "Matrix3x3 test" << endl;

	Matrix3x3 identity;
	cout << "identity = " << identity << endl;

	Vector2 testInputPoint(5, 3);

	cout << "Test Input Point = " << testInputPoint << endl;
	{
		Matrix3x3 rotation(DegreesToRadians(90));
		cout << "rotation(90) = " << rotation << endl;

		Vector2 out = rotation * testInputPoint;

		LOG(out);
		CHECK(out, Vector2(-3, 5));
	}

	{
		Matrix3x3 rotation(DegreesToRadians(180));
		cout << "rotation(180) = " << rotation << endl;

		Vector2 out = rotation * testInputPoint;
		LOG(out);
		CHECK(out, Vector2(-5, -3));
	}

	{
		Matrix3x3 translate;
		translate.SetTranslate(10, 10);
		LOG(translate);
		Vector2 out = translate * testInputPoint;
		LOG(out);
		CHECK(out, Vector2(15, 13));
	}

	{
		Matrix3x3 scale;
		scale.SetScale(2);
		LOG(scale);
		Vector2 out = scale * testInputPoint;
		LOG(out);
		CHECK(out, Vector2(10, 6));
	}

	{
		Matrix3x3 translate;
		translate.SetTranslate(10, 10);
		Matrix3x3 rotation(DegreesToRadians(90));
		Matrix3x3 m1, m2;

		// matrix operations are performed in the reverse order that they are multiplied together.
		// in this case the point is rotated(90 degrees) then translated(10, 10)
		m2 = m1 * translate * rotation;
		Vector2 out = m2 * testInputPoint;
		LOG(out);
		CHECK(out, Vector2(7, 15));

		// in this case the test point is translated(10, 10) then rotated(90 degrees)
		out = (rotation * translate) *  testInputPoint;
		LOG(out);
		CHECK(out, Vector2(-13, 15));
	}
}

void TestMatrix4x4()
{
	const Vector3 X(1, 0, 0);
	const Vector3 Y(0, 1, 0);
	const Vector3 Z(0, 0, 1);

	cout << "Matrix4x4 test" << endl;

	Matrix4x4 identity;
	cout << "identity = " << identity << endl;

	Vector3 testInputPoint(5, 3, 4);

	cout << "Test Input Point = " << testInputPoint << endl;
	{
		Matrix4x4 rotation(Z, DegreesToRadians(90));
		cout << "rotation(90) = " << rotation << endl;

		Vector3 out = rotation * testInputPoint;

		LOG(out);
		CHECK(out, Vector3(-3, 5, 4));
	}

	{
		Matrix4x4 rotation(Z, DegreesToRadians(180));
		cout << "rotation(180) = " << rotation << endl;

		Vector3 out = rotation * testInputPoint;
		LOG(out);
		CHECK(out, Vector3(-5, -3, 4));
	}

	{
		Matrix4x4 translate;
		translate.SetTranslate(10, 10, 7);
		LOG(translate);
		Vector3 out = translate * testInputPoint;
		LOG(out);
		CHECK(out, Vector3(15, 13, 11));
	}

	{
		Matrix4x4 scale;
		scale.SetScale(2);
		LOG(scale);
		Vector3 out = scale * testInputPoint;
		LOG(out);
		CHECK(out, Vector3(10, 6, 8));
	}

	{
		Matrix4x4 translate;
		translate.SetTranslate(10, 10, 7);
		Matrix4x4 rotation(Z, DegreesToRadians(90));
		Matrix4x4 m1, m2;

		// matrix operations are performed in the reverse order that they are multiplied together.
		// in this case the point is rotated(90 degrees) then translated(10, 10)
		m2 = m1 * translate * rotation;
		Vector3 out = m2 * testInputPoint;
		LOG(out);
		CHECK(out, Vector3(7, 15, 11));

		// in this case the test point is translated(10, 10) then rotated(90 degrees)
		out = (rotation * translate) *  testInputPoint;
		LOG(out);
		CHECK(out, Vector3(-13, 15, 11));
	}
}


int main(int argc, char ** argv)
{

	Vector3 v1, v2(1,2,3), v3(5,5);

	LOG(v1);
	LOG(v2);
	LOG(v3);

	v1 = v2 + v3;

	LOG(v1);

	v1 = v2 - v3;

	LOG(v1);

	cout << "The End" << endl;

	TestMatrix3x3();
	TestMatrix4x4();

	LOG(testsRun);
	LOG(testsFailed);

	return 0;
}