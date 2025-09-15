# Array Operations Program

This C++ program reads integers from a file into an array and allows the user to:
- Print all array values
- Check the index of a specific value
- Modify an existing value
- Add new elements (with automatic resizing)
- Exit the program

##  Requirements
- **Windows 10/11**
- **Visual Studio** (Community Edition or higher) with "Desktop development with C++" workload installed
- `input.txt` file containing integers (must be in the same folder as the executable)

##  Files
- `main.cpp` — Main program file containing the menu and logic
- `input.txt` — Input data file
- Additional `.cpp` and `.h` files for helper functions (if applicable)

##  How to Compile and Run (Windows, Visual Studio)

### 1. Open the Project
- Launch Visual Studio
- Open the `.sln` file for this project

### 2. Ensure `input.txt` is in the Correct Location
- Place `input.txt` in the same directory as the compiled `.exe` (usually in `x64\Debug` or `x64\Release` depending on your build settings)

### 3. Build the Program
- In Visual Studio, go to **Build → Build Solution** (or press `Ctrl + Shift + B`)
- Check the Output window for any compilation errors

### 4. Run the Program
- Press `Ctrl + F5` (Start Without Debugging) or click the green **Run** button
- The menu will appear in the console

### 5. Follow the Menu Prompts
1. **Print Array Values** — Displays all integers currently in the array  
2. **Check Array Index** — Enter a number to find its index in the array  
3. **Modify Array Element** — Change a specific value in the array  
4. **Add Elements to Array** — Append new integers (array resizes automatically if full)  
5. **Exit** — Ends the program

---

##  Notes
- The program starts with an initial array size of 100 elements, allocated on the heap for safe resizing.
- Adding elements beyond the current capacity will double the array size automatically.
- Memory is freed at program exit to prevent leaks.
- Accidentaly created a dynamic array to increase reusability and allow for doubling the size of an array to compinsate for the downfalls of an array.
