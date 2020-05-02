#include "stdafx.h"
#include "IndexerCPP.h"
#include <stdexcept>
using namespace std;

IndexerCPP::IndexerCPP(double* array, int arrayLength, int start, int length)
{
	if (start < 0 || length <= 0 || start + length >= arrayLength)
		throw invalid_argument("Incorrect first index or length");
	else
	{
		this->array = array;
		this->start = start;
		this->end = start + length - 1;
	}
}

int IndexerCPP::Length() 
{
	return this->end - this->start + 1;
}

double& IndexerCPP::operator[] (const int index) 
{
	if (index < 0 || index >= Length())
		throw out_of_range("Index out of range");
	return this->array[index + start];
}
