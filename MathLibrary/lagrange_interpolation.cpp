#include "header.h"

/*Takes nodes and corresponding values from input files, then calculates the value of interpolated function for x*/
double LagrangeInterpolation(const char* nodesFilePath, const char* valuesFilePath, double x)
{
	double nodes[MAX_TAB_SIZE];
	double values[MAX_TAB_SIZE];
	int numOfNodes = ReadFromFileToTable(nodesFilePath, nodes);
	ReadFromFileToTable(valuesFilePath, values);

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