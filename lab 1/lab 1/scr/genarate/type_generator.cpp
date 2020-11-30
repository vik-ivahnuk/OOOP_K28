#include "type_generator.h"
#include "../integral/body/body.h"
#include "../integral/body_rotate/body_rotate.h"

int type_generator<int>::int_generate() {
	return rand() % 100;
}

int type_generator<vector<int>>::int_generate() {
	return rand() % 100;
}
double type_generator<double>::double_generate() {
	return rand() % 100 + (rand() % 1) * (rand() % 9) / 10 + (rand() % 1) * (rand() % 9) / 100;
}
double type_generator<vector<double>>::double_generate() {
	return rand() % 100 + (rand() % 1) * (rand() % 9) / 10 + (rand() % 1) * (rand() % 9) / 100;
}


string type_generator<string>::string_generate() {
	string res = "";
	int N = rand() % 6;
	for (int i = 0; i < N; i++) {
		res += rand() % 25 + '0';
	}
	return res;
}
string type_generator<vector<string>>::string_generate() {
	string res = "";
	int N = rand() % 6;
	for (int i = 0; i < N; i++) {
		res += rand() % 26 + '0';
	}
	return res;
}

int type_generator<int>::generate() {
	return int_generate();
}

double type_generator<double>::generate() {
	return double_generate();
}

string type_generator<string>::generate() {
	return string_generate();
}

vector<int>  type_generator<vector<int>>::generate() {

	vector<int> res;
	int N = 1 + rand() % 9;
	for (int i = 1; i < N; i++) {
		res.push_back(int_generate());

	}
	return res;
}

vector<double>  type_generator<vector<double>>::generate() {

	vector<double> res;
	int N = 1 + rand() % 9;
	for (int i = 1; i < N; i++) {
		res.push_back(double_generate());

	}
	return res;
}

vector<string>  type_generator<vector<string>>::generate() {

	vector<string> res;
	int N = 1 + rand() % 9;
	for (int i = 1; i < N; i++) {
		res.push_back(string_generate());

	}
	return res;
}


body type_generator<body>::generate() {
	double x1 = rand() % 4 + (rand() % 2) * (rand() % 9) / 10 + (rand() % 2) * (rand() % 9) / 100;
	double x2 = x1 + rand() % 4 + (rand() % 1) * (rand() % 9) / 10 + (rand() % 1) * (rand() % 9) / 100;
	double y1 = rand() % 4 + (rand() % 2) * (rand() % 10) / 10 + (rand() % 2) * (rand() % 10) / 100;
	double y2 = y1 + rand() % 4 + (rand() % 2) * (rand() % 10) / 10 + (rand() % 2) * (rand() % 10) / 100;
	body BODY(x1, x2, y1, y2, 1 + rand() % 5);
	return BODY;
}



body_rotate type_generator<body_rotate>::generate() {
	double x1 =   -(rand()%4-(rand() % 2) * (rand() % 9) / 10 - (rand() % 2) * (rand() % 9) / 100)/10.0;
	double x2 = x1+1.0;
	cout << x1 << " -- " << x2 << endl;
	body_rotate Body_rotate(x1, x2, 1 + rand() % 2);
	return Body_rotate;
}