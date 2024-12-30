/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CompletedOrder.h
 * Author: Marco
 *
 * Created on 19 November 2024, 3:32 pm
 */

/*-- CompletedOrder.h -------------------------------------------------------
  
  This header file defines the CompletedOrder class for managing completed
  orders. The class uses a linked list to store orders that have been completed.
  Basic operations:
    Constructors:        Initializes an empty CompletedOrder list.
    addCompletedOrder:   Adds an Order to the list of completed orders.
    removeCompletedOrder: Removes and returns an Order from the completed list.
    isEmpty:             Checks if the list of completed orders is empty.
    totalAmountSold:     Calculates the total amount of all completed orders.
    saveToFile:          Saves the list of completed orders to a file.
    loadFromFile:        Loads completed orders from a file.
    search:              Searches for a completed order by its ID.
    size:                Returns the number of completed orders.
    displayCompletedOrders: Displays all completed orders.
    displayRevenue:      Displays the total revenue from completed orders.

  Friend Functions:
    operator<<:          Outputs the CompletedOrder details to an ostream.

---------------------------------------------------------------------------*/

#ifndef COMPLETEDORDER_H
#define COMPLETEDORDER_H

#include <iostream>
#include <fstream>
#include "Order.h"
#include "Node.h"
using namespace std;

class CompletedOrder {
private:
    /***** Data Members *****/
    NodePtr myTop;        // Pointer to the top node of the completed orders list
    int mySize;         // Number of completed orders in the list

public:
    /***** Constructors and Destructor *****/
    CompletedOrder();
    /*------------------------------------------------------------------------
      Constructs an empty CompletedOrder object (no completed orders).

      Precondition:  None.
      Postcondition: A CompletedOrder object is created with no completed orders.
    ------------------------------------------------------------------------*/

    ~CompletedOrder();
    /*------------------------------------------------------------------------
      Destructor for CompletedOrder.

      Precondition:  None.
      Postcondition: The completed orders list is cleared and memory is freed.
    ------------------------------------------------------------------------*/

    /***** Member Functions *****/
    bool isEmpty() const;
    /*------------------------------------------------------------------------
      Checks if the list of completed orders is empty.

      Precondition:  None.
      Postcondition: Returns true if the list is empty, false otherwise.
    ------------------------------------------------------------------------*/

    void addCompletedOrder(Order);
    /*------------------------------------------------------------------------
      Adds a completed order to the list.

      Precondition:  A valid Order object is provided.
      Postcondition: The Order is added to the list of completed orders.
    ------------------------------------------------------------------------*/

    Order removeCompletedOrder();
    /*------------------------------------------------------------------------
      Removes and returns a completed order from the list.

      Precondition:  The list is not empty.
      Postcondition: The completed order is removed from the list and returned.
    ------------------------------------------------------------------------*/

    double totalAmountSold();
    /*------------------------------------------------------------------------
      Calculates the total amount of all completed orders.

      Precondition:  None.
      Postcondition: Returns the total amount of all completed orders.
    ------------------------------------------------------------------------*/

    NodePtr search(int) const;
    /*------------------------------------------------------------------------
      Searches for a completed order by its ID.

      Precondition:  A valid order ID is provided.
      Postcondition: Returns a pointer to the Node containing the completed order
          with the matching ID, or nullptr if no such order is found.
    ------------------------------------------------------------------------*/

    int size();
    /*------------------------------------------------------------------------
      Returns the number of completed orders.

      Precondition:  None.
      Postcondition: Returns the number of completed orders in the list.
    ------------------------------------------------------------------------*/

    void saveToFile(const char*);
    /*------------------------------------------------------------------------
      Saves the list of completed orders to a file.

      Precondition:  A valid file path is provided.
      Postcondition: The completed orders are saved to the specified file.
    ------------------------------------------------------------------------*/

    void loadFromFile(const char*);
    /*------------------------------------------------------------------------
      Loads completed orders from a file.

      Precondition:  A valid file path is provided.
      Postcondition: The completed orders are loaded from the specified file.
    ------------------------------------------------------------------------*/    
    
    void displayRevenue();
    /*------------------------------------------------------------------------
      Displays the total revenue from all completed orders.

      Precondition:  None.
      Postcondition: The total revenue is displayed.
    ------------------------------------------------------------------------*/    
    
    void displayCompletedOrders(ostream&) const;
    /*------------------------------------------------------------------------
      Displays all completed orders.

      Precondition:  An open ostream is provided.
      Postcondition: All completed orders are displayed to the ostream.
    ------------------------------------------------------------------------*/

}; // end of class declaration

/***** Friend Functions *****/
ostream& operator<< (const ostream&, const CompletedOrder&);
/*------------------------------------------------------------------------
  Overloaded insertion operator.

  Precondition:  A valid CompletedOrder object and an open ostream.
  Postcondition: Outputs the details of the CompletedOrder object to the ostream.
------------------------------------------------------------------------*/

#endif /* COMPLETEDORDER_H */

