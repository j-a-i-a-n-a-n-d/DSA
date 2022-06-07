#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class KMP
{
private:
    string x, y;

public:
    KMP(string x, string y);
    void K_M_P();
    void LSP(vector<int> &lsp, string y);
};

KMP::KMP(string x, string y) : x(x), y(y){};

void KMP::K_M_P()
{
    int n = x.length();
    int m = y.length();
    vector<int> lsp(n, 0);
    LSP(lsp, y);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (x[i] == y[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << i - j << endl;
            j = lsp[j - 1];
        }
        else if (i < n && x[i] != y[j])
        {
            if (j == 0)
                i++;
            else
                j = lsp[j - 1];
        }
    }
}

void KMP::LSP(vector<int> &lsp, string y)
{
    lsp[0] = 0;
    int len = 0;
    int n = y.length();
    int i = 1;
    while (i < n)
    {
        if (y[i] == y[len])
        {
            len++;
            lsp[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lsp[i] = 0;
                i++;
            }
            else
            {
                len = lsp[len - 1];
            }
        }
    }
}

int main()
{
    string x, y;
    getline(cin, x);
    getline(cin, y);
    KMP obj1 = KMP(x, y);
    obj1.K_M_P();
}