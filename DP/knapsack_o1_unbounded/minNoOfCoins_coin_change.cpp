
#include <bits/stdc++.h>
using namespace std;

int helperFunction(vector<int> &coins, int amount, int n, vector<vector<int>> &dp)
{
    if (amount == 0)
        return 0;
    if (n < 0 || amount < 0)
        return INT_MAX - 1;

    if (dp[n][amount] != -1)
        return dp[n][amount];
    int counted_as_excluded = helperFunction(coins, amount, n - 1, dp);

    int counted_as_included = 1 + helperFunction(coins, amount - coins[n], n, dp);

    return dp[n][amount] = min(counted_as_included, counted_as_excluded);
}

int coinChange(vector<int> &coins, int amount)
{
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
    int ans = helperFunction(coins, amount, coins.size() - 1, dp);
    return (ans < INT_MAX - 1) ? ans : -1;
}

int main()
{
    // coin change 1 LeetCode
    vector<int> coins = {1, 2, 5};
    int amount = 458;
    cout << coinChange(coins, amount);
}