#include "header.h"

double LagrangeInterpolation(double nodes[], double values[])
{
	double x;
	std::cout << "Enter the node (x) for which you want to get the value (f(x)):" << std::endl;
	std::cin >> x;
	double temp;
	double result = 0.000;
	std::cout << "f(" << x << ") = ";
	for (int i = 0; i < 4; i++)
	{
		temp = 1.000;
		std::cout << "(" << values[i] << ")";
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
			{
				temp *= 1;
			}
			else
			{
				temp *= x - nodes[j];
				std::cout << "*(" << temp;
				temp /= nodes[i] - nodes[j];
				std::cout << "/" << temp << ")";
			}
		}
		result += values[i] * temp;
		
		if (i < 3)
		{
			std::cout << " + ";
		}
		
	}
	std::cout << " = " << result << std::endl;
	std::cout << "f(" << x << ") = " << result << std::endl;
	return result;
}