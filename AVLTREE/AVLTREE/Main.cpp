#include "Main.h"
#include <iostream>
#include <string>
#include <algorithm>
Main::Main()
{
}


Main::~Main()
{
}


int main()
{
	std::cout << "Generating tree" << std::endl;

	Tree * Gen = new Tree;

	std::string Working;

	Working = "ABC+*D/";

	Gen->Generate(Working);

	Gen->Calculate(Gen->arr[0]);
}