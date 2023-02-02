#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // coins = 4
    // [2,5,3,6]
    // sum=10;
    int coins, x, sum;
    cin >> coins;
    int c[coins];
    for (int i = 0; i < coins; i++)
    {
        cin >> x;
        c[i] = x;
    }
    cin >> sum;
    int dp[sum + 1][coins + 1];
    for (int i = 0; i < sum + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < coins + 1; i++)
        dp[0][i] = 1;
    for (int i = 1; i < sum + 1; i++)
    {
        for (int j = 1; j < coins + 1; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (i >= c[j - 1])
            {
                dp[i][j] = dp[i][j] + dp[i - c[j - 1]][j];
            }
        }
    }
    cout << dp[sum][coins];
}