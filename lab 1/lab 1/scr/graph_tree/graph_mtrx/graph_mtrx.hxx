

/*!
\file
\brief  a header file describing the graph_mtrx class

 this file contains a description of method graph_mtrx class
*/





#pragma once

#include "graph_mtrx.h"
#include "../Edge/Edge.h"

#include <iomanip>
#include <iostream>

using namespace std;



/*!
	finds the largest edge in the graph
	return the length of the largest rib
*/
template <typename T>  
Edge<T> graph_mtrx<T>::max_rib() {
	Edge<T> result;
	for (int i = 0; i < 1 + graph.size() / 2; i++)
		for (int j = 0; j < graph.size(); j++)
			if (graph[i][j] > result)
				result = graph[i][j];

	return result;
}


/*!
constructor
param[in] n number vertex of the new graph
*/
template <typename T>
graph_mtrx<T>::graph_mtrx(int n) {
	Edge<T> adjency;

	vector<Edge<T>> t(n, adjency);

	vector<vector<Edge<T>>> m(n, t);
	graph = m;
	beckup_graph = {};
}



/*!
checks whether the graph is connected
return true if the graph is connected and false if otherwise
*/
template <typename T>
bool graph_mtrx<T>::connected_graph() {
	vector<int> vertex;
	Edge<T> null;
	int P = 0;
	vertex.push_back(P);
	bool t,f;
	
	while (vertex.size() < graph.size()) {
	
		f = false;
		for (int i = 0; i < graph.size(); i++) {
			if (graph[P][i] != null) {
			


				t = false;
				for (int k = 0; k < vertex.size(); k++) {
					if (i == vertex[k])
						t = true;
				}
				if (!t)
				{
					f = true;
					P = i;
				
					vertex.push_back(P);
					break;
				}

			}
			
		}
		if (!f)
			break;
	}
	if (vertex.size() == graph.size())
		return true;
	else return false;
}




/*!
getter displays a graph on the screen
*/
template <typename T>
void  graph_mtrx<T>::print() {


	if (graph.size() == 0) {
		cout << endl << "the graph is empty" << endl;
	}
	int m;

	for (int i = 0; i < graph.size(); i++) {
		cout << "   ";
		for (int j = 0; j < graph[i].size(); j++) {

			m = max_length_adjency() - graph[i][j].length_edge;
			while (m) {
				cout << " ";
				m--;
			}
			cout << graph[i][j] << "   ";
		}
		cout << endl << endl;
	}
		
		
	
}


/*!
 finds the edge by its length
 \param key -length of rib
*/
template <typename T>
void graph_mtrx<T>::searsh_of_key(T key) {
	bool  u = true;
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph.size(); j++)
			if (graph[i][j].edge == key) {
				cout << i + 1 << "  " << j + 1 << endl;
				u = false;
			}
		if (!u)
			break;
	}
	if (u)
		cout << "an edge at such length was not found" << endl;
}


/*!
 finds the edge by its vertex
 \param index1.,index2 - numbers of adjacent vertices
 */
template <typename T>
void graph_mtrx<T>::search_for_index(int i, int j) {
	if (i > graph.size() || j > graph.size() || i < 1 || j < 1)
		cout << "incorrect data entered" << endl;
	else  cout << "the distance between the vertices --- " << graph[i - 1][j - 1] << endl;
}


/*!
 setter inserts an edge of length key between vertices i and j
 param i,j - numbers of adjacent vertices
 param key -length of rib
*/
template <typename T>
void graph_mtrx<T>::insert(int i, int j, T key) {
	Edge<T> k(key);
	if (i > graph.size() || j > graph.size() || i < 1 || j < 1)
		cout << "incorrect data entered" << endl;
	else {
		if (i != j)
		{
			graph[i - 1][j - 1] = k;
			graph[j - 1][i - 1] = k;
		}
	}
}



/*!
removes the edge that connects the vertices index1 and index2
*/
template <typename T>
void graph_mtrx<T>::remove_rib(int index1, int index2) {
	Edge<T> null;
	insert(index1, index2, null.edge);
}


/*!
removes the vertex with the number num_of_vertex
*/
template <typename T>
void graph_mtrx<T>::remove_vertex(int m) {
	if (m > graph.size())
		return;
	if (m == 1 && graph.size() == 1) {
		graph = {  };
		return;
	}
	for (int i = m - 1; i < graph.size() - 1; i++) {
		graph[i] = graph[i + 1];
		for (int j = 0; j < graph.size(); j++)
			graph[j][i] = graph[j][i + 1];
	}
	graph.pop_back();
	for (int i = 0; i < graph.size(); i++)
		graph[i].pop_back();
}


/*
adds a new vertex to the graph
*/
template <typename T>
void graph_mtrx<T>::add_vertex() {
	Edge<T> null;
	if (graph.size() == 0)
		graph = { {null} };
	else {
		graph.push_back({});
		for (int i = 0; i < graph.size(); i++) {
			graph[i].push_back(null);
			if (i != graph.size() - 1)
				graph[graph.size() - 1].push_back(null);
		}

	}

}


/*!
finds the maximum length of the line that corresponds to the length of the graph
return maximum length of the line
*/
template <typename T>
int graph_mtrx<T>::max_length_adjency() {
	int max = 0;
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph.size(); j++) {
			if (graph[i][j].length_edge > max)
				max = graph[i][j].length_edge;
		}
	}


	return max;
}

/*!
 setter converts a graph to a minimal skeletal tree using the Kraskal algorithm
*/
template<typename T>
void graph_mtrx<T>::algoritm_kruskal()
{

	if (!connected_graph()) {
		cout << "graph is not connected" << endl;
		return;
	}
	Edge<T> null;
	int n = graph.size();
	vector< vector<Edge<T>> >  gr = graph;
	vector< vector<Edge<T>> > arb(n);
	vector<int> pert(n);
	Edge<T> INF = max_rib();
	for (int i = 0; i < n; i++) {
		arb[i] = vector<Edge<T>>(n, null);
		pert[i] = i;
	}

	int nA;
	int nB;
	int arcos = 1;
	while (arcos < n) {

		Edge<T> min = INF;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (min > gr[i][j] && pert[i] != pert[j] && gr[i][j] != null) {
					min = gr[i][j];
					nA = i;
					nB = j;
				}


		if (pert[nA] != pert[nB]) {

			arb[nA][nB] = min;
			arb[nB][nA] = min;


			int temp = pert[nB];
			pert[nB] = pert[nA];
			for (int k = 0; k < n; k++)
				if (pert[k] == temp)
					pert[k] = pert[nA];

			arcos++;
		}
	}
	graph = arb;
}


/*!
setter  converts a graph to a minimal skeletal tree using the Prima algorithm
*/
template<typename T>
void graph_mtrx<T>::algoritm_prima() {

	if (!connected_graph()) {
		cout << "graph is not connected" << endl;
		return;
	}

	int n = graph.size();
	Edge<T> null;
	vector<Edge<T>> a(n, null);
	vector<vector<Edge<T>>> mtrx(n, a);

	vector<int> vertex;
	for (int i = 1; i < n; i++)
		vertex.push_back(i);
	vector<int> post_vertex = { 0 };
	int k;
	int t;
	Edge<T> min;
	while (post_vertex.size() < n) {
		k = -1;
		t = -1;
		min = max_rib();
		for (int i = 0; i < post_vertex.size(); i++) {
			for (int j = 0; j < vertex.size(); j++) {
				if (vertex[j] > 0 && graph[post_vertex[i]][vertex[j]] != null) {
					if (graph[post_vertex[i]][vertex[j]] < min) {
						min = graph[post_vertex[i]][vertex[j]];
						k = j + 1;
						t = post_vertex[i];
					}
				}
			}
		}

		post_vertex.push_back(k);
		vertex[k - 1] = -1;
		mtrx[k][t] = min;
		mtrx[t][k] = min;

	}

	graph = mtrx;
}

/*!
 setter converts a graph to a minimal skeletal tree using the Borubki algorithm
*/
template<typename T>
void graph_mtrx<T>::algoritm_boruvki() {

	if (!connected_graph()) {
		cout << "graph is not connected" << endl;
		return;
	}

	int N = graph.size();

	vector<vector<int>> component;
	for (int i = 0; i <N ; i++) 
		component.push_back({ i });

	Edge<T> null;

	vector<Edge<T>> a(N, null);

	vector<vector<Edge<T>>> min_kist(N, a);
	
	
	vector<int> s;

	vector<int> DEL;

	Edge<T> MIN;
	pair<int,int> min;
	bool t;
	while (component.size() > 1) {
	
		s = {};
		DEL = {};
		for (int j = 0; j < component.size(); j++) {
			MIN = max_rib();
			for (int i = 0; i < component.size(); i++) {
	
				if (i != j) {
					for (int k = 0; k < component[j].size(); k++) {
						for (int l = 0; l < component[i].size(); l++) {
							if (graph[component [j][k]][component[i][l]] < MIN&& graph[component[j][k]][component[i][l]] != null) {
								MIN = graph[component[j][k]][component[i][l]];
							    min.first = component[j][k];
								min.second = component[i][l];
							}
						}
					}
				}
			}
			min_kist[min.first][min.second] = MIN;
			min_kist[min.second][min.first] = MIN;
			s.push_back(min.second);
			
		}
		
		for (int i = 0; i < component.size(); i++)
			component[i].push_back(s[i]);

		for (int j = 0; j < component.size(); j++) {
			for (int i = 0; i < component.size(); i++) {
				if (i != j) {
					for (int k = 0; k < component[j].size(); k++) {
						for (int l = 0; l < component[i].size(); l++) {
							if (component[j][k] == component[i][l])
							{
								
								for (int u = 0; u < component[i].size(); u++)
									component[j].push_back(component[i][u]);
								component[i] = {};
								DEL.push_back(i);

							}
						}
					}
				}
			}
		}
		
		for (int i = 0; i < DEL.size(); i++) {
	     
			for (int j = DEL[i]; j < component.size() - 1; j++)
				component[j] = component[j + 1];
			component.pop_back();
		}
		
	}
	graph = min_kist;

}


/*!
 setter saves the current graph to a backup graph
*/
template <typename T>
void graph_mtrx<T>::write_from_backup_graph(){
	graph = beckup_graph;
}


/*!
 setter  writes a backup graph to the current graph
*/
template <typename T>
void graph_mtrx<T>::write_to_backup_graph() {
	beckup_graph = graph;
}


/*!
setter generate new graph
*/
template <typename T>
void graph_mtrx<T>::generate_graph() {

	for (int i = 1; i < graph.size()+1; i++) {
		for (int j = 1; j < graph.size()+1; j++) {
			if (i != j)
				insert(i,j,generator.generate());
		}
	}
}
