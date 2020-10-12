
/*!
\authors viktor ivahnuk
\version 2.0
\date   4/10/20
\file
\brief methods of the rotatebady class are registered in the file
*/


#include <iostream>
#include <vector>
#include "rotatebody.h"

using namespace std;


/*!
the method calculates the volume of the body of rotation if the variable C = true or the area if C = false
\ param  x1, x2 integration limits
\ param  C determines the area or volume the function will calculate
\ param  B -change to call mathematical functions which are represented as methods of class rotatebady
\ param  foo reference to a method that represents a function that describes bodies of rotation
\ return the area or volume of the body of rotation given by the function foo
*/
float rotatebady::guldin(rotatebady& B, float x1, float x2, float (rotatebady::* foo)(float), bool C) {
	double num = 500;
	float res, r = 0;
	float 	xo;
	float delta_x;
	float center_of_mass;
	int i = 4;
	while (i) {
		res = 0;
		delta_x = (x2 - x1) / num;
		xo = x1;

		for (int j = 0; j < num; j++) {
			xo += delta_x;
			if (C)
				res += ((B.*foo)(xo) * (B.*foo)(xo) * delta_x);
			else res += ((B.*foo)(xo) * delta_x);
		}
		if (abs(res - r) < norm)
			break;

		r = res;
		num *= 2;
		--i;
	}


	if (C)
		return 3.14 * res;
	return  6.28 * res;
}

/*!
the method displays the area and volume of the body
\ param[in] z function which specifies the body of rotation
\ param[in] derz function by which you can calculate the area of ​​the body of rotation given by the function z
\ param[in] B -change to call mathematical functions which are represented as methods of class rotatebady
*/
void rotatebady::print_num1(rotatebady& B, float (rotatebady::* z)(float), float (rotatebady::* derz)(float)) {
	cout << "V=" << guldin(B, x1, x2, z, true) << endl;
	cout << "S=" << guldin(B, x1, x2, derz, false) << endl;
}


/*!
a method that allows the user to enter the boundaries of integration
*/
void rotatebady::enter() {
	cout << "x1=";
	cin >> x1;
	cout << endl << "x2=";
	cin >> x2;
}