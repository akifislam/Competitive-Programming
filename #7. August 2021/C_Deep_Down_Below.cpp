//Akif Islam (__SHERLOCK__)
//Date: 2021-08-24 21:30:49
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

    ll no_of_caves;
    cin >> no_of_caves;

    vector<pair<ll, ll>> sorted_req_power;

    vector<ll> caves[no_of_caves + 1];

    ll no_of_monsters, power;

    for (int i = 0; i < no_of_caves; i++)
    {
        cin >> no_of_monsters;

        ll max_value = -1, max_index = -1;

        for (int j = 0; j < no_of_monsters; j++)
        {
            cin >> power;
            caves[i].push_back(power);

            if (max_value < power)
            {
                max_value = power;
                max_index = j;
            }
        }
        ll req_power = max_value - max_index + 1;
        cout << "Required Max Power : " << max_value - max_index + 1 << endl;
        sorted_req_power.push_back({req_power, i});
    }

    sort(All(sorted_req_power));

    ll start_power = sorted_req_power[0].first;
    cout << "Start Power : " << start_power << endl;
    ll cur_power = sorted_req_power[0].first;
    ll inc = 0;
    ll max_inc = 0;
    cout << cur_power << endl;

    for (int i = no_of_caves - 1; i >= 0; i--)
    {
        ll cur_cave = sorted_req_power[i].second;
        for (int j = 0; j < caves[cur_cave].size(); j++)
        {
            cout << "Cur Cave : " << caves[cur_cave][j] << endl;
            if (cur_power > caves[cur_cave][j])
                cur_power++;
            else
            {

                inc += caves[cur_cave][j] - cur_power + 1;
                cout << "Incre : " << inc << endl;

                // max_inc = max(max_inc, inc);
                cur_power += (caves[cur_cave][j] - cur_power + 1);
                cur_power++;
            }
        }
    }
    cout << start_power + inc << endl;
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