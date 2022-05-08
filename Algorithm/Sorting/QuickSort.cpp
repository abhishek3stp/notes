#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int start, int end)
{
    int i = start - 1;
    int pivot = a[end];

    for (int j = start; j <= end - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[end]);
    return i + 1;
}

void quickSort(int a[], int start, int end)
{
    if (start >= end)
        return;

    int p = partition(a, start, end);
    quickSort(a, start, p - 1);
    quickSort(a, p + 1, end);
}

int main()
{
    int a[] = {2, 15, 10, 7, 0, 13};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);

    for (auto e : a)
        cout << e << " ";

    return 0;
}
