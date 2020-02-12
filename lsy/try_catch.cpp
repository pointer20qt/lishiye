#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> vec{1,2,3,4,5,6};
	try
	{
		throw 1;
		for (int i = 0; i < 7; i++)
		{
			cout << vec.at(i) << endl;
		}
	
		cout << "打印完了" << endl;
	}
	catch (int n)
	{
		cout << "跳出" << endl;
	}
	catch (out_of_range &e)
	{
		cout << "越界异常" << endl;
	}
	catch (...)
	{
		cout << "发生了异常" << endl;
	}
	cout << "执行完毕" << endl;


    return 0;
}