#include <bits/stdc++.h>
using namespace std;
int BC(int n, int k)
{
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    return BC(n - 1, k - 1) + BC(n - 1, k);
}
int main()
{
    int n = 10;
    int k = 5;
    cout << BC(n, k);
}