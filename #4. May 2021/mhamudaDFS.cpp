#include <bits/stdc++.h>
using namespace std;

vector<int> graph[9];

// Visited or Not Visited
bool visited[9];

void DFS(int x)
{
    if (visited[x])
        return;
    // cout << "Traversing Graph : " << x << endl;
    visited[x] = true;

    for (int i = 0; i < graph[x].size(); i++)
        DFS(graph[x][i]);
}


int main()
{    //Adjancecy List
    int n1, n2;
    for (int i = 1; i <= 8; i++)
    {
        //n1 er sathe n2 connected
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
    }
    DFS(2);
}

