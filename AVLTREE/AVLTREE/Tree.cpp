#include "Tree.h"
#include <iostream>

Tree::Tree()
{
}

Tree::~Tree()   
{
	delete left;
	delete right;
	delete node, ptr1, ptr2;
}
//generate the tree
void Tree::Generate(std::string Express)
{
	char symbol = Express[0];

	

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
//
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
//change the letters to numbers
void Tree::Populate(Tree * t)
{
	if (t != NULL)
	{
		
		Populate(t->left);
		Populate(t->right);
		if (t->data >= 'A' && t->data <= 'Z' || t->data >= 'a' && t->data <= 'z')
		{
			
			switch (t->data)
			{
			case 'A':
				std::cout << 2;
				Totarr[insarr] = 2;
				insarr++;
				break;
			case 'B':
				std::cout << 4;
				Totarr[insarr] = 4;
				insarr++;
				break;
			case 'C':
				std::cout << 6;
				Totarr[insarr] = 6;
				insarr++;
				break;
			case 'D':
				std::cout << 4;
				Totarr[insarr] = 4;
				insarr++;
				break;
			default:
				break;
			}
		}
		else
		{
			Totarr[insarr] = t->data;
			Calculate();
			insarr++;
		std::cout << t->data;
		}
		
		
	}
}
//Calculate the total number
void Tree::Calculate()
{
	int pt1, pt2;
			switch (Totarr[insarr])
			{
			case '-':
				
				pt1 = Totarr[insarr - 1];
				pt2 = Totarr[insarr - 2];
				Totarr[insarr - 2] = pt2 - pt1;

				Totarr[insarr] = NULL;
				Totarr[insarr - 1] = NULL;

				insarr = insarr - 2;
				break;
			case '+':
				
				pt1 = Totarr[insarr - 1];
				pt2 = Totarr[insarr - 2];
				Totarr[insarr - 2]= pt2 + pt1;

				Totarr[insarr] = NULL;
				Totarr[insarr - 1] = NULL;

				insarr = insarr - 2;

				break;
			case '*':
				
				pt1 = Totarr[insarr - 1];
				pt2 = Totarr[insarr - 2];
				Totarr[insarr - 2] = pt2 * pt1;

				Totarr[insarr] = NULL;
				Totarr[insarr - 1] = NULL;

				insarr = insarr - 2;
				break;
			case '/':
				
				pt1 = Totarr[insarr - 1];
				pt2 = Totarr[insarr - 2];
				Totarr[insarr - 2] = pt2 / pt1;

				Totarr[insarr] = NULL;
				Totarr[insarr - 1] = NULL;

				insarr = insarr - 2;
				break;
			default:
				break;
			}
	


}

int Tree::getTotal()
{
	setTotal();
	return finaltotal;
}
void Tree::setTotal()
{
	finaltotal = Totarr[0];
}