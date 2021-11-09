//Akif Islam (__SHERLOCK__)
//Date: 2021-08-25 19:53:01
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
    ll N;
    cin >> N;

    vector<ll> vec(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    sort(All(vec));

    vector<ll> answer;

    for (int i = 0; i < N; i += 2)
    {
        answer.push_back(vec[i]);
    }

    ll st = N - 1;
    if (N % 2 == 1)
        st--;

    for (int i = st; i >= 0; i -= 2)
    {
        answer.push_back(vec[i]);
    }

    for (auto x : answer)
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