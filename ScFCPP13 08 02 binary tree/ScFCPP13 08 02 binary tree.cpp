// ScFCPP13 08 02 binary tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "BinaryTree.h"
using namespace std;
int main() {
	BinaryTree btree;

	int toAdd[] = { 5, 4, -17, 20, 43, 13, 11, 18, 45, 15, 19 };

	for (auto i : toAdd)
		btree.addInt(i);

	btree.printBinaryTree();
	//for (auto i : toAdd)
	for (int i = -20; i < 50; i++)
		if (btree.findNodeByData(i))
			cout << btree.findNodeByData(i)->data << endl;
}