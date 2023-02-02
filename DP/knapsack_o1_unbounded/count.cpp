// Count the number of subsets with a given subset
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m[1000][1000];
int Count_of_given_subset(int[] a, int n, int p)
{
    if (p == 0)
        return 1;
    else if (n == 0)
        return 0;
    else if (m[n][p] != -1)
        return m[n][p];
    else
    {
        if (a[n - 1] > p)
            return m[n][p] = Count_of_given_subset(a, n - 1, p);
        else
            return m[n][p] = Count_of_given_subset(a, n - 1, sum - a[n - 1]) + Count_of_given_subset(a, n - 1, sum);
    }
}
int count_subset_with_given_difference(int[] a, int n, int diff)
{
    // p1 + p2 = total sum of array
    // p1 - p2 = diff
    // 2p1 =   tsm+diff
    //  p1=   tsm+diff/2
    int sum = 0;
    for (int i = 0; i < n, i++)
        sum += a[i];
    sort(a, a + n, greater<int>());
    int partition = (sum + diff) / 2;
    return Count_of_given_subset(a, n, partition);
}
int main()
{
    memset(m, -1, sizeof(m));
    int a[6] = {2, 3, 5, 6, 8, 10};
    int diff = 2;
    cout << count_subset_with_given_difference(a, n, diff);
    return 0;
}