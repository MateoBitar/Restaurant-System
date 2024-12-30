/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CustomOrder.cpp
 * Author: Marco
 * 
 * Created on 19 November 2024, 3:26 pm
 */

/*-- CustomOrder.cpp-----------------------------------------------------------
            This file implements the CustomOrder class member functions.
----------------------------------------------------------------------------*/

#include "CustomOrder.h"
#include "Node.h"

//--- Constructor
// Initializes the custom order queue as empty with no orders.
CustomOrder::CustomOrder() {
    myFront = NULL; // Front of the queue is initially NULL
    myBack = NULL; // Back of the queue is initially NULL
    mySize = 0; // Queue size is 0
}

//--- Destructor
// Clears the queue by dequeuing all orders.
CustomOrder::~CustomOrder() {
    while (!isEmpty()) { // While the queue is not empty
        dequeue(); // Dequeue each order
    }
}

//--- Definition of enqueue()
// Adds an Order to the back of the queue.
void CustomOrder::enqueue(const Order& order) {
    NodePtr customOrder = new Node(order); // Create a new node for the order
    if (isEmpty()) { // If the queue is empty, both front and back point to the new node
        myFront = customOrder;
        myBack = customOrder; 
        mySize++; // Increment the size
        return;
    }
    
    myBack->setNext(customOrder); // Set the next of the current back node to the new node
    myBack = customOrder; // Update the back pointer to the new node
    mySize++; // Increment the size
}

//--- Definition of dequeue()
// Removes and returns the order at the front of the queue.
Order CustomOrder::dequeue() {
    if (!isEmpty()) { // If the queue is not empty
        NodePtr temp = myFront; // Store the current front node
        myFront = myFront->getNext(); // Move the front pointer to the next node
        
        if (myFront == NULL) { // If the front is now NULL, set back to NULL
            myBack = NULL;
        }
        
        temp->setNext(NULL); // Disconnect the node from the list
        mySize--; // Decrease the size
        return temp->getData(); // Return the data from the front node
    }
    
    Order garbage; // Return a garbage order if the queue is empty
    return garbage;
}

//--- Definition of isEmpty()
// Returns true if the queue is empty, false otherwise.
bool CustomOrder::isEmpty() const {
    if (mySize == 0) { // If size is 0, the queue is empty
        return true;
    }
    return false;
}

//--- Definition of search()
// Searches for an order in the queue based on orderId and returns the node containing it.
NodePtr CustomOrder::search(int orderId) {
    NodePtr temp = myFront; // Start from the front of the queue
    while (temp != NULL) { // Traverse through the queue
        if (temp->getData().getOrderId() == orderId) { // If orderId matches
            return temp; // Return the node containing the order
        }
        temp = temp->getNext(); // Move to the next node
    }

    return temp; // Return NULL if the order is not found
}

//--- Definition of deleteOrder()
// Deletes an order from the queue based on orderId.
bool CustomOrder::deleteOrder(int orderId) {
    NodePtr temp = search(orderId); // Search for the order in the queue
    
    if (isEmpty() || temp == NULL) { // If the queue is empty or order not found
        return false; // Return false
    } else if (temp == myFront) { // If the order to delete is at the front
        myFront = myFront->getNext(); // Move the front pointer to the next node
        if (myFront == NULL) { // If the front is now NULL, set back to NULL
            myBack = NULL;
        }
    } else { // If the order is somewhere in the middle or back
        NodePtr prev = myFront; // Start from the front
        // Find the node before the node to be deleted
        while (prev->getNext() != temp) {
            prev = prev->getNext();
        }
        
        prev->setNext(temp->getNext()); // Remove the node from the list
        
        if (temp == myBack) { // If the order was at the back
            myBack = prev; // Update the back pointer to the previous node
        }
    }
    
    delete temp; // Delete the node
    mySize--; // Decrease the size of the queue
    return true; // Return true to indicate the order was deleted
}

//--- Definition of size()
// Returns the current number of orders in the queue.
int CustomOrder::size() {
    return mySize; // Return the current size of the queue
}

//--- Definition of displayCustomOrder()
// Displays all the orders in the queue with their details.
void CustomOrder::displayCustomOrder(ostream& out) const {
    if (isEmpty()) { // If the queue is empty, display a message
        out << "No active orders" << endl;
    } else { // Otherwise, display the orders
        out << "--- Active Orders ---" << endl;
        NodePtr temp = myFront; // Start from the front of the queue
        while (temp != NULL) { // Traverse through the queue
            temp->getData().displayOrder(out); // Display the order details
            out << "Status: Pending" << endl; // Indicate that the order is pending
            out << endl;
            temp = temp->getNext(); // Move to the next node
        }
    }
}

//--- Definition of operator<<
// Outputs the custom order queue to an output stream.
ostream& operator<< (ostream& out, const CustomOrder& custOrder) {
    custOrder.displayCustomOrder(out); // Call displayCustomOrder() to print all orders
    return out; // Return the output stream
}

