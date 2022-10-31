#include <iostream>
#include <vector>

using namespace std;
void heapify(vector<int> &v, int n, int i)
{
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;
    int largest = i;
    if (leftChild <= n && v[leftChild] > v[largest])
        largest = leftChild;
    if (rightChild <= n && v[rightChild] > v[largest])
        largest = rightChild;
    if (largest != i)
    {
        swap(v[largest], v[i]);
        heapify(v, n, largest);
    }
}
void utility(vector<int> &v, int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(v, n, i);
    }
}
vector<int> heapSort(vector<int> &v, int n)
{
    utility(v, n);
    for (int j = n; j > 1; j--)
    {
        swap(v[j], v[1]);
        n--;
        utility(v, n);
    }
    return v;
}

int main()
{
    int x;
    int n;
    cout << "Length of the array : ";
    cin >> n;
    vector<int> v;
    v.push_back(-1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    v = heapSort(v, n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        cout << v[i] << " ";
    }
}