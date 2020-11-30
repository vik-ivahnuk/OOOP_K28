/*!
\file
\brief  a header file describing the body class

 this file contains a description of the class and the names of its methods
*/


#pragma once

#include <string>
#include <vector>


/*!
	\brief  the class generates random values ​​of different data types
	\author viktor ivahnuk
	\date 26.10.20
	\version 2.0
*/
using namespace std;
template<typename T>
class type_generator {
private:
	/*!
	generates integer
	*/
	int int_generate();

	/*!
	generates double num
	*/
	double double_generate();

	/*!
	generates string
	*/
	string string_generate();
public:

	/*!
     generates a value with type T
	*/
	T generate();
};


