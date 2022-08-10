#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2, int m, int n)
{
    if (m == -1 || n == -1)
    {
        return 0;
    }
    if (s1[m] == s2[n])
        return (1 + lcs(s1, s2, m - 1, n - 1));
    else
        return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2, s1.length() - 1, s2.length() - 1);
    return 0;
}

/*
variation in LCS
1.) longest palindromic sequence
    logic : reverse the string and find lcs
2.) shortes super sequence
    logic : ek  geeks
                gefks   answer (6)
3.) printing lcs print at every point
*/