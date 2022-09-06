#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < m + 1; i++)
        dp[0][i] = 0;
    int maxval = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (maxval < dp[i][j])
                    maxval = dp[i][j];
            }
            else
                dp[i][j] = 0;
        }
    }
    return maxval;
}
int main()
{
    string a = "abcdef";
    string b = "abcdeff";
    cout << longestCommonSubstr(a, b, 6, 7) << endl;
}