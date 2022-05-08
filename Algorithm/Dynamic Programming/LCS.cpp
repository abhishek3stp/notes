#include <bits/stdc++.h>
using namespace std;

int lcs(char str1[], char str2[], int n, int m)
{
    if (n == 0 or m == 0)
        return 0;

    if (str1[n - 1] == str2[m - 1])
        return 1 + lcs(str1, str2, n - 1, m - 1);

    else
        return max(lcs(str1, str2, n - 1, m), lcs(str1, str2, n, m - 1));
}

int lcsBU(char str1[], char str2[], int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;

            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }

    return dp[n][m];
}

int main()
{
    char str1[] = "aggtab";
    char str2[] = "gxtxayb";
    int n = strlen(str1), m = strlen(str2);

    cout << lcs(str1, str2, n, m) << endl;
    cout << lcsBU(str1, str2, n, m) << endl;
}
