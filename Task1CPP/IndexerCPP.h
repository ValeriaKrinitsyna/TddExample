#pragma once
class IndexerCPP
{
private:
	double* array;
	int start, end;
public:
	IndexerCPP(double* array, int arrayLength, int start, int length); //access to the part of array by the some element and length from this element
	int Length();
	double& operator[] (const int index); //access to the element by it's index
};

