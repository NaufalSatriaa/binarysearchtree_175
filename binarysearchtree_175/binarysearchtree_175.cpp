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
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}
	void preorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}
	void postorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;

		}
		if (ptr != NULL) {
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

int main() {
	BinaryTree obj;
	while (true) {
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "1. Perform Inorder traversal" << endl;
		cout << "1. Perform Preorder traversal" << endl;
		cout << "1. Perform Postorder traversal" << endl;
		cout << "5. Exit" << endl;
		cout << "\nEnter ur choice : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case '1':
		{
			cout << "Enter a word : ";
			string word;
			cin >> word;
			obj.insert(word);
			break;
		}
		case '2':
		{
			obj.inorder(obj.ROOT);
			break;
		}
		case '3':
		{
			obj.preorder(obj.ROOT);
			break;
		}
		case '4':
		{
			obj.postorder(obj.ROOT);
			break;
		}
		case '5':
			return 0;
		default :
		{
			cout << "Invalid Option" << endl;
			break;
		}
			
		}
	}
}
