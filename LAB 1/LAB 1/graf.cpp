
/*!
\authors viktor ivahnuk
\version 2.0
\date   25/09/20
\file
\brief methods of the graf_matrix class are registered in the file
*/


#include <vector>
#include <iostream>
#include <string>

#include "Graf.h"

using namespace std;


/*!
the method finds the minimum skeletal tree of the weighted graph
\ param n -number of vertices of the graph
\ param ad - adjacency matrix in which the graph lies
\ return the adjacency matrix in which the minimum skeletal tree lies
*/

vector<vector<int>> graf_matrix::Grafo_kruskal(int n, vector <vector<int>> ad)
{
	vector< vector<int> >  gr = ad;
	vector< vector<int> > arb(n);
	vector<int> pert(n);
	int INF = 999;
	for (int i = 0; i < n; i++) {
		arb[i] = vector<int>(n, 0);
		pert[i] = i;
	}

	int nA;
	int nB;
	int arcos = 1;
	while (arcos < n) {

		int min = INF;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (min > gr[i][j] && pert[i] != pert[j] && gr[i][j] != 0) {
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
	return arb;
}

/*!
the method inserts an edge into the graph
\ param [in] a graph in which to insert the tree
\ param [out] x, y vertices with a given edge
\ return [out] l rib length
*/
void graf_matrix::insert(vector<vector<int>>& a, int x, int y, int l) {
	system("cls");
	if (x < a.size() + 1 && y < a.size() + 1) {
		a[y - 1][x - 1] = l;
		a[x - 1][y - 1] = l;
	}
	else cout << "Enter other vertex" << endl;

}

/*!
метод провіряє чи є граф звязним
\param b матриця суміжності у якій лежить граф
\return true якщо граф звязний або false в протианому випадку
*/
bool graf_matrix::conect_graf(vector<vector<int>> b) {

	vector<int> k(b.size(), 0);
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == k)
			return false;
	}
	return true;
}
/*!
the method displays a graph represented by the adjacency matrix which is stored in the val change of the class graf_matrix
*/

void graf_matrix::print() {
	if (val.size()) {
		cout << endl;
		for (int i = 0; i < val.size(); i++) {
			cout << "    ";
			for (int j = 0; j < val.size(); j++)
				cout << " " << val[i][j];
			cout << endl;
		}
		cout << endl;
	}
	else cout << "Graf pust";
}

/*!
the method removes the edge of the graph
param [in] x, y adjacent vertices of the edge of the graph which we will delete
*/
void  graf_matrix::delete_rebro(int x, int y) {
	insert(val, x, y, 0);
}

/*!
method removes the m-th vertex of the graph by deleting the m-th row and the m-th stitch of the adjacency matrix
param [in] x, y adjacent vertices of the edge of the graph which we will delete
*/
void graf_matrix::delete_vertex(int m) {
	if (m > val.size())
		return;
	if (m == 1 && val.size() == 1) {
		val = {  };
		return;
	}
	for (int i = m - 1; i < val.size() - 1; i++) {
		val[i] = val[i + 1];
		for (int j = 0; j < val.size(); j++)
			val[j][i] = val[j][i + 1];
	}
	val.pop_back();
	for (int i = 0; i < val.size(); i++)
		val[i].pop_back();
}

/*!
the method adds a vertex to the graph stored in the val change
*/
void graf_matrix::add() {
	if (val.size() == 0)
		val = { {0} };
	else {
		val.push_back({});
		for (int i = 0; i < val.size(); i++) {
			val[i].push_back(0);
			if (i != val.size() - 1)
				val[val.size() - 1].push_back(0);
		}
		for (;;) {
			system("cls");
			cout << "enter vertex" << endl;
			int k, l;
			cin >> k;
			cout << "enter the length of the edge of the graph" << endl << "l=";
			cin >> l;
			insert(val, val.size(), k, l);
			cout << "press enter to exit";
			if (_getch() == 13)
				break;
		}

	}

}
/*!
the method performs a dialog function to insert an edge into the graph
*/
void graf_matrix::insert_in_graf() {
	int x, y, l;
	cout << "Enter two vertex" << endl;
	cin >> x >> y;
	cout << "enter the length of the edge of the graph" << endl << "l=";
	cin >> l;
	insert(val, x, y, l);
}


/*!
the method checks whether the graph is connected, if so then in change val the minimum skeleton tree of the
previous graph is written down if not connected then the user is deduced this information
*/
void graf_matrix::min_kist_graf() {
	if (conect_graf(val))
		val = Grafo_kruskal(val.size(), val);
	else {
		cout << "the graph is not connected" << endl;
		system("pause");
	}
}


/*!
this method is for selecting an action with a graph
*/
void graf_matrix::menu() {


	bool end = false;
	int position = 0;
	string s[7] = { "add vertex","print","insert","delete rebro","delete vertex","minimal skeletal tree","end" };
	while (!end)
	{
		system("cls");
		cout << "    choose the mode press 'W' and 'S' to move up and down:" << endl;
		for (int i = 0; i < 7; i++)
		{
			if (i == position)
				cout << "->  " << s[i] << endl;
			else cout << "    " << s[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{

			if ((int)key == 119) {
				if (position > 0)
					position--;
				else position = 6;
			}
			if ((int)key == 115)
			{
				if (position < 6)
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

				add();
				system("pause");
				break;
			case 1:
				system("cls");

				print();

				system("pause");
				break;
			case 2:
				system("cls");

				insert_in_graf();
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "Enter two vertex" << endl;
				int x, y;
				cin >> x >> y;
				system("pause");
				delete_rebro(x, y);
				break;
			case 4:
				system("cls");
				cout << "enter vertex " << endl;
				int m;
				cin >> m;
				delete_vertex(m);
				system("pause");
				break;

			case 5:
				system("cls");
				min_kist_graf();
				system("pause");
				break;
			case 6:
				system("cls");
				end = true;
				break;


			}
		}
	}

}

/*!
method for maintaining the elements of the graf
*/
void graf_matrix::enter_date() {
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