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
	LinearEquation(string coeff);
	LinearEquation(list<double>);
	LinearEquation(vector<double>);
	LinearEquation(int n);
	~LinearEquation() { vector<double>().swap(coefs); };
	int size() { return coefs.size(); }
	void randInit();
	void equalInit(double);
	bool isNull();
	double& operator[] (int index);
	LinearEquation operator+(LinearEquation&);
	LinearEquation operator-(LinearEquation&);
	LinearEquation operator-();
	operator string();
	operator bool();
	operator list<double>();
	LinearEquation operator*(const double&);
	friend LinearEquation operator*(double, LinearEquation&);
};

bool operator==(LinearEquation&, LinearEquation&);
bool operator!=(LinearEquation&, LinearEquation&);
