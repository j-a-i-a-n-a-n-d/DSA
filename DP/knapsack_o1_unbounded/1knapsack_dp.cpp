#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int knapSack(int w, int wt[], int val[], int n)
{
    int dp[n + 1][w + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int j = 0; j < w + 1; j++)
        dp[0][j] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
}

int main()
{
    // memset(m, -1, sizeof(m));
    int wt[] = {1, 2, 3};
    int val[] = {4, 5, 6};
    cout << knapSack(4, wt, val, 3);
}