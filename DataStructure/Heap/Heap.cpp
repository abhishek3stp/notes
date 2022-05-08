#include <bits/stdc++.h>
using namespace std;

class Heap
{
    vector<int> v;
    bool minHeap;

    bool campare(int a, int b)
    {
        if (minHeap)
            return a < b;
        else
            return a > b;
    }

    void heapify(int idx)
    {
        int l = 2 * idx;
        int r = 2 * idx + 1;

        int min_idx = idx;
        int last = v.size() - 1;

        if (l <= last && campare(v[l], v[idx]))
            min_idx = l;

        if (r <= last && campare(v[r], v[min_idx]))
            min_idx = r;

        if (min_idx != idx)
        {
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
    }

public:
    Heap(int defult_size = 10, bool type = true)
    {
        v.reserve(defult_size);
        v.push_back(-1);
        minHeap = type;
    }

    void push(int data)
    {
        v.push_back(data);
        int idx = v.size() - 1;
        int parent = idx / 2;

        while (idx > 1 and campare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }

    int top()
    {
        return v[1];
    }

    void pop()
    {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }

    bool empty()
    {
        return v.size() == 1;
    }
};

int main()
{
    Heap h(10, false);
    h.push(5);
    h.push(7);
    h.push(1);
    h.push(4);
    h.push(2);
    h.push(0);

    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }
}
