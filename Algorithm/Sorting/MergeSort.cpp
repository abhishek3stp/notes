#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int left, int right)
{
    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = left;

    int temp[1000];

    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];

    for (i = left; i <= right; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, right);
}

int main()
{
    int a[] = {2, 15, 10, 7, 0, 13};
    int n = sizeof(a) / sizeof(a[0]);

    mergeSort(a, 0, n - 1);

    for (auto e : a)
        cout << e << " ";

    return 0;
}
