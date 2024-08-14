#include <iostream>
#include <string>
using namespace std;


struct MenuItem {
    string itemName;
    double price;
    MenuItem *next;
};

struct Order {
    int orderId;
    int tableNumber;
    MenuItem *itemsList;
    double totalAmount;
    string status;
    Order *next;
};


MenuItem* createMenuItem(string itemName, double price) {
    MenuItem *newItem = new MenuItem;
    newItem->itemName = itemName;
    newItem->price = price;
    newItem->next = NULL;
    return newItem;
}


Order* createOrder(int orderId, int tableNumber, string status) {
    Order *newOrder = new Order;
    newOrder->orderId = orderId;
    newOrder->tableNumber = tableNumber;
    newOrder->itemsList = NULL;
    newOrder->totalAmount = 0.0;
    newOrder->status = status;
    newOrder->next = NULL;
    return newOrder;
}


void addMenuItem(Order *order, string itemName, double price) {
    MenuItem *newItem = createMenuItem(itemName, price);


    newItem->next = order->itemsList;
    order->itemsList = newItem;


    order->totalAmount += price;
}


void displayOrder(Order *order) {
    cout << "Order ID: " << order->orderId << endl;
    cout << "Table Number: " << order->tableNumber << endl;
    cout << "Status: " << order->status << endl;
    cout << "Items Ordered:" << endl;
    MenuItem *currentItem = order->itemsList;
    while (currentItem != NULL) {
        cout << "- " << currentItem->itemName << " ($" << currentItem->price << ")" << endl;
        currentItem = currentItem->next;
    }
    cout << "Total Amount: $" << order->totalAmount << endl;
    cout<<endl;
}
void displayAllOrders(Order *head) {
    if (head == NULL) {
        cout << "No orders in the system." << endl;
        return;
    }
    Order *current = head;
    do {
        displayOrder(current);
        current = current->next;
    } while (current != head);
}
void insertOrder(Order *&head, int orderId, int tableNumber, string status) {
    Order *newOrder = createOrder(orderId, tableNumber, status);

    if (head == NULL) {
        head = newOrder;
        head->next = head;
    } else {
        Order *last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newOrder;
        newOrder->next = head;
    }
}
void removeOrder(Order *&head, int orderId) {
    if (head == NULL) {
        cout << "No orders in the system." << endl;
        return;
    }
    Order *current = head, *prev = NULL;
    do {
        if (current->orderId == orderId) {
            if (current == head) {

                Order *last = head;
                while (last->next != head) {
                    last = last->next;
                }
                if (head->next == head) {

                    head = NULL;
                } else {
                    head = head->next;
                    last->next = head;
                }
                delete current;
                cout << "Order ID " << orderId << " removed successfully." << endl;
                return;
            } else {

                prev->next = current->next;
                delete current;
                cout << "Order ID " << orderId << " removed successfully." << endl;
                return;
            }
        }
        prev = current;
        current = current->next;
    } while (current != head);

    cout << "Order ID " << orderId << " not found." << endl;
}


void updateOrderStatus(Order *head, int orderId, string newStatus) {
    if (head == NULL) {
        cout << "No orders in the system." << endl;
        return;
    }

    Order *current = head;
    do {
        if (current->orderId == orderId) {
            current->status = newStatus;
            cout << "Order ID " << orderId << " status updated to " << newStatus << " successfully." << endl;
            return;
        }
        current = current->next;
    } while (current != head);

    cout << "Order ID " << orderId << " not found." << endl;
}

int main() {
    Order *orders = NULL;
    insertOrder(orders, 101, 1, "ordered");
    addMenuItem(orders, "Pizza", 12.5);
    addMenuItem(orders, "Cola", 2.0);

    insertOrder(orders, 102, 2, "preparing");
    addMenuItem(orders, "Burger", 8.0);
    addMenuItem(orders, "Fries", 4.0);

    insertOrder(orders, 103, 3, "served");
    addMenuItem(orders, "Steak", 20.0);
    addMenuItem(orders, "Wine", 15.0);


    displayAllOrders(orders);


    updateOrderStatus(orders, 101, "preparing");
    displayAllOrders(orders);


    removeOrder(orders, 102);
    displayAllOrders(orders);

    return 0;
}
