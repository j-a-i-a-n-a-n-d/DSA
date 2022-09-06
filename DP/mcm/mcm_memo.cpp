#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int mem[501][501];
int matrix_chain_multiplication(int i, int j, int arr[])
{
    if (i >= j)
        return 0;
    if (mem[i][j] != -1)
        return mem[i][j];
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = matrix_chain_multiplication(i, k, arr) + matrix_chain_multiplication(i + 1, j, arr) + arr[i - 1] * arr[k] * arr[j];
        mn = min(temp, mn);
    }
    return mem[i][j] = mn;
}
int mcm(int n, int arr[])
{
    return matrix_chain_multiplication(1, 2, arr);
}
int main()
{
    memset(mem, -1, sizeof(mem));
    int arr[] = {10, 30, 5, 60};
    cout << mcm(4, arr) << endl;
}