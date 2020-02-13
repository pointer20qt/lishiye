#include<string>
#include<iostream>
using namespace std;
class school
{
public:
	string schoolName;
	school(string str)
	{
		this->schoolName = str;
		cout << this->schoolName << "构造了" << endl;
	}
	virtual void schoolopen()
	{
		cout << this->schoolName << "开学了" << endl;
	}
	~school()
	{
		cout << this->schoolName << "关了" << endl;
	}

};

class highschool :public school
{
	int b;
public:
	highschool(string str) :school("东北石油")
	{
		this->schoolName = str;
		cout << this->schoolName << "构造了" << endl;
	}
	void schoolopen()
	{
		cout << this->schoolName << "开学了2" << endl;
	}

};


int main()
{
	school s("东北石油");
	highschool h("佳木斯一中");				//总结 1.不加virtual（隐藏） 指针是什么类型的就调用那个类型的方法
	school *ps = &s;//父类指针指向父类对象			   2.加了virtual（覆盖） 指针中存放了谁的地址就调用那个类型的方法
	ps->schoolopen();
	highschool *ph = &h;//父类指针指向子类对象
	ph->schoolopen();

	return 0;
}