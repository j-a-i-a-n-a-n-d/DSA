#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int bitCount(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
bool perfectSquare(long double x)
{
    if (x >= 0)
    {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
int counnnty(int a, int b)
{
    int count = 0;
    for (int i = a; i <= b; i++)
    {
        int x = bitCount(i);
        if (perfectSquare(x))
            count++;
    }
    return count;
}
int main()
{
    int a = 1;
    int b = 20;
    cout << counnnty(a, b);
}
