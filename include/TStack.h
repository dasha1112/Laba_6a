#ifndef _STACK_
#define _STACK_

#include <iostream>
using namespace std;
template <class T>
class TStack
{
protected:
	int size;
	int count;
	T* data;

public:
	TStack(int _size = 0);
	TStack(TStack<T>& s);
	TStack(TStack<T>&& s);
	~TStack();
	void Push(T a);
	T GetElem();
	T Top();
	int GetCount();
	bool IsFull();
	bool IsEmpty();
	void Pop();
};

template <class T>
void TStack<T>::Pop()
{
	if (IsEmpty())
	{
		throw "Стек пуст";
	}
	--size;
}

template <class T>
TStack <T> ::TStack(int _size) : size(_size), count(0)
{
	if (_size < 0)
	{
		throw "Ошибка";
	}
	else if (_size == 0)
	{
		data = nullptr;
	}
	else
	{
		data = new T[_size];
	}
}

template <class T>
TStack <T> ::TStack(TStack<T>& s)
{
	if (s.data == nullptr)
	{
		data = nullptr;
		size = 0;
	}
	else
	{
		size = s.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = s.data[i];
		}
	}
	count = s.count;
}

template <class T>
TStack <T> ::TStack(TStack&& s)
{
	size = s.size;
	data = s.data;
	count = s.count;
	s.size = 0;
	s.data = nullptr;
	s.count = 0;
}

template <class T>
TStack <T> :: ~TStack()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}

template <class T>
bool TStack <T> ::IsEmpty()
{
	if (count == 0) return true;
	else return false;
}

template <class T>
bool TStack <T> ::IsFull()
{
	if (count == size) return true;
	else return false;
}

template <class T>
T TStack <T> ::GetElem() //возвращает и удаляет
{
	if (IsEmpty())
	{
		throw "Ошибка";
	}
	T elem = data[count - 1];
	count--;
	return elem;
}

template<class T>
inline T TStack<T>::Top() //возвращает
{
	if (IsEmpty())
	{
		throw "Ошибка";
	}
	return data[count - 1];
}


template <class T>
void TStack<T>::Push(T a)
{
	if (IsFull()) 
	{
		throw "Ошибка";
	}
	data[count] = a;
	count++;
}

template <class T>
int TStack<T> ::GetCount()
{
	return count;
}

#endif