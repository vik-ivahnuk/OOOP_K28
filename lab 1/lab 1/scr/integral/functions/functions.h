
/*!
\file
\brief  a header file describing the fucktions class

 this file contains a description of the class and the names of its methods
*/


#pragma once



/*!
	\brief class contains mathematical functions that can specify the body
	\author viktor ivahnuk
	\date 26.10.20
	\version 2.0
*/
class functions {
public:
	/*!
	f1(x,y)=x^2+y^2
	\ param x,y
	\ return f(x,y)
	*/
	double  f1(double x, double y);

	/*!
	with this function you can find the area of ​​the upper surface of the body by integrating it
	\ param x, y
	\ return   sqrt(1+ (df1/dx)^2+(df1/dy)^2)
	*/
	double  df1(double x, double y);

	/*!
	f2(x,y)=e^x+e^x
	\ param x,y
	\ return f(x,y)
	*/
	double  f2(double x, double y);
	/*!
	with this function you can find the area of ​​the upper surface of the body by integrating it
	\ param x, y
	\ return   sqrt(1+ (df2/dx)^2+(df2/dy)^2)
	*/
	double  df2(double x, double y);

	/*!
	f3(x,y)=|sin(xy)|
	\ param x,y
	\ return f(x,y)
	*/
	double  f3(double x, double y);

	/*!
	with this function you can find the area of ​​the upper surface of the body by integrating it
	\ param x, y
	\ return   sqrt(1+ (df3/dx)^2+(df3/dy)^2)
	*/
	double  df3(double x, double y);


	/*!
	f4(x,y)=4.6
	\ param x,y
	\ return f(x,y)
	*/
	double  f4(double x, double y);

	/*!
	with this function you can find the area of ​​the upper surface of the body by integrating it
	\ param x, y
	\ return   sqrt(1+ (df4/dx)^2+(df4/dy)^2)
	*/
	double  df4(double x, double y);


	/*!
	f5(x,y)=lnx+y
	\ param x,y
	\ return f(x,y)
	*/
	double  f5(double x, double y);

	/*!
	with this function you can find the area of ​​the upper surface of the body by integrating it
	\ param x, y
	\ return   sqrt(1+ (df5/dx)^2+(df5/dy)^2)
	*/
	double  df5(double x, double y);

	/*!
	f1(x,y)=x+y^4
	\ param x,y
	\ return f(x,y)
	*/
	double  f6(double x, double y);

	/*!
	with this function you can find the area of ​​the upper surface of the body by integrating it
	\ param x, y
	\ return   sqrt(1+ (df1/6/dx)^2+(df6/dy)^2)
	*/
	double  df6(double x, double y);



	/*!
	g1(x)=sqrt(1-x^2)
	\ param x
	\ return g1(x)
	*/
	double  g1(double x);

	/*!
	with this function you can find the area  of the rotatebody by integrating it ,dg1=g2*sqrt(1+ (g2')^2)
	\ param x
	\ return   g1*sqrt(1+ (g1')^2)
	*/
	double dg1(double x);

	/*!
	g2(x,y)=sin(x)+5
	\ param x
	\ return g2(x)
	*/
	double g2(double x);

	/*!
	with this function you can find the area  of the rotatebody by integrating it ,dg2=g2*sqrt(1+ (g2')^2)
	\ param x
	\ return   g2*sqrt(1+ (g2')^2)
	*/
	double dg2(double x);

	/*!
	g1(x,y)=e^x
	\ param x
	\ return g3(x)
	*/
	double g3(double x);

	/*!
	with this function you can find the area  of the rotatebody by integrating it  ,dg3=g2*sqrt(1+ (g2')^2)
	\ param x
	\ return   g3*sqrt(1+ (g3')^2)
	*/
	double dg3(double x);
};