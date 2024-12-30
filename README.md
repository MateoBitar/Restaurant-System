# Restaurant-System
Data Structure Project

## Project Overview
The **Restaurant-System** is a C++ application designed to streamline the management of menu items and customer orders for restaurants. It leverages custom data structures such as dynamic arrays, linked lists, stacks, and queues to handle core functionalities efficiently. The system is file-driven and interactive, ensuring ease of use for restaurant staff.

---

## Features
1. **Menu Management**:
   - Load menu items from a file into a custom `DynamicArrayList`.
   - Display the list of menu items.
   - Add new items to the menu.
   - Delete existing menu items.
   - Reset the menu to clear all items.
   - Save the updated menu list back to a file.

2. **Order Management**:
   - Add customer orders, which may include multiple menu items, to a queue of active orders.
   - Serve the next order, removing it from the active queue and adding it to the stack of completed orders.
   - Display all active and completed orders.
   - Cancel an active order from the queue.

3. **Revenue Management**:
   - Calculate the total revenue based on completed orders.
   - Save the details of completed orders to a file for record-keeping.

---

## Data Structures Used
1. **DynamicArrayList**: A custom dynamic array class to manage menu items.
2. **Queue**: A custom queue implemented using a linked list for managing active orders.
3. **Stack**: A custom stack implemented using a linked list for managing completed orders.
4. **Linked List**: Underpins both the queue and stack implementations for efficient memory management.

---

## Project Structure

### Key Files:
- **main.cpp**: The entry point of the application, containing the main program logic.
- **Menu.cpp & Menu.h**: Implements functionalities related to menu management.
- **Order.cpp & Order.h**: Manages customer orders and their attributes.
- **CompletedOrder.cpp & CompletedOrder.h**: Handles operations related to completed orders.
- **CustomOrder.cpp & CustomOrder.h**: Likely for individual order customization.
- **MenuItem.cpp & MenuItem.h**: Represents individual menu items and their attributes.
- **Node.cpp & Node.h**: Implements the building blocks for linked list-based structures.

### Additional Files:
- **menu.txt**: File containing the list of menu items for loading and saving.
- **completed_orders.txt**: Stores details of completed orders.
- **Makefile**: Automates the build process for the project.

---

## Setup Instructions

### Requirements:
- A C++ compiler (e.g., GCC).
- Make utility (optional, for using the provided Makefile).

### Steps to Build and Run:
1. Clone or download the project files.
2. Open a terminal and navigate to the project directory.
3. Run `make` to build the project, or compile manually using:
   ```bash
   g++ -o restaurant_system main.cpp Menu.cpp Order.cpp CompletedOrder.cpp MenuItem.cpp Node.cpp CustomOrder.cpp
   ```
4. Run the executable:
   ```bash
   ./restaurant_system
   ```

---

## Usage
1. **Menu Operations**:
   - Load menu items from menu.txt.
   - Add, delete, or reset menu items interactively.
   - Save updated menu items back to menu.txt.

2. **Order Operations**:
   - Add customer orders to the queue.
   - Serve and complete orders, moving them to the stack.
   - Cancel active orders as needed.

3. **View and Save**:
   - Display active and completed orders.
   - Calculate total revenue from completed orders.
   - Save completed order details to completed_orders.txt.

