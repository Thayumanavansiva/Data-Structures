#include <iostream>
#include <string>
using namespace std;

// Forward declaration of Order class
class Order;

// Structure to represent a node in circular linked list
struct Node {
    Order* data;
    Node* next;

    // Constructor
    Node(Order* order) : data(order), next(NULL) {}
};

// Class to represent an order
class Order {
private:
    static int lastOrderId; // Static variable to generate unique order IDs
    int orderId;
    int tableNumber;
    string itemsOrdered;
    double totalAmount;
    string status;

public:
    // Constructor
    Order(int table, string items, double amount, string st)
        : orderId(++lastOrderId), tableNumber(table), itemsOrdered(items), totalAmount(amount), status(st) {}

    // Getter for order ID
    int getOrderId() const {
        return orderId;
    }

    // Getter for table number
    int getTableNumber() const {
        return tableNumber;
    }

    // Getter for items ordered
    string getItemsOrdered() const {
        return itemsOrdered;
    }

    // Getter for total amount
    double getTotalAmount() const {
        return totalAmount;
    }

    // Getter for status
    string getStatus() const {
        return status;
    }

    // Setter for status
    void setStatus(string newStatus) {
        status = newStatus;
    }
};

// Static initialization for lastOrderId
int Order::lastOrderId = 0;

// Class for managing orders using a circular linked list
class OrderManager {
private:
    Node* head; // Head pointer for circular linked list

public:
    // Constructor
    OrderManager() : head(NULL) {}

    // Destructor to free allocated memory
    ~OrderManager() {
        // Free memory for all nodes in the list
        if (head != NULL) {
            Node* current = head;
            do {
                Node* next = current->next;
                delete current->data; // Delete the order object
                delete current; // Delete the node
                current = next;
            } while (current != head);
        }
    }

    // Function to add a new order
    void addOrder(int tableNumber, string itemsOrdered, double totalAmount, string status) {
        // Create new order object
        Order* newOrder = new Order(tableNumber, itemsOrdered, totalAmount, status);

        // Create a new node for the circular linked list
        Node* newNode = new Node(newOrder);

        if (head == NULL) {
            // If list is empty, make the new node the head and point to itself
            head = newNode;
            head->next = head;
        } else {
            // Traverse to the end of the list to insert the new node
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }

        cout << "Order added successfully with ID: " << newOrder->getOrderId() << endl;
    }

    // Function to remove a completed order by ID
    void removeOrder(int orderId) {
        Node* current = head;
        Node* previous = NULL;

        // Traverse the list to find the order with given ID
        do {
            if (current->data->getOrderId() == orderId && current->data->getStatus() == "SERVED") {
                // Remove the order from the list
                if (previous == NULL) {
                    // If it's the head node
                    if (head->next == head) {
                        delete head->data;
                        delete head;
                        head = NULL;
                    } else {
                        Node* last = head;
                        while (last->next != head) {
                            last = last->next;
                        }
                        last->next = head->next;
                        delete head->data;
                        delete head;
                        head = last->next;
                    }
                } else {
                    previous->next = current->next;
                    delete current->data;
                    delete current;
                }
                cout << "Order " << orderId << " removed successfully.\n";
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);

        cout << "Order " << orderId << " not found or not served yet.\n";
    }

    // Function to update order status
    void updateOrderStatus(int orderId, string newStatus) {
        Node* current = head;

        // Traverse the list to find the order with given ID
        do {
            if (current->data->getOrderId() == orderId) {
                current->data->setStatus(newStatus);
                cout << "Order " << orderId << " status updated.\n";
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "Order " << orderId << " not found.\n";
    }

    // Function to display all orders
    void displayOrders() {
        if (head == NULL) {
            cout << "No orders to display.\n";
            return;
        }

        cout << "List of Orders:\n";
        Node* current = head;
        do {
            cout << "Order ID: " << current->data->getOrderId() << ", Table: " << current->data->getTableNumber()
                 << ", Items: " << current->data->getItemsOrdered() << ", Total Amount: $" << current->data->getTotalAmount()
                 << ", Status: " << current->data->getStatus() << endl;
            current = current->next;
        } while (current != head);
    }
};

int main() {
    OrderManager orderManager;

    // Adding some sample orders
    orderManager.addOrder(1, "Burger, Fries", 10.50, "ORDERED");
    orderManager.addOrder(2, "Pizza, Salad", 15.75, "ORDERED");

    // Display all orders
    orderManager.displayOrders();

    // Update order status
    orderManager.updateOrderStatus(1, "PREPARING");

    // Remove completed order
    orderManager.removeOrder(2);

    // Display all orders after modification
    orderManager.displayOrders();

    return 0;
}
