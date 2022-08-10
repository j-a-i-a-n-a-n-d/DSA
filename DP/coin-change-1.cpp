#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int coinchange(int coin[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    int r = coinchange(coin, n - 1, sum);
    // when we reduce coins we dont reduce sum reason we dont include the coin
    if (sum - coin[n - 1] >= 0)
        r = r + coinchange(coin, n, sum - coin[n - 1]);
    // here we included the coin so we reduced the sum because we included it in our soln.
    return r;
}
int main()
{
    int x, n;
    cin >> n;
    int coin[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        coin[i] = x;
    }
    cout << "-------------------------" << endl;
    int sum;
    cin >> sum;
    cout << coinchange(coin, n, sum);
}