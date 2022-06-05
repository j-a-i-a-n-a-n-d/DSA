#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class MyHashFunction
{
private:
    int bucket;
    vector<vector<int>> hashmap;

public:
    MyHashFunction(int bucket);
    void insert(int key);
    int hashfunction(int key);
    void Delete(int key);
    bool search(int key);
    void display();
};

MyHashFunction::MyHashFunction(int bucket)
{
    this->bucket = bucket;
    hashmap = vector<vector<int>>(bucket);
}

int MyHashFunction::hashfunction(int key)
{
    return key % bucket;
}

void MyHashFunction::insert(int key)
{
    int i = hashfunction(key);
    hashmap[i].push_back(key);
}

void MyHashFunction::Delete(int key)
{
    int i = hashfunction(key);
    for (int j = 0; j < hashmap[i].size(); j++)
    {
        if (hashmap[i][j] == key)
        {
            hashmap[i].erase(hashmap[i].begin() + j);
            cout << "ELEMENT DELETED" << endl;
            return;
        }
    }
    cout << "ELEMENT NOT FOUND" << endl;
}

bool MyHashFunction::search(int key)
{
    int i = hashfunction(key);
    for (int j = 0; j < hashmap[i].size(); j++)
    {
        if (hashmap[i][j] == key)
            return true;
    }
    return false;
}

void MyHashFunction::display()
{
    for (int i = 0; i < hashmap.size(); i++)
    {
        cout << i << " ";
        for (int j = 0; j < hashmap[i].size(); j++)
        {
            cout << "-->" << hashmap[i][j];
        }
        cout << endl;
    }
}
int main()
{
    int size;
    cin >> size;
    MyHashFunction h(size);
    h.insert(78);
    h.insert(55);
    h.insert(77);
    h.insert(23);
    cout << h.search(77) << endl;
    cout << h.search(88) << endl;
    h.Delete(78);
    h.display();
    return 1;
}