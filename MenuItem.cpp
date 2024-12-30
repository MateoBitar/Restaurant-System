/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuItem.cpp
 * Author: Marco
 * 
 * Created on 19 November 2024, 3:31 pm
 */

/*-- MenuItem.cpp-----------------------------------------------------------
            This file implements MenuItem class member functions.
---------------------------------------------------------------------------*/

#include "MenuItem.h"

//--- Default Constructor
// Initializes a MenuItem with empty name, description, and a price of 0.0
MenuItem::MenuItem(){
    setMenuItem("", "", 0.0);
}

//--- Parameterized Constructor
// Initializes a MenuItem with the given name, description, and price
MenuItem::MenuItem(string name, string desc, double price){
    setMenuItem(name, desc, price);
}   

//--- Definition of setMenuItem()
// Sets the name, description, and price of the MenuItem
void MenuItem::setMenuItem(string name, string desc, double price){
    setName(name);
    setDescription(desc);
    setPrice(price);
}

//--- Definition of readMenuItem()
// Reads the details of a MenuItem from an input stream
void MenuItem::readMenuItem(istream& in){
    string inputName, inputDescription;
    double inputPrice;
    
    cout << "Enter Item name: ";
    in.ignore();
    getline(in, inputName);
    setName(inputName);
            
    cout << "Enter Item Description: ";
    in.ignore();
    getline(in, inputDescription);
    setDescription(inputDescription);
    
    cout << "Enter Item Price: ";
    in >> inputPrice;
    setPrice(inputPrice);
}

//--- Definition of setName()
// Sets the name of the MenuItem
void MenuItem::setName(string name){
    this->name = name;
}

//--- Definition of getName()
// Returns the name of the MenuItem
string MenuItem::getName() const{
    return name;
}

//--- Definition of setDescription()
// Sets the description of the MenuItem
void MenuItem::setDescription(string desc){
    this->desc = desc;
}

//--- Definition of getDescription()
// Returns the description of the MenuItem
string MenuItem::getDescription() const{
    return desc;
}

//--- Definition of setPrice()
// Sets the price of the MenuItem if the price is valid (> 0)
void MenuItem::setPrice(double price){
    if(price > 0){
        this->price = price;
    } else {
        price = 1; // Default to a minimum price of 1
    }
}

//--- Definition of getPrice()
// Returns the price of the MenuItem
double MenuItem::getPrice() const{
    return price;
}

//--- Definition of displayMenuItem()
// Displays the MenuItem's details
void MenuItem::displayMenuItem(ostream& out) const{
    cout << ", Name: " << name << ", Price: $" << price << endl;
}

//--- Definition of operator=
// Assigns one MenuItem's details to another
MenuItem& MenuItem::operator=(const MenuItem& other){
    if(this != &other){ // Avoid self-assignment
        name = other.name;
        desc = other.desc;
        price = other.price;
    }
    return *this;
}

//--- Definition of operator<<
// Outputs a MenuItem to an output stream
ostream& operator<< (ostream& out, const MenuItem& menuItem){
    menuItem.displayMenuItem(out);
    return out;
}

//--- Definition of operator>>
// Inputs a MenuItem from an input stream
istream& operator>>(istream& in, MenuItem& menuItem){
    menuItem.readMenuItem(in);
    return in;
}
