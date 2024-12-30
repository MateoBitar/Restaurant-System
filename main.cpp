/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Marco
 *
 * Created on 18 November 2024, 1:08 pm
 */

#include <cstdlib>
#include <iostream>

#include "Menu.h"
#include "CustomOrder.h"
#include "CompletedOrder.h"
using namespace std;

int main(int argc, char** argv) {
    
    int choice;     // Variable to store user menu choice
    Menu* menu = new Menu(10);  // Initialize a dummy menu
    CustomOrder aOrder;         // Create a custom order queue for pending orders
    CompletedOrder cOrder;      // Create a completed orders manager

    // Load previously completed orders from file
    cOrder.loadFromFile("C:\\Users\\Mateo\\Downloads\\trial\\completed_orders.txt");

    // Load menu items from file
    (*menu).loadFromFile("C:\\Users\\Mateo\\Downloads\\trial\\menu.txt");

    // Generate the next order ID based on completed orders count
    static int orderID = cOrder.size() + 1; 
    
    // Display program header
    cout << "---Restaurant Order Management System---" << endl;

    do {
        // Display menu options to the user
        cout << endl;
        cout << "1. Display Menu" << endl
                << "2. Add Menu Item" << endl
                << "3. Delete Menu Item" << endl
                << "4. Reset Menu" << endl
                << "5. Add New Order" << endl
                << "6. Process Next Order" << endl
                << "7. Display Orders" << endl
                << "8. Delete Order" << endl
                << "9. Calculate Total Amount of Sold Orders" << endl
                << "10. Save Completed Orders to File" << endl
                << "11. Exit" << endl << endl
                << "Enter your choice: ";
        cin >> choice;
        
        // Handle user choice using a switch statement
        switch (choice) {
            case 1: { // Display all menu items
                cout << (*menu);
                break;
            }
            
            case 2: { // Add a new menu item
                MenuItem newItem;
                newItem.readMenuItem(cin); // Read menu item details from user
                (*menu).addItem(newItem); // Add the item to the menu
                cout << "Menu Item added successfully!" << endl;
                break;
            }
            
            case 3: { // Delete a menu item by ID
                int id;
                cout << "Enter Id of Item (must be greater than 0): ";
                cin >> id;

                // Validate item ID
                while (id <= 0 || id > (*menu).size()) {
                    cout << "Id not valid" << endl;
                    cin >> id;      
                }
                
                (*menu).removeItem(id); // Remove item from menu
                cout << "Menu Item removed successfully!" << endl;
                break;
            }
            
            case 4: { // Clear all menu items
                (*menu).clear();
                cout << "Menu reset successful!" << endl;
                break;
            }
            
            case 5: { // Add a new customer order
                int orderSize = 0, itemID, capacity = 10;
                string custName;
                // Dynamic array to store item IDs
                int* itemsIdOrdered = new int[capacity]; 

                cout << "Enter Customer Name: ";
                cin >> custName;

                cout << "Enter items ID you want to purchase (0 to finish): ";
                cin >> itemID;

                // Collect item IDs for the order
                while (itemID != 0) {
                    if (itemID > 0 && itemID <= (*menu).size()) {
                        
                        // Resize the array if needed
                        if (orderSize == capacity) {
                            capacity *= 2;
                            int* temp = new int[capacity];
                            for (int j = 0; j < orderSize; j++) {
                                temp[j] = itemsIdOrdered[j];
                            }
                            delete[] itemsIdOrdered;
                            itemsIdOrdered = temp;
                        } 
                        itemsIdOrdered[orderSize++] = itemID;

                    } else {
                        cout << "Invalid Item ID. Try again: ";
                    }
                    
                    cin >> itemID;
                }
                
                if (orderSize == 0) { // Exit if no items were selected
                    cout << "No items selected. Exiting order..." << endl;
                    delete[] itemsIdOrdered;
                    break;
                }

                // Fetch menu items based on IDs
                MenuItem* itemsOrdered = new MenuItem[orderSize];
                for (int i = 0; i < orderSize; i++) {
                    itemsOrdered[i] = (*menu).getMenuItem(itemsIdOrdered[i]);
                }

                // Create the order and enqueue it
                Order order(orderID++, custName, itemsOrdered, orderSize);
                aOrder.enqueue(order);
                
                cout << "Order added successfully!" << endl;
                cout << "Your order will be processed soon!" << endl << endl;

                delete[] itemsIdOrdered;
                delete[] itemsOrdered;
                break;
            }
            
            case 6: { // Process the next customer order
                if (aOrder.isEmpty()) {
                    cout << "No orders to process" << endl;
                    break;
                }
                
                Order copy = aOrder.dequeue(); // Dequeue the next order
                cout << "Processing order for " << copy.getCustName() 
                        << "..." << endl;
                cOrder.addCompletedOrder(copy); // Mark order as completed
                cout << "Order processed successfully!" << endl;

                break;
            }
            
            case 7: { // Display pending and completed orders
                aOrder.displayCustomOrder(cout);
                cOrder.displayCompletedOrders(cout);
                break;
            }
            
            case 8: { // Delete a pending order by ID
                int dId;
                cout << "Enter Id of Order (must be greater than 0): ";
                cin >> dId;

                // Validate order ID
                while (dId <= 0 || aOrder.search(dId) == NULL) {
                    cout << "Id not valid" << endl;
                    cin >> dId;      
                }

                if (aOrder.deleteOrder(dId)) { // Attempt to delete the order
                    cout << "Order deleted successfully!";
                } else {
                    cout << "Order deletion failed...";
                }
                
                cout << endl;
                break;
            }
            
            case 9: { // Display the total revenue from completed orders
                cOrder.displayRevenue();
                break;
            }
            
            case 10: { // Save completed orders to file
                cout << "Saving completed orders to file..." << endl;
                cOrder.saveToFile("C:\\Users\\Mateo\\Downloads\\trial\\completed_orders.txt");
                break;
            }
            
            case 11: { // Exit the program
                cout << "Saving menu to file..." << endl;
                (*menu).saveToFile("C:\\Users\\Mateo\\Downloads\\trial\\menu.txt");
                cout << "Saving completed orders to file..." << endl;
                cOrder.saveToFile("C:\\Users\\Mateo\\Downloads\\trial\\completed_orders.txt");
                cout << "Exiting the program... GoodBye!" << endl;
                exit(0);
                break;
            }
            
            default: { // Handle invalid input
                cout << "Invalid choice" << endl;
                break;
            }    
        }
    } while (choice != 11); // Loop until user chooses to exit

    return 0; // End program
}
