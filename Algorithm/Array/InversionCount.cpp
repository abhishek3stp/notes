#include <bits/stdc++.h>
using namespace std;

int merge(int a[], int left, int right)
{
    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = left;

    int temp[1000];
    int count = 0;

    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            count += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];

    for (i = left; i <= right; i++)
        a[i] = temp[i];

    return count;
}

int inversionCount(int a[], int left, int right)
{
    if (left >= right)
        return 0;

    int mid = (left + right) / 2;
    int count = inversionCount(a, left, mid);
    count += inversionCount(a, mid + 1, right);
    count += merge(a, left, right);

    return count;
}

int main()
{
    int a[] = {5, 3, 2, 1, 4};
    int n = sizeof(a) / sizeof(a[0]);

    cout << inversionCount(a, 0, n - 1) << endl;

    return 0;
}
