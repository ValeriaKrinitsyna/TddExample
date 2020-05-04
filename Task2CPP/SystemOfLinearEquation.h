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
	LinearEquation& operator[] (int index);// access to the equation by it's index
	int size();//get size of the system of linear equations
	void addEquation(LinearEquation&);//add new equation to SLE
	void steppingUp();//stepping up the SLE
	vector<double> solveGauss();// solving by Gauss method
	operator string();//output
};

