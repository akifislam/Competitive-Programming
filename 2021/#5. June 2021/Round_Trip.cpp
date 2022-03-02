//Akif Islam (__SHERLOCK__)
//Date: 2021-06-09 09:20:41

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

const int SIZE = 1e5 + 5;

vector<int> graph[SIZE];
bool visited[SIZE];
vector<int> parent(SIZE,-1);

void DFS(int node, int par)
{
  visited[node] = true;
  parent[node] = par;

  for (auto x : graph[node])
  {
    if (!visited[x])
      DFS(x, node);

    //Already Visited
    else if (x != par)
    {

      //Got a Cycle
      vector<int> cycle;
      // cycle.pb(node); //5
      int cur = node;
      cycle.pb(node);

      while (parent[cur] != x)
      {
        cur = parent[cur];
        cycle.pb(cur); //5,
      }
      cycle.pb(x);
      cycle.pb(node);

      cout << cycle.size() << endl;
      for (auto x : cycle)
      {
        cout << x << " ";
      }
      cout << endl;
      exit(0);
    }
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;

  int from, to;

  for (int i = 0; i < m; i++)
  {
    cin >> from >> to;

    graph[from].pb(to);
    graph[to].pb(from);
  }

  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
      DFS(i, -1);
  }
  cout << "IMPOSSIBLE" << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test = 1;
  // cin >> test;
  while (test--)
  {
    solve();
  }
  return 0;
}