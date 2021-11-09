//Akif Islam (__SHERLOCK__)
//Date: 2021-06-05 07:02:55

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
int n, m;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> sortedLightOrder;

int tc = 1;
void nuclearBomb()
{
    graph.clear();
    visited.clear();

    graph.resize(n + 1);
    visited.resize(n + 1);
}

void topSort(int x)
{
    if (visited[x])
        return;
    visited[x] = true;
    for (auto u : graph[x])
        topSort(u);

    sortedLightOrder.push_back(x);
}

void DFS(int x)
{
    if (visited[x])
        return;
    visited[x] = true;

    for (auto u : graph[x])
        DFS(u);
}
void solve()
{
    cin >> n >> m;
    int from, to;

    nuclearBomb();

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        graph[from].pb(to);
    }

    // Top Sort
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            topSort(i);
    }

    reverse(All(sortedLightOrder));

    // cout << sortedLightOrder << endl;

    int answer = 0;

    visited.clear();
    visited.resize(n + 1, 0);

    for (int i = 0; i < sortedLightOrder.size(); i++)
    {
        if (!visited[sortedLightOrder[i]])
        {
            DFS(sortedLightOrder[i]);
            answer++;
            // cout << visited << endl;
        }
    }
    cout << "Case "<<tc++<<": "<<answer << endl;
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