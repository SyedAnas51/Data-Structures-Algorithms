#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    double price;
    Node *next;

    // constructor
    Node(string name, double price)
    {
        this->name = name;
        this->price = price;
        this->next = nullptr;
    }
}; // end of the struct

class OrderQueue
{
    Node *front;
    Node *rear;

public:
    // constructor
    OrderQueue()
    {
        this->front = nullptr;
        this->rear = nullptr;
    }

    void enqueue(string name, double price)
    {
        Node *newNode = new Node(name, price);
        if (rear == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Order added: " << name << " ($" << price << ")" << endl;
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty. No orders to process" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        cout << "Order processed: " << temp->name << " ($" << temp->price << ")" << endl;
        delete temp;
    }

    void displayQueue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current orders in the queue:" << endl;
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->name << " ($" << current->price << ")" << endl;
            current = current->next;
        }
    }

    void displayMenu()
    {
        cout << "Menu" << endl;
        cout << "1. Burger price $5.99" << endl;
        cout << "2. Pizza price $8.49" << endl;
        cout << "3. Salad price $4.99" << endl;
        cout << "4. Coffee price $2.49" << endl;
        cout << "5. Tea price $1.99" << endl;
    }
};

int main()
{
    OrderQueue obj;
    int choice;
    do
    {
        cout << "1. Display Menu" << endl;
        cout << "2. Place Order" << endl;
        cout << "3. Process Order" << endl;
        cout << "4. Display Current Orders" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.displayMenu();
            break;
        case 2:
            int itemChoice;
            cout << "Enter the number of the item you want to order: ";
            cin >> itemChoice;
            switch (itemChoice)
            {
            case 1:
                obj.enqueue("Burger", 5.99);
                break;
            case 2:
                obj.enqueue("Pizza", 8.49);
                break;
            case 3:
                obj.enqueue("Salad", 4.99);
                break;
            case 4:
                obj.enqueue("Coffee", 2.49);
                break;
            case 5:
                obj.enqueue("Tea", 1.99);
                break;
            default:
                cout << "Invalid choice." << endl;
            }
            break;
        case 3:
            obj.dequeue();
            break;
        case 4:
            obj.displayQueue();
            break;
        case 0:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}





// CODE 2

// #include <iostream>
// using namespace std;

// struct Node
// {

//     Node *next;

//     int info;

//     Node(int info)

//     {

//         this->info = info;

//         this->next = NULL;
//     }
// };

// class single_Que

// {

// public:
//     Node *newNode;

//     Node *rear; // use for instertion

//     Node *front; // use for delete

//     single_Que()

//     {

//         this->rear = NULL;

//         this->front = NULL;

//         this->newNode = NULL;

//     } // end of constructor

//     void Inque(int value)

//     {

//         if (rear == NULL || front == NULL)

//         {

//             newNode = new Node(value);

//             rear = newNode;

//             front = newNode;
//         }

//         else

//         {

//             newNode = new Node(value);

//             rear->next = newNode;

//             rear = newNode;
//         }

//     } // end of inque

//     void Print()

//     {

//         cout << "Values in Queue are: ";

//         Node *current = front;

//         while (current != NULL)

//         {

//             cout << current->info << " ";

//             current = current->next;
//         }

//         cout << endl;

//     } // end of the print

//     void Duplicate()

//     {

//         Node *current = front;

//         while (current != NULL)

//         {

//             for (int i = 1; i < current->info; i++)

//             {

//                 Node *newNode = new Node(current->info);

//                 newNode->next = current->next;

//                 current->next = newNode;

//                 if (current == rear)

//                 {

//                     rear = newNode;
//                 }

//                 current = newNode;
//             }

//             current = current->next; // Move to the next original node
//         }

//     } // end of duplicate
// };

// int main()

// {

//     single_Que obj;

//     int value;

//     int choice;

//     do

//     {

//         cout << endl
//              << "1. Inque" << endl;

//         cout << "2. copy" << endl;

//         cout << "3. print" << endl;

//         cout << "0. Exit" << endl;

//         cout << "Enter your choice here ";

//         cin >> choice;

//         if (choice == 1)
//         {
//             cout << " Entet value ";

//             cin >> value;

//             obj.Inque(value);
//         }

//         else if (choice == 2)

//         {

//             obj.Duplicate();
//         }

//         else if (choice == 3)

//         {

//             obj.Print();
//         }

//     } while (choice != 0);

//     return 0;
// }