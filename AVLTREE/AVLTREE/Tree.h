#pragma once
#include <string>
class Tree
{
public:
	Tree();
	~Tree();

	char data;
	struct Tree* left;
	struct Tree* right;
	int height;
	Tree *arr[35];

	void Generate(std::string);
	void Calculate(Tree*);
private:
	void push(Tree*);
	Tree* pop();
	int checksymbol(char);
	int top = -1;
	//int A, B, C, D, E;
};

