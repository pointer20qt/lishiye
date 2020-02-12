#include<iostream>
#include<string>
using namespace std;
class people
{
public:
	string Name="123";
	char *name;


	people() //析构函数
	{
		this->Name = Name;
		cout << "构造函数" << endl;
	}
	people(const people &arg) :Name(arg.Name)
	{
		cout << "拷贝构造" << endl;
		this->name = (char*)malloc(100);//重新开辟空间 深拷贝
	}
	people(people && arg)
	{
		cout << "移动构造" << endl;
		this->name = arg.name;
		arg.name = NULL;
	}
	~people()
	{
		cout << "析构函数" << endl;
	}
};

people fun()
{
	people p1;
	return p1;
}

int main()
{
	people p1;
	
	//people p2(p1);  //深拷贝构造(p2不是临时变量不走移动构造)

	//p1 = fun(); //fun中的p1是临时变量如果深拷贝浪费空间会走移动构造函数

	people p3(move(p1)); //在这个情况中即使 p3不是临时变量 但因为调用的move(p1)进行了拷贝 也会走移动拷贝构造
	return 0;
}