#include <bits/stdc++.h>
using namespace std;

void filter(string str, int n)
{
    int i = 0;
    while (n > 0)
    {
        int lastbit = (n & 1);
        if (lastbit)
            cout << str[i];
        i++;
        n = n >> 1;
    }
    cout << endl;
}

int main()
{
    string str = "abc";
    int n = str.length();

    for (int i = 0; i < (1 << n); i++)
        filter(str, i);

    return 0;
}
