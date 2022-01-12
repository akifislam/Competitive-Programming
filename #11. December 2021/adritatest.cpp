int dx[] = {+1, -1, +0, 0};
int dy[] = {+0, 0, +1, -1};


bool isOkay(int i, int j)
{
    if ((i >= 0 && i < H) && (j >= 0 && j < W))
        return true;
    return false;
}

void DFS(int i, int j)
{
    // printf("Visiting Cell : [%d][%d]\n", i, j);
    if (visited[i][j])
        return;

    visited[i][j] = true;
    answer++;

    for (int x = 0; x < 4; x++)
    {
        int next_i = i + dx[x]; // i
        int next_j = j + dy[x];
        if (isOkay(next_i, next_j))
            DFS(next_i, next_j);
    }
}

void solve()
{
    answer = 0;
    memset(visited, false, sizeof(visited));

    cin >> W >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == '#')
                visited[i][j] = true;

            if (graph[i][j] == '@')
            {
                start_i = i;
                start_j = j;
            }
        }
    }
    DFS(start_i, start_j);
    printf("Case %d: %d\n",tc++,answer);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}