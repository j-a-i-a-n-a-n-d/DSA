#include <iostream>
using namespace std;
#include <algorithm>
#include <bits/stdc++.h>
class String
{
private:
    string x;
    string y;

public:
    String(string x, string y);
    void anagram(string x, string y);
};
String::String(string x1, string y1) : x(x1), y(y1) {}
void String::anagram(string x, string y)
{
    // s i l e n t
    // l i s t e n
    if (x.length() != y.length())
    {
        cout << "NOT ANAGRAM" << endl;
        return;
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
        cout << "Anagram" << endl;
    else
        cout << "Not Anagram" << endl;
}

// complexity o(n)
int main()
{
    cout << "----------------------------------" << endl;
    string x, y;
    getline(cin, x);
    getline(cin, y);
    String s1 = String(x, y);
    s1.anagram(x, y);

    return 1;
}