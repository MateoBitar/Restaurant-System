/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Order.cpp
 * Author: Marco
 * 
 * Created on 19 November 2024, 3:27 pm
 */

/*-- Order.cpp--------------------------------------------------------------
            This file implements the Order class member functions.
---------------------------------------------------------------------------*/

#include "Order.h"

//--- Default Constructor
// Initializes an Order with default values for orderId, customer name, 
// items array, and order size
Order::Order(){
    setOrder(-1, "", NULL, 0);
}

//--- Parameterized Constructor
// Initializes an Order with the given orderId, customer name, items, and order size
Order::Order(int orderId, string custName, MenuItem* items, int orderSize){
    setOrder(orderId, custName, items, orderSize);
}

//--- Definition of setOrder()
// Sets the details of an Order including orderId, customer name, order size, 
// and calculates the total amount for the order
void Order::setOrder(int orderId, string custName, MenuItem* items, int orderSize){
    setOrderId(orderId);
    setCustName(custName);
    setOrderSize(orderSize);
    calculateTotalAmount(items, orderSize);
    myCapacity = 10; // Initial capacity of items array
    
    this->items = new MenuItem[myCapacity]; // Dynamically allocate memory for items
    for(int i = 0; i < orderSize; i++){
        this->items[i] = items[i]; // Copy the items into the new array
    }
}

//--- Definition of setOrderId()
// Sets the orderId for the Order
void Order::setOrderId(int orderId){
    this->orderId = orderId;
}

//--- Definition of getOrderId()
// Returns the orderId of the Order
int Order::getOrderId() const{
    return orderId;
}

//--- Definition of setCustName()
// Sets the customer name for the Order
void Order::setCustName(string custName){
    this->custName = custName;
}

//--- Definition of getCustName()
// Returns the customer name for the Order
string Order::getCustName() const{
    return custName;
}

//--- Definition of setOrderSize()
// Sets the number of items in the Order
void Order::setOrderSize(int orderSize){
    this->orderSize = orderSize;
}

//--- Definition of getOrderSize()
// Returns the number of items in the Order
int Order::getOrderSize() const{
    return orderSize;
}

//--- Definition of calculateTotalAmount()
// Calculates the total amount by summing the prices of all items in the order
void Order::calculateTotalAmount(MenuItem* items, int orderSize){
    totalAmount = 0; // Reset before calculation
    
    for(int i = 0; i < orderSize; i++){
        totalAmount += items[i].getPrice(); // Add price of each item
    }
}

//--- Definition of getTotalAmount()
// Returns the total amount for the Order
double Order::getTotalAmount() const{
    return totalAmount;
}

//--- Definition of addOrderItem()
// Adds a new MenuItem to the order. If necessary, reallocates the items array 
// to accommodate more items
bool Order::addOrderItem(MenuItem& item) {
    if(orderSize == myCapacity){ // Check if there is space for a new item
        myCapacity *= 2; // Double the capacity of items array
        MenuItem* temp = new MenuItem [myCapacity]; // Create new larger array
        
        for(int i = 0; i < orderSize; i++){
            temp[i] = items[i]; // Copy existing items to the new array
        }
        
        delete[] items; // Free old memory
        items = temp; // Point to the new array
    }
    
    if(items == NULL){ // Check if items array is still null
        items = new MenuItem[myCapacity]; // Allocate memory for items array
    }
    
    items[orderSize] = item; // Add the new item to the array
    orderSize++; // Increment the order size
    return true;
}

//--- Definition of getOrderItem()
// Returns a reference to the MenuItem at the given position in the order
MenuItem& Order::getOrderItem(int pos) const {
    return items[pos];
}

//--- Definition of displayOrder()
// Displays the details of the Order including orderId, customer name, 
// and list of ordered items with their prices
void Order::displayOrder(ostream& out) const{
    out << "Order ID: " << orderId <<
            ", Customer: " << custName << endl <<
            "Items: " << endl;
    
    for(int i = 0; i < orderSize; i++){
        out << "  - " << items[i].getName() << "($" << items[i].getPrice() 
                << ")" << endl; // Display each item with its price
    }
}

//--- Definition of operator=
// Assigns one Order's details to another, ensuring deep copy of dynamic memory
Order& Order::operator=(const Order& other){
    if(this != &other){ // Avoid self-assignment
        delete[] items; // Free old memory
        
        myCapacity = other.myCapacity;
        orderId = other.orderId;
        custName = other.custName;
        orderSize = other.orderSize;
        totalAmount = other.totalAmount;
        
        items = new MenuItem[myCapacity]; // Allocate new memory for items array
        for (int i = 0; i < other.orderSize; ++i) {
            items[i] = other.items[i]; // Copy items from the other order
        }
    }
    
    return *this;
}

//--- Definition of operator<<
// Outputs the details of an Order to an output stream
ostream& operator<< (ostream& out, const Order& order){
    order.displayOrder(out); // Call displayOrder() to print the order details
    return out;
}

