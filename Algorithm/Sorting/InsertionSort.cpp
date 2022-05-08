#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i], j = i - 1;

        while (j >= 0 and arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    vector<int> arr = {2, 15, 10, 7, 0, 13};
    insertionSort(arr);

    for (auto e : arr)
        cout << e << " ";

    return 0;
}
