/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.h
 * Author: Marco
 *
 * Created on 19 November 2024, 3:31 pm
 */

/*-- Menu.h -----------------------------------------------------------------
  
  This header file defines a Menu class for managing a dynamic list of menu items.
  Basic operations:
    Constructor:      Initializes a Menu with a given capacity.
    addItem:          Adds a MenuItem to the Menu.
    removeItem:       Removes a MenuItem at a specific index.
    clear:            Clears all MenuItems from the Menu.
    getMenuItem:      Retrieves a MenuItem at a specific index.
    size:             Returns the current number of items in the Menu.
    saveToFile:       Saves the Menu items to a file.
    loadFromFile:     Loads Menu items from a file.
    displayMenu:      Displays the Menu contents.

  Friend Functions:
    operator<<:       Outputs the Menu contents to an ostream.

---------------------------------------------------------------------------*/

#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <fstream>
#include "MenuItem.h"
using namespace std;

class Menu {
private:
    /***** Data Members *****/
    int mySize;                // Current number of items in the Menu
    unsigned myCapacity;       // Maximum capacity of the Menu
    MenuItem* items;           // Dynamic array of MenuItem objects

public:
    /***** Constructor *****/
    Menu(unsigned);
    /*------------------------------------------------------------------------
      Constructs a Menu object with a specified capacity.

      Precondition:  A valid unsigned integer capacity is provided.
      Postcondition: A Menu object is created with an empty list of MenuItems
          and the specified maximum capacity.
    ------------------------------------------------------------------------*/

    /***** Member Functions *****/
    bool addItem(MenuItem);
    /*------------------------------------------------------------------------
      Adds a MenuItem to the Menu.

      Precondition:  A valid MenuItem object is provided, and there is space
          in the Menu.
      Postcondition: The MenuItem is added to the Menu. Returns true if the
          addition is successful, false otherwise.
    ------------------------------------------------------------------------*/

    bool removeItem(int);
    /*------------------------------------------------------------------------
      Removes a MenuItem at the specified index.

      Precondition:  A valid index within the current size of the Menu.
      Postcondition: The MenuItem at the given index is removed, and the
          remaining items are shifted accordingly. Returns true if successful,
          false otherwise.
    ------------------------------------------------------------------------*/

    MenuItem& getMenuItem(int) const;
    /*------------------------------------------------------------------------
      Retrieves a MenuItem at the specified index.

      Precondition:  A valid index within the current size of the Menu.
      Postcondition: Returns a reference to the MenuItem at the given index.
    ------------------------------------------------------------------------*/
    
    void clear();
    /*------------------------------------------------------------------------
      Clears all items from the Menu.

      Precondition:  None.
      Postcondition: All MenuItems are removed, and the Menu size is reset to 0.
    ------------------------------------------------------------------------*/

    int size();
    /*------------------------------------------------------------------------
      Retrieves the current number of items in the Menu.

      Precondition:  None.
      Postcondition: Returns the number of MenuItems currently in the Menu.
    ------------------------------------------------------------------------*/

    void saveToFile(const char*);
    /*------------------------------------------------------------------------
      Saves the Menu items to a file.

      Precondition:  A valid file path is provided.
      Postcondition: The Menu items are written to the specified file.
    ------------------------------------------------------------------------*/

    void loadFromFile(const char*);
    /*------------------------------------------------------------------------
      Loads Menu items from a file.

      Precondition:  A valid file path is provided.
      Postcondition: The Menu is populated with the items from the file,
          overwriting existing items.
    ------------------------------------------------------------------------*/

    void displayMenu(ostream&) const;
    /*------------------------------------------------------------------------
      Displays the contents of the Menu.

      Precondition:  An open ostream is provided.
      Postcondition: The Menu items are written to the ostream in a readable
          format.
    ------------------------------------------------------------------------*/
}; // end of class declaration

/***** Friend Functions *****/
ostream& operator<< (ostream&, const Menu&);
/*------------------------------------------------------------------------
  Overloaded insertion operator.

  Precondition:  A valid Menu object and an open ostream.
  Postcondition: Outputs the contents of the Menu to the ostream.
------------------------------------------------------------------------*/

#endif /* MENU_H */
