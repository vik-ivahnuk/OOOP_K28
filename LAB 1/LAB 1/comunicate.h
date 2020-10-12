/*!
\authors viktor ivahnuk
\version 1.0
\date   1/10/20
\file
\brief Header file with a description of the main class

this file contains the definition of the main class which creates the menu in the console through which it is possible to choose work with the graph or a binary tree or to choose calculation of volumes and areas of bodies
*/



#pragma once

#include "Graf.h"
#include "tree.h"
#include "integral.h"


/*!
	\brief main class which builds the main menu on the console

	this class builds the main menu through which you can select the function of the program, the menu creates objects graf, beentree and body which create new menus
	in which you can choose in more detail the function of the program with which we want to work

*/
class comunity {
public:
	void comunicate();
};
