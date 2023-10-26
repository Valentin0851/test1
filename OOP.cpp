#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<deque>
#include<queue>
#include<functional>
#include<map>
#include<string.h>
#include<stdio.h>
#include<locale.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<ctime>
using namespace std;


class MyClass
{
public:
	int *data;

	MyClass(int size)
	{
		this->Size = size;
		this->data = new int[size];
		for (int i = 0; i < size; ++i)
		{
			data[i] = i;
		}
		std::cout << "Constructor completed " << this << endl;
	};

	MyClass(const MyClass& other)
	{
		this->Size = other.Size;
		this->data = new int[other.Size];
		for (int i = 0; i < Size; ++i)
		{
			this->data[i] = other.data[i];
		}
		std::cout << "Copy Constructor completed " << this << endl;
	}

	~MyClass()
	{
		std::cout << "Dectructor completed " << this << endl;
		delete[] data;
	};
private:
	int Size;
};

void Foo(MyClass value)
{
	std::cout << "Foo completed" << endl;
}

MyClass Foo2()
{
	std::cout << "Foo2 completed" << endl;
	MyClass temp(2);
	return temp;

}

void table(float(*) (float), float, float, int, float*, float*);
