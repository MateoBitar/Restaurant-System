/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: Marco
 * 
 * Created on 19 November 2024, 3:31 pm
 */

/*-- Menu.cpp---------------------------------------------------------------
            This file implements the Menu class member functions.
---------------------------------------------------------------------------*/

#include "Menu.h"

//--- Constructor
// Initializes the Menu with a given capacity and allocates memory for items array
Menu::Menu(unsigned capacity) {
    mySize = 0; // Initialize size to 0
    myCapacity = capacity; // Set the initial capacity
    items = new MenuItem[myCapacity]; // Allocate memory for items array
}

//--- Definition of addItem()
// Adds a MenuItem to the Menu. If capacity is reached, it dynamically increases the capacity.
bool Menu::addItem(MenuItem item) {
    if (mySize == myCapacity) { // Check if capacity is reached
        // Double the capacity and allocate new memory for items array
        MenuItem* temp = new MenuItem[myCapacity * 2]; 
        for (int i = 0; i < myCapacity; i++) {
            temp[i] = items[i]; // Copy existing items to the new array
        }
        delete[] items; // Free the old memory
        items = temp; // Point to the new array
        myCapacity *= 2; // Double the capacity
    }
    items[mySize] = item; // Add the new item
    mySize++; // Increment the size
    return true;
}

//--- Definition of removeItem()
// Removes a MenuItem from the Menu based on its id by shifting the remaining items
bool Menu::removeItem(int id) {
    // Shift items starting from the given id position
    for (int i = id - 1; i < mySize - 1; i++) {
        items[i] = items[i + 1]; // Move items to the left
    }
    mySize--; // Decrement the size
    return true;
}

//--- Definition of getMenuItem()
// Retrieves a MenuItem based on its id. Returns a garbage MenuItem if not found.
MenuItem& Menu::getMenuItem(int id) const {
    int i = 0;
    while (i < mySize) {
        if (i == id - 1) // If id matches, return the item
            return items[i];
        i++;
    }
    MenuItem garbage; // Return a garbage item if id is not found
    return garbage;
}

//--- Definition of clear()
// Clears the Menu, resetting size and capacity and deallocating memory for items array
void Menu::clear() {
    mySize = 0; // Reset size to 0
    myCapacity = 0; // Reset capacity to 0
    delete[] items; // Free the memory allocated for items array
}

//--- Definition of size()
// Returns the current number of items in the Menu
int Menu::size() {
    return mySize; // Return the current size
}

//--- Definition of saveToFile()
// Saves the Menu items to a file in CSV format (id, name, description, price)
void Menu::saveToFile(const char* fileName) {
    ofstream outputFile; // Create an output file stream
    
    outputFile.open(fileName); // Open the file for writing
    if (!outputFile.is_open()) { // If file can't be opened, show an error
        cerr << "Failed to open file: " << fileName << endl;
        return;
    }
    
    // Write each MenuItem to the file
    for (int i = 0; i < mySize; i++) {
        outputFile << i + 1 << "," << items[i].getName() 
                << "," << items[i].getDescription() << "," 
                << items[i].getPrice() << endl;
    }
    
    outputFile.close(); // Close the file after writing
}

//--- Definition of loadFromFile()
// Loads Menu items from a file (CSV format) and adds them to the Menu
void Menu::loadFromFile(const char* fileName) {
    ifstream inputFile; // Create an input file stream
    
    inputFile.open(fileName); // Open the file for reading
    if (!inputFile.is_open()) { // If file can't be opened, show an error
        cerr << "Failed to open file: " << fileName << endl;
        exit(1); // Exit the program if file cannot be opened
    }
    
    string line;
    // Read each line from the file and parse the data
    while (getline(inputFile, line)) {
        int comma1 = line.find(','); // Find the position of the first comma
        int comma2 = line.find(',', comma1 + 1); // Find the position of the second comma
        int comma3 = line.find(',', comma2 + 1); // Find the position of the third comma

        if (comma1 == -1 || comma2 == -1 || comma3 == -1) { // If any comma is missing, print an error and continue
            cerr << "Invalid line format: " << line << endl;
            continue;
        }

        // Extract data from the line
        string id = line.substr(0, comma1); // Extract id (though not used)
        string name = line.substr(comma1 + 1, comma2 - comma1 - 1); // Extract name
        string desc = line.substr(comma2 + 1, comma3 - comma2 - 1); // Extract description
        string priceStr = line.substr(comma3 + 1); // Extract price as a string

        double price = atof(priceStr.c_str()); // Convert price string to double

        addItem(MenuItem(name, desc, price)); // Add the MenuItem to the Menu
    }
    
    inputFile.close(); // Close the file after reading
}

//--- Definition of displayMenu()
// Displays the Menu items, showing their id, name, description, and price
void Menu::displayMenu(ostream& out) const {
    out << "--- Menu Items ---" << endl; // Print a header
    for (int i = 0; i < mySize; i++) {
        out << "ID: " << i + 1 << items[i]; // Print each MenuItem's id, name, description, and price
    }
}

//--- Definition of operator<<
// Outputs the Menu items to an output stream
ostream& operator<< (ostream& out, const Menu& m) {
    m.displayMenu(out); // Call displayMenu() to print the menu items
    return out;
}

