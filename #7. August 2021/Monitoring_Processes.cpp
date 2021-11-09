//Akif Islam (__SHERLOCK__)
//Date: 2021-08-24 16:05:19
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
ll tc = 0;

void solve()
{

    ll no_of_process;
    cin >> no_of_process;

    vector<pair<ll, ll>> processes;

    for (int i = 0; i < no_of_process; i++)
    {
        ll start, end;
        cin >> start >> end;
        //Compression
        processes.push_back({start, 0}); // 0 Means Start of a Process
        processes.push_back({end, 1});   // 1 indicates ending time
    }

    // We will check in each time (second), max. how many process is running?

    sort(All(processes));

    ll cur_running = 0;
    ll answer = 0;

    for (auto process : processes)
    {
        // cout << process.first << " " << process.second << endl;
        if (process.second == 0)

            cur_running++;
        else
            cur_running--;

        answer = max(answer, cur_running);
    }

    cout << "Case " << ++tc << ": " << answer << endl;
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