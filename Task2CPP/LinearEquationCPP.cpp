#include "stdafx.h"
#include "LinearEquationCPP.h"
#include<iostream>
#include<regex>
#include<ctime>
#include<list>
using namespace std;


vector<string> LinearEquation::resplit(const string& s, string rgx_str) //splits the string
{
	vector<string> elements;
	regex rgx(rgx_str);
	sregex_token_iterator it(s.begin(), s.end(), rgx, -1);
	sregex_token_iterator end;
	while (it != end)
	{
		elements.push_back(*it);
		++it;
	}
	return elements;
}

LinearEquation::LinearEquation(string _s) // makes an equation from the string of coefficients
{
	vector<string> s = resplit(_s, "[-.]"); //splits everywhere besides "-" and "."
	for (int i = 0; i < s.size(); i++)
		if (s[i] != "")
			coefs.push_back(stod(s[i].c_str()));
}

LinearEquation::LinearEquation(vector<double>a) // an equation from the array of coefficients
{
	coefs = a;
}

LinearEquation::LinearEquation(list<double>a) // an equation from the list of coefficients
{
	copy(a.begin(), a.end(), back_inserter(coefs));
}

LinearEquation::LinearEquation(int n) // an equation of n variables with 0 coefficients
{
	coefs.resize(n + 1);
}

void LinearEquation::randInit() // an equation with random numbers
{

	for_each(coefs.begin(), coefs.end(), [](double& t) {t = (rand() % 100) / 10.0; });
}

void LinearEquation::equalInit(double value) // an equation with equal numbers
{
	for_each(coefs.begin(), coefs.end(), [value](double& t) {t = value; });
}

LinearEquation LinearEquation::operator+(LinearEquation& b) // a+b
{
	vector<double> res = coefs;
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
	for_each(res.begin(), res.end(), [r](double& a) {a *= r; });
	return LinearEquation(res);
}

LinearEquation operator*(double r, LinearEquation& a) // r*a
{
	return a * r;
}

LinearEquation LinearEquation::operator-() // a*(-1)
{
	vector<double> res = coefs;
	for_each(res.begin(), res.end(), [](double& a) {a = -a; });
	return LinearEquation(res);
}

bool operator==(LinearEquation& a, LinearEquation& b) // a==b?
{
	for (int i = 0; i < a.size(); i++)
		if (abs(a[i] - b[i]) > 1e-9)
			return false;
	return true;
}

bool operator!=(LinearEquation& a, LinearEquation& b) // a!=b?
{
	return !(a == b);
}

LinearEquation::operator bool() // false - contradictory equation, true - solvable equation
{
	for (int i = 0; i < size() - 1; i++)
		if (coefs[i] != 0)
			return true;
	return (coefs[size() - 1] != 0) ? false : true;
}

LinearEquation::operator string() // output to console
{
	string res = "";
	int i;
	for (i = 0; i < size() - 2; i++)
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
	copy(coefs.begin(), coefs.end(), back_inserter(coef));
	return coef;
}

bool LinearEquation::isNull()
{
	for (int i = 0; i < size(); i++)
		if (coefs[i] != 0)
			return false;
	return true;
}

double& LinearEquation::operator[](int index)
{
	if (index >= 0 && index < coefs.size())
		return coefs.at(index);
	else throw out_of_range("Out of range!");
}