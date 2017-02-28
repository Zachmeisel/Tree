#include "Tree.h"
#include <iostream>

Tree::Tree()
{
}

Tree::~Tree()
{
}

void Tree::Generate(std::string Express)
{
	char symbol = Express[0];

	Tree *node, *ptr1, *ptr2;

	int choose;
	for (int i = 1; i < symbol != NULL; i++)
	{
		choose = checksymbol(symbol);
		if (choose == 1)
		{
			node = new Tree;
			node->data = symbol;
			node->left = NULL;
			node->right = NULL;
			push(node);
		}
		else if (choose == -1)
		{
			ptr1 = pop();
			ptr2 = pop();
			node = new Tree;
			node->data = symbol;
			node->left = ptr2;
			node->right = ptr1;
			push(node);
		}
		else
		{
			std::cout << "Incorrect input" << std::endl;
			exit(EXIT_FAILURE);
		}
		symbol = Express[i];

	}


}

void Tree::push(Tree* a)
{
	top++;
	arr[top] = a;
}

Tree* Tree::pop()
{
	top--;
	Tree* control;
	control = arr[top + 1];
	arr[top + 1] = NULL;
	return(control);
}

int Tree::checksymbol(char sym)
{
	if (sym == '+' || sym == '-' || sym == '*' || sym == '/')
	{
		return -1;
	}
	else if (sym >= 'a' || sym <= 'z')
	{
		return 1;
	}
	else if (sym >= 'A' || sym <= 'Z')
	{
		return 1;
	}
	else
	{
		return -99;
	}
}

void Tree::Populate(Tree * t)
{
	if (t != NULL)
	{
		
		Populate(t->left);
		Populate(t->right);
		if (t->data >= 'A' && t->data <= 'Z' || t->data >= 'a' && t->data <= 'z')
		{
			Totarr[insarr] = t->data;
			insarr++;
			switch (t->data)
			{
			case 'A':
				std::cout << 2;
				break;
			case 'B':
				std::cout << 7;
				break;
			case 'C':
				std::cout << 3;
				break;
			case 'D':
				std::cout << 5;
				break;
			default:
				break;
			}
		}
		else
		{
			Totarr[insarr] = t->data;
			insarr++;
		std::cout << t->data;
		}
		
		
	}
}
void Tree::Calculate(char a[])
{
	/*for (int i = 0; i < a.size(); i++)
	{

	}*/


}