

/*!
\file
\brief  a header file describing the graph_mtrx class

 this file contains a description of the class and the names of its methods
*/
#pragma once

#include "../Edge/Edge.h"
#include "../../genarate/type_generator.h"
#include <vector>

using namespace std;



/*!
	\brief class for working with a graph in matrix
	\author viktor ivahnuk
	\date 20.10.20
	\version 3.0

	the class is intended for work with the following templates: int, double, string, vector <int>, vector <double>, vector <string>, body, body_rotate
*/
template <typename T>
class graph_mtrx {

private:
	
	vector < vector<Edge<T>>> graph;///<matrix in which the graph is stored

	vector<vector<Edge<T>>> beckup_graph;///<beckup graph

	type_generator<T> generator;///<an auxiliary object based on the type_generator class for generating a graph



		/*!
			finds the largest edge in the graph
			return the length of the largest rib
		*/
        Edge<T> max_rib();



	   /*!
	   finds the maximum length of the line that corresponds to the length of the graph
	   return maximum length of the line
	   */
	   int max_length_adjency();

	 
	   /*!
	   checks whether the graph is connected
	   return true if the graph is connected and false if otherwise
	   */
	   bool connected_graph();

public:

	
	/*!
    constructor
	param[in] n number vertex of the new graph
   */
	graph_mtrx(int n);

	/*!
	getter displays a graph on the screen
	*/
	void print();


	/*!
     finds the edge by its length
	 \param key -length of rib
	*/
	void searsh_of_key(T key);


	/*!
	 finds the edge by its vertex
	 \param index1.,index2 - numbers of adjacent vertices
	 */
	void search_for_index(int index1, int index2);


	/*!
     setter inserts an edge of length key between vertices i and j
	 param i,j - numbers of adjacent vertices
	 param key -length of rib
	*/
	void insert(int i, int j, T key);


	/*!
	removes the edge that connects the vertices index1 and index2
	*/
	void remove_rib(int index1, int index2);

	/*!
	removes the vertex with the number num_of_vertex
    */
	void remove_vertex(int num_of_vertex);

	/*
	adds a new vertex to the graph
	*/
	void add_vertex();


	/*!
	 setter converts a graph to a minimal skeletal tree using the Kraskal algorithm
	*/
	void algoritm_kruskal();

	/*!
	setter  converts a graph to a minimal skeletal tree using the Prima algorithm
	*/
	void algoritm_prima();

	/*!
	 setter converts a graph to a minimal skeletal tree using the Borubki algorithm
	*/
	void algoritm_boruvki();

	
	/*!
	 setter saves the current graph to a backup graph
	*/
	void write_from_backup_graph();

	/*!
       setter  writes a backup graph to the current graph
	*/
	void write_to_backup_graph();

	/*!
	setter generate new graph
	*/
	void generate_graph();


};


#include "graph_mtrx.hxx"

