//Akif Islam (__SHERLOCK__)
//Date: 2021-09-28 21:21:17
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
    int N;
    cin >> N;

    priority_queue<pair<int, int>> PQ;
    int input;

    for (int i = 1; i <= N; i++)
    {
        cin >> input;
        PQ.push({input, i});
    }

    vector<pair<int, int>> ans;
    vector<int> occur;

    int totalTalks = 0;

    while (!PQ.empty())
    {
        int top_value = PQ.top().first;
        int top_index = PQ.top().second;
        PQ.pop();
        if (top_value == 0)
            break;

        if (!PQ.empty())
        {
            int top2_value = PQ.top().first;
            int top2_index = PQ.top().second;
            PQ.pop();

            ans.push_back({top_index, top2_index});
            occur.push_back(min(top_value, top2_value));

            totalTalks += min(top_value, top2_value);
            PQ.push({top_value - top2_value, top_index});
        }
    }
    cout << totalTalks << endl;

    int SIZE = ans.size();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < occur[i]; j++)
        {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
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