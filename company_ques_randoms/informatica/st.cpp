#include <bits/stdc++.h>
using namespace std;

bool canBecomeEmpty(string str, string sub_str)
{
    while (str.size() > 0)
    {
        int idx = str.find(sub_str);
        if (idx == -1)
            break;
        str.erase(idx, sub_str.size());
    }

    return (str.size() == 0);
}
int main()
{
    string str = "1010001", sub_str = "100";
    if (canBecomeEmpty(str, sub_str))
        cout << "\nYes";
    else
        cout << "\nNo";
    return 0;
}