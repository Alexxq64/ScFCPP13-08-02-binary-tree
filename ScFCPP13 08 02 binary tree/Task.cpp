#include "BinaryTree.h"
// поиск, возвращает указатель на найденный элемент
BinaryTree::Node* BinaryTree::findNodeByData(int finddata) {
	Node* current = root;
	while (current) {
		if (current->data == finddata) return current;
		if (current->data > finddata && current->leftChild)
			current = current->leftChild;
		else if (current->data < finddata && current->rightChild)
			current = current->rightChild;
		else return nullptr;
	}
}
// удаление элемента
void BinaryTree::delInt(int deldata) {
	Node* toDelete = findNodeByData(deldata);
	Node* dad = dad;
	if (isLeaf(toDelete)) {
		if (dad->leftChild == toDelete) dad->leftChild = nullptr;
		else toDelete->rightChild = nullptr;
		delete toDelete;
	}
	if (dad->leftChild && dad->rightChild) {

	}
}