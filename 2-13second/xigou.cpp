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
	DDemo->show();											//����ָ��ָ���������
	cout << "delete ����ָ��" << endl;			 //�ͷ�����ָ��ʱ�� ������������ ���߸�������
	delete DDemo;                          

	Base* BBase = new Demo(2, "zhou");	
	BBase->show();											//����ָ��ָ���������
	cout << "delete ����ָ��" << endl;			// 1.�������������Ϊ������ʱ�� ֻ���ø�������
	delete BBase;								// 2.���������������Ϊ������ʱ������������鹹���������߸������������

	return 0;
}