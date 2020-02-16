
#ifndef _AUTOP_
#define _AUTOP_
template<calss T>class Liautop
{
	T*p = nullptr;
public:
	Liautop(T* ptr) :p(ptr)
	{
	}
	Liautop() = default;
	~Liautop()
	{
		delete p;
	}
	Liautop(Liautop<T>& ptr)
	{
		p = ptr.p;
		ptr.p = nullptr;
	}
	Liautop& operator=(Liautop<T>& ptr)
	{
		delete p;
		p = ptr.p;
		ptr.p = nullptr;
		return *this;
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

#endif