#pragma once
#include <algorithm>

template <typename Object>
class Vector
{
	explicit Vector(int initSize = 0);
	Vector(const Vector& rhs) ;
	Vector& operator= (const Vector& rhs);
	~Vector();

	static const int SPARE_CAPCITY = 16;
private:
	int theSize;
	int theCapcity;
	Object* objects;
};

