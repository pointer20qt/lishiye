#include<string>
#include<iostream>
#include<Initializer_List>
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
			number[i] = *(arr.begin()+i);
		}
	}
	int& operator[](unsigned int index)
	{
		return number[index];
	}

};



int main()
{

	vec v = { 1, 2, 3, 4, 5, 6, 7 };
	cout << v[2] << endl;
	return 0;
}
