

/*!
\authors viktor ivahnuk
\version 2.0
\date   3/10/20
\file
\brief methods of the figure class are registered in the file
*/
#include <iostream>
#include <vector>
#include "integral.h"

using namespace std;



/*!
the method calculates the lateral area of ​​the body lying on the line x = x1 parallel to the axis Oy
\ param z function which specifies the body 
\ param x1, y1, y2 integration parameters
\ param A -change to call mathematical functions which are represented as methods of class figure
*/
float figure::Sx(figure &A,float x1, float y1, float y2, float (figure::*z)(float, float)) {
	double num = 1000;
	float res, r = 0;;

	float 	yo;
	int i = 0;
	while (1) {
		res = 0;
		float  delta_y = (y2 - y1) / num;
		yo = y1;
		for (int j = 0; j < num; j++) {
			res += (A.*z)(x1, yo) * delta_y;
			yo += delta_y;
		}
		if ((res - r) < norm||i>2)
			break;
		r = res;
		num *= 2;
		++i;
	
	}
	return res;
}


/*!
the method calculates the lateral area of ​​the body lying on the line y = y1 parallel to the axis Ox
\ param z function which specifies the body
\ param x1, y1, y2 integration parameters
\ param A -change to call mathematical functions which are represented as methods of class figure
*/
float  figure::Sy(figure &A,float y1, float x1, float x2, float (figure::*z)(float, float)) {
	double num = 1000;
	float res, r = 0;;

	float 	xo;
	int i = 0;
	while (1) {
		res = 0;
		float  delta_x = (x2 - x1) / num;
		xo = x1;
		for (int j = 0; j < num; j++) {
			res += (A.*z)(xo, y1) * delta_x;
			xo += delta_x;
		}
		if ((res - r) < norm ||i>2)
			break;
		r = res;
		num *= 2;
		++i;
	}
	return res;
}



/*!
the method calculates the volume of a body given by a function of two variables
\ param z function which specifies the body
\ param x1, x2,y1, y2 integration parameters
\ param A -change to call mathematical functions which are represented as methods of class figure
*/
float figure::CratIntegral(figure &A,float x1, float x2, float y1, float y2, float (figure::*z)(float, float)) {
	float xi, xj;
	float yi, yj;
	float V1 = 0;
	float V;
	double num = 100;
	int i = 0;
	while (1) {
		V = 0;
		float delta_x = (x2 - x1) / num;
		float delta_y = (y2 - y1) / num;

		yi = delta_y;
		yj = 0;
		for (int i = 1; i < num; i++) {
			xi = delta_x;
			xj = 0;
			for (int j = 0; j < num; j++) {
				V += (A.*z)((xi + xj) / 2, (yi + yj) / 2) * delta_x * delta_y;

				xi += delta_x;
				xj += delta_x;
			}
			yi += delta_y;
			yj += delta_y;
		}
		if ((V - V1) < norm ||i>2)
			break;

		V1 = V;
		num *= 2;
		++i;
	}


	return V;

}



/*!
the method calculates the area  of a body given by a function of two variables
\ param z function which specifies the body
\ param dz whose integral function is equal to the area of ​​the upper surface of the body
\ param x1, x2,y1, y2 integration parameters
\ param A -change to call mathematical functions which are represented as methods of class figure
*/
float figure::area(figure &A,float x1, float x2, float y1, float y2, float (figure::*z)(float, float), float (figure::*dz)(float, float)) {
	float Spov, Sdno, S1, S2, S3, S4;
	Spov = CratIntegral(A,x1, x2, y1, y2, dz);
	Sdno = (x2 - x1) * (y2 - y1);
	S1 = Sx(A,x1, y1, y2, z);
	S3 = Sx(A,x2, y1, y2, z);
	S2 = Sy(A,y1, x1, x2, z);
	S4 = Sy(A,y1, x1, x2, z);
	return S1 + S2 + S3 + S4 + Sdno + Spov;
}

/*!
the method displays the area and volume of the body
\ param[in] z function which specifies the body of rotation
\ param[in] derz function by which you can calculate the area of ​​the body of  given by the function z
\ param[in] A -change to call mathematical functions which are represented as methods of class figure
*/
void figure::print_num(figure &A,float (figure::*z)(float, float), float (figure::*derz)(float, float)) {
	cout << "V=" << CratIntegral(A,x1, x2, y1, y2, z) << endl;
	cout << "S=" << area(A,x1, x2, y1, y2, z, derz) << endl;
}


/*!
a method that allows the user to enter the boundaries of integration
*/
void figure::Enter() {
	cout << "x1=";
	cin >> x1;
	cout << endl << "x2=";
	cin >> x2;
	cout << "y1=";
	cin >> y1;
	cout << endl << "y2=";
	cin >> y2;
}