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
	Tree *arr[35];
	char Totarr[35];

	void Generate(std::string);
	void Populate(Tree*);
	void Calculate(char[]);
private:
	void push(Tree*);
	Tree* pop();
	int checksymbol(char);
	int top = -1;
	int insarr = 0;
	//int A, B, C, D, E;
};

