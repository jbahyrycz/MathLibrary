#include "header.h"

/*Lagrange Interpolation*/
double nodes[MAX_TAB_SIZE];
double values[MAX_TAB_SIZE];

double test_nodes_1[3] = { -5.000, 0.000, 5.000 };
double test_values_1[3] = { 0.038, 1.000, 0.038 };
double test_nodes_2[5] = { -5.000, -2.000, 0.000, 2.000, 5.000 };
double test_values_2[5] = { 0.038, 0.200, 1.000, 0.200, 0.038 };
double test_nodes_3[15] = { -5.000, -4.000, -3.000, -2.000, -1.000, -0.500, -0.250, 0.000, 0.250, 0.500, 1.000, 2.000, 3.000, 4.000, 5.000 };
double test_values_3[15] = { 0.038, 0.059, 0.100, 0.200, 0.500, 0.800, 0.941, 1.000, 0.941, 0.800, 0.500, 0.200, 0.100, 0.059, 0.038 };

/*Natural/Horner's Polynomial*/
double tabA[MAX_TAB_SIZE];
double tabX[MAX_TAB_SIZE];
double tabY[MAX_TAB_SIZE];

/*Newton's Interpolation*/
double tabANewton[MAX_TAB_SIZE];

int main()
{
	//double x;

	///*Lagrange Interpolation for unknown function*/
	//int numOfNodes = ReadFromFileToTable("InputFiles/lagrange_interpolation_nodes.txt", nodes);
	//ReadFromFileToTable("InputFiles/lagrange_interpolation_values.txt", values);
	//std::cout << "Enter the node (x) for which you want to get the value (f(x)): ";
	//std::cin >> x;
	//LagrangeInterpolation(numOfNodes, nodes, values, x);

	///*Lagrange Interpolation for f(x) = 1/(1+x^2) function, analyzing the influence that the number of the nodes has on calculations precision.
	//With every function call, our function receives more nodes and values for calculations. As you can see from this experiment:
	//the more nodes given, the more precise result.*/
	//std::cout << "Enter the node (x) for which you want to get the value (f(x)), must be a number between -5 and 5: ";
	//std::cin >> x;
	//std::cout << "The correct value for x = " << x << " is: " << 1.000/(1.000+x*x) << std::endl << std::endl;
	//LagrangeInterpolation(3, test_nodes_1, test_values_1, x);
	//LagrangeInterpolation(5, test_nodes_2, test_values_2, x);
	//LagrangeInterpolation(15, test_nodes_3, test_values_3, x);

	/*Calculationg Natural Polynomial values for given a factors and for given table of x arguments. As a result we get a table of polynomial values.*/
	std::cout << "Natural Polynomial:" << std::endl;
	int numOfA = ReadFromFileToTable("InputFiles/horners_polynomial_a.txt", tabA);
	int numOfX = ReadFromFileToTable("InputFiles/horners_polynomial_x.txt", tabX);
	for (int i = 0; i < numOfX; i++)
	{
		tabY[i] = NaturalPolynomial(numOfA, tabA, tabX[i]);
		std::cout << "f(" << tabX[i] << ") = " << tabY[i] << std::endl;
	}
	std::cout << std::endl;

	/*Calculationg polynomial values for given a factors and for given table of x arguments, using Horner's method.
	As a result we get a table of polynomial values.*/
	std::cout << "Horner's method:" << std::endl;
	numOfA = ReadFromFileToTable("InputFiles/horners_polynomial_a.txt", tabA);
	numOfX = ReadFromFileToTable("InputFiles/horners_polynomial_x.txt", tabX);
	for (int i = 0; i < numOfX; i++)
	{
		tabY[i] = HornersPolynomial(numOfA, tabA, tabX[i]);
		std::cout << "f(" << tabX[i] << ") = " << tabY[i] << std::endl;
	}
	std::cout << std::endl;

	/*Newton's Interpolation, as a result we get a table of a factors in Newton's Polynomial.*/
	std::cout << "Newton's Interpolation:" << std::endl;
	int numOfNodes = ReadFromFileToTable("InputFiles/newtons_interpolation_nodes.txt", nodes);
	ReadFromFileToTable("InputFiles/newtons_interpolation_values.txt", values);
	NewtonsInterpolation(numOfNodes, nodes, values, tabANewton);
	for (int i = 0; i < numOfNodes; i++)
	{
		std::cout << "a" << i << " = " << tabANewton[i] << std::endl;
	}
	
	return 0;
}