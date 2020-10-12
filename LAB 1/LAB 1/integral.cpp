
/*!
\authors viktor ivahnuk
\version 2.0
\date   2/10/20
\file
\brief methods of the basic class are registered in the file
*/

#include <iostream>
#include <vector>
#include "integral.h"


/*!
method of the basicc class which displays the menu screen in which it is possible to choose the mathematical equation of a body the area and volume of which we want to calculate
*/
void integral::MENU() {
	string command[10]
	{
			"  z(x,y)= x^2 + y^2",
			"  z(x,y)= e^x + e^y",
			"  z(x,y)= |sin(x*y)|",
			"  z(x,y)= 4.6  ",
			"  z(x,y)=ln(x) + y",
			"  z(x,y)=x + y^4",
			"  y(x) = sqrt( 1 - x^2 )  (rotate body)  ",
			"  y(x) = sin(x) + 5       (rotate body)",
			"  y(x) = e^x              (rotate body)",
			"  end"
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
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


				switch (position)
				{
				case 0:
					system("cls");
					m.Enter();

					m.print_num(m, &figure::f1, &figure::df1);
					system("pause");
					break;
				case 1:
					system("cls");
					m.Enter();
					m.print_num(m, &figure::f2, &figure::df2);
					system("pause");
					break;
				case 2:
					system("cls");
					m.Enter();
					m.print_num(m, &figure::f3, &figure::df3);
					system("pause");
					break;
				case 3:
					system("cls");
					m.Enter();
					m.print_num(m, &figure::f4, &figure::df4);
					system("pause");
					break;
				case 4:
					system("cls");
					m.Enter();
					m.print_num(m, &figure::f5, &figure::df5);
					system("pause");
					break;
				case 5:
					system("cls");
					m.Enter();
					m.print_num(m, &figure::f6, &figure::df6);
					system("pause");
					break;
				case 6:
					system("cls");
					rbady.enter();
					rbady.print_num1(rbady, &rotatebady::g1, &rotatebady::dg1);
					system("pause");
					break;
				case 7:
					system("cls");
					rbady.enter();
					rbady.print_num1(rbady, &rotatebady::g2, &rotatebady::dg2);
					system("pause");
					break;
				case 8:
					system("cls");
					rbady.enter();
					rbady.print_num1(rbady, &rotatebady::g3, &rotatebady::dg3);
					system("pause");
					break;

				}
			}
		}
	}

}