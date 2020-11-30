

/*!
\file
\brief  a header file describing the interective class

 this file contains a description of the class and the names of its methods
*/


#pragma once




#include "../integral/body_rotate/body_rotate.h"
#include "../integral/body/body.h"
#include "../graph_tree/bin_tree/bin_tree.h"
#include <string>

/*!
	\brief class to demonstrate the work of the program
	\author viktor ivahnuk
	\date 29.10.20
	\version 2.0
*/
class interective {
private:



	std::string types[9];///< array with commands

	std::string types_1[14];///< array with commands

	std::string command[10];///< array with commands

	std::string types_3[5];///< array with commands

	body Body;///< object to determine the areaand volume of the body given by the function of two variables

	body_rotate Body_rotate;///<object to determine the area and volume of the body of rotation given by the function of one variable


	/*!
	setter to select a graph template
	*/
	void type_graph_menu();


	/*!
	setter to select a tree template
	*/
	void type_tree_menu();

	/*!
	menu to select the functions that set the bodiesand calculate their volumesand areas
	*/
	void integral_menu();


	/*!
     menu to work with a graph with a pattern int
	*/
	void graph_int_menu();

	/*!
	 menu to work with a graph with a pattern double
	*/
	void graph_double_menu();


	/*!
	 menu to work with a graph with a pattern string
	*/
	void graph_string_menu();

	/*!
	 menu to work with a graph with a pattern vector<int>
	*/
	void graph_vector_int_menu();

	/*!
	 menu to work with a graph with a pattern vector<double>
	*/
	void graph_vector_double_menu();

	/*!
	 menu to work with a graph with a pattern string
	*/
	void graph_vector_string_menu();

	/*!
	 menu to work with a graph with a pattern body
	*/
	void graph_body_menu();

	/*!
	 menu to work with a graph with a pattern body_rotate
	*/
	void graph_body_rotate_menu();



	/*!
	 menu to work with a binary tree with a pattern int
	*/
	void tree_int_menu();

	/*!
	 menu to work with a binary tree with a pattern double
	*/
	void tree_double_menu();


	/*!
	 menu to work with a binary tree with a pattern string
	*/
	void tree_string_menu();

	/*!
	 menu to work with a binary tree with a pattern vector<int>
	*/
	void tree_vector_int_menu();

	/*!
	 menu to work with a binary tree with a pattern vector<double>
	*/
	void tree_vector_double_menu();

	/*!
	 menu to work with a binary tree with a pattern vector<string>
	*/
	void tree_vector_string_menu();

	/*!
	 menu to work with a binary tree with a pattern body
	*/
	void tree_body_menu();

	/*!
	 menu to work with a binary tree with a pattern body_rotate
	*/
	void tree_body_rotate_menu();

public:
	/*!
	constructor withaut parametrs
	*/
	interective();

	/*!
	menu for selecting work with either a graph or a tree or with the calculation of areas and volumes
	*/
	void menu();



};
