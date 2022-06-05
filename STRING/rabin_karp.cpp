#include <iostream>
using namespace std;
#include <algorithm>
#include <bits/stdc++.h>
class String
{
private:
    string x;
    string y;
    int d;

public:
    String(string x, string y);
    int Rabin_Karp(string x, string y);
};
String::String(string x1, string y1) : x(x1), y(y1), d(5) {}
int String::Rabin_Karp(string x, string y)
{
    int n = x.length();
    int m = y.length();

    // computing d^m-1
    int h = 1;
    for (int i = 1; i <= m - 1; i++)
    {
        h = (h * d);
    }

    // comptuing hash for 1st window
    int p = 0;
    int t = 0;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + y[i]); // horners rules
        t = (t * d + x[i]); // horners rules
    }

    // checking if p==t if matches we look into individuals
    int count = 0;
    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (y[j] != x[i + j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                count++;
                cout << i << " ";
            }
        }
        if (i < n - m)
            t = (d * (t - x[i] * h)) + x[i + m];
    }
    return count;
}

int main()
{
    cout << "----------------------------------" << endl;
    string x, y;
    getline(cin, x);
    getline(cin, y);
    String s1 = String(x, y);
    cout << s1.Rabin_Karp(x, y);
    return 1;
}