//Akif Islam (__SHERLOCK__)
//Date: 2021-08-18 06:12:37
// Ask Less, Practise More :)

#include <bits/stdc++.h>

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

ll n, k;
ll x;

vector<ll> vec;

bool check(ll x)
{
    ll required_moves = 0;
    for (int i = n / 2; i < n; i++)
    {
        if (x - vec[i] > 0)
            required_moves += x - vec[i];

        if (required_moves > k)
            return false;
    }
    cout << "RM :"<<required_moves << endl;
    return true;
}

void solve()
{
    cin >> n >> k;
    ll input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        vec.push_back(input);
    }
    sort(All(vec));

    ll small = 1;
    ll big = 2e9;

    while (small != big)
    {
        ll mid = (small + big + 1) / 2;
        if (check(mid))
            small = mid;
        else
            big = mid - 1;
        cout << "Mid : " << mid << endl;
    }
    cout << small << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}