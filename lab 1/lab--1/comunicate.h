/*!
\authors viktor ivahnuk
\version 1.0
\date   1/10/20
\file
\brief Header file with a description of the main class

this file contains the definition of the main class which creates the menu in the console through which it is possible to choose work with the graph or a binary tree or to choose calculation of volumes and areas of bodies
*/



#pragma once

#include "Graf.h"
#include "integral.h"


/*!
	\brief main class which builds the main menu on the console

	this class builds the main menu through which you can select the function of the program, the menu creates objects graf, beentree and body which create new menus
    in which you can choose in more detail the function of the program with which we want to work

*/



class comunity {
public:
	/*!
	displays possible program functions and reads keys to switch between selection items
    */
	void comunicate() {
		basic<vector<vector<int>>> graf;
		basic<beentr> beentree;
		basicc body;
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
					graf.menu();
					break;
				case 1:
					system("cls");
					beentree.menu();
					system("pause");
					break;
				case 2:
					system("cls");
					body.MENU();
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


};
