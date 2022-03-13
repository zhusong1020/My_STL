#include "Vector.h"



template<typename Object>
inline Vector<Object>::Vector(int initSize) : theSize(initSize), theCapcity(initSize + SPARE_CAPCITY)
{
	objects = new Object[theCapcity];
}

template<typename Object>
Vector<Object>::Vector(const Vector& rhs)
{
	objects = new Object[theCapcity];
	for (int i = 0; i < theSize; i++) {
		objects[i] = rhs.objects[i];
	}
}

template<typename Object>
Vector<Object>& Vector<Object>::operator=(const Vector& rhs)
{
	Vector copy = rhs;
	std::swap(*this, copy);
	return *this;
}

template<typename Object>
Vector<Object>::~Vector()
{
	delete[]objects;
}


