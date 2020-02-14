#include<string>
#include<iostream>
#include"e.h"
#include"e.h"
#include"cs.h"
#include"cs.h"
#ifndef _CS_
#define _CS_
class cs
{
public:
	cs();
	~cs();
};
#endif
#ifndef _A_
#define _A_
class A
{
public:
	void run();
};
#endif
using namespace std;

int main()
{
	A a;
	a.run();
	cs S;
	S.fun();
}
void A::run()
{
	cout << "ÄãºÃ" << endl;
}
