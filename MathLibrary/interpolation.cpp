#include "header.h"

/*Takes nodes and corresponding values as arguments, then calculates the value of interpolated function for x*/
double LagrangeInterpolation(int numOfNodes, double nodes[], double values[], double x)
{
	double temp;
	double result = 0.000;
	for (int i = 0; i < numOfNodes; i++)
	{
		temp = 1.000;
		for (int j = 0; j < numOfNodes; j++)
		{
			if (i == j)
			{
				temp *= 1;
			}
			else
			{
				temp *= x - nodes[j];
				temp /= nodes[i] - nodes[j];
			}
		}
		result += values[i] * temp;
	}
	std::cout << "f(" << x << ") = " << result << std::endl << std::endl;
	return result;
}

/*Calculates values of a factors in Newton's Polynomial. Takes nodes and values as arguments.*/
void NewtonsInterpolation(int numOfNodes, double nodes[], double values[], double tabA[])
{
	double diffQuotients[MAX_TAB_SIZE][MAX_TAB_SIZE];
	for (int j = 0; j < numOfNodes; j++)
	{
		diffQuotients[0][j] = values[j];
		tabA[j] = diffQuotients[0][j];
		for (int i = 0; i < numOfNodes; i++)
		{
			if (i == 0)
			{
				diffQuotients[i][j] = values[j];
			}
			else if (i <= j)
			{
				diffQuotients[i][j] = (diffQuotients[i - 1][j] - diffQuotients[i - 1][j - 1]) / (nodes[j] - nodes[j - i]);
			}
			if (i == j)
			{
				tabA[j] = diffQuotients[i][j];
			}
		}
	}
}