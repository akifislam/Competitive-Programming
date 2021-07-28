//Akif Islam (__SHERLOCK__)
//Date: 2021-07-28 20:56:26

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

void solve()
{
    ll N;
    cin >> N;

    vector<ll> vec;
    vec.pb(0);

    for (int i = 0; i < N; i++)
    {
        ll input;
        cin >> input;
        vec.pb(input);
    }
    vec.pb(1e5 + 5);

    set<ll> ans;

    for (int i = 1; i <= N; i++)
    {
        //Find Awkward item
        if (vec[i - 1] < vec[i] && vec[i] < vec[i + 1])
            continue;
        else
            ans.insert(vec[i]);
    }

    //Print Set
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
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