#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int m = 1000000007;
int perfectSum(int arr[], int n, int sum)
{
    sort(arr, arr + n, greater<int>());
    // Your code goes here
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;
    for (int j = 1; j < sum + 1; j++)
        dp[0][j] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] +
                            dp[i - 1][j - arr[i - 1]]) %
                           m;
            }
        }
    }
    return dp[n][sum];
}
int main()
{
    /*10 31
    9 7 0 3 9 8 6 5 7 6*/
    int arr[10] = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};
    cout << perfectSum(arr, 10, 31);
    return 0;
}