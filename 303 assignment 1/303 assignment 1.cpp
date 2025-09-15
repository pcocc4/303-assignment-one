// 303 assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Functions.h"
#include <string>

using namespace std;

int convertToInt(const string& input) {
    try {
        int value = stoi(input); // Attempt conversion
        return value;
    }
    catch (const invalid_argument& e) {
        cerr << "Error: Input is not a valid number." << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Error: Number is out of range for an int." << endl;
    }
    return -1; // Return a sentinel value to indicate failure
}


int main()
{
    // === Open input file ===
    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Unable to open file input.txt";
        return 1; // terminate with error
    }

    const int size = 100;

    // === Initialize array tracking ===
    // numElements tracks how many elements are currently in the array
    int numElements = 0; // start empty

    // Allocate initial array on the heap so it can be resized later
    int* arr = new int[size];

    // Struct to hold array pointer and current capacity
    newArr Array;
    Array.newSize = size;
    Array.newArray = arr;

    // === Load initial data from file ===
    processFile(inFile, arr, size);

    int choice = 0;
    string userInput, choiceInput;

    // === Main menu loop ===
    while (choice != 6) {
        // Display menu
        cout << "\n=== Array Operations Menu ===" << endl;
        cout << "1. Print Array Values" << endl;
        cout << "2. Check Array Index" << endl;
        cout << "3. Modify Array Element" << endl;
        cout << "4. Add Elements to Array" << endl;
        cout << "5. Remove Elements from Array" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";

        cin >> choice;

        // Validate menu choice
        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number between 1 and 6." << endl;
            continue;
        }

        // === Handle menu selection ===
        switch (choice) {
        case 1:
            // Print all current array values
            for (int i = 0; i < numElements; ++i) {
                cout << Array.newArray[i] << " ";
            }
            cout << endl;
            break;

        case 2:
            // Search for a value and display its index
            cout << "Please type an integer to check: ";
            cin >> userInput;
            {
                int result = convertToInt(userInput);
                if (result != -1) {
                    int index = checkIndex(result, Array.newArray, Array.newSize);
                    if (index != -1) cout << "Found at index: " << index << endl;
                    else cout << result << " is not in the array" << endl;
                }
                else {
                    cout << "Conversion failed." << endl;
                }
            }
            break;

        case 3:
            // Modify a value at a given index
            cout << "Enter index to modify (0 to " << numElements - 1 << "): ";
            cin >> choiceInput;
            {
                int choiceNum = convertToInt(choiceInput);
                if (choiceNum != -1) {
                    Values newValue = modifyArrElement(Array.newArray, choiceNum, Array.newSize);
                    if (newValue.isChanged) {
                        cout << "Value changed from " << newValue.oldNum << " to " << newValue.newNum << endl;
                    }
                    else {
                        cout << "Error: index not found" << endl;
                    }
                }
            }
            break;

        case 4:
            // Add a new element (resizes array if full)
            Array = addingElements(Array.newArray, Array.newSize, numElements);
            break;

        case 5:
            // Remove an element by value
            Array = removeElements(Array.newArray, Array.newSize, numElements);
            break;

        case 6:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
    }

    // === Cleanup ===
    delete[] Array.newArray; // free heap memory
}


