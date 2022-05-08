#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<char> q;
    int freq[26] = {0};

    char ch;
    cin >> ch;

    while (ch != '.')
    {
        q.push(ch);
        freq[ch - 'a']++;

        while (!q.empty())
        {
            if (freq[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << endl;
                break;
            }
        }

        if (q.empty())
            cout << -1 << endl;

        cin >> ch;
    }
}
