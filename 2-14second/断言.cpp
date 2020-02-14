#include<string>
#include<iostream>
#include<Initializer_List>
#include<assert.h>
using namespace std;

class vec
{
private:
	int *number;
public:
	vec(initializer_list<int> arr)
	{
		number = new int[arr.size()];
		for (int i = 0; i < arr.size(); i++)
		{
			number[i] = *(arr.begin() + i);
		}
	}
	int& operator[](int index)
	{
		assert(index>=0);
		return number[index];
	}

};
void adjustNumber(int &a, char &b)
{
	static_assert(sizeof(a)<=sizeof(b), "²»ÏàµÈ");
}
int main()
{
	int a;
	char b;
	adjustNumber(a,b);
	vec v = { 1, 2, 3, 4, 5, 6, 7 };
	cout << v[2] << endl;
	return 0;
}

