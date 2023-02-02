#include <bits/stdc++.h>
using namespace std;
class Trie
{
private:
    vector<Trie *> child;
    bool isWord;

public:
    Trie()
    {
        isWord = false;
        for (int i = 0; i < 26; i++)
            child.push_back(NULL);
    }
    void insert(string word)
    {
        int n = word.size();
        Trie *node = this;
        for (int i = 0; i < n; i++)
        {
            int index = word[i] - 'a';
            if (node->child[index] == NULL)
            {
                node->child[index] = new Trie();
            }
            node = node->child[index];
        }
        node->isWord = true;
    }
    bool search(string word)
    {
        Trie *node = this;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            int index = word[i] - 'a';
            if (node->child[index] == NULL)
                return false;
            node = node->child[index];
        }
        return node->isWord;
    }
    // searching prefix
    bool startsWith(string word)
    {
        Trie *node = this;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (node->child[index] == NULL)
                return false;
            node = node->child[index];
        }
        return true;
    }
};
int main()
{
    Trie *myTrie = new Trie();
    myTrie->insert("apple");
    myTrie->insert("appy");
    cout << myTrie->search("apple") << endl;
    cout << myTrie->search("apky");
}