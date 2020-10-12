/*!
\authors viktor ivahnuk
\version 1.0
\date   3/10/20
\file
\brief Header file with class description


this file contains the definitions of the basic classes for calculating the areas and volumes of bodies given by the function of two variables and bodies of rotation of rotation given by the function of one variable
*/


#pragma once


/*!
	\brief  class for calculating the volume and area of ​​the body of rotation

	 this class has a method of guldin which calculates volumes and area of ​​a body also this class contains
	 a package of functions which any given body of rotation
*/
class rotatebady {

private:
	float x1, x2;
	float guldin(rotatebady& B, float x1, float x2, float (rotatebady::* foo)(float), bool C);
	const float norm = 0.001;
public:

	rotatebady() = default;
	void print_num1(rotatebady& B, float (rotatebady::* z)(float), float (rotatebady::* derz)(float));
	void enter();

	float g1(float x);
	float dg1(float x);
	float g2(float x);
	float dg2(float x);
	float g3(float x);
	float dg3(float x);
};
