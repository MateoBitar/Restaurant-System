/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CompletedOrder.cpp
 * Author: Marco
 * 
 * Created on 19 November 2024, 3:32 pm
 */

/*-- CompletedOrder.cpp-------------------------------------------------------
            This file implements the CompletedOrder class member functions.
----------------------------------------------------------------------------*/

#include "CompletedOrder.h"

//--- Constructor
// Initializes the completed order stack as empty.
CompletedOrder::CompletedOrder() {
    myTop = NULL; // Top of the stack is initially NULL
    mySize = 0; // Stack size is 0
}

//--- Destructor
// Clears the completed order stack by deleting all nodes.
CompletedOrder::~CompletedOrder() {
    if (!isEmpty()) { // If the stack is not empty
        mySize = 0; // Reset size
        while (myTop != NULL) { // While the stack is not empty
            NodePtr temp = myTop; // Temporarily store the top node
            myTop = myTop->getNext(); // Move the top pointer to the next node
            delete temp; // Delete the old top node
        }
    }
}

//--- Definition of isEmpty()
// Returns true if the stack is empty, otherwise false.
bool CompletedOrder::isEmpty() const {
    return mySize == 0; // Check if size is 0
}

//--- Definition of addCompletedOrder()
// Adds a completed order to the stack.
void CompletedOrder::addCompletedOrder(Order addOrder) {
    NodePtr newNode = new Node(addOrder); // Create a new node with the given order
    newNode->setNext(myTop); // Set the next of the new node to the current top
    myTop = newNode; // Set the top pointer to the new node
    mySize++; // Increase the size of the stack
}

//--- Definition of removeCompletedOrder()
// Removes and returns the order from the top of the stack.
Order CompletedOrder::removeCompletedOrder() {
    Order output = myTop->getData(); // Store the data from the top node
    NodePtr temp = myTop; // Temporarily store the top node
    myTop = myTop->getNext(); // Move the top pointer to the next node
    delete temp; // Delete the old top node
    mySize--; // Decrease the size of the stack
    return output; // Return the order data
}

//--- Definition of totalAmountSold()
// Returns the total revenue from all completed orders.
double CompletedOrder::totalAmountSold() {
    if (isEmpty()) { // If the stack is empty, return 0
        return 0;
    }
    double total = 0;
    NodePtr temp = myTop; // Start from the top of the stack
    while (temp != NULL) { // Traverse the stack
        total += temp->getData().getTotalAmount(); // Add the order's total amount
        temp = temp->getNext(); // Move to the next node
    }
    return total; // Return the total revenue
}

//--- Definition of search()
// Searches for an order in the stack based on the orderId and returns the node containing it.
NodePtr CompletedOrder::search(int orderId) const {
    NodePtr temp = myTop; // Start from the top of the stack
    while (temp != NULL) { // Traverse the stack
        if (temp->getData().getOrderId() == orderId) { // If the orderId matches
            return temp; // Return the node containing the order
        }
        temp = temp->getNext(); // Move to the next node
    }
    return temp; // Return NULL if the order was not found
}

//--- Definition of size()
// Returns the current size of the stack.
int CompletedOrder::size() {
    return mySize; // Return the size of the stack
}

//--- Definition of saveToFile()
// Saves all completed orders to a file.
void CompletedOrder::saveToFile(const char* fileName) {
    ofstream outputFile;
    outputFile.open(fileName); // Open the file for writing
    if (!outputFile.is_open()) { // If the file cannot be opened, print an error message
        cerr << "Failed to open file: " << fileName << endl;
        return;
    }

    CompletedOrder tempStack;
    NodePtr temp = myTop;
    // Traverse the stack and push orders onto a temporary stack to reverse the order
    while (temp != NULL) {
        tempStack.addCompletedOrder(temp->getData());
        temp = temp->getNext();
    }

    // Write the orders from the temporary stack to the file
    while (!tempStack.isEmpty()) {
        Order order = tempStack.removeCompletedOrder(); // Get an order from the temporary stack
        outputFile << order.getOrderId() << ","
                   << order.getCustName() << ",";
        for (int i = 0; i < order.getOrderSize(); i++) { // Write each item in the order
            MenuItem& item = order.getOrderItem(i);
            outputFile << item.getName() << "-"
                       << item.getDescription() << "-"
                       << item.getPrice() << "/";
        }
        outputFile << "," << order.getTotalAmount() << endl; // Write total amount of the order
    }

    outputFile.close(); // Close the file
}

//--- Definition of loadFromFile()
// Loads completed orders from a file.
void CompletedOrder::loadFromFile(const char* fileName) {
    ifstream inputFile;
    inputFile.open(fileName); // Open the file for reading
    if (!inputFile.is_open()) { // If the file cannot be opened, print an error message
        cerr << "Failed to open file: " << fileName << endl;
        exit(1);
    }

    string line;
    while (getline(inputFile, line)) { // Read each line from the file
        if (line.empty()) { // Skip empty lines
            continue;
        }

        // Parse the line to extract order details
        int comma1 = line.find(',');
        int comma2 = line.find(',', comma1 + 1);
        int comma3 = line.find(',', comma2 + 1);

        if (comma1 == -1 || comma2 == -1 || comma3 == -1) {
            cerr << "Invalid line format: " << line << endl;
            continue;
        }

        string idStr = line.substr(0, comma1);
        int id = atoi(idStr.c_str());
        string name = line.substr(comma1 + 1, comma2 - comma1 - 1);
        string itemsStr = line.substr(comma2 + 1, comma3 - comma2 - 1);

        int itemCount = 0;
        int pos = 0;
        while ((pos = itemsStr.find('/', pos)) != -1) {
            itemCount++; // Count the number of items in the order
            pos++;
        }

        MenuItem* items = new MenuItem[itemCount]; // Allocate memory for the items

        int start = 0;
        for (int i = 0; i < itemCount; ++i) {
            int end = itemsStr.find('/', start);
            if (end == -1) {
                end = itemsStr.length();  
            }
            string item = itemsStr.substr(start, end - start);

            int dash1 = item.find('-');
            int dash2 = item.find('-', dash1 + 1);
            if (dash1 == -1 || dash2 == -1) {
                cerr << "Invalid item format in order: " << line << endl;
                continue;
            }

            string itemName = item.substr(0, dash1);
            string itemDesc = item.substr(dash1 + 1, dash2 - dash1 - 1);
            string itemPriceStr = item.substr(dash2 + 1);

            if (itemName.empty() || itemDesc.empty() || itemPriceStr.empty()) {
                cerr << "Invalid item details: " << item << endl;
                continue;
            }

            double itemPrice = atof(itemPriceStr.c_str());
            if (itemPriceStr.empty() || itemPrice <= 0) {
                cerr << "Invalid price format: " << itemPriceStr << endl;
                continue;
            }

            items[i] = MenuItem(itemName, itemDesc, itemPrice); // Store the item in the array
            start = end + 1; // Move the starting position for the next item
        }
        
        string totalStr = line.substr(comma3 + 1);
        double total = atof(totalStr.c_str());

        addCompletedOrder(Order(id, name, items, itemCount)); // Add the order to the stack
        delete[] items; // Free memory for the items
    }

    inputFile.close(); // Close the file
}

//--- Definition of displayRevenue()
// Displays the total revenue from completed orders.
void CompletedOrder::displayRevenue() {
    cout << "--- Total Revenue ---" << endl;
    CompletedOrder tempStack;
    NodePtr temp = myTop;

    while (temp != NULL) {
        tempStack.addCompletedOrder(temp->getData());
        temp = temp->getNext();
    }

    while (!tempStack.isEmpty()) {
        Order order = tempStack.removeCompletedOrder();
        cout << "Order " << order.getOrderId() << ": $" <<
                order.getTotalAmount() << endl;
    }

    cout << "Total Sold: $" << totalAmountSold() << endl; // Display total revenue
}

//--- Definition of displayCompletedOrders()
// Displays all completed orders with their details.
void CompletedOrder::displayCompletedOrders(ostream& out) const {
    if (isEmpty()) { // If the stack is empty, display a message
        out << "No orders completed" << endl;
        return;
    }

    CompletedOrder tempStack;
    NodePtr temp = myTop;

    while (temp != NULL) {
        tempStack.addCompletedOrder(temp->getData());
        temp = temp->getNext();
    }

    out << "-- Completed Orders --" << endl;
    while (!tempStack.isEmpty()) {
        Order order = tempStack.removeCompletedOrder();
        order.displayOrder(out); // Display the order details
        out << "Status: Completed" << endl;
        out << endl;
    }
}

//--- Definition of the overloaded stream insertion operator
// Displays completed orders when the object is printed.
ostream& operator<<(ostream& out, const CompletedOrder& c) {
    c.displayCompletedOrders(out); // Display the completed orders
    return out; // Return the output stream
}

