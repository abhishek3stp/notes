#include <bits/stdc++.h>
using namespace std;
#define ll long long

void primeSieve(int prime[])
{
    for (ll i = 3; i <= 100000; i += 2)
        prime[i] = 1;

    for (ll i = 3; i <= 100000; i += 2)
    {
        if (prime[i] == 1)
        {
            for (ll j = i * i; j <= 100000; j += i)
                prime[j] = 0;
        }
    }
    prime[2] = 1;
    prime[0] = prime[1] = 0;
}

int main()
{
    int prime[100005] = {0};
    primeSieve(prime);
    int csum[100005] = {0};

    for (ll i = 1; i <= 100000; i++)
        csum[i] = csum[i - 1] + prime[i];

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << csum[b] - csum[a - 1] << endl;
    }
}
