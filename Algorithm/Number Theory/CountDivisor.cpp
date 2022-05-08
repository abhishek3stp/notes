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

int countDivisor(int n)
{
    vector<int> prime = primeSieve(n);
    int ans = 1;

    for (int i = 0; i * i <= n; i++)
    {
        int p = prime[i];
        if (n % p == 0)
        {
            int cnt = 0;
            while (n % p == 0)
            {
                n = n / p;
                cnt++;
            }
            ans *= cnt + 1;
        }
    }
    if (n != 1)
        ans *= 2;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << countDivisor(n);
}
