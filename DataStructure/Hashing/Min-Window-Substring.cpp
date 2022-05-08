#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string p)
{
    int s_len = s.length(), p_len = p.length();

    if (p_len > s_len)
        return "None";

    int s_freq[256] = {0};
    int p_freq[256] = {0};
    int min_window = INT_MAX, start_ind = -1;

    for (int i = 0; i < p_len; i++)
    {
        char ch = p[i];
        p_freq[ch]++;
    }

    int cnt = 0, start = 0;
    for (int i = 0; i < s_len; i++)
    {
        char ch = s[i];
        s_freq[ch]++;

        if (p_freq[ch] != 0 and s_freq[ch] <= p_freq[ch])
            cnt++;

        if (cnt == p_len)
        {
            char temp = s[start];
            while (p_freq[temp] == 0 or s_freq[temp] > p_freq[temp])
            {
                start++;
                s_freq[temp]--;
                temp = s[start];
            }

            int window = i - start + 1;
            if (window < min_window)
            {
                min_window = window;
                start_ind = start;
            }
        }
    }

    if (start_ind == -1)
        return "None";

    else
        return s.substr(start_ind, min_window);
}

int main()
{
    string s = "helleeeo world";
    string p = "eelo";

    cout << minWindow(s, p);
}
