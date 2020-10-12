
/*!
\authors viktor ivahnuk
\version 1.0
\date   3/10/20
\file
\brief Header file with class description


this file contains a class for calculating the area and volume of a body given by a two-variable function
*/

#pragma once


/*!
	\brief class for calculating the volume and area of ​​the body given of functions of two variables

	this class has methods that calculate the volume and area of ​​the body also this class contains
	a package of functions of two variables which can be a given body

*/
class figure {
private:
	const float norm = 0.001;
	float x1, x2, y1, y2;

	float Sx(figure& A, float x1, float y1, float y2, float (figure::* z)(float, float));

	float Sy(figure& A, float y1, float x1, float x2, float (figure::* z)(float, float));

	float CratIntegral(figure& A, float x1, float x2, float y1, float y2, float (figure::* z)(float, float));

	float area(figure& A, float x1, float x2, float y1, float y2, float (figure::* z)(float, float), float (figure::* dz)(float, float));

public:

	figure() = default;
	void print_num(figure& A, float (figure::* z)(float, float), float (figure::* derz)(float, float));
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
