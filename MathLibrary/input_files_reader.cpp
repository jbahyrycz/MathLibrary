#include "header.h"

/*Takes values from file, puts them in the table (as doubles) and returns number of elements*/
int ReadFromFileToTable(const char* filePath, double tab[])
{
	tab[MAX_TAB_SIZE];
	std::string str;
	std::fstream inputFile;
	inputFile.open(filePath, std::ios::in);
	int i = 0;
	int numOfElements;
	if (!inputFile)
	{
		std::cout << "Error! Cannot open " << filePath << " file!" << std::endl;
	}
	else
	{
		while (!inputFile.eof())
		{
			inputFile >> str;
			tab[i] = stod(str);
			i++;
		}
	}
	inputFile.close();
	numOfElements = i;

	return numOfElements;
}

//void ReadMatrixFromFileToTable(const char* filePath, double matrix[N][N+1])
//{
//	std::string str;
//	std::fstream inputFile;
//	inputFile.open(filePath, std::ios::in);
//	int numOfElements;
//	if (!inputFile)
//	{
//		std::cout << "Error! Cannot open " << filePath << " file!" << std::endl;
//	}
//	else
//	{
//		for (int i = 0; i < N * (N + 1); i++)
//		{
//			inputFile >> str;
//			if (i < N)
//			{
//				matrix[i][N] = stod(str);
//			}
//			else
//			{
//				matrix[i / N - 1][i%N] = stod(str);
//			}
//		}
//	}
//	inputFile.close();
//}

void ReadMatrixFromFileToTable(const char* filePath, double matrix[N][N + 1])
{
	std::string str;
	std::fstream inputFile;
	inputFile.open(filePath, std::ios::in);
	if (!inputFile)
	{
		std::cout << "Error! Cannot open " << filePath << " file!" << std::endl;
	}
	else
	{
		for (int i = 0; i < N * (N + 1); i++)
		{
			inputFile >> str;
			matrix[i % N][N - (i / N)] = stod(str);
		}
	}
	inputFile.close();
}