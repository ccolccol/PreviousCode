#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template <class ElementType>
class Linear_Array {
	ElementType* data;
	int lastIndex;
	int MAXSIZE;
public:
	Linear_Array(int maxSize) : MAXSIZE(maxSize) {
		data = new ElementType[maxSize];
		lastIndex = -1;
	}

	void Insert(int insertPos, ElementType object) {
		assert(lastIndex + 1 != MAXSIZE && insertPos >= 1 && insertPos <= lastIndex + 2);
		for (int i = lastIndex; i >= insertPos - 1; i--)
			data[i + 1] = data[i];
		data[insertPos - 1] = object;
		lastIndex++;
	}

	void Delete(int deletePos) {
		assert(deletePos >= 1 && deletePos <= lastIndex + 1);
		for (int i = deletePos; i <= lastIndex; i++)
			data[i - 1] = data[i];
		lastIndex--;
	}

	int Find(ElementType object) {
		int pos = 0;
		while (pos <= lastIndex && data[pos] != object && ++pos);
		if (pos > lastIndex) return -1;
		return pos;
	}

	~Linear_Array() {
		delete[] data;
	}
};