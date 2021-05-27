void DFS(int x)
{
    if (visited[x])
        return;
    // cout << "Traversing Graph : " << x << endl;
    visited[x] = true;

    for (int i = 0; i < graph[x].size(); i++)
        DFS(graph[x][i]);
}