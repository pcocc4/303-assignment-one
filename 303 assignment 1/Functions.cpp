#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
#include "Functions.h"



void processFile(ifstream& inputFile, int* arr, int size) {
	string line;
	int index = 0;
	while (getline(inputFile, line) && index < size) {
		istringstream iss(line);
		int number;
		while (iss >> number && index < size) {
			arr[index++] = number;
		}
	}

}

int checkIndex(int num, int* arr, int size) {
	int index = 0;
	while (index < size) {
		if (arr[index] == num) {
			return index;
		}
		else {
			index++;
		}
	}
	// If the number is not found, return -1
	return -1;
}

Values modifyArrElement(int* arr, int choiceNum, int size) {
	int index = 0;
	int i = 0;
	int ogValue;
	string userInput;
	int convertedNum;
	Values newValue;
	for (i; i < size; ++i) {
		if (arr[index] != choiceNum) {
			index++;
		}
		else if(arr[index] == choiceNum) {
			int ogValue = arr[index];
			cout << "What would you like to change this value to?: " << endl;
			cin >> userInput;
			try {
				convertedNum = stoi(userInput);
				arr[index] = convertedNum;

				newValue.oldNum = ogValue;
				newValue.newNum = convertedNum;
				newValue.isChanged = true;

				return newValue; // Return the original value and the new value
			}
			catch (invalid_argument&) {
				cout << "Invalid input. Please enter a valid integer." << endl;
				return newValue; // Return with isChanged as false
			}
		}
	}
	return newValue; // If the number was not found, return with isChanged as false
} 

newArr addingElements(int* arr, int arrSize, int& numElements) {
	string userInput;
	int numInput;
	newArr biggerArr;

	// keep asking until valid integer
	while (true) {
		cout << "Please enter an element to add to the array: " << endl;
		cin >> userInput;
		try {
			numInput = stoi(userInput);
			break;
		}
		catch (invalid_argument&) {
			cout << "Invalid input. Please enter a valid integer." << endl;
		}
	}

	if (numElements < arrSize) {
		arr[numElements] = numInput;
		numElements++;
		biggerArr.newArray = arr;
		biggerArr.newSize = arrSize;
		return biggerArr;
	}
	else {
		cout << "Array is full. Creating a bigger array..." << endl;
		int newArrSize = arrSize * 2;
		int* newArr = new int[newArrSize];

		for (int i = 0; i < arrSize; ++i) {
			newArr[i] = arr[i];
		}

		newArr[numElements] = numInput;
		numElements++;

		delete[] arr;

		biggerArr.newArray = newArr;
		biggerArr.newSize = newArrSize;
		return biggerArr;
	}
}

newArr removeElements(int* arr, int arrSize, int& numElements) {
	string userInput;
	int numInput;
	newArr smallerArr;

	// keep asking until valid integer
	while (true) {
		cout << "Please enter an element to remove from the array: " << endl;
		cin >> userInput;
		try {
			numInput = stoi(userInput);
			break;
		}
		catch (invalid_argument&) {
			cout << "Invalid input. Please enter a valid integer." << endl;
		}
	}
	// Find the index of the element to remove
	int index = checkIndex(numInput, arr, arrSize);

	if (index != -1) {
		// Shift elements to the left to overwrite the removed element
		for (int i = index; i < numElements - 1; ++i) {
			arr[i] = arr[i + 1];
		}
		numElements--;
		smallerArr.newArray = arr;
		smallerArr.newSize = arrSize;
		return smallerArr;
	}
	else {
		cout << "Element not found in the array." << endl;
		smallerArr.newArray = arr;
		smallerArr.newSize = arrSize;
		return smallerArr;
	}
}
