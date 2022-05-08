#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int idx)
{
    int l = 2 * idx;
    int r = 2 * idx + 1;

    int min_idx = idx;
    int last = v.size() - 1;

    if (l <= last && v[l] > v[idx])
        min_idx = l;

    if (r <= last && v[r] > v[min_idx])
        min_idx = r;

    if (min_idx != idx)
    {
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx);
    }
}

void buildHeap(vector<int> &v)
{
    for (int i = 2; i < v.size(); i++)
    {
        int idx = i;
        int parent = i / 2;

        while (idx > 1 and v[idx] > v[parent])
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

void buildHeapOptimal(vector<int> &v)
{
    for (int i = (v.size() - 1) / 2; i >= 1; i--)
        heapify(v, i);
}

int main()
{
    vector<int> v = {-1, 10, 20, 5, 6, 1, 8, 9, 4};
    // buildHeap(v);
    buildHeapOptimal(v);

    for (auto x : v)
        cout << x << ", ";
    cout << endl;
}
