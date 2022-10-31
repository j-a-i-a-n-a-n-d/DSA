#include <iostream>
#include <vector>

using namespace std;
// we are making a 1 index based heap to store the data
class Heap
{
    vector<int> v;
    int size;

public:
    Heap()
    {
        // size dene ke lie asal gotcha :)
        v.assign(101, 0);
        size = 0;
        v[0] = -1;
    }
    void Insert(int val)
    {
        size = size + 1;
        int index = size;
        v[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (v[parent] < v[index])
            {
                swap(v[index], v[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }
    void Delete()
    {
        if (size == 0)
            return;
        v[1] = v[size];
        size = size - 1;
        for (int i = 1; i < size;)
        {
            int l = i * 2;
            int r = i * 2 + 1;
            if (l < size && v[i] < v[l])
            {
                swap(v[i], v[l]);
                i = l;
            }
            else if (r < size && v[i] < v[r])
            {
                swap(v[i], v[r]);
                i = r;
            }
            else
                return;
        }
    }

    void Printf()
    {
        for (int i = 1; i <= size; i++)
            cout << v[i] << " ";
    }
};

int main()
{
    Heap h;
    int x;
    for (int i = 0; i < 5; i++)
    {

        cin >> x;
        h.Insert(x);
    }
    h.Printf();
    h.Delete();
    h.Printf();

    // Heapify
    // converting an array to a heap - min or max
    // 1 based indexing le rhe Equals to lagana mt bhoolna :-|
}

// Notes
//  Insertion
//  1.) declare array 1 indexed and s[1]=val;
//  2.) place this element in the correct position
//  3.) done

// Deletion
// talking about deleting the node of the heap -> max heap/min heap
// 1.) last element ko root banao
// 2.) us element to uski shi jagah p leke ao
// 2.) a-> left chid and b->right child se compare krvao tb tk jb tk vo shi jagah p nahi pahuch jaye
