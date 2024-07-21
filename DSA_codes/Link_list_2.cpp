#include <iostream>
using namespace std;
class Product // this is linked list bro
{
public:
    int id;
    string name;
    double price;
    int quantity;
    Product *next;
    Product *prev;
};
class Inventory
{
    Product *head;

public:
    Inventory()
    {
        head = NULL;
    }
    void addToInventory(int id, string name, double price, int quantity)
    {
        Product *newNode = new Product();
        newNode->id = id;
        newNode->name = name;
        newNode->price = price;
        newNode->quantity = quantity;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
        }
        else

        {
            Product *temp = head;
            while (temp->next != NULL){
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
            }
        }
    }
    void deleteProduct(int id)
    {
        // Implement the function here.
        if (head == NULL)
        {
            cout << "Inventory is empty." << endl;
            return;
        }
        Product *current = head;
        if (current->id == id)
        {
            if (current->next == NULL)
            {
                delete head;
                head = NULL;
                return;
            }
            else
            {
                Product *next = current->next;
                delete head;
                head = next;
                next->prev = NULL;
            }
        }
    }
    void displayInventory()
    {
        if (head == NULL)
        {

            cout << "No products in Inventory.\n";
            return;
        }
        Product *temp = head;
        while (temp != nullptr)
        {
            cout << "ID: " << temp->id << "\n"
                 << "Name" << temp->name << "\n$ " << temp->price <<

                "\n"

                 << "Quantity: " << temp->quantity << endl;
            temp = temp->next;
        }
    }
    void updateProduct(int id, double new_price)
    {
        if (head == NULL)
        {
            cout << "The Inventory is empty." << endl;
            return;
        }
        Product *temp = head;
        while (temp != nullptr)
        {
            if (temp->id == id)
            {
                temp->price = new_price;
                return;
            }
            temp = temp->next;
        }
        cout << "Product with ID " << id << " dont exist. Please try again." << endl;
    }
    void findProduct(int id)
    {
        if (head == nullptr)
        {
            cout << "Inventory is empty." << endl;
            return;
        }

        Product *temp = head;
        while ((temp != nullptr) && (temp->id != id))
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Product with ID " << id << " not found." << endl;
            return;
        }
        cout << "Name: " << temp->name << ", Price: $" << temp->price

             << ", Quantity: " << temp->quantity << endl;
    }
};
int main()
{
    int choice;
    Inventory inventory;
    do
    {
        cout << "Welcome to robust Inventory!" << endl;
        cout << "1. Add product" << endl;     //
        cout << "2. Delete product" << endl;  //
        cout << "3. Display product" << endl; //
        cout << "4. Update price" << endl;
        cout << "5. Find product" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int id, quantity;
            double price;
            string name;
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter product name: ";
            cin.ignore();

            getline(cin, name);
            cout << "Enter product price: ";
            cin >> price;
            cout << "Enter product quantity: ";
            cin >> quantity;
            inventory.addToInventory(id, name, price, quantity);
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter ID of product to delete: ";
            cin >> id;
            inventory.deleteProduct(id);
        }
        else if (choice == 3)
        {
            inventory.displayInventory();
        }
        else if (choice == 4)
        {
            int id;
            double new_price;
            cout << "Enter ID of product to update price: ";
            cin >> id;
            cout << "Enter new price: ";
            cin >> new_price;
            inventory.updateProduct(id, new_price);
        }
        else if (choice == 5)
        {
            int id;
            cout << "Enter ID of product to find: ";
            cin >> id;
            inventory.findProduct(id);
        }
        else if (choice == 6)
        {
            cout << "Exiting the program...." << endl;
            break;
        }
        else
        {
            cout << "Wrong input, try again...\n\n"

                 << endl;
        }
    } while (1);
    return 0;
}



// CODE 2

// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node *prev;
//     Node(int val) : data(val), next(NULL), prev(NULL) {}
// };
// class DoublyLinkedList
// {
// public:
//     Node *head;
//     DoublyLinkedList() : head(NULL) {}
//     void insert(int val)
//     {
//         Node *newNode = new Node(val);
//         if (head == NULL)
//         {
//             head = newNode;
//         }
//         else
//         {
//             Node *temp = head;
//             while (temp->next != NULL)
//             {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//             newNode->prev = temp;
//         }
//     }
//     void separateEvenOdd(Node *&evenHead, Node *&oddHead)
//     {
//         Node *temp = head;
//         while (temp != NULL)
//         {

//             Node *nextNode = temp->next;
//             temp->next = NULL;
//             if (temp->data % 2 == 0)
//             {
//                 if (evenHead == NULL)
//                 {
//                     evenHead = temp;
//                 }
//                 else
//                 {
//                     temp->next = evenHead;
//                     evenHead->prev = temp;
//                     evenHead = temp;
//                 }
//             }
//             else
//             {
//                 if (oddHead == NULL)
//                 {
//                     oddHead = temp;
//                 }
//                 else
//                 {
//                     temp->next = oddHead;
//                     oddHead->prev = temp;
//                     oddHead = temp;
//                 }
//             }
//             temp = nextNode;
//         }
//     }
//     void printList(Node *head)
//     {
//         if (head == NULL)
//         {
//             cout << "NULL" << endl;
//             return;
//         }
//         Node *temp = head;
//         while (temp != NULL)

//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << "->NULL" << endl;
//     }
// };
// int main()
// {
//     DoublyLinkedList dll;
//     for (int i = 1; i <= 9; i++)
//     {
//         dll.insert(i);
//     }
//     Node *evenHead = NULL;
//     Node *oddHead = NULL;
//     cout << "Input:" << endl;
//     dll.printList(dll.head);
//     cout << "\nOutput:" << endl;
//     dll.separateEvenOdd(evenHead, oddHead);
//     cout << "1st: ";
//     dll.printList(evenHead);
//     cout << "2nd: ";
//     dll.printList(oddHead);
//     return 0;
// }