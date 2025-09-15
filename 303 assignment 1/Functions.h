#pragma once
using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <limits>

struct Values {
	int oldNum;
	int newNum;
	bool isChanged = false;
};

struct newArr {
	int newSize;
	int* newArray;
};

// Function to read data from a file and store it in a 2D array
void processFile(ifstream& inputFile, int* arr, int size);
int checkIndex(int index, int* arr,int size);
Values modifyArrElement(int* arr, int choiceNum, int size); 
newArr addingElements(int* arr, int arrSize, int& numElements);
newArr removeElements(int* arr, int arrSize, int& numElements);