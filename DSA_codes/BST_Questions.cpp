#include <iostream>
#include <string>
using namespace std;
// Definition for Employee Node in BST
class Employee
{
public:
    int empID;
    string name;
    string department;
    Employee *left;
    Employee *right;
    Employee(int id, string n, string dep)
    {
        empID = id;
        name = n;
        department = dep;
        left = right = NULL;
    }
};
Employee *createEmployeeNode(int empID, string name, string department)
{
    Employee *newNode = new Employee(empID, name, department);
    return newNode;
}
Employee *insertEmployee(Employee *root, int empID, string name, string department)
{
    if (root == NULL)
    {
        return createEmployeeNode(empID, name, department);
    }
    if (empID < root->empID)
    {
        root->left = insertEmployee(root->left, empID, name, department);
    }
    else if (empID > root->empID)
    {

        root->right = insertEmployee(root->right, empID, name, department);
    }
    return root;
}
Employee *searchEmployee(Employee *root, int empID)
{
    if (root == NULL || root->empID == empID)
    {
        return root;
    }
    if (empID < root->empID)
    {
        return searchEmployee(root->left, empID);
    }
    else
    {
        return searchEmployee(root->right, empID);
    }
}
int calculateTotalDepth(Employee *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lDepth = calculateTotalDepth(root->left);
    int rDepth = calculateTotalDepth(root->right);
    return 1 + max(lDepth, rDepth);
}

void findEmployeesWithSameAuthorityHelper(Employee *root, int authority, int empID)
{
    if (root == NULL)
    {
        return;
    }
    if (root->empID != empID && root->empID % 10 == authority)
    {
        cout << "Employee ID: " << root->empID << ", Name: " << root->name << ",Department : " << root->department << endl;
    }
    findEmployeesWithSameAuthorityHelper(root->left, authority, empID);
    findEmployeesWithSameAuthorityHelper(root->right, authority, empID);
}
void findEmployeesWithSameAuthority(Employee *root, int empID)
{
    if (root == NULL)
    {

        return;
    }
    Employee *emp = searchEmployee(root, empID);
    if (emp == NULL)
    {
        cout << "Employee not found." << endl;
        return;
    }
    int authority = emp->empID % 10;
    cout << "Employees with the same authority as Employee ID " << empID << ":\n";
    findEmployeesWithSameAuthorityHelper(root, authority, empID);
}
void viewEmp(Employee *root)
{
    if (root == NULL)
    {
        return;
    }
    viewEmp(root->left);
    cout << "Employee ID: " << root->empID << ", Name: " << root->name << ", Department: " << root->department << endl;
    viewEmp(root->right);
}
void findSubordinates(Employee *root, int empID)
{
    if (root == NULL)
    {
        return;
    }
    Employee *emp = searchEmployee(root, empID);
    if (emp == NULL)
    {
        cout << "Employee not found." << endl;
        return;
    }
    cout << "Subordinates of Employee ID " << empID << ":\n";
    viewEmp(emp->left);  // Corrected line
    viewEmp(emp->right); // Corrected line
}
int main()
{
    Employee *root = NULL;
    int choice, empID;
    string name, department;
    do
    {
        cout << "\nMenu:\n";

        cout << "1. Insert Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Find Employees with Same Authority\n";
        cout << "4. Calculate Total Depth of Hierarchy\n";
        cout << "5. Find Subordinates of Employee\n";
        cout << "6. View All Employees\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Employee ID, Name, and Department: ";
            cin >> empID >> name >> department;
            root = insertEmployee(root, empID, name, department);
        }
        else if (choice == 2)
        {
            cout << "Enter Employee ID to search: ";
            cin >> empID;
            Employee *emp = searchEmployee(root, empID);
            if (emp != NULL)
            {
                cout << "Employee Found: ID=" << emp->empID << ", Name=" << emp->name << ", Department=" << emp->department << endl;
            }
            else
            {
                cout << "Employee not found." << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Enter Employee ID to find employees with same authority: ";
            cin >> empID;
            findEmployeesWithSameAuthority(root, empID);
        }
        else if (choice == 4)
        {
            cout << "Total Depth of Hierarchy: " << calculateTotalDepth(root) << endl;
        }
        else if (choice == 5)
        {
            cout << "Enter Employee ID to find subordinates: ";
            cin >> empID;
            findSubordinates(root, empID); // Implement this function
        }
        else if (choice == 6)
        {
            cout << "All Employees:\n";
            viewEmp(root);
        }
        else if (choice == 7)
        {
            cout << "Exiting program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (1);
    return 0;
}