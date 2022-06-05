#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class my_hash_table
{

private:
    int bucket;
    list<int> *table;

public:
    my_hash_table(int size)
    {
        bucket = size;
        table = new list<int>[size];
    }
    void Insert(int key)
    {
        int i = key % bucket;
        table[i].push_back(key);
    }
    void Delete(int key)
    {
        int i = key % bucket;
        table[i].remove(key);
    }
    bool Search(int key)
    {
        int i = key % bucket;
        for (auto it : table[i])
        {
            if (it == key)
                return true;
        }
        return false;
    }
    void Display()
    {
        for (int i = 0; i < bucket; i++)
        {
            cout << i;
            for (auto x : table[i])
            {
                cout << "-->" << x;
            }
            cout << endl;
        }
    }
};

int main()
{
    int size;
    cin >> size;
    my_hash_table h(size);
    h.Insert(78);
    h.Insert(55);
    h.Insert(77);
    h.Insert(23);
    cout << h.Search(77) << endl;
    cout << h.Search(88) << endl;
    h.Delete(78);
    h.Display();

    return 1;
}