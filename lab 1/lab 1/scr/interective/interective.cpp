
/*!
\file
\brief  a file describing methods the interective class

this file contains interective class definition definitions
*/
#include "interective.h"

#include "../graph_tree/graph_mtrx/graph_mtrx.h"
#include "../integral/body/body.h"
#include "../integral/body_rotate/body_rotate.h"
#include "../integral/functions/functions.h"


#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

/*!
constructor withaut parametrs
*/
interective::interective() {


	types[0] = "int",
	types[1] = "double",
	types[2] = "string",
	types[3] = "vector<int>";
	types[4] = "vector<double>";
	types[5] = "vector<string>";
	types[6] = "body";
	types[7] = "body_rotate";
	types[8] = "exit";


	types_1[0] = "print";
	types_1[1] = "search for ribs by length";
	types_1[2] = "search for edges by vertices";
	types_1[3] = "add edge";
	types_1[4] = "insert rib";
	types_1[5] = "remove rib";
	types_1[6] = "remove edge";
	types_1[7] = "genarete new graph";
	types_1[8] = "min kist tree with algorithm Kruskal";
	types_1[9] = "min kist tree with algotithm Prima";
	types_1[10] = "min kist tree with algorthm  Boruvki";
	types_1[11] = "save the current graph to a backup graph";
	types_1[12] = "read the backup graph";
	types_1[13] = "End";


	command[0] = "  z(x,y)= x^2 + y^2";
	command[1] = "  z(x,y)= e^x + e^y";
	command[2] = "  z(x,y)= |sin(x*y)|";
	command[3] = "  z(x,y)= 4.6  ";
	command[4] = "  z(x,y)=ln(x) + y";
	command[5] = "  z(x,y)=x + y^4";
	command[6] = "  y(x) = sqrt( 1 - x^2 )  (rotate body)  ";
	command[7] = "  y(x) = sin(x) + 5       (rotate body)";
	command[8] = "  y(x) = e^x              (rotate body)";
	command[9] = "  end";

	types_3[0] = "print";
	types_3[1]="insert";
	types_3[2]="delete element";
	types_3[3] ="generate new tree";
	types_3[4]="exit";
};
	

/*!
menu for selecting work with either a graph or a tree or with the calculation of areas and volumes
*/
void interective::menu() {
	string types[4]
	{
		"work with the graph in matrix form;",
		"work with binary tree;",
		"calculate the area and volume of the body",
		"Exit."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << endl << "    choose the mode press 'W' and 'S' to move up and down:" << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			if (i == position)
				cout << "->  " << types[i] << endl;
			else cout << "    " << types[i] << endl;
		}

		char key;
		key = _getch();


		if ((int)key != 13)
		{
			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 3;
			}
			if ((int)key == 115)
			{
				if (position < 3)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{
			case 0:
				system("cls");
				type_graph_menu();
				break;
			case 1:
				system("cls");
				type_tree_menu();
				system("pause");
				break;
			case 2:
				system("cls");
				integral_menu();
				system("pause");
				break;
			case 3:
				system("cls");
				end = true;
				break;
			}

		}
	}

}


/*!
setter to select a graph template
*/
void interective::type_graph_menu() {

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << endl << "    choose the mode press 'W' and 'S' to move up and down:" << endl << endl;
		for (int i = 0; i < 9; i++)
		{
			if (i == position)
				cout << "->  " << types[i] << endl;
			else cout << "    " << types[i] << endl;
		}

		char key;
		key = _getch();


		if ((int)key != 13)
		{
			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 8;
			}
			if ((int)key == 115)
			{
				if (position < 8)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{
			case 0:
				system("cls");
				graph_int_menu();
				break;
			case 1:
				system("cls");
				graph_double_menu();
				system("pause");
				break;
			case 2:
				system("cls");
				graph_string_menu();
				system("pause");
				break;
			case 3:
				system("cls");
				graph_vector_int_menu();
				system("pause");
				break;
			case 4:
				system("cls");
				graph_vector_double_menu();
				system("pause");
				break;
			case 5:
				system("cls");
				graph_vector_string_menu();
				system("pause");
				break;
			case 6:
				system("cls");
				graph_body_menu();
				system("pause");
				break;
			case 7:
				system("cls");
				graph_body_rotate_menu();
				system("pause");
				break;
			case 8:
				system("cls");
	
				end = true;
				system("pause");
				break;
	
		
			}

		}
	}

}
/*!
setter to select a tree template
*/
void interective::type_tree_menu() {
	string types[9]
	{
		"int",
		"double",
		"string",
		"vector<int>",
		"vector<double>",
		"vector<string>",
		"body",
		"body_rotate",
		"exit",
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << endl << "    choose the mode press 'W' and 'S' to move up and down:" << endl << endl;
		for (int i = 0; i < 9; i++)
		{
			if (i == position)
				cout << "->  " << types[i] << endl;
			else cout << "    " << types[i] << endl;
		}

		char key;
		key = _getch();


		if ((int)key != 13)
		{
			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 8;
			}
			if ((int)key == 115)
			{
				if (position < 9)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{
			case 0:
				system("cls");
				tree_int_menu();
				break;
			case 1:
				system("cls");
				tree_double_menu();
				system("pause");
				break;
			case 2:
				system("cls");
				tree_string_menu();
				system("pause");
				break;
			case 3:
				system("cls");
				tree_vector_int_menu();
				system("pause");
				break;
			case 4:
				system("cls");
				tree_vector_double_menu();

				system("pause");
				break;
			case 5:
				system("cls");
				tree_vector_string_menu();
				system("pause");
				break;
			case 6:
				system("cls");
				tree_body_menu();
				system("pause");
				break;
			case 7:
				system("cls");
				tree_body_rotate_menu();
				system("pause");
				break;
			case 8:
				system("cls");

				end = true;
				system("pause");
				break;


			}

		}
	}

}


/*!
menu to select the functions that set the bodiesand calculate their volumesand areas
*/
void interective::integral_menu() {




	int position = 0;
	bool end = false;


	double x1, x2, y1, y2;


	while (!end)
	{
		x1 = 0;
		x2 = 0;
		y1 = 0;
		y2 = 0;
		system("cls");
		cout << endl << "    choose the mode press 'W' and 'S' to move up and down:" << endl << endl;
		for (int i = 0; i < 10; i++)
		{
			if (i == position)
				cout << "->  " << command[i] << endl;
			else cout << "    " << command[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13) {
			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 9;
			}
			if ((int)key == 115)
			{
				if (position < 9)
					position++;
				else position = 0;
			}
		}

		else
		{
			if (position == 9) {
				system("cls");
				end = true;

			}
			else {
		
				cout << "enter the integration limits" << endl;
				cout << "x1 = ";
				cin >> x1;
				cout << endl << "x2 = ";
				cin >> x2;
		
				switch (position)
				{
				case 0:
					system("cls");
					cout << endl << "y1 = ";
					cin >> y1;
					cout << endl << "y2 = ";
					cin >> y2;
				
					Body.volumes(x1, x2, y1, y2, &functions::f1);
					Body.area(x1, x2, y1, y2, &functions::f1,&functions::df1);
					Body.print();
					system("pause");
					break;
				case 1:
					system("cls");
					cout << endl << "y1 = ";
					cin >> y1;
					cout << endl << "y2 = ";
					cin >> y2;
					Body.volumes(x1, x2, y1, y2, &functions::f2);
					Body.area(x1, x2, y1, y2, &functions::f2, &functions::df3);
					Body.print();
					system("pause");
					break;
				case 2:
					system("cls");
					cout << endl << "y1 = ";
					cin >> y1;
					cout << endl << "y2 = ";
					cin >> y2;
				
					Body.volumes(x1, x2, y1, y2, &functions::f3);
					Body.area(x1, x2, y1, y2, &functions::f3, &functions::df3);
					Body.print();
					system("pause");
					break;
				case 3:
					system("cls");
					cout << endl << "y1 = ";
					cin >> y1;
					cout << endl << "y2 = ";
					cin >> y2;
					Body.volumes(x1, x2, y1, y2, &functions::f4);
					Body.area(x1, x2, y1, y2, &functions::f4, &functions::df4);
					Body.print();
					system("pause");
					break;
				case 4:
					system("cls");
					cout << endl << "y1 = ";
					cin >> y1;
					cout << endl << "y2 = ";
					cin >> y2;
					Body.volumes(x1, x2, y1, y2, &functions::f5);
					Body.area(x1, x2, y1, y2, &functions::f5, &functions::df6);
					Body.print();
					system("pause");
					break;
				case 5:
					system("cls");
					cout << endl << "y1 = ";
					cin >> y1;
					cout << endl << "y2 = ";
					cin >> y2;
					Body.volumes(x1, x2, y1, y2, &functions::f6);
					Body.area(x1, x2, y1, y2, &functions::f6, &functions::df6);
					Body.print();
				
					system("pause");
					break;
				case 6:
					system("cls");
					Body_rotate.volumes(x1, x2, &functions::g1);
					Body_rotate.area_rotetion(x1, x2, &functions::dg1);
					Body_rotate.print();
					system("pause");
					break;
				case 7:
					system("cls");
					Body_rotate.volumes(x1, x2, &functions::g2);
					Body_rotate.area_rotetion(x1, x2, &functions::dg2);
					Body_rotate.print();
					system("pause");
					break;
				case 8:
					system("cls");
					Body_rotate.volumes(x1, x2, &functions::g3);
					Body_rotate.area_rotetion(x1, x2, &functions::dg3);
					Body_rotate.print();
					system("pause");
					break;

				}
			}
		}
	}
}


/*!
 menu to work with a graph with a pattern int
*/
void interective::graph_int_menu() {
	int n;
	cout << "Enter nummer Edge of graph " << endl << " n  =";
	cin >> n;
	graph_mtrx<int>  *graph;
	graph = new graph_mtrx<int>(n);


	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << endl << "    choose the mode press 'W' and 'S' to move up and down:" << endl << endl;
		for (int i = 0; i < 14; i++)
		{
			if (i == position)
				cout << "->  " << types_1[i] << endl;
			else cout << "    " << types_1[i] << endl;
		}

		char key;
		key = _getch();


		if ((int)key != 13)
		{
			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 13;
			}
			if ((int)key == 115)
			{
				if (position < 13)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{
			case 0:
				system("cls");
				graph->print();
				cout << endl << endl;
				system("pause");
				break;
			case 1:

				system("cls");
				cout << "Enter length of rib" << endl;
				int key;
				cin >> key;
				graph->searsh_of_key(key);
				system("pause");
				break;

			case 2:

				system("cls");
				cout << "enter vertex indices" << endl;
				int index1, index2;
				cout << "index1 =";
				cin >> index1;
				cout << "index2 =";
				cin >> index2;
				graph->search_for_index(index1, index2);
				system("pause");
				break;

			case 3:

				system("cls");
				graph->add_vertex();
				system("pause");
				break;

			case 4:

				system("cls");
				cout << "enter vertex" << endl;
				int index_1, index_2, length;
				cout << "number first vertex = ";
				cin >> index_1;
				cout << endl << "number second vertex = ";
				cin >> index_2;
				cout << endl << "enter lenght of rib" << endl;
				cout << " length = ";
				cin >> length;
				graph->insert(index_1, index_2, length);
				system("pause");
				break;

			case 5:

				system("cls");
				cout << "enter vertex" << endl;
				int Index1, Index2;
				cout << "number first vertex = ";
				cin >> Index1;
				cout << endl << "number second vertex = ";
				cin >> Index2;
				graph->remove_rib(Index1, Index2);
				system("pause");
				break;

			case 6:

				system("cls");
				int vertex;
				cout << "enter number of vertex" << endl;
				cin >> vertex;
				graph->remove_vertex(vertex);
				system("pause");
				break;

			case 7:
				system("cls");
				graph->generate_graph();
				system("pause");
				break;
			case 8:
				system("cls");
				graph->algoritm_kruskal();
				system("pause");
				break;
			case 9:
				system("cls");
				graph->algoritm_prima();
				system("pause");
				break;
			case 10:
				system("cls");
				graph->algoritm_boruvki();
				system("pause");
				break;
			case 11:
				system("cls");
				graph->write_to_backup_graph();
				
				break;
			case 12:
				system("cls");
				graph->write_from_backup_graph();
				break;
			case 13:
				system("cls");

				end = true;
				system("pause");
				break;
			}
		}
	}
}


/*!
 menu to work with a graph with a pattern double
*/
void interective::graph_double_menu() {
	int n;
	cout << "Enter nummer Edge of graph " << endl << " n  =";
	cin >> n;
	graph_mtrx<double>* graph;
	graph = new graph_mtrx<double>(n);


	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << endl << "    choose the mode press 'W' and 'S' to move up and down:" << endl << endl;
		for (int i = 0; i < 14; i++)
		{
			if (i == position)
				cout << "->  " << types_1[i] << endl;
			else cout << "    " << types_1[i] << endl;
		}

		char key;
		key = _getch();


		if ((int)key != 13)
		{
			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 13;
			}
			if ((int)key == 115)
			{
				if (position < 13)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{
			case 0:
				system("cls");
				graph->print();
				cout << endl << endl;
				system("pause");
				break;
			case 1:

				system("cls");
				cout << "Enter length of rib" << endl;
				double key;
				cin >> key;
				graph->searsh_of_key(key);
				system("pause");
				break;

			case 2:

				system("cls");
				cout << "enter vertex indices" << endl;
				int index1, index2;
				cout << "index1 =";
				cin >> index1;
				cout << "index2 = ";
				cin >> index2;
				graph->search_for_index(index1, index2);
				system("pause");
				break;

			case 3:

				system("cls");
				graph->add_vertex();
				system("pause");
				break;

			case 4:

				system("cls");
				cout << "enter vertex" << endl;
				int index_1, index_2; double length;
				cout << "number first vertex = ";
				cin >> index_1;
				cout << endl << "number second vertex = ";
				cin >> index_2;
				cout << endl << "enter lenght of rib" << endl;
				cout << " length =";
				cin >> length;
				graph->insert(index_1, index_2, length);
				system("pause");
				break;

			case 5:

				system("cls");
				cout << "enter vertex" << endl;
				int Index1, Index2;
				cout << "number first vertex = ";
				cin >> Index1;
				cout << endl << "number second vertex = ";
				cin >> Index2;
				graph->remove_rib(Index1, Index2);
				system("pause");
				break;

			case 6:

				system("cls");
				int vertex;
				cout << "enter number of vertex" << endl;
				cin >> vertex;
				graph->remove_vertex(vertex);
				system("pause");
				break;

			case 7:
				system("cls");
				graph->generate_graph();
				system("pause");
				break;
			case 8:
				system("cls");
				graph->algoritm_kruskal();
				system("pause");
				break;
			case 9:
				system("cls");
				graph->algoritm_prima();
				system("pause");
				break;
			case 10:
				system("cls");
				graph->algoritm_boruvki();
				system("pause");
				break;
			case 11:
				system("cls");
				graph->write_to_backup_graph();
				break;
			case 12:
				system("cls");
				graph->write_from_backup_graph();
				break;
			case 13:
				system("cls");
		
				end = true;
				system("pause");
				break;
			}
		}
	}
}


/*!
 menu to work with a graph with a pattern string
*/
void interective::graph_string_menu() {
	int n;
	cout << "Enter nummer Edge of graph " << endl << " n  =";
	cin >> n;
	graph_mtrx<string>* graph;
	graph = new graph_mtrx<string>(n);

	string key1;
	string length;

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << endl << "    choose the mode press 'W' and 'S' to move up and down:" << endl << endl;
		for (int i = 0; i < 14; i++)
		{
			if (i == position)
				cout << "->  " << types_1[i] << endl;
			else cout << "    " << types_1[i] << endl;
		}

		char key;
		key = _getch();


		if ((int)key != 13)
		{
			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 13;
			}
			if ((int)key == 115)
			{
				if (position < 13)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{
			case 0:
				system("cls");
				graph->print();
				cout << endl << endl;
				system("pause");
				break;
			case 1:

				system("cls");
				cout << "Enter length of rib" << endl;
				cin >> key1;
		
				graph->searsh_of_key(key1);
				system("pause");
				break;

			case 2:

				system("cls");
				cout << "enter vertex indices" << endl;
				int index1, index2;
				cout << "index1 = ";
				cin >> index1;
				cout << "index2 = ";
				cin >> index2;
				graph->search_for_index(index1, index2);
				system("pause");
				break;

			case 3:

				system("cls");
				graph->add_vertex();
				system("pause");
				break;

			case 4:

				system("cls");
				cout << "enter vertex" << endl;
				int index_1, index_2;
				cout << "number first vertex = ";
				cin >> index_1;
				cout << endl << "number second vertex = ";
				cin >> index_2;
				cout << endl << "enter lenght of rib" << endl;
				cout << " length = ";
				cin >> length;
				graph->insert(index_1, index_2, length);
				system("pause");
				break;

			case 5:

				system("cls");
				cout << "enter vertex" << endl;
				int Index1, Index2;
				cout << "number first vertex = ";
				cin >> Index1;
				cout << endl << "number second vertex = ";
				cin >> Index2;
				graph->remove_rib(Index1, Index2);
				system("pause");
				break;

			case 6:

				system("cls");
				int vertex;
				cout << "enter number of vertex" << endl;
				cin >> vertex;
				graph->remove_vertex(vertex);
				system("pause");
				break;

			case 7:
				system("cls");
				graph->generate_graph();
				system("pause");
				break;
			case 8:
				system("cls");
				graph->algoritm_kruskal();
				system("pause");
				break;
			case 9:
				system("cls");
				graph->algoritm_prima();
				system("pause");
				break;
			case 10:
				system("cls");
				graph->algoritm_boruvki();
				system("pause");
				break;
			case 11:
				system("cls");
				graph->write_to_backup_graph();
				break;
			case 12:
				system("cls");
				graph->write_from_backup_graph();
				break;
			case 13:
				system("cls");

				end = true;
				system("pause");
				break;
			}
		}
	}
}


/*!
 menu to work with a graph with a pattern vecotr<int>
*/
void interective::graph_vector_int_menu() {
	int n;
	cout << "Enter nummer Edge of graph " << endl << " n  =";
	cin >> n;
	graph_mtrx<vector<int>>* graph;
	graph = new graph_mtrx<vector<int>>(n);

	vector<int> key1;
	vector<int> length;

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << endl << "    choose the mode press 'W' and 'S' to move up and down:" << endl << endl;
		for (int i = 0; i < 14; i++)
		{
			if (i == position)
				cout << "->  " << types_1[i] << endl;
			else cout << "    " << types_1[i] << endl;
		}

		char key;
		key = _getch();


		if ((int)key != 13)
		{
			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 13;
			}
			if ((int)key == 115)
			{
				if (position < 13)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{
			case 0:
				system("cls");
				graph->print();
				cout << endl << endl;
				system("pause");
				break;
			case 1:

				system("cls");
				int n;
				int element;
				key1 = {};
				cout << "enter number of elements vector" << endl;
				cin >> n;
				cout << "Enter length of rib (vector<int>)" << endl;
				for (int i = 0; i < n; i++) {
					
					key1.push_back(0);
					cin >> key1[i];
				}

				graph->searsh_of_key(key1);
				system("pause");
				break;

			case 2:

				system("cls");
				cout << "enter vertex indices" << endl;
				int index1, index2;
				cout << "index1 = ";
				cin >> index1;
				cout << "index2 = ";
				cin >> index2;
				graph->search_for_index(index1, index2);
				system("pause");
				break;

			case 3:

				system("cls");
				graph->add_vertex();
				system("pause");
				break;

			case 4:

				system("cls");
				length = {};

				cout << "enter vertex" << endl;
				int index_1, index_2;
				cout << "number first vertex = ";
				cin >> index_1;
				cout << endl << "number second vertex = ";
				cin >> index_2;
				int elmnt, num;
				cout << "enter number of elements vector" << endl;
				cin >> num;
				cout << endl << "enter lenght of rib(vector<int>)" << endl;
				for (int i = 0; i < num; i++) {
			
					length.push_back(0);
					cin >> length[i];
				}
			
				graph->insert(index_1, index_2, length);
				system("pause");
				break;

			case 5:

				system("cls");
				cout << "enter vertex" << endl;
				int Index1, Index2;
				cout << "number first vertex = ";
				cin >> Index1;
				cout << endl << "number second vertex = ";
				cin >> Index2;
				graph->remove_rib(Index1, Index2);
				system("pause");
				break;

			case 6:

				system("cls");
				int vertex;
				cout << "enter number of vertex" << endl;
				cin >> vertex;
				graph->remove_vertex(vertex);
				system("pause");
				break;

			case 7:
				system("cls");
				graph->generate_graph();
				system("pause");
				break;
			case 8:
				system("cls");
				graph->algoritm_kruskal();
				system("pause");
				break;
			case 9:
				system("cls");
				graph->algoritm_prima();
				system("pause");
				break;
			case 10:
				system("cls");
				graph->algoritm_boruvki();
				system("pause");
				break;
			case 11:
				system("cls");
				graph->write_to_backup_graph();
				break;
			case 12:
				system("cls");
				graph->write_from_backup_graph();
				break;
			case 13:
				system("cls");

				end = true;
				system("pause");
				break;
			}
		}
	}
}


/*!
 menu to work with a graph with a pattern vector<double>
*/
void interective::graph_vector_double_menu() {
	int n;
	cout << "Enter nummer Edge of graph " << endl << " n  =";
	cin >> n;
	graph_mtrx<vector<double>>* graph;
	graph = new graph_mtrx<vector<double>>(n);

	vector<double> key1;
	vector<double> length;

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << endl << "    choose the mode press 'W' and 'S' to move up and down:" << endl << endl;
		for (int i = 0; i < 14; i++)
		{
			if (i == position)
				cout << "->  " << types_1[i] << endl;
			else cout << "    " << types_1[i] << endl;
		}

		char key;
		key = _getch();


		if ((int)key != 13)
		{
			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 13;
			}
			if ((int)key == 115)
			{
				if (position < 13)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{
			case 0:
				system("cls");
				graph->print();
				cout << endl << endl;
				system("pause");
				break;
			case 1:

				system("cls");
				int n;
				int element;
				key1 = {};
				cout << "enter number of elements vector" << endl;
				cin >> n;
				cout << "Enter length of rib (vector<double>)" << endl;
				for (int i = 0; i < n; i++) {

					key1.push_back(0);
					cin >> key1[i];
				}

				graph->searsh_of_key(key1);
				system("pause");
				break;

			case 2:

				system("cls");
				cout << "enter vertex indices" << endl;
				int index1, index2;
				cout << "index1 = ";
				cin >> index1;
				cout << "index2 = ";
				cin >> index2;
				graph->search_for_index(index1, index2);
				system("pause");
				break;

			case 3:

				system("cls");
				graph->add_vertex();
				system("pause");
				break;

			case 4:

				system("cls");
				length = {};

				cout << "enter vertex" << endl;
				int index_1, index_2;
				cout << "number first vertex = ";
				cin >> index_1;
				cout << endl << "number second vertex = ";
				cin >> index_2;
				int elmnt, num;
				cout << "enter number of elements vector" << endl;
				cin >> num;
				cout << endl << "enter lenght of rib(vector<double>)" << endl;
				for (int i = 0; i < num; i++) {

					length.push_back(0);
					cin >> length[i];
				}

				graph->insert(index_1, index_2, length);
				system("pause");
				break;

			case 5:

				system("cls");
				cout << "enter vertex" << endl;
				int Index1, Index2;
				cout << "number first vertex = ";
				cin >> Index1;
				cout << endl << "number second vertex = ";
				cin >> Index2;
				graph->remove_rib(Index1, Index2);
				system("pause");
				break;

			case 6:

				system("cls");
				int vertex;
				cout << "enter number of vertex" << endl;
				cin >> vertex;
				graph->remove_vertex(vertex);
				system("pause");
				break;

			case 7:
				system("cls");
				graph->generate_graph();
				system("pause");
				break;
			case 8:
				system("cls");
				graph->algoritm_kruskal();
				system("pause");
				break;
			case 9:
				system("cls");
				graph->algoritm_prima();
				system("pause");
				break;
			case 10:
				system("cls");
				graph->algoritm_boruvki();
				system("pause");
				break;
			case 11:
				system("cls");
				graph->write_to_backup_graph();
				break;
			case 12:
				system("cls");
				graph->write_from_backup_graph();
				break;
			case 13:
				system("cls");

				end = true;
				system("pause");
				break;
			}
		}
	}
}


/*!
 menu to work with a graph with a pattern vector<string>
*/
void interective::graph_vector_string_menu() {
	int n;
	cout << "Enter nummer Edge of graph " << endl << " n  =";
	cin >> n;
	graph_mtrx<vector<string>>* graph;
	graph = new graph_mtrx<vector<string>>(n);

	vector<string> key1;
	vector<string> length;

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << endl << "    choose the mode press 'W' and 'S' to move up and down:" << endl << endl;
		for (int i = 0; i < 14; i++)
		{
			if (i == position)
				cout << "->  " << types_1[i] << endl;
			else cout << "    " << types_1[i] << endl;
		}

		char key;
		key = _getch();


		if ((int)key != 13)
		{
			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 13;
			}
			if ((int)key == 115)
			{
				if (position < 13)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{
			case 0:
				system("cls");
				graph->print();
				cout << endl << endl;
				system("pause");
				break;
			case 1:

				system("cls");
				int n;
				int element;
				key1 = {};
				cout << "enter number of elements vector" << endl;
				cin >> n;
				cout << "Enter length of rib (vector<string>)" << endl;
				for (int i = 0; i < n; i++) {

					key1.push_back("0");
					cin >> key1[i];
				}

				graph->searsh_of_key(key1);
				system("pause");
				break;

			case 2:

				system("cls");
				cout << "enter vertex indices" << endl;
				int index1, index2;
				cout << "index1 = ";
				cin >> index1;
				cout << "index2 = ";
				cin >> index2;
				graph->search_for_index(index1, index2);
				system("pause");
				break;

			case 3:

				system("cls");
				graph->add_vertex();
				system("pause");
				break;

			case 4:

				system("cls");
				length = {};

				cout << "enter vertex" << endl;
				int index_1, index_2;
				cout << "number first vertex = ";
				cin >> index_1;
				cout << endl << "number second vertex = ";
				cin >> index_2;
				int elmnt, num;
				cout << "enter number of elements vector" << endl;
				cin >> num;
				cout << endl << "enter lenght of rib(vector<string>)" << endl;
				for (int i = 0; i < num; i++) {

					length.push_back("0");
					cin >> length[i];
				}

				graph->insert(index_1, index_2, length);
				system("pause");
				break;

			case 5:

				system("cls");
				cout << "enter vertex" << endl;
				int Index1, Index2;
				cout << "number first vertex = ";
				cin >> Index1;
				cout << endl << "number second vertex = ";
				cin >> Index2;
				graph->remove_rib(Index1, Index2);
				system("pause");
				break;

			case 6:

				system("cls");
				int vertex;
				cout << "enter number of vertex" << endl;
				cin >> vertex;
				graph->remove_vertex(vertex);
				system("pause");
				break;

			case 7:
				system("cls");
				graph->generate_graph();
				system("pause");
				break;
			case 8:
				system("cls");
				graph->algoritm_kruskal();
				system("pause");
				break;
			case 9:
				system("cls");
				graph->algoritm_prima();
				system("pause");
				break;
			case 10:
				system("cls");
				graph->algoritm_boruvki();
				system("pause");
				break;
			case 11:
				system("cls");
				graph->write_to_backup_graph();
				break;
			case 12:
				system("cls");
				graph->write_from_backup_graph();
				break;
			case 13:
				system("cls");
				
				end = true;
				system("pause");
				break;
			}
		}
	}
}

/*!
 menu to work with a graph with a pattern body
*/
void interective::graph_body_menu(){
	int n;
	cout << "Enter nummer Edge of graph " << endl << " n  =";
	cin >> n;
	graph_mtrx<body>* graph;
	graph = new graph_mtrx<body>(n);

	body key1;
	body length;

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << endl << "    choose the mode press 'W' and 'S' to move up and down:" << endl << endl;
		for (int i = 0; i < 14; i++)
		{
			if (i == position)
				cout << "->  " << types_1[i] << endl;
			else cout << "    " << types_1[i] << endl;
		}

		char key;
		key = _getch();
		double x1, x2, y1, y2;

		if ((int)key != 13)
		{
			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 13;
			}
			if ((int)key == 115)
			{
				if (position < 13)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{
			case 0:
				system("cls");
				graph->print();
				cout << endl << endl;
				system("pause");
				break;
			case 1:

				system("cls");
				int number;
				for (int i = 0; i < 6; i++) {
					cout << i + 1 << " - " << command[i] << endl;
				}
				cout << "\n \n Enter num of function" << endl;
				cin >> number;
				cout << endl << "enter integral limits" << endl;
				cout << "x1 = ";
				cin >> x1;
				cout << endl << "x2 = ";
				cin >> x2;
				cout << endl<<"y1 = ";
				cin >> y1;
				cout << endl << "y2 = ";
				cin >> y2;
				key1.build(x1, x2, y1, y2, number);
				graph->searsh_of_key(key1);
				system("pause");
				break;

			case 2:

				system("cls");
				cout << "enter vertex indices" << endl;
				int index1, index2;
				cout << "index1 = ";
				cin >> index1;
				cout << "index2 = ";
				cin >> index2;
				graph->search_for_index(index1, index2);
				system("pause");
				break;

			case 3:

				system("cls");
				graph->add_vertex();
				system("pause");
				break;

			case 4:

				system("cls");
				
				int num;
				cout << "enter vertex" << endl;
				int index_1, index_2;
				cout << "number first vertex = ";
				cin >> index_1;
				cout << endl << "number second vertex = ";
				cin >> index_2;
				for (int i = 0; i < 6; i++) {
					cout << i + 1 << " - " << command[i] << endl;
				}
				cout << "\n \n Enter num of function" << endl;
				cin >> num;
				cout << endl << "enter integral limits" << endl;
				cout << "x1 = ";
				cin >> x1;
				cout << endl << "x2 = ";
				cin >> x2;
				cout << endl << "y1 = ";
				cin >> y1;
				cout << endl << "y2 = ";
				cin >> y2;
				length.build(x1, x2, y1, y2, num);
				graph->insert(index_1, index_2, length);
				system("pause");
				break;

			case 5:

				system("cls");
				cout << "enter vertex" << endl;
				int Index1, Index2;
				cout << "number first vertex = ";
				cin >> Index1;
				cout << endl << "number second vertex = ";
				cin >> Index2;
				graph->remove_rib(Index1, Index2);
				system("pause");
				break;

			case 6:

				system("cls");
				int vertex;
				cout << "enter number of vertex" << endl;
				cin >> vertex;
				graph->remove_vertex(vertex);
				system("pause");
				break;

			case 7:
				system("cls");
				graph->generate_graph();
				system("pause");
				break;
			case 8:
				system("cls");
				graph->algoritm_kruskal();
				system("pause");
				break;
			case 9:
				system("cls");
				graph->algoritm_prima();
				system("pause");
				break;
			case 10:
				system("cls");
				graph->algoritm_boruvki();
				system("pause");
				break;
			case 11:
				system("cls");
				graph->write_to_backup_graph();
				break;
			case 12:
				system("cls");
				graph->write_from_backup_graph();
				break;
			case 13:
				system("cls");

				end = true;
				system("pause");
				break;
			}
		}
	}
}

/*!
 menu to work with a graph with a pattern body_rotate
*/
void interective::graph_body_rotate_menu() {
	int n;
	cout << "Enter nummer Edge of graph " << endl << " n  =";
	cin >> n;
	graph_mtrx<body_rotate>* graph;
	graph = new graph_mtrx<body_rotate>(n);

	body_rotate key1;
	body_rotate length;

	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << endl << "    choose the mode press 'W' and 'S' to move up and down:" << endl << endl;
		for (int i = 0; i < 14; i++)
		{
			if (i == position)
				cout << "->  " << types_1[i] << endl;
			else cout << "    " << types_1[i] << endl;
		}

		char key;
		key = _getch();
		double x1, x2;

		if ((int)key != 13)
		{
			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 13;
			}
			if ((int)key == 115)
			{
				if (position < 13)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{
			case 0:
				system("cls");
				graph->print();
				cout << endl << endl;
				system("pause");
				break;
			case 1:

				system("cls");
				int number;
				for (int i = 0; i < 3; i++) {
					cout << i + 1 << " - " << command[i+6] << endl;
				}
				cout << "\n \n Enter num of function" << endl;
				cin >> number;
				cout << endl << "enter integral limits" << endl;
				cout << "x1 = ";
				cin >> x1;
				cout << endl << "x2 = ";
				cin >> x2;
		
				key1.build(x1, x2,  number);
				graph->searsh_of_key(key1);
				system("pause");
				break;

			case 2:

				system("cls");
				cout << "enter vertex indices" << endl;
				int index1, index2;
				cout << "index1 = ";
				cin >> index1;
				cout << "index2 = ";
				cin >> index2;
				graph->search_for_index(index1, index2);
				system("pause");
				break;

			case 3:

				system("cls");
				graph->add_vertex();
				system("pause");
				break;

			case 4:

				system("cls");

				int num;
				cout << "enter vertex" << endl;
				int index_1, index_2;
				cout << "number first vertex = ";
				cin >> index_1;
				cout << endl << "number second vertex = ";
				cin >> index_2;
				for (int i = 0; i < 3; i++) {
					cout << i + 1 << " - " << command[i+6] << endl;
				}
				cout << "\n \n Enter num of function" << endl;
				cin >> num;
				cout << endl << "enter integral limits" << endl;
				cout << "x1 = ";
				cin >> x1;
				cout << endl << "x2 = ";
				cin >> x2;
			
				length.build(x1, x2,  num);
				graph->insert(index_1, index_2, length);
				system("pause");
				break;

			case 5:

				system("cls");
				cout << "enter vertex" << endl;
				int Index1, Index2;
				cout << "number first vertex = ";
				cin >> Index1;
				cout << endl << "number second vertex = ";
				cin >> Index2;
				graph->remove_rib(Index1, Index2);
				system("pause");
				break;

			case 6:

				system("cls");
				int vertex;
				cout << "enter number of vertex" << endl;
				cin >> vertex;
				graph->remove_vertex(vertex);
				system("pause");
				break;

			case 7:
				system("cls");
				graph->generate_graph();
				system("pause");
				break;
			case 8:
				system("cls");
				graph->algoritm_kruskal();
				system("pause");
				break;
			case 9:
				system("cls");
				graph->algoritm_prima();
				system("pause");
				break;
			case 10:
				system("cls");
				graph->algoritm_boruvki();
				system("pause");
				break;
			case 11:
				system("cls");
				graph->write_to_backup_graph();
				break;
			case 12:
				system("cls");
				graph->write_from_backup_graph();
				break;
			case 13:
				system("cls");

				end = true;
				system("pause");
				break;
			}
		}
	}
}



/*!
 menu to work with a binaty tree with a pattern int
*/
void interective::tree_int_menu() {
	bool end = false;
	int position = 0;
	bin_tree<int>* tree;
	tree = new bin_tree<int>;

	int Key1;
	char key;
	while (!end)
	{
		system("cls");
		cout << "    choose the mode press 'W' and 'S' to move up and down:" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (i == position)
				cout << "->  " << types_3[i] << endl;
			else cout << "    " << types_3[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{


			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 4;
			}
			if ((int)key == 115)
			{
				if (position < 4)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{


			case 0:
				system("cls");
				tree->print();

				system("pause");
				break;
			case 1:
				system("cls");
				cout << "Entre element " << endl;
			
				cin >> Key1;
				tree->insert(Key1);
				break;
			case 2:
				system("cls");
				
				cout << "Entre element  for removed" << endl;
			    
				cin >> Key1;
				tree->remove_node(Key1);
				break;
			case 3:
				system("cls");
				tree->generate_tree();
				break;
			case 4:
				system("cls");
				end = true;
				break;


			}
		}
	}
}


/*!
 menu to work with a binaty tree with a pattern double
*/
void interective::tree_double_menu() {
	bool end = false;
	int position = 0;
	bin_tree<double>* tree;
	tree = new bin_tree<double>;

	double Key;
	char key;
	while (!end)
	{
		system("cls");
		cout << "    choose the mode press 'W' and 'S' to move up and down:" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (i == position)
				cout << "->  " << types_3[i] << endl;
			else cout << "    " << types_3[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{


			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 4;
			}
			if ((int)key == 115)
			{
				if (position < 4)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{


			case 0:
				system("cls");
				tree->print();

				system("pause");
				break;
			case 1:
				system("cls");
				cout << "Entre element " << endl;

				cin >> Key;
				tree->insert(Key);
				break;
			case 2:
				system("cls");

				cout << "Entre element  for removed" << endl;

				cin >> Key;
				tree->remove_node(Key);
				break;
			case 3:
				system("cls");
				tree->generate_tree();
				break;
			case 4:
				system("cls");
				end = true;
				break;


			}
		}
	}
}


/*!
 menu to work with a binaty tree with a pattern string
*/
void interective::tree_string_menu() {
	bool end = false;
	int position = 0;
	bin_tree<string>* tree;
	tree = new bin_tree<string>;

	string Key;
	char key;
	while (!end)
	{
	
		system("cls");
		cout << "    choose the mode press 'W' and 'S' to move up and down:" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (i == position)
				cout << "->  " << types_3[i] << endl;
			else cout << "    " << types_3[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{


			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 4;
			}
			if ((int)key == 115)
			{
				if (position < 4)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{


			case 0:
				system("cls");
				tree->print();

				system("pause");
				break;
			case 1:
				system("cls");
				cout << "Entre element " << endl;

				cin >> Key;
				tree->insert(Key);
				break;
			case 2:
				system("cls");

				cout << "Entre element  for removed" << endl;

				cin >> Key;
				tree->remove_node(Key);
				break;
			case 3:
				system("cls");
				tree->generate_tree();
				break;
			case 4:
				system("cls");
				end = true;
				break;


			}
		}
	}
}

/*!
 menu to work with a binaty tree with a pattern vector<int>
*/
void interective::tree_vector_int_menu() {
	bool end = false;
	int position = 0;
	bin_tree<vector<int>>* tree;
	tree = new bin_tree<vector<int>>;

	vector<int> Key;
	int n;
	char key;
	while (!end)
	{
		Key = {};
		system("cls");
		cout << "    choose the mode press 'W' and 'S' to move up and down:" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (i == position)
				cout << "->  " << types_3[i] << endl;
			else cout << "    " << types_3[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{


			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 4;
			}
			if ((int)key == 115)
			{
				if (position < 4)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{


			case 0:
				system("cls");
				tree->print();

				system("pause");
				break;
			case 1:
				system("cls");
				cout << "Entre number elements of vector " << endl;
				cin >> n;
				cout << "enter vector" << endl;
				for (int i = 0; i < n; i++) {
					 Key.push_back(0);
					 cin >> Key[i];
				}
				tree->insert(Key);
				break;
			case 2:
				system("cls");

			
				cout << "Entre number elements of vector " << endl;
				cin >> n;
				cout << "enter vector for removed" << endl;
				for (int i = 0; i < n; i++) {
					Key.push_back(0);
					cin >> Key[i];
				}
			
				tree->remove_node(Key);
				break;
			case 3:
				system("cls");
				tree->generate_tree();
				break;
			case 4:
				system("cls");
				end = true;
				break;


			}
		}
	}
}


/*!
 menu to work with a binaty tree with a pattern vecotr<double>
*/
void interective::tree_vector_double_menu() {
	bool end = false;
	int position = 0;
	bin_tree<vector<double>>* tree;
	tree = new bin_tree<vector<double>>;

	vector<double> Key;
	int n;
	char key;

	while (!end)
	{
		Key = {};
		system("cls");
		cout << "    choose the mode press 'W' and 'S' to move up and down:" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (i == position)
				cout << "->  " << types_3[i] << endl;
			else cout << "    " << types_3[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{


			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 4;
			}
			if ((int)key == 115)
			{
				if (position < 4)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{


			case 0:
				system("cls");
				tree->print();

				system("pause");
				break;
			case 1:
				system("cls");
				cout << "Entre number elements of vector " << endl;
				cin >> n;
				cout << "enter vector" << endl;
				for (int i = 0; i < n; i++) {
					Key.push_back(0);
					cin >> Key[i];
				}
				tree->insert(Key);
				break;
			case 2:
				system("cls");


				cout << "Entre number elements of vector " << endl;
				cin >> n;
				cout << "enter vector for removed" << endl;
				for (int i = 0; i < n; i++) {
					Key.push_back(0);
					cin >> Key[i];
				}

				tree->remove_node(Key);
				break;
			case 3:
				system("cls");
				tree->generate_tree();
				break;
			case 4:
				system("cls");
				end = true;
				break;


			}
		}
	}
}

/*!
 menu to work with a binaty tree with a pattern vector<string>
*/
void interective::tree_vector_string_menu() {
	bool end = false;
	int position = 0;
	bin_tree<vector<string>>* tree;
	tree = new bin_tree<vector<string>>;

	vector<string> Key;
	int n;
	char key;
	while (!end)
	{
		Key = {};
		system("cls");
		cout << "    choose the mode press 'W' and 'S' to move up and down:" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (i == position)
				cout << "->  " << types_3[i] << endl;
			else cout << "    " << types_3[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{


			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 4;
			}
			if ((int)key == 115)
			{
				if (position < 4)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{


			case 0:
				system("cls");
				tree->print();

				system("pause");
				break;
			case 1:
				system("cls");
				cout << "Entre number elements of vector " << endl;
				cin >> n;
				cout << "enter vector" << endl;
				for (int i = 0; i < n; i++) {
					Key.push_back("0");
					cin >> Key[i];
				}
				tree->insert(Key);
				break;
			case 2:
				system("cls");


				cout << "Entre number elements of vector " << endl;
				cin >> n;
				cout << "enter vector for removed" << endl;
				for (int i = 0; i < n; i++) {
					Key.push_back("0");
					cin >> Key[i];
				}

				tree->remove_node(Key);
				break;
			case 3:
				system("cls");
				tree->generate_tree();
				break;
			case 4:
				system("cls");
				end = true;
				break;


			}
		}
	}
}

/*!
 menu to work with a binaty tree with a pattern body
*/
void interective::tree_body_menu() {
	bool end = false;
	int position = 0;
	bin_tree<body>* tree;
	tree = new bin_tree<body>;

	body Key;
	int n;
	char key;
	double x1, x2, y1, y2;
	while (!end)
	{
		system("cls");
		cout << "    choose the mode press 'W' and 'S' to move up and down:" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (i == position)
				cout << "->  " << types_3[i] << endl;
			else cout << "    " << types_3[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{


			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 4;
			}
			if ((int)key == 115)
			{
				if (position < 4)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{


			case 0:
				system("cls");
				tree->print();

				system("pause");
				break;
			case 1:
				system("cls");
				for (int i = 0; i < 6; i++) {
					cout << i + 1 << " - " << command[i] << endl;
				}
				cout << "Entre number functions " << endl;
				cin >> n;
				cout << endl << "enter integral limits" << endl;
				cout << "x1 = ";
				cin >> x1;
				cout << endl << "x2 = ";
				cin >> x2;
				cout << endl << "y1 = ";
				cin >> y1;
				cout << endl << "y2 = ";
				cin >> y2;
				Key.build(x1, x2, y1, y2, n);
			
				tree->insert(Key);
				break;
			case 2:
				system("cls");
				for (int i = 0; i < 6; i++) {
					cout << i + 1 << " - " << command[i] << endl;
				}
				cout << "Entre number functions " << endl;
				cin >> n;
				cout << endl << "enter integral limits" << endl;
				cout << "x1 = ";
				cin >> x1;
				cout << endl << "x2 = ";
				cin >> x2;
				cout << endl << "y1 = ";
				cin >> y1;
				cout << endl << "y2 = ";
				cin >> y2;
				Key.build(x1, x2, y1, y2, n);
				tree->remove_node(Key);
				break;
			case 3:
				system("cls");
				tree->generate_tree();
				break;
			case 4:
				system("cls");
				end = true;
				break;


			}
		}
	}
}


/*!
 menu to work with a binaty tree with a pattern body_rotate
*/
void interective::tree_body_rotate_menu() {
	bool end = false;
	int position = 0;
	bin_tree<body_rotate>* tree;
	tree = new bin_tree<body_rotate>;

	body_rotate Key;
	int n;
	char key;
	double x1, x2;
	while (!end)
	{
		system("cls");
		cout << "    choose the mode press 'W' and 'S' to move up and down:" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (i == position)
				cout << "->  " << types_3[i] << endl;
			else cout << "    " << types_3[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{


			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 4;
			}
			if ((int)key == 115)
			{
				if (position < 4)
					position++;
				else position = 0;
			}
		}

		else
		{
			switch (position)
			{


			case 0:
				system("cls");
				tree->print();

				system("pause");
				break;
			case 1:
				system("cls");
				for (int i = 0; i < 3; i++) {
					cout << i + 1 << " - " << command[i+6] << endl;
				}
				cout << "Entre number functions " << endl;
				cin >> n;
				cout << endl << "enter integral limits" << endl;
				cout << "x1 = ";
				cin >> x1;
				cout << endl << "x2 = ";
				cin >> x2;
				cout << endl << "y1 = ";
			
				Key.build(x1, x2, n);

				tree->insert(Key);
				break;
			case 2:
				system("cls");
				for (int i = 0; i < 6; i++) {
					cout << i + 1 << " - " << command[i] << endl;
				}
				cout << "Entre number functions " << endl;
				cin >> n;
				cout << endl << "enter integral limits" << endl;
				cout << "x1 = ";
				cin >> x1;
				cout << endl << "x2 = ";
				cin >> x2;
				cout << endl << "y1 = ";
			
				Key.build(x1, x2, n);
				tree->remove_node(Key);
				break;
			case 3:
				system("cls");
				tree->generate_tree();
				break;
			case 4:

				system("cls");
				end = true;
				break;


			}
		}
	}
}