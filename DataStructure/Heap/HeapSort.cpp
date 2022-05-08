#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int idx, int size)
{
    int l = 2 * idx;
    int r = 2 * idx + 1;

    int min_idx = idx;
    int last = size - 1;

    if (l <= last && v[l] > v[idx])
        min_idx = l;

    if (r <= last && v[r] > v[min_idx])
        min_idx = r;

    if (min_idx != idx)
    {
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx, size);
    }
}

void buildHeap(vector<int> &v)
{
    for (int i = (v.size() - 1) / 2; i >= 1; i--)
        heapify(v, i, v.size());
}

void heapSort(vector<int> &v)
{
    buildHeap(v);
    int n = v.size();

    while (n > 1)
    {
        swap(v[1], v[n - 1]);
        n--;
        heapify(v, 1, n);
    }
}

int main()
{
    vector<int> v = {-1, 10, 20, 5, 6, 1, 8, 9, 4};
    heapSort(v);

    for (auto x : v)
        cout << x << ", ";
    cout << endl;
}
