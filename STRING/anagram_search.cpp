// geeksforgeeks
// fro

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool anagram(string x, string y)
{
    if (x.length() != y.length())
    {
        return 0;
    }
    vector<int> x_array(26, 0);
    for (int i = 0; i < x.length(); i++)
    {
        x_array[x[i] - 97]++;
    }
    vector<int> y_array(26, 0);
    for (int i = 0; i < y.length(); i++)
    {
        y_array[y[i] - 97]++;
    }
    int flag = 1;
    for (int i = 0; i < x.length(); i++)
    {
        if (x_array[i] != y_array[i])
        {
            flag = -1;
            break;
        }
    }
    if (flag == 1)
        return true;
    else
        return false;
}
void slidingwindow(string str, string pattern)
{
    int n = str.length();
    int m = pattern.length();
    int i = 0, j = 0, count = 0;
    for (i = 0; i < n - m + 1; i++)
    {
        bool tf = anagram(str.substr(i, m), pattern);
        if (tf)
        {
            cout << "EXISTS" << endl;
            return;
        }
    }
    cout << "DOES NOT EXIST" << endl;
}
int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    slidingwindow(a, b);
    return 1;
}