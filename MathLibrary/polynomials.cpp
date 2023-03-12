#include "header.h"

/*Calculates the value of polynomial for given x*/
double NaturalPolynomial(int numOfA, double tabA[], double x)
{
	double result = tabA[0];
	double temp = 1.0000;

	for (int i = 1; i < numOfA; i++)
	{
		temp *= x;
		result += tabA[i] * temp;
	}

	return result;
}

/*Calculates the value of polynomial for given x, using Horner's method*/
double HornersPolynomial(int numOfA, double tabA[], double x)
{
	double result = tabA[numOfA];

	for (int i = numOfA - 1; i >= 0; i--)
	{
		result *= x;
		result += tabA[i];
	}

	return result;
}