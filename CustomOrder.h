/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CustomOrder.h
 * Author: Marco
 *
 * Created on 19 November 2024, 3:26 pm
 */

/*-- CustomOrder.h ----------------------------------------------------------
  
  This header file defines a CustomOrder class for managing a queue of Orders.
  The class uses a linked list of nodes to store orders in a queue structure.
  Basic operations:
    Constructors:      Initializes a CustomOrder with an empty queue.
    enqueue:           Adds an Order to the queue.
    dequeue:           Removes and returns the first Order in the queue.
    isEmpty:           Checks if the queue is empty.
    search:            Searches for an Order by its ID.
    deleteOrder:       Deletes an Order by its ID.
    size:              Returns the number of Orders in the queue.
    displayCustomOrder: Displays the Orders in the queue.

  Friend Functions:
    operator<<:        Outputs the CustomOrder details to an ostream.

---------------------------------------------------------------------------*/

#ifndef CUSTOMORDER_H
#define CUSTOMORDER_H

#include <cstring>
#include <iostream>
#include "Order.h"
#include "Node.h"
using namespace std;

class CustomOrder {
private:
    /***** Data Members *****/
    int mySize;         // Number of Orders in the queue
    NodePtr myFront;      // Pointer to the first node of the queue
    NodePtr myBack;       // Pointer to the last node of the queue

public:
    /***** Constructors and Destructor *****/
    CustomOrder();
    /*------------------------------------------------------------------------
      Constructs an empty CustomOrder object (queue with no orders).

      Precondition:  None.
      Postcondition: A CustomOrder object is created with an empty queue.
    ------------------------------------------------------------------------*/

    ~CustomOrder();
    /*------------------------------------------------------------------------
      Destructor for CustomOrder.

      Precondition:  None.
      Postcondition: The queue is cleared and memory is freed.
    ------------------------------------------------------------------------*/

    /***** Member Functions *****/
    void enqueue(const Order&);
    /*------------------------------------------------------------------------
      Adds an Order to the back of the queue.

      Precondition:  A valid Order object is provided.
      Postcondition: The Order is added to the queue at the back.
    ------------------------------------------------------------------------*/

    Order dequeue();
    /*------------------------------------------------------------------------
      Removes and returns the Order at the front of the queue.

      Precondition:  The queue is not empty.
      Postcondition: The front Order is removed from the queue and returned.
    ------------------------------------------------------------------------*/

    bool isEmpty() const;
    /*------------------------------------------------------------------------
      Checks if the queue is empty.

      Precondition:  None.
      Postcondition: Returns true if the queue is empty, false otherwise.
    ------------------------------------------------------------------------*/

    NodePtr search(int);
    /*------------------------------------------------------------------------
      Searches for an Order by its ID.

      Precondition:  A valid order ID is provided.
      Postcondition: Returns the Node containing the Order with the matching ID,
          or nullptr if no such Order is found.
    ------------------------------------------------------------------------*/

    bool deleteOrder(int);
    /*------------------------------------------------------------------------
      Deletes an Order by its ID.

      Precondition:  A valid order ID is provided.
      Postcondition: The Order with the matching ID is removed from the queue.
          Returns true if successful, false otherwise.
    ------------------------------------------------------------------------*/

    int size();
    /*------------------------------------------------------------------------
      Returns the number of Orders in the queue.

      Precondition:  None.
      Postcondition: Returns the current size of the queue.
    ------------------------------------------------------------------------*/

    void displayCustomOrder(ostream&) const;
    /*------------------------------------------------------------------------
      Displays all the Orders in the queue.

      Precondition:  An open ostream is provided.
      Postcondition: The Orders in the queue are displayed in order from front
          to back of the queue.
    ------------------------------------------------------------------------*/
}; // end of class declaration

/***** Friend Functions *****/
ostream& operator<< (ostream&, const CustomOrder&);
/*------------------------------------------------------------------------
  Overloaded insertion operator.

  Precondition:  A valid CustomOrder object and an open ostream.
  Postcondition: Outputs the details of the CustomOrder to the ostream.
------------------------------------------------------------------------*/

#endif /* CUSTOMORDER_H */
