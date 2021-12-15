// Date: 2021-11-26 21:40:57

// Instruction ::
// 1. Never check the editorials before trying 3 times.
// 2. Never check other solutions before passing WA on testcase 2
// 3. Do not listen to others, follow your own advice.
// 4. If you don't see any improvement before February 2021, retired from CP.
// 5. To make your family happy, you have to code.

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
    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<int> permutation(n + 1);
    vector<int> weight(n + 1);
    vector<int> dist(n + 1, -1);

    int root = -1;

    for (int i = 1; i <= n; i++)
    {
        cin >> parent[i];
        if (parent[i] == i)
            root = i;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> permutation[i];
    }

    if (permutation[1] != root)
    {
        cout << -1 << endl;
        return;
    }

    dist[root] = 0;
    weight[root] = 0;

    for (int i = 2; i <= n; i++)
    {
        int node = permutation[i];
        int cur_parent = parent[node];

        if (dist[cur_parent] == -1)
        {
            cout << -1 << endl;
            return;
        }
        dist[node] = i - 1;
        weight[node] = dist[node] - dist[cur_parent];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << weight[i] << " ";
    }
    cout << endl;
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