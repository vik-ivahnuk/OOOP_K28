#include"comunicate.h"
#include <iostream>

using namespace std;

/*!
displays possible program functions and reads keys to switch between selection items
*/
void comunity::comunicate() {

	graf_matrix graf;
	tree beentree;
	integral body;

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
				graf.enter_date();
				graf.menu();
				break;
			case 1:
				system("cls");
				beentree.enter_date();
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