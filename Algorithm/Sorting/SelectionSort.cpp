#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &a)
{
	for (int i = 0; i < a.size() - 1; i++)
	{
		int min_index = i;

		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[j] < a[min_index])
				min_index = j;
		}
		swap(a[min_index], a[i]);
	}
}

int main()
{
	vector<int> a = {2, 15, 10, 7, 0, 13};

	selectionSort(a);

	for (auto e : a)
		cout << e << " ";

	return 0;
}
