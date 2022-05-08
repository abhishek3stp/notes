#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x[100], y[100];

    int width, height, n;
    cin >> width >> height >> n;

    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    sort(x, x + n);
    sort(y, y + n);

    int dx = x[0] - 1;
    int dy = x[0] - 1;

    for (int i = 1; i < n; i++)
    {
        dx = max(dx, x[i] - x[i - 1] - 1);
        dy = max(dy, y[i] - y[i - 1] - 1);
    }

    dx = max(dx, width - x[n - 1]);
    dy = max(dy, height - y[n - 1]);

    cout << dx * dy << endl;
}
