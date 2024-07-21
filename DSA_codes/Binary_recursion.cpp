#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node *insertNode(Node *root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root)

{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int findSmallest(Node *root)
{
    if (root->left == NULL)
        return root->data;

    return findSmallest(root->left);
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void displayMenu()

{
    cout << "Binary Search Tree Operations:" << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. In-order Traversal" << endl;
    cout << "3. Pre-order Traversal" << endl;
    cout << "4. Post-order Traversal" << endl;
    cout << "5. Find the smallest value" << endl;
    cout << "6. Count nodes" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    Node *root = NULL;
    int choice, value;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insertNode(root, value);
            break;
        case 2:
            cout << "In-order Traversal: ";
            inorderTraversal(root);
            cout << endl;
            break;
        case 3:
            cout << "Pre-order Traversal: ";

            preorderTraversal(root);
            cout << endl;
            break;
        case 4:
            cout << "Post-order Traversal: ";
            postorderTraversal(root);
            cout << endl;
            break;
        case 5:
            if (root == NULL)
                cout << "Tree is empty." << endl;
            else

                cout << "Smallest value: " << findSmallest(root) << endl;
            break;
        case 6:
            cout << "Number of nodes: " << countNodes(root) << endl;
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}