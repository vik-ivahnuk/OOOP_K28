/*!
\authors viktor ivahnuk
\version 1.0
\date   1/10/20
\file
\brief Header file with a description of the main class

this file contains a class for working with binary trees
*/


#pragma once

#include "tree.h"
#include <conio.h>
using namespace std;

/*!
	\brief class which will be a node of a binary tree

*/
typedef class btr {
public:
	int key;
	btr* left;
	btr* right;
	btr() {
		left = NULL;
		right = NULL;
	}
} *beentr;


/*!
	\brief a child class that inherits from the basic class a variable val with data type * beentr

	this class contains methods for working with a binary tree: inserting an element by key removing an element by key outputting the entire tree to the console
*/
class tree {
private:


	beentr val;

	beentr insert(beentr a, int key);

	beentr delmax(beentr p, beentr t);

	beentr del(beentr root, int h);

	void print_tree(int l, beentr a);
public:
	tree() {
		val = NULL;
	}


	void print_btr();

	void enter_date();

	void insert_in_beetree();

	void deletetree();

	void menu();
};
