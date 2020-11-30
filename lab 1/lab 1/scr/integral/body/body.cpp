/*!
\file
\brief  a file describing methods the body class

this file contains body class definition definitions 
*/



#include "body.h"
#include <iostream>
#include "../functions/functions.h"
using namespace std;



/*!
constructor withaut parametrs
*/
body::body() {
	Volumes = 0.0;
	Area = 0.0;
}


/*!
 constructor
 \param[in] x1,x2,y1,y2 limits integration
 \param[in] mum_of_function - number of functions body
*/
body::body(double x1, double x2, double y1, double  y2, int num_of_function) {
	if (num_of_function < 1)
		num_of_function = 1;
	if (num_of_function > 6)
		num_of_function = 6;
	switch (num_of_function){

	case 1:
		volumes(x1, x2, y1, y2, &functions::f1);
		area(x1, x2, y1, y2, &functions::f1, &functions::df1);
		break;
	case 2:
		volumes(x1, x2, y1, y2, &functions::f2);
		area(x1, x2, y1, y2, &functions::f2, &functions::df2);
		break;
	case 3:
		volumes(x1, x2, y1, y2, &functions::f3);
		area(x1, x2, y1, y2, &functions::f3, &functions::df3);
		break;
	case 4:
		volumes(x1, x2, y1, y2, &functions::f4);
		area(x1, x2, y1, y2, &functions::f4, &functions::df4);
		break;
	case 5:
		volumes(x1, x2, y1, y2, &functions::f5);
		area(x1, x2, y1, y2, &functions::f5, &functions::df5);
		break;
	case 6:
		volumes(x1, x2, y1, y2, &functions::f6);
		area(x1, x2, y1, y2, &functions::f6, &functions::df6);
		break;
	}
}



/*!
 calculate area and volumes body
 \param[in] x1,x2,y1,y2 limits integration
 \param[in] mum_of_function - number of functions body
*/
void body::build(double x1, double x2, double y1, double  y2, int num_of_function) {
	if (num_of_function < 1)
		num_of_function = 1;
	if (num_of_function > 6)
		num_of_function = 6;
	switch (num_of_function) {

	case 1:
		volumes(x1, x2, y1, y2, &functions::f1);
		area(x1, x2, y1, y2, &functions::f1, &functions::df1);
		break;
	case 2:
		volumes(x1, x2, y1, y2, &functions::f2);
		area(x1, x2, y1, y2, &functions::f2, &functions::df2);
		break;
	case 3:
		volumes(x1, x2, y1, y2, &functions::f3);
		area(x1, x2, y1, y2, &functions::f3, &functions::df3);
		break;
	case 4:
		volumes(x1, x2, y1, y2, &functions::f4);
		area(x1, x2, y1, y2, &functions::f4, &functions::df4);
		break;
	case 5:
		volumes(x1, x2, y1, y2, &functions::f5);
		area(x1, x2, y1, y2, &functions::f5, &functions::df5);
		break;
	case 6:
		volumes(x1, x2, y1, y2, &functions::f6);
		area(x1, x2, y1, y2, &functions::f6, &functions::df6);
		break;
	}
}


/*!
 calculates the area of ​​the body parallel to the axis of the OY
\param dz - function link
\param x1,x2,y1,y2  - limits of integration
*/
double body::area_paralel_oy(double x1,  double y1, double  y2, double (functions::* dz)(double, double)) {
	double num = 1000;
	float res, r = 0;;

	float 	yo;
	int i = 0;
	while (1) {
		res = 0;
		float  delta_y = (y2 - y1) / num;
		yo = y1;
		for (int j = 0; j < num; j++) {
			res += (A.*dz)(x1, yo) * delta_y;
			yo += delta_y;
		}
		if ((res - r) < precision || i > 2)
			break;
		r = res;
		num *= 2;
		++i;

	}
	return res;
}


/*!
 calculates the area of ​​the body parallel to the axis of the OX
\param dz - function link
\param x1,x2,y1,y2  - limits of integration
*/
double body::area_paralel_ox(double y1, double x1, double  x2, double (functions::* dz)(double, double)) {
	double num = 1000;
	float res, r = 0;;

	float 	xo;
	int i = 0;
	while (1) {
		res = 0;
		float  delta_x = (x2 - x1) / num;
		xo = x1;
		for (int j = 0; j < num; j++) {
			res += (A.*dz)(xo, y1) * delta_x;
			xo += delta_x;
		}
		if ((res - r) < precision || i > 2)
			break;
		r = res;
		num *= 2;
		++i;
	}
	return res;
}


/*!
getter displays the area and volume of the body
*/
void body::print() {
	cout << "Volumes = " << Volumes  << endl;
	cout << "Area    = " << Area  << endl;
}




/*!
calculates double integral
\param dz - function link
\param x1,x2,y1,y2  - limits of integration
*/
double body::double_integral(double x1, double x2, double y1, double  y2, double (functions::* z)(double, double)) {
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
		if ((V - V1) < precision || i > 3)
			break;

		V1 = V;
		num *= 2;
		++i;
	}

	return V;

}


/*!
setter  calculate area  body
 \param x1,x2,y1,y2 limits integration
 \param z -link function a body
 \param dz link  to a function that is superficial for z
*/
void body::area(double x1, double x2, double y1, double  y2, double (functions::* z)(double, double), double (functions::* dz)(double, double)) {
	double Spov, Sdno, S1, S2, S3, S4;
	Spov = double_integral(x1, x2, y1, y2, dz);
	Sdno = (x2 - x1) * (y2 - y1);
	S1 = area_paralel_oy( x1, y1, y2, z);
	S3 = area_paralel_oy( x2, y1, y2, z);
	S2 = area_paralel_oy( y1, x1, x2, z);
	S4 = area_paralel_oy( y2, x1, x2, z);
	Area= floor((S1 + S2 + S3 + S4 + Sdno + Spov)*1000)/1000;
}


/*!
setter  calculate volumes body
 \param x1,x2,y1,y2 limits integration
 \param z -link function a body
 \param dz link  to a function that is superficial for z
*/
void body::volumes(double x1, double x2, double y1, double  y2, double (functions::* z)(double, double)) {
	Volumes = floor(double_integral(x1, x2, y1, y2, z)*1000)/1000;
}

