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
#include "figure.h"
#include "rotatebody.h"
using namespace std;


/*!
	\brief parent class

   method of this class MENU () is used to create a dialog box in which you can select a three-dimensional object, the volume and area of ​​which we want to find
   MENU () also creates child classes that already use their methods to calculate volumes and areas
*/
class integral {
private:

	figure m;
	rotatebady rbady;
public:
	integral() = default;
	void MENU();
};
