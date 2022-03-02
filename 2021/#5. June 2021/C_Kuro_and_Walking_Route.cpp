//Akif Islam (__SHERLOCK__)
//Date: 2021-06-09 12:53:42

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

#define int long long
#define pb push_back
#define All(x) (x).begin(), (x).end()

const int SIZE = 3e5 + 5;

vector<int> graph[SIZE];
vector<int> dist(SIZE, -1);
vector<int> shortest_path;
int n, x, y;

void findingShortestPath(int src)
{
    if (src == y)
    {
        shortest_path.pb(y);
        return;
    }

    shortest_path.push_back(src);

    for (auto x : graph[src])
    {
        if (dist[x] == dist[src] - 1)
        {
            findingShortestPath(x);
            break;
        }
    }
}

void BFS(int src)
{

    dist[src] = 0;

    queue<int> Q;
    Q.push(src);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (auto u : graph[cur])
        {
            if (dist[u] == -1)
            {
                Q.push(u);
                dist[u] = dist[cur] + 1;
            }
        }
    }
}

bool visited[SIZE];
int cnt = 0;

void DFS(int x)
{
    if (visited[x])
        return;

    cnt++;

    visited[x] = true;

    for (auto xx : graph[x])
        DFS(xx);
}

void solve()
{
    cin >> n >> x >> y;

    int from, to;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> from >> to;
        graph[from].pb(to);
        graph[to].pb(from);
    }

    BFS(y);
    findingShortestPath(x);
    // cout << shortest_path << endl;

    if (shortest_path.size() > 2)
    {
        visited[shortest_path[1]] = visited[shortest_path[shortest_path.size() - 2]] = true;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << visited[i] << " ";
    // }
    // cout << endl;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dist[i] << " ";
    // }
    // cout << endl;

    //Counting Left Side
    visited[y] = true; // Pashapashi X,Y thakle Jhamela Hobe. Tai Visited.
    DFS(x);
    int left = cnt;
    cnt = 0;
    // cout << "Left : " << left << endl;
    //Counting Right Side
    visited[y] = false;
    DFS(y);
    int right = cnt;

    cout << (n * (n - 1)) - (left * right) << endl;
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