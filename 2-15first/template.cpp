#include<string>
#include<iostream>
#include<Initializer_List>
#include<assert.h>
using namespace std;


template<class T>T LiMax (T& a, T& b)
{
	cout << "模板推导" << "    ";
	return a > b ? a : b;
}
int LiMax(int a,int b)
{
	cout << "函数推导"<<"    " ;
	return a > b ? a : b;
}
template<class T,class T2>T LiMax(T& a, T2& b)
{
	return a > b ? a : b;
}
template<int a,class T, class T2>T LiMax(T& a, T2& b)
{
	return a > b ? a : b;
}

class A
{

public:
	char *name;
	int value = 0;
	A(int a)
	{
		name = new char[100];
		value = a;
	}
	A(const A& other)
	{
		name = new char[100];
		this->value = other.value;
	}
	A& operator=(const A& other)
	{
		name = new char[100];
		this->value = other.value;
		return *this;
	}
	~A()
	{
		delete name;
	}
};
template<class T>void Liswap(T& a, T& b)
{
	T tmp(a);
	tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int x1 = 3;
	int x2= 5;
	double d1 = 3.1;
	double d2 = 4.4;
	//隐式推导
	cout << "隐式推导" << endl;
	cout << LiMax(x1, x2) << endl;
	cout << LiMax(x1, d1) << endl;
	//显式推导
	cout << "显式推导" << endl;
	cout << LiMax<int>(x1, d2) << endl;
	//指定模板 重写了int的比较的话，会让使用模板推导 不然会用自己写好的int推导
	cout << LiMax<>(x1, x2) << endl;

	Liswap(x1,x2);
	//模板交换
	cout << x1 << "交换了" << x2 << endl;
	//拷贝构造交换
	A a1(2);
	A a2(3);
	Liswap(a1,a2);
	cout << a1.value << "交换了" << a2.value;
	return 0;
}

