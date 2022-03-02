#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
bool visited[1000];

void DFS(int src)
{
    if (visited[src])
        return;
    cout << "Visiting : " << src << endl;
    visited[src] = true;

    for (auto x : graph[src])
        DFS(x);
}

int main()
{

    memset(visited, 0, sizeof(visited));

    int node, edges;
    cin >> node >> edges;

    int from, to;

    for (int i = 0; i < edges; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    DFS(1);
}