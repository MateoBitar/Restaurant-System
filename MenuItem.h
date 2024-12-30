/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuItem.h
 * Author: Marco
 *
 * Created on 19 November 2024, 3:31 pm
 */

/*-- MenuItem.h -------------------------------------------------------------
  
  This header file defines a MenuItem class.
  Basic operations:
    Constructor:      Constructs a default or parameterized MenuItem object.
    displayMenuItem:  Outputs the details of a MenuItem object.
    readMenuItem:     Inputs the details for a MenuItem object.
    setMenuItem:      Sets the name, description, and price of a MenuItem.
    Accessors:        Retrieve the name, description, or price of a MenuItem.
    Mutators:         Modify the name, description, or price of a MenuItem.
    Operator=:        Assigns one MenuItem object to another.

  Friend Functions:
    operator<<:       Outputs a MenuItem object to an ostream.
    operator>>:       Inputs a MenuItem object from an istream.

---------------------------------------------------------------------------*/

#ifndef MENUITEM_H
#define MENUITEM_H

#include <cstring>
#include <iostream>
using namespace std;

class MenuItem {
private:
    /***** Data Members *****/
    string name; // Name of the menu item
    string desc; // Description of the menu item
    double price; // Price of the menu item

public:
    /***** Constructors *****/
    MenuItem();
    /*------------------------------------------------------------------------
      Default constructor for MenuItem.

      Precondition:  None.
      Postcondition: A MenuItem object with empty name, empty description,
          and a price of 0.0 is created.
    ------------------------------------------------------------------------*/

    MenuItem(string, string, double);
    /*------------------------------------------------------------------------
      Parameterized constructor for MenuItem.

      Precondition:  Valid name, description, and price are provided.
      Postcondition: A MenuItem object is created with the given name,
          description, and price.
    ------------------------------------------------------------------------*/

    /***** Member Functions *****/
    void setMenuItem(string, string, double);
    /*------------------------------------------------------------------------
      Sets the name, description, and price of a MenuItem.

      Precondition:  Valid name, description, and price are provided.
      Postcondition: The MenuItem object is updated with the given values.
    ------------------------------------------------------------------------*/
    
    void readMenuItem(istream&);
    /*------------------------------------------------------------------------
      Reads the details of a MenuItem object from an istream.

      Precondition:  istream is open.
      Postcondition: Inputs the name, description, and price from the istream.
    ------------------------------------------------------------------------*/

    void setName(string);
    /*------------------------------------------------------------------------
      Sets the name of the MenuItem.

      Precondition:  A valid name is provided.
      Postcondition: The name of the MenuItem is updated.
    ------------------------------------------------------------------------*/

    string getName() const;
    /*------------------------------------------------------------------------
      Retrieves the name of the MenuItem.

      Precondition:  None.
      Postcondition: Returns the name of the MenuItem.
    ------------------------------------------------------------------------*/

    void setDescription(string);
    /*------------------------------------------------------------------------
      Sets the description of the MenuItem.

      Precondition:  A valid description is provided.
      Postcondition: The description of the MenuItem is updated.
    ------------------------------------------------------------------------*/

    string getDescription() const;
    /*------------------------------------------------------------------------
      Retrieves the description of the MenuItem.

      Precondition:  None.
      Postcondition: Returns the description of the MenuItem.
    ------------------------------------------------------------------------*/

    void setPrice(double);
    /*------------------------------------------------------------------------
      Sets the price of the MenuItem.

      Precondition:  A valid price is provided.
      Postcondition: The price of the MenuItem is updated.
    ------------------------------------------------------------------------*/

    double getPrice() const;
    /*------------------------------------------------------------------------
      Retrieves the price of the MenuItem.

      Precondition:  None.
      Postcondition: Returns the price of the MenuItem.
    ------------------------------------------------------------------------*/
    
    void displayMenuItem(ostream&) const;
    /*------------------------------------------------------------------------
      Displays the details of a MenuItem object.

      Precondition:  ostream is open.
      Postcondition: Outputs the name, description, and price to the ostream.
    ------------------------------------------------------------------------*/

    MenuItem& operator= (const MenuItem&);
    /*------------------------------------------------------------------------
      Overloaded assignment operator.

      Precondition:  A valid MenuItem object is provided.
      Postcondition: The current MenuItem object is assigned the values of
          the provided MenuItem object.
    ------------------------------------------------------------------------*/
}; // end of class declaration

/***** Friend Functions *****/
ostream& operator<< (ostream&, const MenuItem&);
/*------------------------------------------------------------------------
  Overloaded insertion operator.

  Precondition:  A valid MenuItem object and an open ostream.
  Postcondition: Outputs the details of the MenuItem object to the ostream.
------------------------------------------------------------------------*/

istream& operator>> (istream&, MenuItem&);
/*------------------------------------------------------------------------
  Overloaded extraction operator.

  Precondition:  A valid MenuItem object and an open istream.
  Postcondition: Inputs the details for the MenuItem object from the istream.
------------------------------------------------------------------------*/

#endif /* MENUITEM_H */
