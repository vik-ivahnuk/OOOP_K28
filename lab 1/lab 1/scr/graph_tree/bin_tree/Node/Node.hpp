
/*!
\file
\brief a header file describing the Node class

 this file contains a description of the class and the names of its methods
*/

#pragma once

#include "../../Edge/Edge.h"


/*!
	\brief class for working with a binary tree
	\author viktor ivahnuk
	\date 21.10.20
	\version 2.0

    this class is a node of the binary tree
*/
template<typename T>
class Node {
public:
	Edge<T> key;///< node key
	Node* left;///< link to the left child node
	Node* right;///< link to the right child node

	/*!
	constructor withaut parametrs
	*/
	Node() {
		left = NULL;
		right = NULL;
		Edge<T> a;
		key = a;
	}

	/*!
	constructor
	\param key - node key value
	*/
	Node(T key) {
		left = NULL;
		right = NULL;
		Edge<T> a(key);
		this->key = a;
	}
	/*!
	constructor
	\param key - key of node
	*/
	Node(Edge<T> key) {
		left = NULL;
		right = NULL;
		this->key = key;
	}

};
