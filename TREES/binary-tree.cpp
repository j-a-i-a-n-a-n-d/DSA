#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Binary_Tree
{
public:
    int key;
    Binary_Tree *left;
    Binary_Tree *right;
    Binary_Tree(int key) : key(key), left(NULL), right(NULL) {}
    void display(Binary_Tree *root);
};
void Binary_Tree::display(Binary_Tree *root)
{
    if (root)
    {
        display(root->left);
        cout << root->key << endl;
        display(root->right);
    }
    else
        return;
}
int main()
{
    Binary_Tree *root = new Binary_Tree(30);
    int flag = 0, n, x;
    // no of items
    cout << "no of items" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (flag == 0)
        {
            cout << "what you want to insert" << endl;
            cin >> x;
            root->left = new Binary_Tree(x);
            flag = 1;
        }
        else if (flag == 1)
        {
            cout << "what you want to insert" << endl;
            cin >> x;
            root->right = new Binary_Tree(x);
            flag = 0;
        }
    }
    cout << "Displaying the binary tree" << endl;
    (*root).display(root);
}