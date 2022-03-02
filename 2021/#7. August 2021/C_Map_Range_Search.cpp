//Akif Islam (__SHERLOCK__)
//Date: 2021-08-25 20:01:43
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

void solve()
{
    ll Q;
    cin >> Q;

    // map<ll, string> xToKey;
    map<string, ll> keyToX;

    string key;
    ll type, x;

    for (int i = 0; i < Q; i++)
    {
        cin >> type;

        // Insert Key -- X
        if (type == 0)
        {
            cin >> key >> x;

            if (keyToX.find(key) != keyToX.end())
                keyToX.erase(key);

            keyToX[key] = x;
        }
        //Insert
        else if (type == 1)
        {
            cin >> key;
            auto x = keyToX.find(key);
            
            if (x != keyToX.end())
                cout << keyToX[key] << endl;
            else
                cout << 0 << endl;
        }
        //Delete
        else if (type == 2)
        {
            cin >> key;
            ll temp = keyToX[key];
            keyToX.erase(key);
            // xToKey.erase(temp);
        }
        else
        {
            string L, R;
            cin >> L >> R;

            auto it_start = keyToX.lower_bound(L);
            auto it_end = keyToX.upper_bound(R);

            for (auto it = it_start; it != it_end; it++)
            {
                cout << it->first << " " << it->second << endl;
            }
        }
    }
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