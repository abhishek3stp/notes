#include <bits/stdc++.h>
using namespace std;

vector<int> primeSieve(int n) // Return vector of prime numbers upto n
{
    bool prime[n + 1] = {false};

    for (int i = 3; i <= n; i += 2)
        prime[i] = true;

    for (int i = 3; i <= n; i += 2)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    vector<int> p;
    p.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (prime[i] == true)
            p.push_back(i);
    }
    return p;
}

void factorizePS(int n) // By using Prime Sieve
{
    vector<int> prime = primeSieve(n);

    for (int i = 0; i * i <= n; i++)
    {
        int p = prime[i];
        if (n % p == 0)
        {
            cout << p << " ";
            while (n % p == 0)
                n = n / p;
        }
    }
    if (n != 1)
        cout << n;
    return;
}

void factorize(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n = n / i;
            cout << i << " ";
        }
    }
    if (n != 1)
        cout << n;
    return;
}

int main()
{
    int n;
    cin >> n;
    factorize(n);
    factorizePS(n);
}
