#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Student
{
private:
    int id;
    string name;
    float gpa;

public:
    Student(int _id, string _name, float _gpa) : id(_id), name(_name), gpa(_gpa) {}
    int getID()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    float getGPA()
    {
        return gpa;
    }
};
class Node
{
public:
    Student *data;
    Node *next;
    Node(Student *_data)
    {
        data = _data;
        next = NULL;
    }
};
class StudentList
{
private:
    Node *head;

public:
    StudentList()
    {
        head = NULL;
    }
    void addStudent(Student *student)
    {
        Node *newNode = new Node(student);
        newNode->next = head;
        head = newNode;
        cout << "Student added successfully." << endl;
    }
    void removeStudent(int id)
    {
        Node *current = head;
        Node *prev = NULL;
        while (current != NULL && current->data->getID() != id)
        {
            prev = current;
            current = current->next;
        }
        if (current == NULL)
        {
            cout << "Student with ID " << id << " not found." << endl;
            return;
        }
        if (prev == NULL)
        {
            head = current->next;
        }

        else
        {
            prev->next = current->next;
        }
        delete current->data;
        delete current;
        cout << "Student with ID " << id << " removed successfully." <<endl;
    }
    void displayAllStudents() const
    {
        Node *current = head;
        if (current == NULL)
        {
            cout << "No students in the list." << endl;
            return;
        }
        cout << "Student records:" << endl;
        while (current != NULL)
        {
            cout << "ID: " << current->data->getID() << ", Name: " << current->data->getName() << ", GPA: " << current->data->getGPA() << endl;

            current = current->next;
        }
    }
    void searchStudent(int id) const
    {
        Node *current = head;
        while (current != NULL && current->data->getID() != id)
        {
            current = current->next;
        }
        if (current == NULL)
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
        else
        {
            cout << "Student found:" << endl;

            cout << "ID: " << current->data->getID() << ", Name: " << current->data->getName() << ", GPA: " << current->data->getGPA() << endl;
        }
    }
    float calculateAverageGPA() const
    {
        Node *current = head;
        float totalGPA = 0;
        int count = 0;
        while (current != NULL)
        {
            totalGPA += current->data->getGPA();
            count++;
            current = current->next;
        }
        if (count == 0)
            return 0;
        return totalGPA / count;
    }
    ~StudentList()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *next = current->next;
            delete current->data;
            delete current;
            current = next;
        }
    }
};
int main()
{
    StudentList studentList;
    int choice;
    do
    {
        cout << "\nWelcome to the Student Registration System!" <<

            endl;

        cout << "1. Add a student" << endl;
        cout << "2. Remove a student" << endl;
        cout << "3. Search for a student" << endl;
        cout << "4. Display all students" << endl;
        cout << "5. Calculate average GPA" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int id;
            string name;
            float gpa;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter student GPA: ";
            cin >> gpa;
            studentList.addStudent(new Student(id, name, gpa));
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter student ID to remove: ";
            cin >> id;
            studentList.removeStudent(id);
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter student ID to search: ";
            cin >> id;
            studentList.searchStudent(id);
        }
        else if (choice == 4)
        {
            studentList.displayAllStudents();
        }
        else if (choice == 5)
        {

            cout << "Average GPA of all students: " <<

                studentList.calculateAverageGPA() << endl;

             cout << "Average GPA of all students: " << fixed << setprecision(2) << studentList.calculateAverageGPA() << endl;
        }
        else if (choice == 6)
        {
            cout << "Exiting program." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please enter a number between 1 and 6. " << endl;
        }
    } while (1);
    return 0;
}