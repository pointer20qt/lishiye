#include<iostream>
#include<string>
using namespace std;
class people
{
public:
	string Name="123";
	char *name;


	people() //��������
	{
		this->Name = Name;
		cout << "���캯��" << endl;
	}
	people(const people &arg) :Name(arg.Name)
	{
		cout << "��������" << endl;
		this->name = (char*)malloc(100);//���¿��ٿռ� ���
	}
	people(people && arg)
	{
		cout << "�ƶ�����" << endl;
		this->name = arg.name;
		arg.name = NULL;
	}
	~people()
	{
		cout << "��������" << endl;
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
	
	//people p2(p1);  //�������(p2������ʱ���������ƶ�����)

	//p1 = fun(); //fun�е�p1����ʱ�����������˷ѿռ�����ƶ����캯��

	people p3(move(p1)); //���������м�ʹ p3������ʱ���� ����Ϊ���õ�move(p1)�����˿��� Ҳ�����ƶ���������
	return 0;
}