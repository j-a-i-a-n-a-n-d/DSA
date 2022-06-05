// a b c a b d c d c
// d c a b
// a string belongs to rotation or not
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
    void RSTR(string x, string y);
    void Naive_Pattern_Matching(string x, string y);
};
String::String(string x1, string y1) : x(x1), y(y1) {}
void String::RSTR(string x, string y)
{
    x = x + x;
    Naive_Pattern_Matching(x, y);
}
void String::Naive_Pattern_Matching(string x, string y)
{
    int n = x.length();
    int m = y.length();
    int i = 0, j = 0;
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
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    cout << "----------------------------------" << endl;
    string x, y;
    getline(cin, x);
    getline(cin, y);
    String s1 = String(x, y);
    s1.RSTR(x, y);

    return 1;
}