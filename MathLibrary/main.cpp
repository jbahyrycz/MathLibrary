#include "header.h"

int main()
{
	/*Lagrange Interpolation for unknown function*/
	LagrangeInterpolation("InputFiles/lagrange_interpolation_nodes.txt", "InputFiles/lagrange_interpolation_values.txt");

	/*Lagrange Interpolation for f(x) = 1/(1+x^2) function, analysing the influence that the number of the nodes has on calculations precision.
	With every function call, our function receives input files containing more nodes and values. As you can see from this experiment:
	the more nodes given, the more precise result.*/
	std::cout << "For the next 5 cases the node you choose must be the number between -5 and 5." << std::endl;
	LagrangeInterpolation("InputFiles/lagrange_interpolation_nodes_test_file_1.txt", "InputFiles/lagrange_interpolation_values_test_file_1.txt");
	LagrangeInterpolation("InputFiles/lagrange_interpolation_nodes_test_file_2.txt", "InputFiles/lagrange_interpolation_values_test_file_2.txt");
	LagrangeInterpolation("InputFiles/lagrange_interpolation_nodes_test_file_3.txt", "InputFiles/lagrange_interpolation_values_test_file_3.txt");
	LagrangeInterpolation("InputFiles/lagrange_interpolation_nodes_test_file_4.txt", "InputFiles/lagrange_interpolation_values_test_file_4.txt");
	LagrangeInterpolation("InputFiles/lagrange_interpolation_nodes_test_file_5.txt", "InputFiles/lagrange_interpolation_values_test_file_5.txt");
	LagrangeInterpolation("InputFiles/lagrange_interpolation_nodes_test_file_6.txt", "InputFiles/lagrange_interpolation_values_test_file_6.txt");
	LagrangeInterpolation("InputFiles/lagrange_interpolation_nodes_test_file_7.txt", "InputFiles/lagrange_interpolation_values_test_file_7.txt");

	return 0;
}