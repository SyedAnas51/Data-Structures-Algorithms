#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    string word;
    int frequency;
    Node *left;
    Node *right;
    int height;

    Node(string word, int frequency)
    {
        this->word = word;
        this->frequency = frequency;
        left = right = NULL;
        height = 1;
    }
};

Node *newNode(string word, int frequency);
Node *insertNode(Node *node, string word, int frequency);
int getHeight(Node *node);
int getBalance(Node *node);
Node *leftRotate(Node *node);
Node *rightRotate(Node *node);
void findWords(Node *node, string prefix);

Node *newNode(string word, int frequency)
{
    return new Node(word, frequency);
}

Node *insertNode(Node *node, string word, int frequency)
{
    if (node == NULL)
    {
        return newNode(word, frequency);
    }

    if (word < node->word)
    {
        node->left = insertNode(node->left, word, frequency);
    }
    else if (word > node->word)
    {
        node->right = insertNode(node->right, word, frequency);
    }
    else
    {
        node->frequency += frequency;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && word < node->left->word)
    {
        return rightRotate(node);
    }

    if (balance < -1 && word > node->right->word)
    {
        return leftRotate(node);
    }

    if (balance > 1 && word > node->left->word)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && word < node->right->word)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int getHeight(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getBalance(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node *leftRotate(Node *node)
{
    Node *temp = node->right;
    Node *temp2 = temp->left;

    temp->left = node;
    node->right = temp2;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));

    return temp;
}

Node *rightRotate(Node *node)
{
    Node *temp = node->left;
    Node *temp2 = temp->right;

    temp->right = node;
    node->left = temp2;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));

    return temp;
}

void findWords(Node *node, string prefix)
{
    if (node == NULL)
    {
        return;
    }

    if (node->word.find(prefix) == 0)
    {
        cout << node->word << endl;
    }

    if (prefix < node->word)
    {
        findWords(node->left, prefix);
    }
    else if (prefix > node->word)
    {
        findWords(node->right, prefix);
    }
    else
    {
        findWords(node->left, prefix);
        findWords(node->right, prefix);
    }
}

int main()
{
    Node *root = NULL;

    int n;
    cout << "Enter the number of words: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string word;
        int frequency;
        cout << "Enter word " << i + 1 << ": ";
        cin >> word;
        cout << "Enter frequency for word " << word << ": ";
        cin >> frequency;
        root = insertNode(root, word, frequency);
    }

    string prefix;

    cout << "Auto-completion system" << endl;
    cout << "Enter word: ";
    cin >> prefix;

    findWords(root, prefix);

    return 0;
}
