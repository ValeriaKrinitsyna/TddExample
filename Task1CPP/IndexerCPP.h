#pragma once
class IndexerCPP
{
private:
	double* array;
	int start, end;
public:
	IndexerCPP(double* array, int arrayLength, int start, int length);
	int Length();
	double& operator[] (const int index);
};

