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
    int Naive_Pattern_Matching();
};
String::String(string x1, string y1) : x(x1), y(y1) {}
int String::Naive_Pattern_Matching()
{
    int n = x.length();
    int m = y.length();
    int i = 0, j = 0, count = 0;
    for (i = 0; i < n - m + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (y[j] != x[i + j])
            {

                break;
            }
        }
        if (j == m)
        {
            count++;
            cout << i << " ";
        }
    }
    cout << endl;
    return count;
}

int main()
{
    cout << "----------------------------------" << endl;
    string x, y;
    getline(cin, x);
    getline(cin, y);
    String s1 = String(x, y);
    cout << s1.Naive_Pattern_Matching();

    return 1;
}