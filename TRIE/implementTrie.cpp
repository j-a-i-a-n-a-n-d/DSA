#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char ch;
    vector<TrieNode *> children;
    bool isWord;
    // constructor for Trie
    // char ===> char
    //  children ko ===> null
    //  isWord ===>not a word till now so false
    TrieNode(char ch)
    {
        this->ch = ch;
        for (int i = 0; i < 26; i++)
            children.push_back(NULL);
        isWord = false;
    }
};
class TrieImplementation
{
public:
    TrieNode *root;
    void utilityFunction(TrieNode *root, string s, int i)
    {
        if (i == s.size())
        {
            root->isWord = true;
            return;
        }
        int indexWhereItHasToBeInserted = s[i] - 'a';
        TrieNode *child;
        if (root->children[indexWhereItHasToBeInserted] != NULL)
            child = root->children[indexWhereItHasToBeInserted];
        else
        {
            child = new TrieNode(s[i]);
            root->children[indexWhereItHasToBeInserted] = child;
        }
        utilityFunction(root, s, ++i);
    }
    void insertInTrie(string s)
    {
        utilityFunction(root, s, 0);
    }
};

int main()
{
    TrieImplementation *myTrie = new TrieImplementation();
    myTrie->insertInTrie("bhaikakutta");
    myTrie->insertInTrie("bhaikaktta");
    myTrie->insertInTrie("bha");
    myTrie->insertInTrie("bhaik");
    myTrie->insertInTrie("bhaika");
    cout << "Trie Made Successfully" << endl;
}

// NOT working