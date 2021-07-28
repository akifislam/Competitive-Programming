//Akif Islam (__SHERLOCK__)
//Date: 2021-07-28 19:41:58

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

void MAP(map<ll, ll> mp)
{
    cout << "--MAP--" << endl;

    for (auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << "-----" << endl;
}

void SET(set<ll> s)
{
    cout << "--SET--" << endl;
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "-----" << endl;
}

void solve()
{
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    //Input Done
    set<ll> s;
    map<ll, ll> mp;
    ll j = 0;

    for (int i = 0; i < N; i++)
    {
        // MAP(mp);

        mp[A[i]]++;

        //If the item is only once piece, Push into Set
        if (mp[A[i]] == 1)
        {
            s.insert(A[i]);
        }

        //Item is going to be duplicate
        else if (s.count(A[i]) >= 1)
        {
            s.erase(A[i]);
        }

        if (i < K - 1)
            continue;
        // SET(s);

        if (s.size())
        {
            cout << *s.rbegin() << endl;
        }
        else
        {
            cout << "Nothing" << endl;
        }

        mp[A[j]]--; //ith item ta ar Segment e porbena. So Ota Bad. Ekta Komai Dilam

        //Ekta Komanor porew jodi dekhi ar just 1 ta ache, tahole Set e PUSH
        if (mp[A[j]] == 1)
            s.insert(A[j]);

        else if (s.count(A[j])>= 1)
            s.erase(A[j]);

        j++;
    }
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}