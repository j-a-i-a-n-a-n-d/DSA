#include <iostream>
#include <vector>
using namespace std;

// Heapify
// converting an array to a heap - min or max
// 1 based indexing le rhe Equals to lagana mt bhoolna :-|

void heapify(vector<int> &v, int n, int i)
{

    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;
    int largest = i;
    if (leftChild <= n && v[leftChild] > v[largest])
    {
        largest = leftChild;
    }
    if (rightChild <= n && v[rightChild] > v[largest])
    {
        largest = rightChild;
    }
    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}
int main()
{
    int x;
    vector<int> v2(6, 0);
    v2[0] = -1;
    int n = 5;

    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        v2[i + 1] = x;
    }
    // heap me jitne element h ==> 5
    for (int i = n / 2; i > 0; i--)
    {
        heapify(v2, n, i);
    }
    for (int j = 1; j < v2.size(); j++)
        cout << v2[j] << " ";
    return 0;
}

//                    x
//                  /   \
//                 x      x
//                / \   /  \
//               x   x x    x

//                 (1)    75
//
//               (2) 60        65 (3)
//
//
//           (4)  49  (5)55 (6) 54   (7)  62