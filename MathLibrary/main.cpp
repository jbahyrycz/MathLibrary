#include "header.h"

double nodes[MAX_TAB_SIZE] = { -1.000, 0.000, 1.000, 2.000 };
double values[MAX_TAB_SIZE] = { 4.000, -3.000, 5.000, -6.000 };

int main()
{
	LagrangeInterpolation(nodes, values);
	return 0;
}