

/*!
\file
\brief  a header file describing the Edge class

 this file contains a description of the class and the names of its methods
*/
#pragma once

#include <string>
#include <vector>
#include "../../integral/body/body.h" 
#include "../../integral/body_rotate/body_rotate.h" 
using namespace std;

/*!
	\brief   the class is the edge of the graph and the key in the node of the binary tree
	\author viktor ivahnuk
	\date 26.10.20
	\version 2.0
*/
template <typename T>
class Edge {
private:

	/*!
     finds the text length of the value of the edge attribute
	*/
	int Length_edge(T edge);

	/*!
	returns zero for each data type
	*/
	T type_null();

	/*!
	converts string to int
	*/
	int string_to_int(string a);

public:


	T edge;///< value of Edge 

	int length_edge;///< text length 

	/*!
	constructor withaut parametrs
	*/
	Edge() {
		edge = type_null();
		length_edge = Length_edge(edge);
	}
	/*!
	constructor 
	\param edge - value Edge
	*/
	Edge(T edge) {
		this->edge = edge;
		length_edge = Length_edge(edge);
	}

	

	

	/*!
	 operator overload != for body class with a pattern int
	*/
	bool operator != (Edge<int>& ed) {
		return !(this->edge == ed.edge);
	}

	/*!
	 operator overload != for body class with a pattern double
	*/
	bool operator != (Edge<double>& ed) {
		return !(this->edge == ed.edge);
	}

	/*!
	 operator overload != for body class with a pattern string
	*/
	bool operator != (Edge<string>& ed) {
		return !(this->edge == ed.edge);
	}

	/*!
	 operator overload != for body class with a pattern vector<int>
	*/
	bool operator != (Edge<vector<int>>& ed) {
		return !(this->edge == ed.edge);
	}
	/*!
	 operator overload != for body class with a pattern vector<double>
	*/
	bool operator != (Edge<vector<double>>& ed) {
		return !(this->edge == ed.edge);
	}

	/*!
	 operator overload != for body class with a pattern vector<string>
	*/
	bool operator != (Edge<vector<string>>& ed) {
		return !(this->edge == ed.edge);
	}
	/*!
	 operator overload != for body class with a pattern body
	*/
	bool operator!=(Edge<body>& ed) {
		return !(this->edge.Volumes == ed.edge.Volumes && this->edge.Area == ed.edge.Area);
	}
	/*!
	 operator overload != for body class with a pattern body_rotate
	*/
	bool operator!=(Edge<body_rotate>& ed) {
		return !(this->edge.Volumes == ed.edge.Volumes && this->edge.Area == ed.edge.Area);
	}

	/*!
	 operator overload > for body class with a pattern int
	*/
	bool operator>(Edge<int>& ed) {
		return    this->edge > ed.edge;
	}

	/*!
	 operator overload < for body class with a pattern int
	*/
	bool operator<(Edge<int>& ed) {
		return    this->edge < ed.edge;
	}

	/*!
	 operator overload > for body class with a pattern double
	*/
	bool operator>(Edge<double> ed) {
		return  this->edge > ed.edge;
	}
	/*!
	 operator overload < for body class with a pattern double
	*/
	bool operator<(Edge<double> ed) {
		return  this->edge < ed.edge;
	}

	/*!
	 operator overload < for body class with a pattern string
	*/
	bool operator>(Edge<string>& ed) {
		return   string_to_int(this->edge) >string_to_int(ed.edge);
	}


	/*!
	 operator overload > for body class with a pattern string
	*/
	bool operator<(Edge<string>& ed) {
		return   string_to_int(this->edge) < string_to_int(ed.edge);
	}



	/*!
	 operator overload > for body class with a pattern vector<int>
	*/
	bool operator>(Edge<vector<int>>& ed) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < ed.edge.size(); i++)
			sum1 += ed.edge[i];
		for (int i = 0; i < this->edge.size(); i++)
			sum2 += this->edge[i];
		return sum2 > sum1;
	}



	/*!
	 operator overload < for body class with a pattern vector<int>
	*/
	bool operator<(Edge<vector<int>>& ed) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < ed.edge.size(); i++)
			sum1 += ed.edge[i];
		for (int i = 0; i < this->edge.size(); i++)
			sum2 += this->edge[i];
		return sum2 < sum1;
	}


	/*!
	 operator overload > for body class with a pattern vector<double>
	*/
	bool operator>(Edge<vector<double>>& ed) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < ed.edge.size(); i++)
			sum1 += ed.edge[i];
		for (int i = 0; i < this->edge.size(); i++)
			sum2 += this->edge[i];
		return sum2 > sum1;
	}
	/*!
	 operator overload < for body class with a pattern vector<double>
	*/
	bool operator<(Edge<vector<double>>& ed) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < ed.edge.size(); i++)
			sum1 += ed.edge[i];
		for (int i = 0; i < this->edge.size(); i++)
			sum2 += this->edge[i];
		return sum2 < sum1;
	}
	/*!
	 operator overload > for body class with a pattern vector<string>
	*/
	bool operator>(Edge<vector<string>>& ed) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < ed.edge.size(); i++)
			sum1 += string_to_int(ed.edge[i]);
		for (int i = 0; i < this->edge.size(); i++)
			sum2 += string_to_int(this->edge[i]);
		return sum2 > sum1;
	}
	/*!
	 operator overload < for body class with a pattern vector<string>
	*/
	bool operator<(Edge<vector<string>>& ed) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < ed.edge.size(); i++)
			sum1 += string_to_int(ed.edge[i]);
		for (int i = 0; i < this->edge.size(); i++)
			sum2 += string_to_int(this->edge[i]);
		return sum2 < sum1;
	}
	/*!
	 operator overload > for body class with a pattern body
	*/
	bool operator>(Edge<body>& ed) {
		return (this->edge.Volumes > ed.edge.Volumes);
	}
	/*!
	 operator overload < for body class with a pattern body
	*/
	bool operator<(Edge<body>& ed) {
		return (this->edge.Volumes < ed.edge.Volumes);
	}

	bool operator>(Edge<body_rotate>& ed) {
		return (this->edge.Volumes > ed.edge.Volumes);
	}
	/*!
	 operator overload < for body class with a pattern body_rotate
	*/
	bool operator<(Edge<body_rotate>& ed) {
		return (this->edge.Volumes < ed.edge.Volumes);
	}


        
};


/*!
 operator overload << for vector pattern
*/
template<typename S>
ostream& operator<< (ostream& out, Edge<vector<S>> ed) {

	
	for (int i = 0; i < ed.edge.size(); i++)
		out << ed.edge[i] << " ";
	return out;
}

/*!
 operator overload << for pattern value 
*/
template<typename T>
ostream& operator<< (ostream& out, Edge<T> ed) {
	out << ed.edge;
	return out;
}
