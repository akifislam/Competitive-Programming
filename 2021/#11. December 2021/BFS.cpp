#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
bool visited[1000];

void BFS(int src)
{


    queue<int> Q;

    visited[src] = true;
    Q.push(src);

    cout << "Visiting :" << src << endl;

    while (!Q.empty())
    {

        int cur = Q.front();
        Q.pop();

        for (auto x : graph[cur])
        {
            if (!visited[x])
            {
                Q.push(x);
                cout << "Visiting :" << x << endl;
            }

            visited[x] = true;
        }
    }
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
    BFS(1);
}