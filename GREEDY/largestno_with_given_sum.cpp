#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int GIVEN(int sum, int d)
{
    int n = 0;
    int h = 1;

    for (int i = 1; i < d; i++) // calculating 10^d-1
    {
        h = h * 10;
    }

    if (sum > d * 9)
        return -1;
    while (sum != 0)
    {
        if (sum >= 9)
        {
            sum = sum - 9;
            n = (9 * h) + n;
            h = h / 10;
        }
        else
        {
            n = (sum * h) + n;
            break;
        }
    }
    return n;
}
int main()
{
    cout << GIVEN(29, 3) << endl;
    cout << GIVEN(29, 4) << endl;
    cout << GIVEN(12, 5) << endl;
}