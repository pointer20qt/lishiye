#include<string>
#include<iostream>
#include<Initializer_List>
#include<assert.h>
#include<vector>
#include<memory>

using namespace std;
template<class T>class Lunique_ptr
{
	T*p = nullptr;
public:
	Lunique_ptr(T* ptr) :p(ptr)
	{
	}
	Lunique_ptr() = default;
	~Lunique_ptr()
	{
		delete p;
	}
	Lunique_ptr(const Lunique_ptr<T> & ptr) = default;
	Lunique_ptr(Lunique_ptr<T> && ptr)
	{
		p = ptr.p;
		ptr.p = nullptr;
	}
	T* get()
	{
		return p;
	}
	T* release()
	{
		auto tmp = p;
		delete p;
		return tmp;
	}
	void reset(T* newptr)
	{
		delete p;
		p = newptr;
	}
	T& operator*()
	{
		return *p;
	}
	T* operator->()
	{
		return p;
	}
};
class Tool
{
public:
	int value = 0;
};


int main()
{
	Lunique_ptr<Tool> pstr(new Tool);
	Lunique_ptr<Tool>pstr2(move(pstr));
	return 0;
}

 