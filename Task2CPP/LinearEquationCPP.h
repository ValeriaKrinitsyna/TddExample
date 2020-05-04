#pragma once
#include<vector>
#include<string>
#include<list>
using namespace std;

class LinearEquation
{
private:
	vector<double> coefs;
	vector<string> resplit(const string&, std::string);

public:
	LinearEquation(string coeff);// makes an equation from the string of coefficients
	LinearEquation(list<double>);// an equation from the list of coefficients
	LinearEquation(vector<double>);// an equation from the array of coefficients
	LinearEquation(int n);// an equation of n variables with 0 coefficients
	~LinearEquation() { vector<double>().swap(coefs); };
	int size() { return coefs.size(); }
	void randInit();// an equation with random numbers
	void equalInit(double);// an equation with equal numbers
	bool isNull();// empty check
	double& operator[] (int index); //access to coefficient by index
	LinearEquation operator+(LinearEquation&);// a+b
	LinearEquation operator-(LinearEquation&);// a-b
	LinearEquation operator-();// a*(-1)
	operator string();// output to console
	operator bool();// false - contradictory equation, true - solvable equation
	operator list<double>();//copy coefficients from vector to list
	LinearEquation operator*(const double&);// a*r
	friend LinearEquation operator*(double, LinearEquation&);// r*a
};

bool operator==(LinearEquation&, LinearEquation&); //comparison
bool operator!=(LinearEquation&, LinearEquation&); //comparison using operator ==
