#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] < 0)
            arr.erase(arr.begin() + i);
    }
    int k = (arr.size() - 1) / 2;
    cout << arr[k] << endl;
    return 0;
}
