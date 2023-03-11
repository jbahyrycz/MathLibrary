#include "header.h"

/*Takes nodes and corresponding values from input files, then calculates the value of interpolated function for a given argument (from a keybord)*/
double LagrangeInterpolation(const char* nodesFilePath, const char* valuesFilePath)
{
	double nodes[MAX_TAB_SIZE];
	double values[MAX_TAB_SIZE];
	int numOfNodes = ReadFromFileToTable(nodesFilePath, nodes);
	ReadFromFileToTable(valuesFilePath, values);

	double x;
	std::cout << "Enter the node (x) for which you want to get the value (f(x)):" << std::endl;
	std::cin >> x;
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