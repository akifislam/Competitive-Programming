//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-06-27 16:23:35

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << " " << x;
    return os << '}';
}

// 1 2 4 5 10
void solve()
{
    ll N, K;
    cin >> N >> K;

    if (N < K)
    {
        cout << -1 << endl;
        return;
    }

    if (K == 1)
    {
        cout << 1 << endl;
        return;
    }

    vector<ll> divisors;
    divisors.push_back(1);
    divisors.push_back(N);
    for (ll i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            divisors.push_back(i);
            if (N / i != i)
                divisors.push_back(N / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    // cout << divisors << endl;
    if (divisors.size() < K)
        cout << -1 << endl;
    else
        cout << divisors[K - 1] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}