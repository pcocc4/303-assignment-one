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
    ifstream inFile("input.txt");

    if (!inFile) {
        cerr << "Unable to open file input.txt";
        return 1; // terminate with error
    }

    const int size = 100;

    // this is to keep track of the most recent position of a value in the array
    int numElements = 100; // ✅ Start at 0, not size

    int* arr = new int[size]; // ✅ Allocate on heap

    newArr Array;
    Array.newSize = size;
    Array.newArray = arr;

    processFile(inFile, arr, size);

    int choice = 0;
    string userInput, choiceInput;

    while (choice != 6) {
        cout << "\n=== Array Operations Menu ===" << endl;
        cout << "1. Print Array Values" << endl;
        cout << "2. Check Array Index" << endl;
        cout << "3. Modify Array Element" << endl;
        cout << "4. Add Elements to Array" << endl;
		cout << "5. Remove Elements from Array" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";

        cin >> choice;

        // Validate input: must be a number between 1 and 5
        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\nInvalid input. Please enter a number between 1 and 5." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            cout << "You selected: Print Array Values" << endl;
            cout << "Array contents:" << endl;
            for (int i = 0; i < numElements; ++i) {
                cout << Array.newArray[i] << " "; // ✅ Use Array.newArray instead of arr
            }
            cout << endl;
            break;
        case 2:
            cout << "You selected: Check Array Index" << endl;
            int result;
            int index;
            cout << "Please type an integer that you would like to check: " << endl;
            cin >> userInput;
            result = convertToInt(userInput);
            if (result != -1) {
                index = checkIndex(result, Array.newArray, Array.newSize); // ✅ Use Array.newArray
                if (index != -1) { cout << "The index of the number you entered is: " << index << endl; }
                else { cout << result << " is not in the array" << endl; }
               
            }
            else {
                cout << "Conversion failed." << std::endl;
            }
            break;
        case 3:
            cout << "You selected: Modify Array Element" << endl;
            int choiceNum;
            cout << "Please type an integer that you would like to modify: " << endl;
            cin >> choiceInput;
            choiceNum = convertToInt(choiceInput);
            if (choiceNum != -1) {
                Values newValue = modifyArrElement(Array.newArray, choiceNum, Array.newSize); // ✅ Use Array.newArray
                if (newValue.isChanged) {
                    cout << "Value changed from " << newValue.oldNum << " to " << newValue.newNum << endl;
                }
                else {
                    cout << "Value not found in the array." << endl;
                }
            }
            break;
        case 4:
            cout << "You selected: Add Elements to Array" << endl;
            Array = addingElements(Array.newArray, Array.newSize, numElements); // ✅ Update Array.newArray
            break;
		case 5:
			cout << "You selected: Remove Elements from Array" << endl;
			Array = removeElements(Array.newArray, Array.newSize, numElements); // ✅ Update Array.newArray
			break;
        case 6:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
    }

    delete[] Array.newArray; // ✅ Free heap memory before exiting
}


