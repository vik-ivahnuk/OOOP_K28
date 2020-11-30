



/*!
\file
\brief  a file describing methods the body_rotate class


this file contains body_rotate class definition definitions
*/


#include "body_rotate.h"
#include "../functions/functions.h"
#include <iostream>
#include <cmath>

using namespace std;


/*!
constructor withaut parametrs
*/
body_rotate::body_rotate() {
	Volumes = 0.0;
	Area = 0.0;
}



/*!
 constructor
 \param[in] x1,x2  - limits integration
 \param[in] mum_of_function - number of functions body
*/
body_rotate::body_rotate(double x1, double x2, int num_of_function) {
	if (num_of_function < 1)
		num_of_function = 1;
	if (num_of_function > 3)
		num_of_function = 3;
	switch (num_of_function) {

	case 1:
		volumes(x1, x2, &functions::g1);
		area_rotetion(x1, x2, &functions::dg1);
		
		break;
	case 2:
		volumes(x1, x2, &functions::g2);
		area_rotetion(x1, x2, &functions::dg2);
	
		break;

	case 3:
		volumes(x1, x2, &functions::g3);
		area_rotetion(x1, x2, &functions::dg3);

		break;

	}
}


/*!
 calculate area and volumes rotate body
 \param[in] x1,x2 limits integration
 \param[in] num_of_function - number of functions body
*/
void body_rotate::build(double x1, double x2, int num_of_function) {
	if (num_of_function < 1)
		num_of_function = 1;
	if (num_of_function > 3)
		num_of_function = 3;
	switch (num_of_function) {

	case 1:
		volumes(x1, x2, &functions::g1);
		area_rotetion(x1, x2, &functions::dg1);

		break;
	case 2:
		volumes(x1, x2, &functions::g2);
		area_rotetion(x1, x2, &functions::dg2);

		break;

	case 3:
		volumes(x1, x2, &functions::g3);
		area_rotetion(x1, x2, &functions::dg3);
		break;

	}
}




/*!
getter displays the area and volume of the rotate body
*/
void body_rotate::print() {
	cout << "Volumes = " << Volumes << endl;
	cout << "Area    = " << Area << endl;
}



/*!
 setter  calculate volumes  body
 \param x1,x2 limits integration
 \param foo -link function a body
*/
void body_rotate::volumes(double x1, double x2, double (functions::* foo)(double)) {
	double num = 500;
	double res, r = 0;
	double  xo;
	double delta_x;

	int i = 4;
	while (i) {
		res = 0;
		delta_x = (x2 - x1) / num;
		xo = x1;
		for (int j = 1; j < num; j++) {
			xo += delta_x;
				res += ((B.*foo)(xo) * (B.*foo)(xo) * delta_x);
		}
		if (res - r < precision)
			break;

		r = res;
		num *= 2;
		--i;
	}

	Volumes =floor(( 3.14 * res)*1000)/1000;
	
}


/*!
 setter  calculate area  body
 \param x1,x2,y1,y2 limits integration
 \param dz link  to a function that is superficial for z
*/
void body_rotate::area_rotetion(double x1, double x2, double (functions::* dfoo)(double)) {
	double num = 500;
	double res, r = 0;
	double  xo;
	double delta_x;

	int i = 10;
	while (i) {
		res = 0;
		delta_x = (x2 - x1) / num;
		xo = x1;

		for (int j = 1; j < num; j++) {
			xo += delta_x;
			res += ((B.*dfoo)(xo) * delta_x);
		}
		if (res - r < precision)
			break;

		r = res;
		num *= 2;
		--i;
	}
	Area = floor(6.28 * res*1000)/1000;
}




