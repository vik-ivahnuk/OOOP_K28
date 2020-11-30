
/*!
\file
\brief  a header file describing the bin_tree class

 this file contains a description of the class and the names of its methods
*/

#pragma once
#include "Node/Node.hpp"
#include "../../genarate/type_generator.h"


/*!
	\brief class for working with a binary tree
	\author viktor ivahnuk
	\date 24.10.20
	\version 2.0

	the class is intended for work with the following templates: int, double, string, vector <int>, vector <double>, vector <string>, body, body_rotate
*/
template<typename T>
class bin_tree {

private:


	Node<T>* root;///<link to the root of the binary tree

	type_generator<T> generator;///<an auxiliary object based on the type_generator class for generating a binary tree
	

	/*!
	setter inserts a value into a tree with the root a
	\param a,value - tree root and value respectively
	\return root of a modified binary tree
	*/
	Node<T>* insert_in_tree(Node<T>* a,Edge<T> value);



	/*!
    setter displays a tree on the screen
	\param l,a - the number of spaces between the tiers of the tree and the root of the tree
	*/
	void print_tree(int l, Node<T>* a);


	/*!
	removes the largest element in the sub-tree
	\param p,t -parent and child node tree
	*/
	Node<T>* delmax(Node<T>* p, Node<T>* t);

	/*!
	setter removes an item from the tree
	\param[out] root -root of a binary tree
	\param[in] h - element that we insert into the tree
    */
	Node<T>* del(Node<T>*root, Edge<T> h);

public:

	/*!
	constructor withaut parametrs
	*/
	bin_tree();
	

	/*!
	setter inserts a value into a tree with the root a
	\param[in] value -  the value we insert into the tree
	*/
	void insert(T value);

	/*!
	getter displays a tree on the screen
	*/
	void print();


	/*!
	setter removes an item from the tree
	\param[in] key - element that we insert into the tree
	*/
	void remove_node(T key);

	/*!
	setter generate new binary tree
	*/
	void generate_tree();
};

#include "bin_tree.hxx"
