#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree() { root = NULL; }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (root == NULL)
        {
            root = newNode;
            return;
        }
        else
        {
            insertHelper(root, newNode);
        }
    }

private:
    void insertHelper(Node *current, Node *newNode)
    {
        if (current->left == NULL)
        {
            current->left = newNode;
            return;
        }
        else if (current->right == NULL)
        {
            current->right = newNode;
            return;
        }
        else
        {
            insertHelper(current->left, newNode);
        }
    }
};
bool same(Node *p, Node *q)
{
    if (!p && !q)
        return true;
    else if (p && !q || !p && q)
        return false;
    else if (p->data != q->data * q->data && p->data * p->data != q->data)
        return false;
    else
    {
        return (same(p->left, q->left) && same(p->right, q->right));
    }
}
bool isSameTree(Node *p, Node *q)
{
    return same(p, q);
}

int main()
{
    BinaryTree bt1, bt2;
    int x;
    for (int i = 0; i < 3; i++)
    {
        /* code */
        cin >> x;
        bt1.insert(x);
    }
    for (int i = 0; i < 3; i++)
    {
        /* code */
        cin >> x;
        bt2.insert(x);
    }
    cout << bt1.root->data;
    cout << bt2.root->data;
    cout << endl;
    cout << bool(isSameTree(bt1.root, bt2.root));
    return 0;
}