/*!
\file
\brief  a file describing methods the Edge class

this file contains Edge class definition definitions
*/


#include "Edge.h"

#include <iostream>
#include <string>
#include <cmath>

#include "../../integral/body/body.h" 
#include "../../integral/body_rotate/body_rotate.h" 

using namespace std;


int Edge<string>::string_to_int(string a) {
	int res = 0;
	for (int i = 0; i < a.length(); i++)
		res += a[i] - '0';
	return res;
}


int Edge<vector<string>>::string_to_int(string a) {
	int res = 0;
	for (int i = 0; i < a.length(); i++)
		res += a[i] - '0';
	return res;
}



int Edge<int>::Length_edge(int edge) {
	if (edge == 0)
		return 1;
	int i=0;
	int num = edge;
	while (num) {
		i++;
		num /= 10;
	}
	return i;
}


int Edge<double>::Length_edge(double edge) {
	if (edge == 0)
		return 1;
	string num = to_string(edge);
	int b = num.length() - 1;
	int len = num.length();
	while (num[b] == '0') {
		--len;
		--b;
	}
	return len;
}



int Edge<string>::Length_edge(string edge) {
	return edge.length();
}



int Edge<vector<int>>::Length_edge(vector<int> edge) {
	int i = 0;
	int k;
	int num;
	for (int j = 0; j < edge.size(); j++) {
		if (edge[j] == 0)
			++i;
		else {
			k = 0;
			num = edge[j];
			while (num) {
				k++;
				num /= 10;
			}
			i += k;
		}
	}
	return i + edge.size() - 1;
}



int Edge<vector<double>>::Length_edge(vector<double> edge) {
	int len=0;
	bool check;
	string num;
	int b;
	int l;
	for (int k = 0; k < edge.size(); k++) {
		if (edge[k] == 0)
			++len;
		else {
			num = to_string(edge[k]);
			b = num.length() - 1;
			l = num.length();
			while (num[b] == '0') {
				--l;
				--b;
			}
			len += l;
		}
	}
	
	return len + edge.size() - 1;
}


int Edge<vector<string>>::Length_edge(vector<string> edge) {
	int len=0;
	for (int i = 0; i < edge.size(); i++) {
		len += edge[i].length();
	}
	return len + edge.size() - 1;
}

int Edge<body>::Length_edge(body edge) {

	int len1, len2;

	if (edge.Area == 0)
		len1 = 1;
	else {
		string num1 = to_string(edge.Area);
		int b1 = num1.length() - 1;
		len1 = num1.length();
		while (num1[b1] == '0') {
			--len1;
			--b1;
		}
	}
	if (edge.Volumes == 0)
		len2 = 1;
	else {
		string num2 = to_string(edge.Volumes);
		int b2 = num2.length() - 1;
		len2 = num2.length();
		while (num2[b2] == '0') {
			--len2;
			--b2;
		}
	}
 
	return len1 + len2 + 5;
  

}

int Edge<body_rotate>::Length_edge(body_rotate edge) {

	int len1, len2;
	if (edge.Area == 0.0)
		len1 = 1;
	else {
		string num1 = to_string(edge.Area);
		int b1 = num1.length() - 1;
		len1 = num1.length();
		while (num1[b1] == '0') {
			--len1;
			--b1;
		}
	}

	if (edge.Volumes == 0.0)
		len2 = 1;
	else {
		
		string num2 = to_string(edge.Volumes);
	
		int b2 = num2.length() - 1;
		len2 = num2.length();
		while (num2[b2] == '0') {
			--len2;
			--b2;
		}
	}

	return len1 + len2 + 5;

}

vector<int> Edge<vector<int>>::type_null() {
	return { 0 };
}



int Edge<int>::type_null() {
	return 0;
}



vector<double> Edge<vector<double>>::type_null() {
	return { 0.0 };
}



double Edge<double>::type_null() {
	return 0.0;
}



vector<string> Edge<vector<string>>::type_null() {
	return { "0" };
}


string Edge<string>::type_null() {
	return "0";
}

body Edge<body>::type_null() {
	body a;
	return a;
}

body_rotate Edge<body_rotate>::type_null() {
	body_rotate a;
	return a;
}