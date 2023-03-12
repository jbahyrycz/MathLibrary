#include "header.h"

double test_nodes_1[3] = { -5.000, 0.000, 5.000 };
double test_values_1[3] = { 0.038, 1.000, 0.038 };
double test_nodes_2[5] = { -5.000, -2.000, 0.000, 2.000, 5.000 };
double test_values_2[5] = { 0.038, 0.200, 1.000, 0.200, 0.038 };
double test_nodes_3[15] = { -5.000, -4.000, -3.000, -2.000, -1.000, -0.500, -0.250, 0.000, 0.250, 0.500, 1.000, 2.000, 3.000, 4.000, 5.000 };
double test_values_3[15] = { 0.038, 0.059, 0.100, 0.200, 0.500, 0.800, 0.941, 1.000, 0.941, 0.800, 0.500, 0.200, 0.100, 0.059, 0.038 };

int main()
{
	double x;
	/*Lagrange Interpolation for unknown function*/
	std::cout << "Enter the node (x) for which you want to get the value (f(x)):" << std::endl;
	std::cin >> x;
	LagrangeInterpolation("InputFiles/lagrange_interpolation_nodes.txt", "InputFiles/lagrange_interpolation_values.txt", x);

	/*Lagrange Interpolation for f(x) = 1/(1+x^2) function, analysing the influence that the number of the nodes has on calculations precision.
	With every function call, our function receives more nodes and values for calculations. As you can see from this experiment:
	the more nodes given, the more precise result.*/
	std::cout << "Enter a number between -5 and 5:" << std::endl;
	std::cin >> x;
	std::cout << "The correct value for x = " << x << " is: " << 1.000/(1.000+x*x) << std::endl << std::endl;
	LagrangeInterpolation(3, test_nodes_1, test_values_1, x);
	LagrangeInterpolation(5, test_nodes_2, test_values_2, x);
	LagrangeInterpolation(15, test_nodes_3, test_values_3, x);

	return 0;
}