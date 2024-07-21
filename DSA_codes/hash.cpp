#include <iostream>
#include <string>

using namespace std;

// Define the structure for a student
struct Student
{
    string roll_number;
    string name;
    string father_name;
    string department;
    string degree;
};

// Define the structure for a node in the linked list
struct ListNode
{
    Student data;
    ListNode *next;
    ListNode(const Student &s) : data(s), next(nullptr) {}
};

// Define the hash table class
class HashTable
{
public:
    // Constructor
    HashTable(int table_size) : size(table_size)
    {
        table = new ListNode *[size]();
    }

    // Destructor to free memory
    ~HashTable()
    {
        for (int i = 0; i < size; ++i)
        {
            ListNode *current = table[i];
            while (current != nullptr)
            {
                ListNode *next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] table;
    }

    // Insert a student record into the hash table
    void insert(const Student &student)
    {
        int index = hashFunction(student.roll_number);
        ListNode *newNode = new ListNode(student);
        if (table[index] == nullptr)
        {
            table[index] = newNode;
        }
        else
        {
            ListNode *current = table[index];
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Retrieve a student record given the roll number
    Student *retrieve(const string &roll_number)
    {
        int index = hashFunction(roll_number);
        ListNode *current = table[index];
        while (current != nullptr)
        {
            if (current->data.roll_number == roll_number)
            {
                return &(current->data);
            }
            current = current->next;
        }
        return nullptr; // Student not found
    }

private:
    int size;         // Size of the hash table
    ListNode **table; // Dynamic array to store linked lists

    // Hash function to map admission years to indices
    int hashFunction(const string &roll_number)
    {
        // Extract two-digit admission year
        string admission_year = roll_number.substr(0, 2);
        // Convert admission year to integer and use modulo to map to index
        return stoi(admission_year) % size;
    }
};

int main()
{
    HashTable hashTable(100); // Assuming 100 slots for the hash table

    // Example usage
    Student student1 = {"23P-1234", "John Doe", "Michael Doe", "Computer Science", "Bachelor"};
    hashTable.insert(student1);

    // Retrieve a student record
    Student *retrieved_student = hashTable.retrieve("23P-1234");
    if (retrieved_student)
    {
        cout << "Student found: " << retrieved_student->name << endl;
    }
    else
    {
        cout << "Student not found" << endl;
    }

    return 0;
}
