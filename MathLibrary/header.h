#pragma once
#include <iostream>
#include <fstream>
#include <string>
#define MAX_TAB_SIZE 200
#define N 5

int ReadFromFileToTable(const char* filePath, double tab[]);
void ReadMatrixFromFileToTable(const char* filePath, double matrix[N][N+1]);
double LagrangeInterpolation(int numOfNodes, double nodes[], double values[], double x);
double NaturalPolynomial(int numOfA, double tabA[], double x);
double HornersPolynomial(int numOfA, double tabA[], double x);
double NewtonsInterpolation(int numOfNodes, double nodes[], double values[], double tabA[], double x);
void GaussianElimination(double matrix[N][N + 1]);


