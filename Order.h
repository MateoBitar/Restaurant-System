/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Order.h
 * Author: Marco
 *
 * Created on 19 November 2024, 3:27 pm
 */

/*-- Order.h ----------------------------------------------------------------
  
  This header file defines an Order class for managing customer orders with a
  list of ordered items.
  Basic operations:
    Constructors:     Initializes an Order with default or provided values.
    setOrder:         Sets the order details (ID, customer name, items, size).
    Accessors:        Retrieves order information like ID, customer name, 
                      order size, and total amount.
    Mutators:         Modifies order properties such as ID, customer name, 
                      order size, and individual items.
    calculateTotalAmount: Computes the total amount of the order based on its items.
    displayOrder:     Displays the details of the order.

  Friend Functions:
    operator<<:       Outputs the Order details to an ostream.

---------------------------------------------------------------------------*/

#ifndef ORDER_H
#define ORDER_H

#include <cstring>
#include <iostream>
#include "MenuItem.h"
using namespace std;

class Order {
private:
    /***** Data Members *****/
    int orderId;        // Unique identifier for the order
    int orderSize;      // Number of items in the order
    int myCapacity;     // Capacity for the number of MenuItems
    string custName;    // Customer's name
    MenuItem* items;    // Array of MenuItem objects for the order
    double totalAmount; // Total amount of the order

public:
    /***** Constructors *****/
    Order();
    /*------------------------------------------------------------------------
      Default constructor for Order.

      Precondition:  None.
      Postcondition: An Order object with default values (empty items and
          total amount set to 0) is created.
    ------------------------------------------------------------------------*/

    Order(int, string, MenuItem*, int);
    /*------------------------------------------------------------------------
      Parameterized constructor for Order.

      Precondition:  Valid order ID, customer name, array of MenuItems, and
          order size are provided.
      Postcondition: An Order object is created with the provided details.
    ------------------------------------------------------------------------*/

    /***** Member Functions *****/
    void setOrder(int, string, MenuItem*, int);
    /*------------------------------------------------------------------------
      Sets the order details (ID, customer name, items, size).

      Precondition:  Valid order ID, customer name, array of MenuItems, and
          order size are provided.
      Postcondition: The Order object is updated with the given values.
    ------------------------------------------------------------------------*/

    void setOrderId(int);
    /*------------------------------------------------------------------------
      Sets the order ID.

      Precondition:  A valid order ID is provided.
      Postcondition: The order ID is updated.
    ------------------------------------------------------------------------*/

    int getOrderId() const;
    /*------------------------------------------------------------------------
      Retrieves the order ID.

      Precondition:  None.
      Postcondition: Returns the order ID of the Order object.
    ------------------------------------------------------------------------*/

    void setCustName(string);
    /*------------------------------------------------------------------------
      Sets the customer name.

      Precondition:  A valid customer name is provided.
      Postcondition: The customer name is updated.
    ------------------------------------------------------------------------*/

    string getCustName() const;
    /*------------------------------------------------------------------------
      Retrieves the customer name.

      Precondition:  None.
      Postcondition: Returns the customer name of the Order object.
    ------------------------------------------------------------------------*/

    void setOrderSize(int);
    /*------------------------------------------------------------------------
      Sets the size (number of items) of the order.

      Precondition:  A valid order size is provided.
      Postcondition: The order size is updated.
    ------------------------------------------------------------------------*/

    int getOrderSize() const;
    /*------------------------------------------------------------------------
      Retrieves the number of items in the order.

      Precondition:  None.
      Postcondition: Returns the order size of the Order object.
    ------------------------------------------------------------------------*/

    void calculateTotalAmount(MenuItem*, int);
    /*------------------------------------------------------------------------
      Calculates the total amount of the order.

      Precondition:  A valid array of MenuItems and the number of items are
          provided.
      Postcondition: The total amount is calculated based on the items and
          their prices.
    ------------------------------------------------------------------------*/

    double getTotalAmount() const;
    /*------------------------------------------------------------------------
      Retrieves the total amount of the order.

      Precondition:  None.
      Postcondition: Returns the total amount of the Order object.
    ------------------------------------------------------------------------*/

    bool addOrderItem(MenuItem&);
    /*------------------------------------------------------------------------
      Adds a MenuItem to the order.

      Precondition:  A valid MenuItem is provided.
      Postcondition: The MenuItem is added to the order. If the order exceeds
          its capacity, an error is handled.
    ------------------------------------------------------------------------*/
    
    MenuItem& getOrderItem(int) const;
    /*------------------------------------------------------------------------
      Retrieves a specific MenuItem from the order.

      Precondition:  A valid index within the order size.
      Postcondition: Returns a reference to the MenuItem at the specified index.
    ------------------------------------------------------------------------*/

    void displayOrder(ostream&) const;
    /*------------------------------------------------------------------------
      Displays the details of the order.

      Precondition:  An open ostream is provided.
      Postcondition: The order details, including the customer name, item
          details, and total amount, are output to the ostream.
    ------------------------------------------------------------------------*/

    Order& operator=(const Order&);
    /*------------------------------------------------------------------------
      Overloaded assignment operator.

      Precondition:  A valid Order object is provided.
      Postcondition: The current Order object is assigned the values of the
          provided Order object.
    ------------------------------------------------------------------------*/
}; // end of class declaration

/***** Friend Functions *****/
ostream& operator<< (ostream&, const Order&);
/*------------------------------------------------------------------------
  Overloaded insertion operator.

  Precondition:  A valid Order object and an open ostream.
  Postcondition: Outputs the details of the Order object to the ostream.
------------------------------------------------------------------------*/

#endif /* ORDER_H */
