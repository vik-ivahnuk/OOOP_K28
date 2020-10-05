/*!
\authors viktor ivahnuk
\version 1.0
\date   3/10/20
\file
\brief Header file with class description

      this file contains the definition of basic classes for calculating the areas and volumes of bodies given by the function of two variables and bodies of rotation given by the function of the same change
*/



#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;


/*!
	\brief parent class 

   method of this class MENU () is used to create a dialog box in which you can select a three-dimensional object, the volume and area of ​​which we want to find
   MENU () also creates child classes that already use their methods to calculate volumes and areas
*/
class basicc {
protected:
	const float norm = 0.001;

	float x1, x2, y1, y2;



	basicc(bool f) {
		cout << "x1=";
		cin >> x1;
		cout << endl << "x2=";
		cin >> x2;
		if (f) {
			cout << "y1=";
			cin >> y1;
			cout << endl << "y2=";
			cin >> y2;
		}
	}
public:

	basicc() {
		x1 = 0;
		x2 = 0;
		y1 = 0;
		y2 = 0;
	}


	void MENU();
};

/*!
	\brief a child class that inherits from the basicc class  


   from the class basicc variables  x1, x2, y1, y2 in which the limits of integration of function by which this body is set will remain
   and inherits the constructor by default
   by its methods calculates the volume and area of ​​the body which is given by the function of two variables
  
*/
class figure :basicc {
private:
	float Sx(figure &A,float x1, float y1, float y2, float (figure::*z)(float, float));
                       
	float Sy(figure &A,float y1, float x1, float x2, float (figure::*z)(float, float));

	float CratIntegral(figure &A,float x1, float x2, float y1, float y2, float (figure::*z)(float, float));

	float area(figure &A,float x1, float x2, float y1, float y2, float (figure::*z)(float, float), float (figure::*dz)(float, float));

public:

	figure():basicc() {}
	void print_num(figure &A,float (figure::*z)(float, float), float (figure::*derz)(float, float));
	void Enter();

	float  f1(float x, float y);
	float  df1(float x, float y);

	float  f2(float x, float y);
	float  df2(float x, float y);

	float  f3(float x, float y);
	float  df3(float x, float y);

	float  f4(float x, float y);
	float  df4(float x, float y);

	float  f5(float x, float y);
	float  df5(float x, float y);

	float  f6(float x, float y);
	float  df6(float x, float y);
};
/*!
	\brief a child class that inherits from the basicc class variables  x1, x2, y1, y2 in which the limits of integration of the function by which this body is set will be stored

 
   from the class basicc variables x1,x2,y1,y2 in which the limits of integration of the function by which this body is set will be stored
   and inherits the constructor by default
   by its methods calculates the volume and area of ​​the body of rotation around the axis Ox which is given by the function of one change

*/
class rotatebady :basicc {
private:
	float guldin(rotatebady &B,float x1, float x2,float (rotatebady::*foo)(float), bool C);
public:

	rotatebady(): basicc() {};
	void print_num1(rotatebady &B, float (rotatebady::*z)(float), float (rotatebady::* derz)(float));
	void enter();

	float g1(float x);
	float dg1(float x);
	float g2(float x);
	float dg2(float x);
	float g3(float x);
	float dg3(float x);
};








