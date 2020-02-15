#include<string>
#include<iostream>
#include<Initializer_List>
#include<assert.h>
#include<vector>
using namespace std;

//栈，先入后出， push,pop,top，size，empty
template<class T>class Lstcak
{
	vector<T> vec;
public:
	void push(T &&val)
	{
		vec.push_back(val);
	}
	void pop()
	{
		 vec.pop_back();
	}
	T& top()
	{
		return vec.back();
	}
	rsize_t size()
	{
		return vec.size();
	}
	bool empty()
	{
		return vec.size();
	}

};



int main()
{
	Lstcak<int> l;
	l.push(1);
	l.push(2);
	l.push(3);
	cout<<l.top()<<endl;
	l.pop();
	cout << l.top() << endl;
	l.pop();
	cout << l.top() << endl;
	l.pop();

	return 0;
}

