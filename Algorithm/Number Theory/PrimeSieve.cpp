#include <bits/stdc++.h>
using namespace std;
#define ll long long

void primeSieve(bool prime[]) // Return bool array in which prime numbers are true
{
    for (ll i = 3; i <= 1000000; i += 2)
        prime[i] = true;

    for (ll i = 3; i <= 1000000; i += 2)
    {
        if (prime[i] == true)
        {
            for (ll j = i * i; j <= 1000000; j += i)
                prime[j] = false;
        }
    }
    prime[2] = true;
    prime[0] = prime[1] = false;
}

int main()
{
    bool prime[1000005] = {false};
    primeSieve(prime);
    int n = 100;

    for (int i = 0; i < n; i++)
        if (prime[i] == true)
            cout << i << " ";
    cout << endl;
}
