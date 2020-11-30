

/*!
\file
\brief  a header file describing the rotate body  class

 this file contains a description of the class and the names of its methods
*/

#pragma once

#include "../functions/functions.h"
#include <iostream>

using namespace std;


/*!
	\brief class for calculating the area and volume of a rotate body given by the function of one variable
	\author viktor ivahnuk
	\date 26.10.20
	\version 2.0
*/
class body_rotate {

private:
	functions B;///< object from which the function for the rotate body task is taken

	double precision = 0.001;///< the accuracy with which the volumeand area of ​​the body are calculated

public:

	double Volumes;///< volumes body

	double Area;///< area body


	/*!
	constructor withaut parametrs
	*/
	body_rotate();

	/*!
	 constructor
	 \param[in] x1,x2  - limits integration
	 \param[in] mum_of_function - number of functions body
	*/
	body_rotate(double x1, double x2, int num_of_function);


	/*!
	getter displays the area and volume of the rotate body
	*/
	void print();

	/*!
	 setter  calculate volumes  body
	 \param x1,x2 limits integration
	 \param foo -link function a body
	*/
	void volumes(double x1, double x2, double (functions::* foo)(double));

	/*!
	 setter  calculate area  body
	 \param x1,x2,y1,y2 limits integration
	 \param dz link  to a function that is superficial for z
	*/
	void area_rotetion(double x1, double x2, double (functions::* dfoo)(double));

 

	/*!
	 calculate area and volumes rotate body
	 \param[in] x1,x2 limits integration
	 \param[in] num_of_function - number of functions body
	*/
	void build(double x1, double x2, int num_of_function);



	/*!
	 operator overload == for body_rotate class
	*/
	bool operator==(body_rotate ed) {
		return (this->Volumes == ed.Volumes);
	}


	/*!
	 operator overload << for body_rotate class
	*/
	friend ostream& operator<< (ostream& out, body_rotate ed) {
		out << "V=" << ed.Volumes << " S=" << ed.Area;
		return out;
	}

    
	
};

