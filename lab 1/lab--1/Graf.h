/*!
\authors viktor ivahnuk
\version 1.1
\date   24/09/20
\file
\brief Header file with class description

       this file contains the definition of the main classes for working with graphs and binary trees
*/


#pragma once

#include <vector>
#include <conio.h>
#include <iostream>
#include <string>


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
	\brief parrebnt class

	this class contains a template variable val which will be inherited
    this class contains the menu () method that will be used to create child classes 
*/
template <class T>
class basic {
protected:
	T val;
public:
	basic() {

	}
	void menu();
};

/*!
	\brief a child class that inherits from the basic class a variable val with data type * beentr 

	this class contains methods for working with a binary tree: inserting an element by key removing an element by key outputting the entire tree to the console
    the constructor of this class creates the tree whose root is stored in the variable val
*/
class tree : public basic <beentr> {
private:
	beentr insert(beentr a, int key);

	beentr delmax(beentr p, beentr t);

	beentr del(beentr root, int h);

	void print_tree(int l, beentr a);
public:
	tree() {
		int j;
		for (;;) {
			cout << "enter elemnt of the tree" << endl;
			cin >> j;
			val = insert(val, j);
			cout << "press enter to finish building the graph or any other key to continue working" << endl;
			if (_getch() == 13)break;
		}

	}

	void print_btr();

	void insert_in_beetree();

	void deletetree();
};

/*!
	\brief a child class that inherits the variable val with the data type vector <vector <int>>

	this class contains methods for working with a weighted graph represented by an adjacency matrix
    the constructor of this class creates the adjacency matrix itself, which is stored in the change T
*/
class graf_matrix : public basic <vector<vector<int>>> {
private:
	vector<vector<int>> Grafo_kruskal(int n, vector <vector<int>> ad);

	void insert(vector<vector<int>>& a, int x, int y, int l);

	bool conect_graf(vector<vector<int>> b);
public:
	graf_matrix() {
		cout << "enter the number of vertices of the graph" << endl << endl;
		int n;
		while (1) {
			cout << "n =";
			cin >> n;
			if (0 >= n)
				cout << "Enter other number (n>0)" << endl;
			else break;
		}

		for (int i = 0; i < n; i++) {
			val.push_back(vector<int>(n, 0));
		}
		for (;;) {
			int i; int j; int l;
			if (n > 1) {
				cout << "Enter two vertex" << endl;
				cin >> i >> j;
				cout << "enter the length of the edge of the graph" << endl;
				cin >> l;
				insert(val, i, j, l);
			}
			cout << "press enter to finish building the graph or any other key to continue working" << endl;
			if (_getch() == 13) break;
		}
	}

	void print();

	void delete_rebro(int x, int y);

	void delete_vertex(int m);

	void add();

	void insert_in_graf();

	void min_kist_graf();
};


