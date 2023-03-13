#include <bits/stdc++.h>
using namespace std;

void Merge_sort(int *a, int s, int e);
void Merge(int a[], int s, int mid, int e);

int main()
{
    int n;
    cout << "Enter the number of elements : " << endl;
    cin >> n;

    int a[n];
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Merge_sort(a, 0, n - 1);

    cout << "Using Merge sort : " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }

    return 0;
}

void Merge(int a[], int s, int mid, int e)
{
    int temp[e - s + 1];
    int i1 = s, i2 = mid + 1;

    int x = 0;

    while (i1 <= mid && i2 <= e)
    {
        if (a[i1] < a[i2])
        {
            temp[x] = a[i1];
            x++;
            i1++;
        }
        else
        {
            temp[x] = a[i2];
            x++;
            i2++;
        }
    }

    while (i1 <= mid)
    {
        temp[x++] = a[i1++];
    }

    while (i2 <= e)
    {
        temp[x++] = a[i2++];
    }

    int m = 0;

    for (int i = 0; i < (e - s + 1); i++)
    {
        a[m] = temp[i];
        m++;
    }
}

void Merge_sort(int a[], int s, int e)
{

    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    Merge_sort(a, s, mid);
    Merge_sort(a, mid + 1, e);

    Merge(a, s, mid, e);
}