#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool sortbyratio(pair<int, int> a, pair<int, int> b)
{
    return (double(a.first / a.second) < double(b.first / b.second));
}
float fractional_knapsack(vector<pair<int, int>> vp, int w1)
{
    sort(vp.begin(), vp.end(), sortbyratio);
    int i = 0;
    float w = w1;
    float max_weight = 0;
    for (int j = 0; j < vp.size(); j++)
    {
        cout << vp[j].first << " " << vp[j].second << endl;
    }
    cout << endl;
    while (w != 0)
    {
        if (vp[i].first <= w)
        {
            w = w - vp[i].first;                    // 40  20
            max_weight = max_weight + vp[i].second; // 60 160
            i++;
        }
        else
        {
            max_weight = max_weight + (w / vp[i].first) * vp[i].second;
            w = 0;
        }
    }
    return max_weight;
}
int main()
{
    vector<pair<int, int>> vp;
    int weight, size, b, a;
    cin >> size;
    cout << "-------------------------" << endl;
    cin >> weight;
    cout << "---------------------------" << endl;
    cout << "weight---value" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a >> b;
        vp.push_back(make_pair(a, b));
    }
    float wweight = fractional_knapsack(vp, weight);
    cout << wweight;
    cout << endl;
    return 1;
}
//#f***k type conversions :/