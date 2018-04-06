#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <iostream>

template <class T>
class BoundCheckArray
{
	T ** arr;
	int arrlen;
public:
	BoundCheckArray(int arrlen) : arrlen(arrlen)
	{
		arr = new T*[arrlen];
	}
	T*& operator[](int idx)
	{
		//if(idx < 0 || idx >= arrlen)
		return arr[idx];
	}
	T*& operator[](int idx) const
	{
		//if(idx < 0 || idx >= arrlen)
		return arr[idx];
	}
	int GetArrLen() const
	{
		return arrlen;
	}
};

#endif
