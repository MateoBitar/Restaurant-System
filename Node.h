/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: Marco
 *
 * Created on 19 November 2024, 3:56 pm
 */

/*-- Node.h -----------------------------------------------------------------
  
  This header file defines a Node class for use in a linked list structure.
  Basic operations:
    Constructor:      Creates a Node with a given data element.
    setData:          Updates the data stored in the Node.
    getData:          Retrieves the data stored in the Node.
    setNext:          Updates the pointer to the next Node.
    getNext:          Retrieves the pointer to the next Node.

  Type Definitions:
    ElementType:      Alias for the type of data stored in the Node (Order).
    NodePtr:          Alias for a pointer to a Node object.

---------------------------------------------------------------------------*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Order.h"
using namespace std;

typedef Order ElementType; // Defines the type of data stored in the Node

class Node {
private:
    /***** Data Members *****/
    ElementType data; // Data stored in the Node
    Node* next;       // Pointer to the next Node in the list

public:
    /***** Constructor *****/
    Node(const ElementType&);
    /*------------------------------------------------------------------------
      Constructs a Node object with the given data element.

      Precondition:  A valid ElementType object is provided.
      Postcondition: The Node is created with the given data, and the next
          pointer is initialized to nullptr.
    ------------------------------------------------------------------------*/

    /***** Member Functions *****/
    void setData(const ElementType&);
    /*------------------------------------------------------------------------
      Sets the data stored in the Node.

      Precondition:  A valid ElementType object is provided.
      Postcondition: The data of the Node is updated to the provided value.
    ------------------------------------------------------------------------*/

    ElementType& getData();
    /*------------------------------------------------------------------------
      Retrieves the data stored in the Node.

      Precondition:  None.
      Postcondition: Returns a reference to the data stored in the Node.
    ------------------------------------------------------------------------*/

    void setNext(Node*);
    /*------------------------------------------------------------------------
      Sets the pointer to the next Node.

      Precondition:  A valid Node pointer is provided.
      Postcondition: The next pointer is updated to the provided value.
    ------------------------------------------------------------------------*/

    Node* getNext();
    /*------------------------------------------------------------------------
      Retrieves the pointer to the next Node.

      Precondition:  None.
      Postcondition: Returns the pointer to the next Node, or nullptr if
          there is no next Node.
    ------------------------------------------------------------------------*/
}; // end of class declaration

typedef Node* NodePtr; // Alias for a pointer to a Node object

#endif /* NODE_H */
