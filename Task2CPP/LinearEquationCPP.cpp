#include "stdafx.h"
#include "LinearEquationCPP.h"
#include<iostream>
#include<regex>
#include<ctime>
#include<list>
using namespace std;


vector<string> LinearEquation::resplit(const string& s, string rgx_str) //splits the string by regular expression
{
	vector<string> elements;
	regex rgx(rgx_str); // regular expression
	sregex_token_iterator it(s.begin(), s.end(), rgx, -1); //iterator using string s and regular expression
	sregex_token_iterator end; //end of string
	while (it != end)
	{
		elements.push_back(*it); //add element to vector if met something from regular expression
		++it; //go to next element
	}
	return elements;
}

LinearEquation::LinearEquation(string _s) // makes an equation from the string of coefficients
{
	vector<string> s = resplit(_s, "[^\\d-.]"); // split the string s when nothing from regex met
	for (int i = 0; i < s.size(); i++)
		if (s[i] != "")
			coefs.push_back(stod(s[i].c_str())); // extract double from string
}

LinearEquation::LinearEquation(vector<double>a) // an equation from the array of coefficients
{
	coefs = a; //copy elements from one vector to another
}

LinearEquation::LinearEquation(list<double>a) // an equation from the list of coefficients
{
	copy(a.begin(), a.end(), back_inserter(coefs)); // copy each coefficient from the list to the end of vector
}

LinearEquation::LinearEquation(int n) // an equation of n variables with 0 coefficients
{
	coefs.resize(n + 1);
}

void LinearEquation::randInit() // an equation with random numbers
{

	for_each(coefs.begin(), coefs.end(), [](double& t) {t = (rand() % 100) / 10.0; }); //put random numbers to each vector's element
}

void LinearEquation::equalInit(double value) // an equation with equal numbers
{
	for_each(coefs.begin(), coefs.end(), [value](double& t) {t = value; }); //put some number to each vector's element
}

LinearEquation LinearEquation::operator+(LinearEquation& b) // a+b
{
	vector<double> res = coefs; //result vector is coefs
	for (int i = 0; i < size(); i++)
		res[i] += b[i]; 
	return LinearEquation(res);
}

LinearEquation LinearEquation::operator-(LinearEquation& b) // a-b
{
	vector<double> res = coefs;
	for (int i = 0; i < size(); i++)
		res[i] -= b[i];
	return LinearEquation(res);
}
LinearEquation LinearEquation::operator*(const double& r) // a*r
{
	vector<double> res = coefs;
	for_each(res.begin(), res.end(), [r](double& a) {a *= r; }); // put a*r to each element
	return LinearEquation(res);
}

LinearEquation operator*(double r, LinearEquation& a) // r*a
{
	return a * r;
}

LinearEquation LinearEquation::operator-() // a*(-1)
{
	vector<double> res = coefs;
	for_each(res.begin(), res.end(), [](double& a) {a = -a; }); // put -a to each element
	return LinearEquation(res);
}

bool operator==(LinearEquation& a, LinearEquation& b) // a==b?
{
	for (int i = 0; i < a.size(); i++)
		if (abs(a[i] - b[i]) > 1e-9) //if the difference is bigger than 10^(-9), then we think they are not equal
			return false;
	return true;
}

bool operator!=(LinearEquation& a, LinearEquation& b) // a!=b?
{
	return !(a == b); //comparison by operator==
}

LinearEquation::operator bool() // false - contradictory equation, true - solvable equation
{
	for (int i = 0; i < size() - 1; i++)
		if (coefs[i] != 0) 
			return true;
	return (coefs[size() - 1] != 0) ? false : true; //coefs!=0 but last of coefs == 0, then false
}

LinearEquation::operator string() // output to console
{
	string res = "";
	int i;
	for (i = 0; i < size() - 2; i++) //add coefs to string, increase degree of x
	{
		res += (coefs[i + 1] >= 0) ? (to_string(coefs[i]) + 'x' + to_string((i + 1)) + '+') : (to_string(coefs[i]) + 'x' + to_string((i + 1)));
	}
	res += (to_string(coefs[i]) + 'x' + to_string((i + 1)));
	res += '=' + to_string(coefs[size() - 1]);
	return res;
}

LinearEquation::operator list<double>() // to list
{
	list<double> coef;
	copy(coefs.begin(), coefs.end(), back_inserter(coef)); //copy coefficients from vector to list
	return coef;
}

bool LinearEquation::isNull() // empty check
{
	for (int i = 0; i < size(); i++)
		if (coefs[i] != 0)
			return false;
	return true;
}

double& LinearEquation::operator[](int index) //access to coefficient by index
{
	if (index >= 0 && index < coefs.size())
		return coefs.at(index);
	else throw out_of_range("Out of range!");
}