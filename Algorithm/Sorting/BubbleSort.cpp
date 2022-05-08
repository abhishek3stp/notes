#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

int main()
{
	vector<int> arr = {2, 15, 10, 7, 0, 13};
	bubbleSort(arr);

	for (auto e : arr)
		cout << e << " ";

	return 0;
}
