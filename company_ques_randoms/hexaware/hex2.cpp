#include <bits/stdc++.h>
#include <string>
#define lli long long int
using namespace std;
int main()
{
    string s = "";
    cin >> s;
    unordered_map<char, int> mappy;
    for (auto ch : s)
        mappy[ch]++;

    lli sol = 1;
    for (auto it : mappy)
    {
        sol *= it.second;
    }
    cout << sol << endl;
    return 0;
}
