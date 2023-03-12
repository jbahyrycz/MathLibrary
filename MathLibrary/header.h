#pragma once
#include <iostream>
#include <fstream>
#include <string>
#define MAX_TAB_SIZE 500

int ReadFromFileToTable(const char* filePath, double tab[]);
double LagrangeInterpolation(const char* nodesFilePath, const char* valuesFilePath, double x);
double LagrangeInterpolation(int numOfNodes, double nodes[], double values[], double x);


