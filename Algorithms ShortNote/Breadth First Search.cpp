void bfs(int src)
{

    queue<int> Q;

    //Start Node : Source (A)

    Q.push(src);
    visited[src] = true;

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            if (!visited[graph[cur][i]])
            {
                //True means Visited
                visited[graph[cur][i]] = true;
                Q.push(graph[cur][i]);
            }
        }
    }
}