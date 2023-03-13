/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Returns true if s1 is substring of s2
int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        int j = 0;
        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
        if (j == M)
            return i + M;
    }
    return -1;
}
int main()
{
    string s1;
    string s2;
    int t;
    cin >> s1;
    cin >> t;
    while (t--)
    {
        cin >> s2;
        int res = isSubstring(s2, s1);
        if (res != -1)
        {
            res++;
            string s = "";
            bool flag = true;
            while (res < s1.size() && flag)
            {
                if (s1[res] == '&')
                {
                    flag = false;
                    break;
                }
                s += s1[res];
                res++;
            }
            cout << s << endl;
        }
        else
            cout << -1;
    }
    return 0;
}
