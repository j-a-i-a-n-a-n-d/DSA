#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool sort_function(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return (a.second > b.second);
    }
    else
    {
        return (a.first < b.first);
    }
}
int jobsequencing(vector<pair<int, int>> vp)
{
    sort(vp.begin(), vp.end(), sort_function);

    // deadline     profit
    //   3            20
    //   3            20
    //   3            40
    //   1            5

    // 1-40 1-30 1-10 4-20
    for (int i = 0; i < vp.size(); i++)
    {
        cout << vp[i].first << " " << vp[i].second << endl;
    }
    return 1;
}
int main()
{
    vector<pair<int, int>> vp;
    int size, a, b;
    cout << "--------------------------" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> a >> b;
        vp.push_back(make_pair(a, b));
    }
    cout << jobsequencing(vp) << endl;
}