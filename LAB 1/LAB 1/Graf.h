/*!
\authors viktor ivahnuk
\version 1.1
\date   24/09/20
\file
\brief Header file with class description

	   this file contains the definition of the main classes for working with graphs
*/


#pragma once

#include <vector>
#include <conio.h>
#include <iostream>
#include <string>


using namespace std;





/*!
	\brief a child class that inherits the variable val with the data type vector <vector <int>>

	this class contains methods for working with a weighted graph represented by an adjacency matrix

*/
class graf_matrix {

private:
	vector<vector<int>> val;
	vector<vector<int>> Grafo_kruskal(int n, vector <vector<int>> ad);

	void insert(vector<vector<int>>& a, int x, int y, int l);

	bool conect_graf(vector<vector<int>> b);
public:
	graf_matrix() = default;

	void print();

	void enter_date();

	void delete_rebro(int x, int y);

	void delete_vertex(int m);

	void add();

	void insert_in_graf();

	void min_kist_graf();

	void menu();
};
