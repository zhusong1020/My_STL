#pragma once
#include <algorithm>

template <typename Object>
class Vector
{
public:
	explicit Vector(int initSize = 0);
	Vector(const Vector& rhs) ;
	Vector(Vector&& rhs) noexcept;
	Vector& operator= (const Vector& rhs);
	Vector& operator= (Vector&& rhs) noexcept;
	void resize(int newSize);
	void reserve(int newCapacity);
	Object& operator [](int index);
	const Object& operator [](int index) const;
	bool empty() const;
	int size() const;
	int capacity() const;
	void push_back(const Object &x);
	void pop_back();
	const Object& back() const;
	~Vector();


	Object* begin();

	const Object* begin() const;

	Object* end();

	const Object* end() const;

	static const int SPARE_CAPCITY = 16;
private:
	int theSize;
	int theCapacity;
	Object* objects;
};

template class Vector<int>;