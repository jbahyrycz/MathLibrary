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