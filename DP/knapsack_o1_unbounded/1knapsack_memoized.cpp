#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m[1002][1002];
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W <= 0)
        return 0;
    if (m[n - 1][W - 1] != -1)
        return m[n - 1][W - 1];
    else if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else if (wt[n - 1] <= W)
        return m[n - 1][W - 1] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}
int main()
{
    memset(m, -1, sizeof(m));
    int wt[] = {1, 2, 3};
    int val[] = {4, 5, 6};
    cout << knapSack(4, wt, val, 3);
}