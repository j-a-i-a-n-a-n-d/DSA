#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int const m1 = 10000;

int LCS(string x, string y, int m, int n, int mem[][m1])
{
    if (m == 0 || n == 0) // base case
        return 0;
    if (mem[m - 1][n - 1] != -1) // if value exists
        return mem[m - 1][n - 1];
    if (x[m - 1] == y[n - 1])
    { // last character same
        mem[m - 1][n - 1] = 1 + LCS(x, y, m - 1, n - 1, mem);
        return mem[m - 1][n - 1];
    }
    else // last character not same
    {
        mem[m - 1][n - 1] = max(LCS(x, y, m - 1, n, mem), LCS(x, y, m, n - 1, mem));
        return mem[m - 1][n - 1];
    }
}
int main()
{
    string x, y;
    cin >> x >> y;
    int mem[x.length()][m1];
    memset(mem, -1, sizeof(mem));
    cout << LCS(x, y, x.length(), y.length(), mem);
    return 0;
}