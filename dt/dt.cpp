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
		cout << this->schoolName << "������" << endl;
	}
	virtual void schoolopen()
	{
		cout << this->schoolName << "��ѧ��" << endl;
	}
	~school()
	{
		cout << this->schoolName << "����" << endl;
	}

};

class highschool :public school
{
	int b;
public:
	highschool(string str) :school("����ʯ��")
	{
		this->schoolName = str;
		cout << this->schoolName << "������" << endl;
	}
	void schoolopen()
	{
		cout << this->schoolName << "��ѧ��2" << endl;
	}

};


int main()
{
	school s("����ʯ��");
	highschool h("��ľ˹һ��");				//�ܽ� 1.����virtual�����أ� ָ����ʲô���͵ľ͵����Ǹ����͵ķ���
	school *ps = &s;//����ָ��ָ�������			   2.����virtual�����ǣ� ָ���д����˭�ĵ�ַ�͵����Ǹ����͵ķ���
	ps->schoolopen();
	highschool *ph = &h;//����ָ��ָ���������
	ph->schoolopen();

	return 0;
}