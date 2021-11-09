//Akif Islam (__SHERLOCK__)
//Date: 2021-07-06 19:42:14

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;

char gap = 32;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << gap << x;
    return os << '}';
}

#define ll long long
#define pb push_back
#define All(x) (x).begin(), (x).end()
ll tc = 1;

vector<ll> get_divisors(ll num)
{

    vector<ll> D;

    for (ll i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            D.pb(i);
            if (i != num / i)
            {
                D.pb(num / i);
            }
        }
    }
    sort(All(D));
    return D;
}

void solve(ll input)
{
    if (input == 1)
    {
        cout << input << " " << 1 << endl;
        return;
    }
    vector<ll> divisors = get_divisors(input);

    ll count = 0;
    for (ll i = 0; i < divisors.size(); i++)
    {
        for (ll j = i; j < divisors.size(); j++)
        {
            if (((divisors[i] * divisors[j]) / (__gcd(divisors[i], divisors[j]))) == input)

                count++;
        }
    }
    cout << input << " " << count << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll input = 1;

    while (cin >> input)
    {
        if (input == 0LL)
            return 0;
        solve(input);
    }
}
