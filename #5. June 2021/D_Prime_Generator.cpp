//Akif Islam (__SHERLOCK__)
//Date: 2021-06-27 18:30:01

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define All(x) (x).begin(), (x).end()

vector<bool> segmentedSieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false); // 1 1 0 1 0 1 0 0 ...
    //2 theke Sqrt of Last Range Porjonto Shobgulor Moddhe Prime gulo ber kore nicchi
    vector<long long> primes; // 2,3,5...

    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

void solve()
{
    ll l, r;
    cin >> l >> r;

    vector<bool> segPrime;
    segPrime = segmentedSieve(l, r);

    for (int i = 0; i < segPrime.size(); i++)
    {
        if (segPrime[i])
            cout << i + l << endl;
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}