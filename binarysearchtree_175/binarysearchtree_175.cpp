#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//constructor for the node class
	Node(string i, Node * l, Node* r) {
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public:
	Node* ROOT;
	
	BinaryTree() {
		ROOT = NULL; //initializing ROOT to NULL
	}
	void insert(string element) //insert a node in the binarysearch tree
	{
		Node* newNode = new Node(element, NULL, NULL); //allocate memory for the new node
		newNode->info = element; //assign value to the data field of the new node
		newNode->leftchild = NULL; //make the left child pf the new node point to NULL
		newNode->rightchild = NULL; //make the right childe of the new node point to NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode); //locate the new node which will be parent of the node to be interested

		if (parent == NULL) {
			ROOT = newNode;
			return;
		}
		if (element < parent->info) {
			parent->leftchild = newNode;
		}
		else if (element > parent-> info) {
			parent->rightchild = newNode;
		}
	}
	void search(string element, Node*& parent, Node*& currentNode) {
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element)) {
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->rightchild;
			else
				currentNode = currentNode->rightchild;

		}
	}
	void inorder(Node* ptr) {

	}
};

