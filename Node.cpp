/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: Marco
 * 
 * Created on 19 November 2024, 3:56 pm
 */

/*-- Node.cpp---------------------------------------------------------------
            This file implements the Node class member functions.
---------------------------------------------------------------------------*/

#include "Node.h"

//--- Definition of Node Constructor
// Initializes a Node with the given data and sets the next pointer to NULL
Node::Node(const ElementType& n){
    data = n;
    next = NULL;
}

//--- Definition of setData()
// Sets the data value of the Node
void Node::setData(const ElementType& n){
    this->data = n;
}

//--- Definition of getData()
// Returns a reference to the data stored in the Node
ElementType& Node::getData(){
    return data;
}

//--- Definition of setNext()
// Sets the next pointer of the Node
void Node::setNext(NodePtr newNext){
    next = newNext;
}

//--- Definition of getNext()
// Returns the next pointer of the Node
NodePtr Node::getNext(){
    return next;
}
