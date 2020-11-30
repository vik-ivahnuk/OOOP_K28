/*!
\file
\brief  a file describing methods the functions class

this file contains functions class definition definitions
*/


#include "functions.h"
#include <cmath>



/*!
f1(x,y)=x^2+y^2
\ param x,y
\ return f(x,y)
*/
double  functions::f1(double x, double y) {
	return pow(x, 2) + pow(y, 2);
}


/*!
with this function you can find the area of ​​the upper surface of the body by integrating it
\ param x, y
\ return   sqrt(1+ (df1/dx)^2+(df1/dy)^2)
*/
double functions::df1(double x, double y) {
	return sqrt(1 + pow(2 * x, 2) + pow(2 * y, 2));
}

/*!
f2(x,y)=e^x+e^x
\ param x,y
\ return f(x,y)
*/
double functions::f2(double x, double y) {
	float e = 2.71;
	return pow(e, x) + pow(e, y);
}


/*!
with this function you can find the area of ​​the upper surface of the body by integrating it
\ param x, y
\ return   sqrt(1+ (df2/dx)^2+(df2/dy)^2)
*/
double  functions::df2(double x, double y) {
	float e = 2.71;
	return sqrt(1 + pow(e, x) * pow(e, x) + pow(e, y) * pow(e, y));
}

/*!
f3(x,y)=|sin(xy)|
\ param x,y
\ return f(x,y)
*/
double  functions::f3(double x, double y) {
	return abs(sin(x * y));
}


/*!
with this function you can find the area of ​​the upper surface of the body by integrating it
\ param x, y
\ return   sqrt(1+ (df3/dx)^2+(df3/dy)^2)
*/
double functions::df3(double x, double y) {
	return sqrt(1 + pow(x * cos(x * y), 2) + pow(y * cos(x * y), 2));
}


/*!
f4(x,y)=4.6
\ param x,y
\ return f(x,y)
*/
double  functions::f4(double x, double y) {
	return 4.6;
}



/*!
with this function you can find the area of ​​the upper surface of the body by integrating it
\ param x, y
\ return   sqrt(1+ (df4/dx)^2+(df4/dy)^2)
*/
double  functions::df4(double x, double y) {
	return 1;
}


/*!
f5(x,y)=lnx+y
\ param x,y
\ return f(x,y)
*/
double  functions::f5(double  x, double y) {
	return   log(x) + y;
}

/*!
with this function you can find the area of ​​the upper surface of the body by integrating it
\ param x, y
\ return   sqrt(1+ (df5/dx)^2+(df5/dy)^2)
*/
double  functions::df5(double x, double y) {
	return sqrt(1 + pow(1 / x, 2) + 1);
}

/*!
f1(x,y)=x+y^4
\ param x,y
\ return f(x,y)
*/
double  functions::f6(double x, double y) {
	return x + pow(y, 4);
}

/*!
with this function you can find the area of ​​the upper surface of the body by integrating it
\ param x, y
\ return   sqrt(1+ (df1/6/dx)^2+(df6/dy)^2)
*/
double  functions::df6(double x, double y) {
	return sqrt(2 + 4 * pow(y, 3));
}


/////////////////////

/*!
g1(x,y)=sqrt(1-x^2)
\ param x
\ return g1(x)
*/
double  functions::g1(double x) {
	
	return sqrt(1 - pow(x, 2));
}
/*!
with this function you can find the area  of the rotatebody by integrating it ,dg1=g2*sqrt(1+ (g2')^2)
\ param x
\ return   g1*sqrt(1+ (g1')^2)
*/
double functions::dg1(double x) {


	return  sqrt(1 - pow(x, 2)) * sqrt(1 + x * x / (1 - pow(x, 2)));
}


/*!
g2(x,y)=sin(x)+5
\ param x
\ return g2(x)
*/
double functions::g2(double x) {
	return sin(x) + 5;
}



/*!
with this function you can find the area  of the rotatebody by integrating it ,dg2=g2*sqrt(1+ (g2')^2)
\ param x
\ return   g2*sqrt(1+ (g2')^2)
*/
double functions::dg2(double x) {
	return (sin(x) + 5) * sqrt(1 + pow(cos(x), 2));
}

/*!
g1(x,y)=e^x
\ param x
\ return g3(x)
*/
double functions::g3(double x) {
	return pow(2.71, x);
}

/*!
with this function you can find the area  of the rotatebody by integrating it  ,dg3=g2*sqrt(1+ (g2')^2)
\ param x
\ return   g3*sqrt(1+ (g3')^2)
*/
double functions::dg3(double x) {
	return pow(2.71, x) * sqrt(1 + pow(2.71, 2 * x));
}
