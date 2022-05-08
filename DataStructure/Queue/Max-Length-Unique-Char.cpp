#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[] = "abbacdeb";
    int n = strlen(s);

    int current_len = 1, max_len = 1;
    int visited[256];

    for (int i = 0; i < 256; i++)
        visited[i] = -1;

    visited[s[0]] = 0;

    for (int i = 1; i < n; i++)
    {
        int last_occ = visited[s[i]];

        if (last_occ == -1 or i - current_len > last_occ)
        {
            current_len++;
        }
        else
        {
            if (current_len > max_len)
                max_len = current_len;

            current_len = i - last_occ;
        }
        visited[s[i]] = i;
    }

    if (current_len > max_len)
        max_len = current_len;

    cout << max_len << endl;
}
