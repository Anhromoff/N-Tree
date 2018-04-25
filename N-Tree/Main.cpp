#include "NTree.h"

int main()
{
	node* tree=0;

	tree=Insert(tree, 1);
	//PrintTree(tree);
	tree = Insert(tree, 2);
	//PrintTree(tree);
	tree = Insert(tree, 3);
	//PrintTree(tree);
	tree = Insert(tree, 4);
	//PrintTree(tree);
	tree = Insert(tree, 5);
	//PrintTree(tree);
	tree = Insert(tree, 6);
	//PrintTree(tree);
	tree = Insert(tree, 7);
	//PrintTree(tree);
	tree = Insert(tree, 8);
	//PrintTree(tree);
	tree = Insert(tree, 9);
	//PrintTree(tree);
	tree = Insert(tree, 10);
	//PrintTree(tree);
	tree = Insert(tree, 11);
	//PrintTree(tree);
	tree = Insert(tree, 12);
	PrintTree(tree);
	return 0;
}