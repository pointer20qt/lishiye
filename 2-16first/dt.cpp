#include<string>
#include<iostream>
#include<Initializer_List>
#include<assert.h>
#include<vector>
#include<memory>
using namespace std;

class Tool
{
	
public:
	int value = 0;
};

void run()
{
	auto_ptr<Tool> pstr{ new Tool };
	auto_ptr<Tool> p2(pstr);
	auto_ptr<Tool> p3;
	p3 = p2;
}
int main()
{

	

	return 0;
}

