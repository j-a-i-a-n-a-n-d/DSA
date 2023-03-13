/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, len, k;
    cin >> n;
    cin >> len;
    cin >> k;
    int num;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    // int arr[] = {3,3,2,1,3};
    // int k = 6;
    // int len=2;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            a++;
            sum += arr[j];
            if (sum == k && a != len)
                res++;
        }
    }
    cout << res << endl;
}
