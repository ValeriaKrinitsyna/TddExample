#pragma once
#include"LinearEquationCPP.h"

using namespace std;

class SystemOfLinearEquation
{
private:
	vector<LinearEquation> SLE;
	int n;
public:
	SystemOfLinearEquation(int _n) :n(_n) {}
	~SystemOfLinearEquation() { vector<LinearEquation>().swap(SLE); }
	LinearEquation& operator[] (int index);
	int size();
	void addEquation(LinearEquation&);
	void steppingUp();
	vector<double> solveGauss();
	operator string();
};

