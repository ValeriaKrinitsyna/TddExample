#include "stdafx.h"
#include "SystemOfLinearEquation.h"
using namespace std;


LinearEquation& SystemOfLinearEquation::operator[](int index) // appeal to the equation by it's index
{
	if (index >= 0 && index < SLE.size())
		return SLE[index];
	else throw out_of_range("Out of range!");
}  

int SystemOfLinearEquation::size()
{
	return SLE.size();
}

void SystemOfLinearEquation::addEquation(LinearEquation& a)
{
	if (a.size() == n + 1)
		SLE.push_back(a);
	else throw invalid_argument("Invalid argument!");
}

void SystemOfLinearEquation::steppingUp()
{
	int c, z;
	for (int i = 0; i < size(); i++)
	{
		z = i;
		if (SLE[i][z] == 0)
		{
			while (SLE[i][z] == 0 && z < n) z++;
			c = 1;
			while ((i + c) < size() && SLE[i + c][z] == 0) c++;
			if ((i + c) == size())
				return;
			swap(SLE[i], SLE[i + c]);
		}
		for (int j = i + 1; j < size(); j++)
		{
			LinearEquation tmp1 = SLE[j] * SLE[i][z];
			LinearEquation tmp2 = SLE[i] * SLE[j][z];
			SLE[j] = tmp1 - tmp2;
		}
	}
}

vector<double> SystemOfLinearEquation::solveGauss() // solving by Gauss method
{
	while (SLE[size() - 1].isNull())
		SLE.pop_back();
	if (SLE[size() - 1])
	{
		if (size() == n)
		{
			vector<double> solve(n);
			for (int i = size() - 1; i >= 0; i--)
			{
				solve[i] = SLE[i][n];
				for (int j = i + 1; j < n; j++)
					solve[i] -= SLE[i][j] * solve[j];
				solve[i] /= SLE[i][i];
			}
			return solve;
		}
		else throw invalid_argument("Infinitely many solutions!");
	}
	else throw invalid_argument("No solutions!");
}

SystemOfLinearEquation::operator string()
{
	string res = "";
	for (int i = 0; i < size(); i++)
		res += (string)SLE[i] + '\n';
	return res;
}