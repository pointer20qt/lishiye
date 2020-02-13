#include "stdafx.h"
#include "text.h"
#include<iostream>


text::text()
{
	std::cout << "这是新的text" << std::endl;
}


text::~text()
{
	std::cout << "这是结束的text" << std::endl;
}
void text::run()
{
	std::cout << "1" << std::endl;
}