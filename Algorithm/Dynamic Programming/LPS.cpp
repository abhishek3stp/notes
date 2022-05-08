#include <bits/stdc++.h>
using namespace std;

int lps(char str[], int start, int end)
{
    if (end == start)
        return 1;

    else if (start > end)
        return 0;

    else if (str[start] == str[end])
        return 2 + lps(str, start + 1, end - 1);

    else
        return max(lps(str, start, end - 1), lps(str, start + 1, end));
}

int lpsBU(char str[], int n)
{
    int dp[n][n] = {0};

    for (int gap = 0; gap < n; gap++)
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;

            else if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;

            else
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }

    return dp[0][n - 1];
}

int main()
{
    char str[] = "agbdba";
    int n = strlen(str);
    cout << lps(str, 0, n - 1) << endl;
    cout << lpsBU(str, n) << endl;
    return 0;
}
