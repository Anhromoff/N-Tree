#ifndef NTREE_H
#define NTREE_H

#include <iostream>
#include <queue>
using namespace std;

const int max_children_size = 4; // a maximum number of children that each node may have

struct node
{
	int value; // some node data
	node* children[max_children_size]; // pointer to array of child nodes
	node(int v)
	{
		value = v;
		for (int i = 0; i < max_children_size; i++) children[i] = 0;
	}
};

node* Insert(node* root, int value)
{
	queue <node*> nodes_to_visit;
	node* current_node;
	if (!root)
	{
		root = new node(value);
		return root;
	}
	else
	{
		nodes_to_visit.push(root);
	}
	while (!nodes_to_visit.empty())
	{
		current_node = nodes_to_visit.front();
		nodes_to_visit.pop();

		for (int i = 0; i<max_children_size; i++)
		{
			if (!current_node->children[i])
			{
				current_node->children[i] = new node(value);
				return root;
			}
			else
			{
				nodes_to_visit.push(current_node->children[i]);
			}
		}
	}
}

bool IsLeaf(node* p)
{
	bool flag = 1;
	for (int i = 0; i < max_children_size; i++)
	{
		if (p->children[i])
		{
			flag = 0;
		}
	}
	return flag;
}

int FindMin(node* p)
{
	for (int i = 0; i < max_children_size; i++)
	{
		if (p->children[i])
		{
			if (IsLeaf(p->children[i]))
			{
				int q = p->children[i]->value;
				//cout << q << endl;
				p->children[i]=0;
				return q;
			}
			else
			{
				FindMin(p->children[i]);
			}
		}
	}
}

node* Delete(node* root, int value)
{
	if (!root) return 0;
	if (root->value != value)
	{
		for (int i = 0; i < max_children_size; i++) root->children[i]=Delete(root->children[i], value);
		return root;
	}
	else
	{
		if (IsLeaf(root))
		{
			delete root;
			return 0;
		}
		else
		{
			root->value = FindMin(root);
			return root;
		}
	}
}

void DeleteOdd(node* root, node* p)
{
	if (!p) return;
	else if (p->value % 2 != 0) Delete(root, p->value);
	else
	{
		for (int i = 0; i < max_children_size; i++)
		{
			if (p->children[i])
			{
				DeleteOdd(root, p->children[i]);
			}
		}
	}
}

void PrintTree(node* current_node) 
{
	static int level = 0; 
	level++;
	if (current_node)
	{
		printf("\\__%d \n", current_node->value); 
		for (int j = 0; (j<max_children_size); j++)
		{
			if (current_node->children[j])
			{
				for (int i = 0; i<level; i++) printf("   ");
				PrintTree(current_node->children[j]);
			}
		}
	}
	level--;
}

#endif

