#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
vector<pair<int, int>> activity_selection(vector<pair<int, int>> vp)
{
    sort(vp.begin(), vp.end(), sortbysec);
    vector<pair<int, int>> sol;
    sol.push_back(make_pair(vp[0].first, vp[0].second));
    int j = 0;
    for (int i = 1; i < vp.size(); i++)
    {
        if (sol[j].second <= vp[i].first)
        {
            j++;
            sol.push_back(make_pair(vp[i].first, vp[i].second));
        }
    }
    return sol;
}
int main()
{
    vector<pair<int, int>> vp;
    int size, b, a;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> a >> b;
        vp.push_back(make_pair(a, b));
    }
    vp = activity_selection(vp);
    cout << vp.size();
    cout << endl;
    for (int i = 0; i < vp.size(); i++)
    {
        cout << vp[i].first << " " << vp[i].second << endl;
    }
}