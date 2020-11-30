

/*!
\file
\brief  a header file describing the body class

 this file contains a description of the class and the names of its methods
*/

#pragma once
#include <vector>
#include <iostream>
#include "../functions/functions.h"



using namespace std;

/*!
	\brief class for calculating the area and volume of a body given by the function of two variables
	\author viktor ivahnuk
	\date 26.10.20
	\version 2.0
*/
class body {
private:



	double precision = 0.001;///< the accuracy with which the volumeand area of ​​the body are calculated

	functions A;///< object from which the function for the body task is taken

	/*!
	 calculates the area of ​​the body parallel to the axis of the OY
	\param dz - function link
	\param x1,x2,y1,y2  - limits of integration
	*/
	double area_paralel_oy(double x1, double y1, double  y2, double (functions::* dz)(double, double));



	/*!
	calculates the area of ​​the body parallel to the axis of the OX
	\param dz - function link
	\param x1,x2,y1,y2  - limits of integration
	*/
	double area_paralel_ox(double x1, double y1, double  y2, double (functions::* dz)(double, double));


	/*!
	calculates double integral
	\param dz - function link
	\param x1,x2,y1,y2  - limits of integration
	*/
	double double_integral(double x1, double x2, double y1, double  y2, double (functions::* z)(double, double));


public:

	double Volumes;///< volumes body

	double Area;///< area body

	/*!
	constructor withaut parametrs
	*/
	body();

	/*!
     constructor 
	 \param[in] x1,x2,y1,y2 limits integration
	 \param[in] mum_of_function - number of functions body
    */
	body(double x1, double x2, double y1, double  y2, int num_of_function);


	/*!
	 calculate area and volumes body
	 \param[in] x1,x2,y1,y2 limits integration
	 \param[in] mum_of_function - number of functions body
	*/
	void build(double x1, double x2, double y1, double  y2, int num_of_function);

	/*!
	getter displays the area and volume of the body
	*/
	void print();

	

	/*!
	setter  calculate area  body
	 \param x1,x2,y1,y2 limits integration
	 \param z -link function a body
	 \param dz link  to a function that is superficial for z
	*/
	void area(double x1, double x2, double y1, double  y2, double (functions::* z)(double, double), double (functions::* dz)(double, double));



	/*!
	 setter  calculate volumes  body
	 \param x1,x2,y1,y2 limits integration
	 \param z -link function a body
	 \param dz link  to a function that is superficial for z
	*/
	void volumes(double x1, double x2, double y1, double  y2, double (functions::* z)(double, double));

	/*!
	 operator overload == for body class
	*/
	bool operator==(body ed) {
		return (this->Volumes == ed.Volumes );
	}

	/*!
	 operator overload << for body class
	*/
	friend ostream& operator<< (ostream& out, body ed) {
		out << "V=" << ed.Volumes << " S=" << ed.Area;
		return out;
	}

};



