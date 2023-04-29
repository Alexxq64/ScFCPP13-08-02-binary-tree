#include "BinaryTree.h"
#include <string>
#include <iostream>
using namespace std;
//
BinaryTree::Node::Node(int d, Node* p) :
	data(d), parent(p) {
	leftChild = nullptr;
	rightChild = nullptr;
}
//
BinaryTree::Node::~Node() {
	// чистим за собой память
	if (rightChild != nullptr)
		delete rightChild;
	if (leftChild != nullptr)
		delete leftChild;
}
//
BinaryTree::BinaryTree() {
	root = nullptr;
}
//
BinaryTree::~BinaryTree() {
	if (root != nullptr)
	{
		delete root;
	}
}
void BinaryTree::addInt(int newdata) {
	if (root == nullptr) {
		// если дерево пустое, то новый элемент станет корнем
		root = new Node(newdata);
	}
	else {
		Node* current = root; // начинаем с корня
		Node* newNode = nullptr;
		while (newNode == nullptr) {
			if (current->data >= newdata) {
				// если элемент меньше текущего, идем влево
				if (current->leftChild != nullptr) {
					current = current->leftChild;
					continue;
				}
				// если левого узла нет, то нашли место для нового элемента
				newNode = new Node(newdata, current);
				current->leftChild = newNode;
			}
			else {
				// если элемент меньше текущего, идем вправо
				if (current->rightChild != nullptr) {
					current = current->rightChild;
					continue;
				}
				// если правого узла нет, то нашли место для нового элемента
				newNode = new Node(newdata, current);
				current->rightChild = newNode;
			}
		}
	}
}
// проверка является ли узел листом        
bool BinaryTree::isLeaf(Node* check) {
	return check->leftChild == nullptr
		&& check->rightChild == nullptr;
}

// проверка, являтся ли узел корневым
bool BinaryTree::isRoot(Node* check) {
	return check == root;
}
//---------

void  BinaryTree::printBinaryTree() {
	Node* queue[100];
	int queueCount = 0;
	queue[queueCount++] = root;
	while (queueCount != 0) {
		Node* current = queue[0];
		queueCount--;
		for (int i = 0; i < queueCount; i++) {
			queue[i] = queue[i + 1];
		}
		if (current->parent)
			cout << current->parent->data;
		cout << " " << current->data << endl;

		//if (current->parent) {
		//	if (current->parent->leftChild) cout << current->data + " <- ";
		//	else cout << "      ";
		//	cout << current->parent->data;
		//	if (current->parent->rightChild) cout << " -> " + current->data;
		//	cout << endl;
		//}
		if (current->leftChild) queue[queueCount++] = current->leftChild;
		if (current->rightChild) queue[queueCount++] = current->rightChild;
	}
}
