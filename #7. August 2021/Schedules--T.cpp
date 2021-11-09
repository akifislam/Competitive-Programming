//Akif Islam (__SHERLOCK__)
//Date: 2021-08-22 13:03:40
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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve()
{
    ll N;
    cin >> N;

    vector<pair<int, int>> classtime;

    int start;
    int end;

    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;
        classtime.push_back({end, start});
    }

    sort(classtime.begin(), classtime.end());

    int intersected = 0;

    int prev_end = -1;

    int answer = -1;

    for (int i = 0; i < N; i++)
    {
        if (prev_end > classtime[i].second)
        {
            intersected++;
            answer = i + 1;
        }
    }

    if (!intersected)
    {
        cout << N << endl;
        for (int i = 1; i <= N i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else if (intersected == 1)
    {
        cout << 1 << endl;
        cout << answer << endl;
    }
    else
        cout << 0 << endl;
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