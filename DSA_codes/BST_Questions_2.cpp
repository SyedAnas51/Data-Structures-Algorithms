// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//     int val;
//     Node *left;
//     Node *right;
//     Node(int val)
//     {
//         this->val = val;
//         right = left = NULL;
//     }
// };

// Node *insert(Node *root, int data)
// {
//     if (root == NULL)
//     {
//         return new Node(data);
//     }
//     if (root->val < data)
//     {
//         root->right = insert(root->right, data);
//     }
//     if (root->val > data)
//     {
//         root->left = insert(root->left, data);
//     }
//     return root;
// }

// int height(Node *node)
// {
//     if (node == NULL)
//         return 0;
//     int lHeight = height(node->left);
//     int rHeight = height(node->right);
//     if (lHeight > rHeight)
//         return 1 + lHeight;
//     else
//         return 1 + rHeight;
// }
// bool isAvl(Node *root)
// {
//     if (root == NULL)
//         return true;
//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
//     int balance = leftHeight - rightHeight;
//     if (balance < -1 || balance > 1)
//         return false;
//     return isAvl(root->left) && isAvl(root->right);
// }

// int main()
// {
//     Node *root = NULL;
//     root = insert(root, 10);
//     root = insert(root, 5);
//     root = insert(root, 15);
//     root = insert(root, 2);
//     root = insert(root, 20);
//     root = insert(root, 17);
//     root = insert(root, 25);
//     if (isAvl(root))
//     {
//         cout << "The tree is AVL tree." << endl;
//     }
//     else
//     {
//         cout << "The tree is Not AVL tree..." << endl;
//     }

//     return 0;
// }

/////////////////////////////////// code 2 //////////////////////////////////////////

// #include <iostream>
// #include <algorithm> // Added for std::max
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;
//     int height;
//     Node(int data)
//     {
//         this->data = data;
//         right = left = NULL;
//         height = 1;
//     }
// };
// class AVL
// {
// public:
//     Node *Root;
//     AVL()
//     {
//         Root = NULL;
//     }

    
//     Node *rightRotate(Node *y)
//     {
//         Node *x = y->left;
//         Node *T = x->right;
//         x->right = y;
//         y->left = T;
//         y->height = 1 + max(height(y->left), height(y->right));
//         x->height = 1 + max(height(x->left), height(x->right));
//         return x;
//     }
//     Node *leftRotate(Node *x)
//     {
//         Node *y = x->right;
//         Node *T = y->left;
//         y->left = x;
//         x->right = T;
//         x->height = max(height(x->left), height(x->right)) + 1;
//         y->height = max(height(y->left), height(y->right)) + 1;
//         return y;
//     }
//     Node *RL_Rotation(Node *root)
//     {
//         root->right = rightRotate(root->right);
//         return leftRotate(root);
//     }
//     Node *LR_Rotation(Node *root)
//     {
//         root->left = leftRotate(root->left);
//         return rightRotate(root);
//     }
//     Node *Insert(Node *root, int data)
//     {
//         if (root == NULL)
//         {
//             return new Node(data);
//         }
//         if (data < root->data)
//         {
//             root->left = Insert(root->left, data);
//         }
//         else if (data > root->data)
//         {
//             root->right = Insert(root->right, data);
//         }
//         else
//         {
//             return root;
//         }
//         root->height = max(height(root->left), height(root->right)) + 1;
//         int balance = getBalance(root);
//         if (balance > 1 && data < root->left->data)
//         {
//             return rightRotate(root);
//         }
//         if (balance < -1 && data > root->right->data)
//         {
//             return leftRotate(root);
//         }
//         if (balance > 1 && data > root->left->data)
//         {
//             return LR_Rotation(root);
//         }
//         if (balance < -1 && data < root->right->data)

//         {
//             return RL_Rotation(root);
//         }
//         return root;
//     }

//     // Get Height of a Node
//     int height(Node *node)
//     {
//         if (node == NULL)
//         {
//             return 0;
//         }
//         return node->height;
//     }
//     int getBalance(Node *node)
//     {
//         if (node == NULL)
//         {
//             return 0;
//         }
//         return height(node->left) - height(node->right);
//     }
//     void displayNodes(Node *root)
//     {
//         if (root == NULL)
//         {
//             return;
//         }
//         displayNodes(root->left);
//         cout << root->data << " ";
//         displayNodes(root->right);
//     }
// };
// int main()
// {
//     AVL object;
//     object.Root = object.Insert(object.Root, 22);
//     object.Root = object.Insert(object.Root, 20);
//     object.Root = object.Insert(object.Root, 38);
//     object.Root = object.Insert(object.Root, 11);

//     object.Root = object.Insert(object.Root, 26);
//     object.Root = object.Insert(object.Root, 42);
//     object.Root = object.Insert(object.Root, 33);
//     object.Root = object.Insert(object.Root, 45);
//     cout << "Nodes in the AVL tree: ";
//     object.displayNodes(object.Root);
//     return 0;
// }