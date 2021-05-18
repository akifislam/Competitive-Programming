#include <bits/stdc++.h>
using namespace std;

//Weighted Graph Input
vector<vector<pair<int, int>>> graph;

vector<int> processed;
vector<int> dist;
int n, m;

void Dijkstra(int src)
{

    //Initialize
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    //Weight, Node
    dist[src] = 0;

    priority_queue<pair<int, int>> Q;
    Q.push({0, src});

    while (!Q.empty())
    {
        auto x = Q.top();
        Q.pop();

        int w = x.first;
        int u = x.second;

        if (processed[u])
            continue;
        else
            processed[u] = true;

        for (auto p : graph[u])
        {
            int v = p.first;  //Neighbour Node
            int d = p.second; //Neighbour Distance

            if (dist[v] > dist[u] + d)
            {
                dist[v] = dist[u] + d;
                Q.push({-dist[v], v});
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;

    for (int xx = 1; xx <= t; xx++)
    {

        cin >> n >> m;

        graph.clear();
        dist.clear();
        processed.clear();

        graph.resize(n + 1);
        dist.resize(n + 1, 0);
        processed.resize(n + 1, 0);

        int from, to, w;

        for (int i = 0; i < m; i++)
        {
            cin >> from >> to >> w;
            graph[from].push_back({to, w});
            graph[to].push_back({from, w});
        }

        Dijkstra(1);
        //Print
        if (dist[n] == INT_MAX)
            printf("Case %d: Impossible\n", xx);
        else
            printf("Case %d: %d\n", xx, dist[n]);
    }
}