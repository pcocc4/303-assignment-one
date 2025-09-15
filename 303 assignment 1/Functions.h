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

// Pre:  inputFile is open and contains integer data; arr points to a valid array of at least 'size' elements.
// Post: arr is filled with up to 'size' integers read from inputFile; any remaining positions are unchanged.
void processFile(ifstream& inputFile, int* arr, int size);

// Pre:  arr points to a valid array of at least 'size' elements.
// Post: Returns the index of the first occurrence of 'index' in arr, or -1 if not found; arr is unchanged.
int checkIndex(int index, int* arr, int size);

// Function to modify an element at a given index in the array
// Pre:  arr points to a valid array of at least 'size' elements; choiceNum is a valid index (0 <= choiceNum < size).
// Post: If index is valid and input is a valid integer, arr[choiceNum] is updated and returned in a Values struct; otherwise, arr is unchanged.
Values modifyArrElement(int* arr, int choiceNum, int size);

// Pre:  arr points to a valid array of at least 'arrSize' elements; numElements tracks the number of elements currently stored.
// Post: If space is available, new element is added; if full, a larger array is allocated, old elements copied, and the new element added; returns updated array and size.
newArr addingElements(int* arr, int arrSize, int& numElements);

// Pre:  arr points to a valid array of at least 'arrSize' elements; numElements > 0.
// Post: If element is found, it is removed and subsequent elements are shifted left; numElements is decremented; returns updated array and size.
newArr removeElements(int* arr, int arrSize, int& numElements);