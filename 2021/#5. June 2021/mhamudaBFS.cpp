#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1000;

vector<int> graph[SIZE];
int visited[SIZE];

//unweighted

void BFS(int src)
{
 
    queue<int> Q;

    Q.push(src);
    visited[src] = 0;

    while (!Q.empty()) //0
    {
        int cur = Q.front(); // 0
        Q.pop();

        for (auto x : graph[cur])
        {
            if (visited[x]==-1)
            {
                // cout << "Visiting : " << x << endl;
                visited[x] = visited[cur] + 1;
                Q.push(x);
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    memset(visited, -1, sizeof(visited));
    int from, to;

    for (int i = 0; i < edges; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    //
    BFS(0);

    for (int i = 1; i <=nodes; i++)
    {
        cout<<"Visited of "<<i<<" : "<<visited[i]<<endl;
    }
    

}