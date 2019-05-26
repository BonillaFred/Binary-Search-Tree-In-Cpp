#include <iostream>
#include <conio.h>
using namespace std; 


struct Node
{
	int data;
	Node* right;
	Node* left;
	Node* parent; 
};

typedef Node* NodePtr;


NodePtr makeNode(int data)
{
	NodePtr madeNode = new Node;
	if (madeNode == NULL)
	{
		cout << "Could Not make Node" << endl; 
	}
	else
	{
		madeNode->data = data;
		madeNode->right = NULL; 
		madeNode->left = NULL; 
		madeNode->parent = NULL; 
	}

	return madeNode; 
}


void addNodeHelper(NodePtr& root, NodePtr toAdd, NodePtr parent)
{
	if (root == NULL)
	{
		root = toAdd;
		root->parent = parent; 
	}
	else
	{
		// Data will never be the same so not checked
		if (toAdd->data > root->data)
			addNodeHelper(root->right, toAdd, root);
		else
			addNodeHelper(root->left, toAdd, root); 
	}
}

void addNode(NodePtr& root, NodePtr toAdd)
{
	addNodeHelper(root, toAdd, NULL); // root has no parent 
}

NodePtr findNode(NodePtr currentNode, int data)
{
	if (currentNode == NULL)
		return NULL; 
	else
	{
		if (currentNode->data == data)
			return currentNode; 
		if (currentNode->data < data)
			findNode(currentNode->right, data);
		else
			findNode(currentNode->left, data); 
	}
}

void removeSingleNode(NodePtr& toRemove)
{
	// todo: work
}

int main()
{
	NodePtr root = NULL; 

	addNode(root, makeNode(10)); 
	addNode(root, makeNode(20));
	addNode(root, makeNode(30));
	addNode(root, makeNode(15));

	cout << findNode(root, 30)->data << " Should be 30" << endl; 
	return 0; 
}
