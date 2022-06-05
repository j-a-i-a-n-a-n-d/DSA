#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class MyHashFunction2
{
private:
    int bucket;
    vector<int> v;

public:
    MyHashFunction2(int bucket);
    void Insert(int key);
    int Hashfunction(int key);
    void Delete(int key);
    void Display();
    bool Search(int key);
};
MyHashFunction2::MyHashFunction2(int bucket) // constructor
{
    this->bucket = bucket;
    v = vector<int>(bucket, -1);
}

void MyHashFunction2::Insert(int key) // insert
{
    int i = Hashfunction(key);
    while (v[i] != -1 && v[i] != -2 && v[i] != key)
    {
        i = (i + 1) % bucket;
    }
    if (v[i] == key)
        cout << "ALREADY EXIST ";
    else
        v[i] = key;
}

int MyHashFunction2::Hashfunction(int key) // hashfunction
{
    return key % bucket;
}

void MyHashFunction2::Delete(int key)
{
    int i = Hashfunction(key);
    int j = i;
    while (v[j] != -1)
    {
        if (v[j] == key)
        {
            v[j] = -2;
            cout << "DELETED" << endl;
            return;
        }
        j = (j + 1) % bucket;
        if (j == i)
        {
            cout << "not found" << endl;
            return;
        }
    }
    cout << "NOT FOUnd" << endl;
}
void MyHashFunction2::Display() // display
{
    for (auto &it : v)
    {
        if (it == -1 || it == -2)
            cout << "EMPTY" << endl;
        else
            cout << it << endl;
    }
}
bool MyHashFunction2::Search(int key) // search
{
    int i = Hashfunction(key);
    int j = i;
    while (v[j] != -1)
    {
        if (v[j] == key)
            return true;
        j = (j + 1) % bucket;
        if (j == i)
            return false;
    }
    return false;
}

int main()
{
    int size, a;
    cin >> size;
    vector<int> v1;
    for (int i = 0; i < size; i++)
    {
        cin >> a;
        v1.push_back(a);
    }
    MyHashFunction2 obj(size);
    for (int i = 0; i < size; i++)
    {
        obj.Insert(v1[i]);
    }
    cout << endl;
    cout << "--------------------------" << endl;
    obj.Display();
    cout << "--------------------------" << endl;
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    obj.Delete(d1);
    obj.Delete(d2);
    obj.Delete(d3);
    cout << "--------------------------" << endl;
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << obj.Search(s1) << endl;
    cout << obj.Search(s2) << endl;
    cout << obj.Search(s3) << endl;
    cout << "--------------------------" << endl;
    obj.Display();
}