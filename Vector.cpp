#include "Vector.h"
#include <iostream>


template<typename Object>
inline Vector<Object>::Vector(int initSize) : theSize(initSize), theCapacity(initSize + SPARE_CAPCITY)
{
	objects = new Object[theCapacity]{};
}

template<typename Object>
Vector<Object>::Vector(const Vector& rhs): theSize(rhs.theSize), theCapacity(rhs.theCapacity), objects(nullptr)
{
	if (theCapacity <= 2) return;	//��ΪtheCapacity�ܻ����SPARE_CAPCITY ��������û���� ���ֻ��Ϊ���������� ����ɾ������
	objects = new Object[theCapacity];
	for (int i = 0; i < theSize; i++) {
		objects[i] = rhs.objects[i];
	}
}

template<typename Object>
Vector<Object>::Vector(Vector&& rhs) noexcept: theSize(rhs.theSize), theCapacity(rhs.theCapacity), objects(rhs.objects)
{
	rhs.objects = nullptr;
	rhs.theSize = 0;
	rhs.theCapacity = 0;
}

template<typename Object>
Vector<Object>& Vector<Object>::operator=(const Vector& rhs)
{
	Vector copy = rhs;
	std::swap(*this, copy);
	return *this;
}

template<typename Object>
Vector<Object>& Vector<Object>::operator=(Vector&& rhs) noexcept
{
	std::swap(theSize, rhs.theSize);
	std::swap(theCapacity, rhs.theCapacity);
	std::swap(objects, rhs.objects);
	return *this;
}

template<typename Object>
void Vector<Object>::resize(int newSize)
{
	if (newSize > theCapacity) {
		reserve(newSize * 2);
	}
	theSize = newSize;
}

template<typename Object>
void Vector<Object>::reserve(int newCapacity)
{
	if (newCapacity < theSize) return;

	Object* newArray = new Object[newCapacity];
	for (int i = 0; i < theSize; i++) {
		newArray[i] = std::move(objects[i]);
	}
	theCapacity = newCapacity;
	std::swap(objects, newArray);
	delete[]newArray;

}

template<typename Object>
Object& Vector<Object>::operator[](int index)
{
	return objects[index];
}

template<typename Object>
const Object& Vector<Object>::operator[](int index) const
{
	return objects[index];
}

template<typename Object>
bool Vector<Object>::empty() const
{
	return size() == 0;
}

template<typename Object>
int Vector<Object>::size() const
{
	return theSize;
}

template<typename Object>
int Vector<Object>::capacity() const
{
	return theCapacity;
}

template<typename Object>
void Vector<Object>::push_back(const Object& x)
{
	if (theSize == theCapacity) {
		reserve(2 * theCapacity + 1);
	}
	objects[theSize++] = x;
}

template<typename Object>
void Vector<Object>::pop_back()
{
	--theSize;
}

template<typename Object>
const Object& Vector<Object>::back() const
{
	return objects[theSize - 1];
}


template<typename Object>
Vector<Object>::~Vector()
{
	delete[]objects;
}

template<typename Object>
Object* Vector<Object>::begin()
{
	return &objects[0];
}

template<typename Object>
const Object* Vector<Object>::begin() const
{
	return &objects[0];
}

template<typename Object>
Object* Vector<Object>::end()
{
	return &objects[theSize];
}

template<typename Object>
const Object* Vector<Object>::end() const
{
	return &objects[theSize];
}


