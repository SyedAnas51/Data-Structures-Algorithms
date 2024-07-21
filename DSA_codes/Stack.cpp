#include <iostream>
#include <string>
using namespace std;
class Browser
{
private:
    static const int MAX_HISTORY = 100;
    string backStack[MAX_HISTORY];
    string forwardStack[MAX_HISTORY];
    int backTop;
    int forwardTop;
    string currentPage;

public:
    Browser()
    {
        backTop = -1;
        forwardTop = -1;
        currentPage = "Home";
    }
    void pushBackStack(const string &url)
    {
        if (backTop < MAX_HISTORY - 1)
        {
            backStack[++backTop] = url;
        }
        else
        {
            cout << "Back history is full." << endl;
        }
    }
    void pushForwardStack(const string &url)
    {
        if (forwardTop < MAX_HISTORY - 1)
        {
            forwardStack[++forwardTop] = url;
        }
        else
        {
            cout << "Forward history is full." << endl;
        }
    }
    string popBackStack()
    {
        if (backTop >= 0)
        {
            return backStack[backTop--];
        }
        else
        {
            cout << "Back history is empty." << endl;
            return "";
        }
    }
    string popForwardStack()
    {
        if (forwardTop >= 0)
        {
            return forwardStack[forwardTop--];
        }
        else
        {
            cout << "Forward history is empty." << endl;
            return "";
        }
    }
    void visitPage(const string &url)
    {
        pushBackStack(currentPage);
        currentPage = url;
        forwardTop = -1;
        displayCurrentPage();
    }
    void goBack()
    {

        string url = popBackStack();
        if (!url.empty())
        {
            pushForwardStack(currentPage);
            currentPage = url;
            displayCurrentPage();
        }
    }
    void goForward()
    {
        string url = popForwardStack();
        if (!url.empty())
        {
            pushBackStack(currentPage);
            currentPage = url;
            displayCurrentPage();
        }
    }
    void displayCurrentPage()
    {
        cout << "Current Page: " << currentPage << endl;
    }
};
int main()
{
    Browser browser;
    browser.visitPage("https://www.wikipedia.org/");
    browser.visitPage("https://www.example.com/page2");
    browser.visitPage("https://www.example.com/page3");
    browser.goBack();
    browser.goBack();
    browser.goForward();
    browser.visitPage("https://www.example.com/page4");
    browser.goForward();
    browser.goBack();
    return 0;
}




// CODE 2

// #include <iostream>
// #include <string>
// using namespace std;
// class Solution
// {
// public:
//     bool isValid(string s)
//     {
//         const int MAX_SIZE = 1000;
//         char stack[MAX_SIZE];
//         int top = -1;
//         for (char c : s)
//         {
//             if (c == '(' || c == '[' || c == '{')
//             {
//                 if (top < MAX_SIZE - 1)
//                     stack[++top] = c;
//                 else
//                     return false;
//             }
//             else if (c == ')' || c == ']' || c == '}')
//             {
//                 if (top >= 0 && isMatching(stack[top], c))
//                     top--;
//                 else
//                     return false;
//             }
//         }
//         if (top == -1)
//             return true;
//         else
//             return false;
//     }
//     bool isMatching(char open, char close)
//     {
//         return (open == '(' && close == ')') ||
//                (open == '[' && close == ']') ||
//                (open == '{' && close == '}');
//     }
// };
// int main()
// {
//     Solution solution;
//     string input;
//     char choice;
//     do
//     {
//         cout << "Enter a string containing only '(', ')', '{', '}','[',']' : ";
//         getline(cin, input);
//         bool valid = solution.isValid(input);
//         if (valid)
//             cout << "The string is valid." << endl;
//         else
//             cout << "The string is invalid." << endl;
//         cout << "Do you want to enter another string? (y/n): ";

//         cin >> choice;
//         cin.ignore(); // Clear the input buffer
//     } while (choice == 'y' || choice == 'Y');
//     return 0;
// }