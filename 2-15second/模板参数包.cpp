#include<string>
#include<iostream>
#include<Initializer_List>
#include<assert.h>
#include<vector>
using namespace std;

//ջ���������� push,pop,top��size��empty
void Lprint()
{

}
template<class T, class... args> void Lprint(T f, args... d){
	cout << f << endl;
	Lprint(d...);
}


int main()
{
	Lprint(2, 3, 2, 6, 2, 3, 5);
	return 0;
}

