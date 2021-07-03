//Superb
//Interesting Problem
//Akif Islam (__SHERLOCK__)
//Date: 2021-06-29 05:07:45

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

    vector<ll> vec(N);
    ll ans_1 = 0;
    ll ans_2 = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    sort(All(vec));

    ans_1 = vec.back();
    //Cuting the divisor of Ans_1 (means -1) //20
    int prev = -1;
    for (int i = 0; i < N; i++)
    {
        if (vec[i] != prev && (ans_1 % vec[i] == 0))
        {
            prev = vec[i];
            vec[i] = -1;
        }
        else
        {
            ans_2 = max(ans_2, vec[i]);
        }
    }
    cout << ans_1 << " " << ans_2 << endl;
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