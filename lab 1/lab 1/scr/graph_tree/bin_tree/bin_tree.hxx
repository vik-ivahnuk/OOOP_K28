

/*!
\file
\brief the header file with the method definition of the bin_tree class

this file contains the definition of the class methods for the universal template
*/

#pragma once

#include "bin_tree.h"
#include <iostream>

using namespace std;




/*!
constructor withaut parametrs
*/
template<typename T>
bin_tree<T>::bin_tree() {
	root = NULL;
}




/*!
setter inserts a value into a tree with the root a
\param a,value - tree root and value respectively
\return root of a modified binary tree
*/
template<typename T>
Node<T>* bin_tree<T>::insert_in_tree(Node<T>* a, Edge<T> key) {

	if (!a)
	{
		Node<T>* k = new Node<T>(key);
		return k;
	}
	if (a->key > key)
		a->left = insert_in_tree(a->left, key);
	else
		a->right = insert_in_tree(a->right, key);
	return a;
}



/*!
setter inserts a value into a tree with the root a
\param[in] value -  the value we insert into the tree
*/
template<typename T>
void bin_tree<T>::insert(T value) {
	Edge<T> a(value);
	root = insert_in_tree(root, a);
}



/*!
setter displays a tree on the screen
\param l,a - the number of spaces between the tiers of the tree and the root of the tree
*/
template<typename T>
void bin_tree<T>::print_tree(int l, Node<T>* a)
{
	if (a)
	{
		print_tree(l + 1, a->left);
		for (int i = 0; i < l; i++)cout << "      ";
		cout << a->key << endl << endl;
		print_tree(l + 1, a->right);
	}
}


/*!
getter displays a tree on the screen
*/
template<typename T>
void bin_tree<T>::print() {
	if (!root)
		cout << "tree is emty" << endl;
	print_tree(2, root);
}




/*!
removes the largest element in the sub-tree
\param p,t -parent and child node tree
*/
template<typename T>
Node<T>* bin_tree<T>::delmax(Node<T>* p, Node<T>* t) {

	Node<T>* q;
	if (p->right) {
		p->right = delmax(p->right, t);
	}
	else {
		t->key = p->key;
		q = p;
		p = p->left;
		delete q;
	}
	return p;
}


/*!
setter removes an item from the tree
\param[out] root -root of a binary tree
\param[in] h - element that we insert into the tree
*/
template <typename T>
Node<T>* bin_tree<T>::del(Node<T>* root, Edge<T> h) {
	Node<T>* q;
	if (root) {
		if (root->key > h) root->left = del(root->left, h);
		else if (root->key < h) root->right = del(root->right, h);
		else if (root->left)root->left = delmax(root->left, root);
		else { q = root; root = root->right; delete q; }
	}
	return root;
}

/*!
setter removes an item from the tree
\param[in] key - element that we insert into the tree
*/
template<typename T>
void bin_tree<T>::remove_node(T key) {
	Edge<T> Key(key);
	root = del(root, key);
}

/*!
setter generate new binary tree
*/
 template<typename T>
 void bin_tree<T>::generate_tree(){
	 root = NULL;
	 int N = rand() % 12;
	 for (int i = 0; i < N; i++) {
		 insert(generator.generate());
	 }
}