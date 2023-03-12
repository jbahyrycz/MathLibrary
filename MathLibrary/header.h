#pragma once
#include <iostream>
#include <fstream>
#include <string>
#define MAX_TAB_SIZE 200

int ReadFromFileToTable(const char* filePath, double tab[]);
double LagrangeInterpolation(int numOfNodes, double nodes[], double values[], double x);
double NaturalPolynomial(int numOfA, double tabA[], double x);
double HornersPolynomial(int numOfA, double tabA[], double x);
void NewtonsInterpolation(int numOfNodes, double nodes[], double values[], double tabA[]);

