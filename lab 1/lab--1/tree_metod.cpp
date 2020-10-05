/*!
\authors viktor ivahnuk
\version 1.0
\date   27/09/20
\file
\brief methods of the tree class are registered in the file
*/



#include <vector>
#include <iostream>
#include <string>

#include "Graf.h"

using namespace std;


/*!
auxiliary method that searches for the node of the tree with the largest value and removes it after sending its value to node p
\ param t the root of the tree
\ param p the node to which the largest value will be forwarded
\ return p the node to which the largest value of the tree has already been sen
*/
beentr tree::delmax(beentr p, beentr t) {
	beentr q;
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
 method that removes a node in a tree with the key h
\ param root the root of the tree from which the node will be removed
\ param h the key behind which the tree node will be deleted
\ return root the root of the modified tree
*/
beentr tree::del(beentr root, int h) {
	beentr q;
	if (root) {
		if (root->key > h) root->left = del(root->left, h);
		else if (root->key < h) root->right = del(root->right, h);
		else if (root->left)root->left = delmax(root->left, root);
		else { q = root; root = root->right; delete q; }
	}
	return root;
}

/*!
the method inserts an element into the binary tree with the key
\ param a the root of the binary tree 
\ param key - the key of the node that will be inserted into the tree
\ return root the root of the modified tree
*/

beentr tree::insert(beentr a, int key) {

	if (!a)
	{
		beentr k = new btr;
		k->key = key;
		return k;
	}
	if (key < a->key)
		a->left = insert(a->left, key);
	else
		a->right = insert(a->right, key);
	return a;
}

/*!
the method displays a binary tree
\ param[in] a the root of the binary tree
\ param[in]  l -the number of spaces between tree levels
*/
void tree::print_tree(int l, beentr a)
{
	if (a)
	{
		print_tree(l + 1, a->left);
		for (int i = 0; i < l; i++)cout << "    ";
		cout << a->key << endl;
		print_tree(l + 1, a->right);
	}
}
/*!
the method displays a binary tree with one space
*/
void tree::print_btr() {
	print_tree(1, val);
}


/*!
the method asks the user which key to insert into the tree and inserts it after insertion
*/
void tree::insert_in_beetree() {
	int  key;
	cout << "enter elemnt" << endl;
	cin >> key;
	insert(val, key);

}
/*!
the method asks the user which key to remove the element from the trees and removes it after input
*/
void tree::deletetree() {
	int k;
	cout << "enter element" << endl << "key  =  ";
	cin >> k;

	val = del(val, k);
}