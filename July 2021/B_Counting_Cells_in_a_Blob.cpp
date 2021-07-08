#include <bits/stdc++.h>
using namespace std;
int n;
char graph[40][40];
int visited[40][40];
int cnt = 0;

int dx[] = {+1, -1, +0, -0, -1, -1, 1, 1};
int dy[] = {+0, -0, +1, -1, -1, 1, -1, 1};

bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n && !visited[i][j] && graph[i][j]!='0')
        return true;
    return false;
}

void DFS(int i, int j)
{
    if (visited[i][j])
        return;
    visited[i][j] = true;
    if (graph[i][j] == '1')
        cnt++;

    for (int x = 0; x < 8; x++)
    {
        int new_i = i + dx[x];
        int new_j = j + dy[x];

        if (valid(new_i, new_j))
            DFS(new_i, new_j);
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    gets(graph[0]);
    gets(graph[0]);
    
    while (t--)
    {
        n = 0;
        memset(graph, 0, sizeof(graph));
        while (gets(graph[n]))
        {
            if (graph[n][0] == '\0')
                break;
            n++;
        }
        int ans = 0;
        
        memset(visited,0,sizeof(visited));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; graph[i][j]; j++)
            {
                // cout << graph[i][j];
                if (graph[i][j] == '1' && !visited[i][j])
                {
                    cnt = 0;
                    DFS(i, j);
                    ans = max(ans, cnt);
                }
            }
            // cout << endl;
        }

        printf("%d\n", ans);
        if (t)
            puts("");
    }
    return 0;
}