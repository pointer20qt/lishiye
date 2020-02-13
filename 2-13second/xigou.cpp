#include<string>
#include<iostream>
using namespace std;
class Base
{
public:
	Base(string data) : m_data(data){ }
	virtual ~Base(){ cout << "Base:: ~Base" << endl; }
	void show()
	{
		cout << "Base show" << endl;
	}
private:
	string m_data;
};

class Demo : public Base
{
public:
	Demo(int id, string data) : m_id(id), Base(data){ }
	~Demo(){ cout << "Demo::~Demo" << endl; }
	void show()
	{
		cout << "Demo show" << endl;
	}
private:
	int m_id;
};

int main()
{
	Demo* DDemo = new Demo(1, "hello");
	DDemo->show();											//子类指针指向子类对象
	cout << "delete 子类指针" << endl;			 //释放子类指针时候 先走子类析构 再走父类析构
	delete DDemo;                          

	Base* BBase = new Demo(2, "zhou");	
	BBase->show();											//父类指针指向子类对象
	cout << "delete 父类指针" << endl;			// 1.当父类的析构不为虚析构时候 只调用父类析构
	delete BBase;								// 2.当父类的析构函数为虚析构时候，先走子类的虚构函数，再走父类的析构函数

	return 0;
}
