#pragma once
#include <string>
class Tree
{
public:
	Tree();
	~Tree();

	char data;
	
	Tree *arr[35];
	
	void Generate(std::string);
	void Populate(Tree*);
	
	int getTotal();
private:
	int finaltotal;
	void setTotal();
	struct Tree* left;
	struct Tree* right;
	char Totarr[35] = { NULL };
	void push(Tree*);
	Tree* pop();
	void Calculate();
	int checksymbol(char);
	int top = -1;
	int insarr = 0;
	//int A, B, C, D, E;
};

