#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();
    int dp[m][n];
    for (int i = 0; i < m; i++)
        dp[i][0] = 0;
    for (int i = 0; i < n; i++)
        dp[0][i] = 0;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (dp[i - 1] == dp[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[j - 1][i]);
        }
    }
    cout << dp[m - 1][n - 1];
}