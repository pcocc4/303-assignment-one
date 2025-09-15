#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
#include "Functions.h"



// Reads integers from an input file into an array, up to the given size
void processFile(ifstream& inputFile, int* arr, int size) {
    string line;
    int index = 0;

    // Read file line-by-line until EOF or array is full
    while (getline(inputFile, line) && index < size) {
        istringstream iss(line);
        int number;

        // Extract integers from the current line and store them in the array
        while (iss >> number && index < size) {
            arr[index++] = number;
        }
    }
}

// Searches for a number in the array and returns its index, or -1 if not found
int checkIndex(int num, int* arr, int size) {
    int index = 0;

    // Loop through the array to find the target number
    while (index < size) {
        if (arr[index] == num) {
            return index; // Found, return position
        }
        else {
            index++;
        }
    }

    // If the number is not found, return -1
    return -1;
}

// Modifies an element at a given index in the array and returns the old/new values
Values modifyArrElement(int* arr, int index, int size) {
    int ogValue; // Original value before modification
    string userInput;
    int convertedNum;
    Values newValue; // Struct to store change details

    // Check if index is valid
    if (index >= 0 && index < size) {
        ogValue = arr[index];

        // Ask user for the new value
        cout << "What would you like to change this value to?: " << endl;
        cin >> userInput;

        try {
            // Convert input to integer and update array
            convertedNum = stoi(userInput);
            arr[index] = convertedNum;

            // Store change details in the struct
            newValue.oldNum = ogValue;
            newValue.newNum = convertedNum;
            newValue.isChanged = true;
            return newValue;
        }
        catch (invalid_argument&) {
            // Handle invalid integer input
            cout << "Invalid input. Please enter a valid integer." << endl;
            return newValue;
        }
    }

    // If index is invalid, return struct with default values (isChanged = false)
    return newValue;
}

// Adds a new element to the array, resizing if necessary
newArr addingElements(int* arr, int arrSize, int& numElements) {
    string userInput;
    int numInput;
    newArr biggerArr; // Struct to return updated array and size

    // Keep asking until a valid integer is entered
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

    // If there is space in the current array
    if (numElements < arrSize) {
        arr[numElements] = numInput;
        numElements++;
        biggerArr.newArray = arr;
        biggerArr.newSize = arrSize;
        cout << "Element " << numInput << " has been added to the array." << endl;
        return biggerArr;
    }
    else {
        // No space left — create a bigger array (double the size)
        int newArrSize = arrSize * 2;
        int* newArr = new int[newArrSize];

        // Copy old elements into the new array
        for (int i = 0; i < arrSize; ++i) {
            newArr[i] = arr[i];
        }

        // Add the new element
        newArr[numElements] = numInput;
        numElements++;

        // Free old array memory
        delete[] arr;

        // Return updated array and size
        biggerArr.newArray = newArr;
        biggerArr.newSize = newArrSize;
        cout << "Element " << numInput << " has been added to the array." << endl;
        return biggerArr;
    }
}

// Removes an element from the array by shifting elements left
newArr removeElements(int* arr, int arrSize, int& numElements) {
    string userInput;
    int numInput;
    newArr smallerArr; // Struct to return updated array and size

    // Keep asking until a valid integer is entered
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
        // Shift elements left to overwrite the removed element
        for (int i = index; i < numElements - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        numElements--;
        cout << "Element " << numInput << " has been removed from the array." << endl;
    }
    else {
        cout << "Element not found in the array." << endl;
    }

    // Return updated array and size (size stays the same, but numElements changes)
    smallerArr.newArray = arr;
    smallerArr.newSize = arrSize;
    return smallerArr;
}