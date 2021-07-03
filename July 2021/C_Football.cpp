//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-01 22:04:31
#include <cstdio>
#include<vector>
 
using namespace std;
 
#ifdef AKIF
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')' << ':', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ll long long
#define lll __int128_t
#define pb push_back
#define mp make_pair
#define All(x) (x).begin(), (x).end()
#define sz(z) (int)((z).size())
 
int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};
 
void solve()
{
    int no_of_teams, wins;
    // cin >> no_of_teams >> wins;
    scanf("%d %d",&no_of_teams,&wins);
 
    //If wins > possible_wins
    int total_matches = (no_of_teams * (no_of_teams - 1)) / 2;
    int matches_per_team = no_of_teams - 1;
    int possible_wins = matches_per_team / 2;
 
    if (wins > possible_wins)
    {
        printf("-1\n");
        return;
    }
    // cout << wins * no_of_teams << endl;
    printf("%d\n",wins*no_of_teams);
    // +100 means Wins
    //-100 means lose
    //-1 No Game Yet
 
    //Result Process
 
    vector<vector<int>> graph(no_of_teams + 1, vector<int>(no_of_teams + 1, 0));
 
    //Making Graph
    // for (int i = 1; i < no_of_teams + 1; i++)
    // {
    //     for (int j = 0; j < (no_of_teams + 1); j++)
    //         graph[i].push_back(0);
    // }
 
    const int WIN = 100;
    const int LOSE = -100;
    //Process
    for (int i = 1; i < no_of_teams + 1; i++)
    {
        int t = wins;
        for (int j = 1; j < (no_of_teams + 1) && (t > 0); j++)
        {
            if (i == j || graph[i][j] == LOSE)
                continue;
 
            if (graph[i][j] == 0)
            {
                graph[i][j] = WIN;  //Win Value
                graph[j][i] = LOSE; //Lose Value
                printf("%d %d\n", i, j);
            }
            t--;
        }
    }
    return;
}
 
int main()
{
    // ios_base::sync_with_stdio(false);
#ifdef AKIF
#endif
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}