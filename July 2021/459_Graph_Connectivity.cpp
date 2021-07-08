#include <bits/stdc++.h>
using namespace std;

bool visited[30];
vector<int> graph[30];

void DFS(int x)
{
    if (visited[x])
        return;
    visited[x] = true;

    for (auto xx : graph[x])
        DFS(xx);
}

int dx[] = {+1, -1, +0, -0, -1, -1, 1, 1};
int dy[] = {+0, -0, +1, -1, -1, 1, -1, 1};

bool valid(int i,int j){
    if(i>)
}
void DFS(int i, int j)
{
    if (visited[i][j])
        return;
    visited[i][j] = true;

    for (int x = 0; x < 8; x++)
    {
        int new_i = i + dx[x];
        int new_j = j + dy[x];

        if(valid(new_i,new_j))
            DFS(new_i,new_j);
    }
}

int main()
{

    map<char, int> mp;

    //Mapping
    char xx = 'A';
    for (int i = 1; i <= 26; i++)
    {
        mp[xx] = i;
        xx++;
    }
    //----

    int t;
    scanf("%d\n", &t);

    while (t--)
    {
        memset(visited, 0, sizeof(visited));

        char N[2];
        gets(N);

        int largest_node = mp[N[0]];
        // printf("Total Nodes : %d\n", largest_node);

        char s[5];
        while (gets(s))
        {
            if (s[0] == '\0')
                break;
            int from = mp[s[0]];
            int to = mp[s[1]];

            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        //Print
        // printf("Weird Input\n");
        // for (int i = 1; i <= largest_node; i++)
        // {
        //     for (int j = 0; j < graph[i].size(); j++)
        //     {
        //         printf("%d --  %d\n", i, graph[i][j]);
        //     }
        // }

        int answer = 0;
        for (int i = 1; i <= largest_node; i++)
        {
            if (!visited[i])
            {
                DFS(i);
                answer++;
            }
        }
        if (t == 0)
            cout << answer << endl;
        else
            cout << answer << endl
                 << endl;
        //Clearing
        for (int i = 0; i <= largest_node; i++)
        {
            graph[i].clear();
        }
    }
}