/*!
\authors viktor ivahnuk
\version 1.0
\date   25/09/20
\file
\brief methods of the basic class are registered in the file
*/

#include <vector>
#include <conio.h>
#include <iostream>
#include <string>

#include "Graf.h"
using namespace std;




/*!
method of class basic which displays a menu in which you can select an action with a graph,
this method can be used in objects based on the basic class with the vector <vector <int>> template
*/
void basic <vector<vector<int>>>::menu() {

	graf_matrix graf;
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

				graf.add();
				system("pause");
				break;
			case 1:
				system("cls");

				graf.print();

				system("pause");
				break;
			case 2:
				system("cls");

				graf.insert_in_graf();
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "Enter two vertex" << endl;
				int x, y;
				cin >> x >> y;
				system("pause");
				graf.delete_rebro(x, y);
				break;
			case 4:
				system("cls");
				cout << "enter vertex " << endl;
				int m;
				cin >> m;
				graf.delete_vertex(m);
				system("pause");
				break;

			case 5:
				system("cls");
				graf.min_kist_graf();
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
method of class basic which displays a menu in which you can select an action with a binary tree,
this method can be used in objects based on the basic class with the beentr template
*/
void basic <beentr>::menu() {
	tree beentree;
	bool end = false;
	int position = 0;
	string s[4] = { "print","insert","delete element","exit" };
	while (!end)
	{
		system("cls");
		cout << "    choose the mode press 'W' and 'S' to move up and down:" << endl;
		for (int i = 0; i < 4; i++)
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
				beentree.print_btr();

				system("pause");
				break;
			case 1:
				system("cls");
				beentree.insert_in_beetree();
				break;
			case 2:
				system("cls");
				beentree.deletetree();
				break;
			case 3:
				system("cls");
				end = true;
				break;


			}
		}
	}


}




