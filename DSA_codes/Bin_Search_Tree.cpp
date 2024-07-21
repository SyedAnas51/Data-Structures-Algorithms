#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        left = right = NULL;
        this->val = val;
    }
};

Node* insert(int val, Node* root) {
    if (root == NULL) {
        return new Node(val);
    }

    if (root->val < val) {
        root->right = insert(val, root->right);
    } else if (root->val > val) {
        root->left = insert(val, root->left);
    }

    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

Node* update(int val, int updatedval, Node* root) {
    if (root == NULL) return root;

    if (root->val == val) {
        root->val = updatedval;
    }

    update(val, updatedval, root->left);
    update(val, updatedval, root->right);

    return root;
}

void pre_order(Node* root) {
    if (root == NULL) return;

    cout << root->val << " -> ";
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(Node* root) {
    if (root == NULL) return;

    post_order(root->left);
    post_order(root->right);
    cout << root->val << " -> ";
}

void in_order(Node* root) {
    if (root == NULL) return;

    in_order(root->left);
    cout << root->val << " -> ";
    in_order(root->right);
}

int Sum(Node* root, int sum = 0) {
    if (root == NULL) return sum;

    sum += root->val;
    sum = Sum(root->left, sum);
    sum = Sum(root->right, sum);

    return sum;
}

int Sum2(Node* root) {
    if (root == NULL) return 0;
    return root->val + Sum2(root->left) + Sum2(root->right);
}

int Size(Node* root) {
    if (root == NULL) return 0;
    return 1 + Size(root->left) + Size(root->right);
}

int CountEven(Node* root) {
    if (root == NULL) return 0;

    if (root->val % 2 == 0) {
        return 1 + CountEven(root->left) + CountEven(root->right);
    } else {
        return CountEven(root->left) + CountEven(root->right);
    }
}

int Max(Node* root) {
    if (root == NULL) return 0;

    int x = Max(root->left);
    int y = Max(root->right);
    int z = root->val;

    if (x > y && x > z) {
        return x;
    } else if (y > x && y > z) {
        return y;
    } else {
        return z;
    }
}

int CountOdd(Node* root) {
    if (root == NULL) return 0;

    if (root->val % 2 != 0) {
        return 1 + CountOdd(root->left) + CountOdd(root->right);
    } else {
        return CountOdd(root->left) + CountOdd(root->right);
    }
}

int CountDivisors(Node* root, int val) {
    if (root == NULL) return 0;
    if (root->val % val == 0) {
        return 1 + CountDivisors(root->left, val) + CountDivisors(root->right, val);
    } else {
        return CountDivisors(root->left, val) + CountDivisors(root->right, val);
    }
}

int main() {
    Node* root = NULL;

    root = insert(50, root);
    root = insert(33, root);
    root = insert(70, root);
    root = insert(20, root);
    root = insert(40, root);
    root = insert(65, root);
    root = insert(80, root);

    cout << endl << CountDivisors(root, root->val) << endl;

    in_order(root);
    root = deleteNode(root, 50);
    cout << endl;
    in_order(root);

    return 0;
}