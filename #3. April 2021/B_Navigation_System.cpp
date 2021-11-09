//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-24 02:05:39

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;
char gap = 32;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << gap << x;
    return os << '}';
}

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << gap << p.second << ')';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}

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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
mt19937 rng((uint_fast32_t)chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;

#define MAX 100005

void Breadth_First_Search(int s)
{
    // queue<int> q;
    // q.push(s);
    // depth[s] = 1;

    // //BFS
    // while (!q.empty())
    // {
    //     // cout << "Looping" << endl;
    //     int t = q.front();
    //     q.pop();

    //     for (auto x : reverse_graph[t])
    //     {
    //         if (depth[x] != 0)
    //             continue;

    //         depth[x] = depth[t] + 1;
    //         q.push(x);
    //     }
    // }
}

void solve()
{

    int no_of_nodes, no_of_paths;
    cin >> no_of_nodes >> no_of_paths;

    vector<int> graph[no_of_nodes + 1];
    vector<int> reverse_graph[no_of_nodes + 1];
    int depth[no_of_nodes + 1];
    int n1, n2, input;

    for (int i = 0; i < no_of_paths; i++)
    {
        cin >> n1 >> n2;
        graph[n1].pb(n2);
        reverse_graph[n2].pb(n1);
    }

    memset(depth, 0, sizeof(depth));
    int no_of_user_path;
    cin >> no_of_user_path;

    int user_input[no_of_user_path + 1];

    for (int i = 1; i <= no_of_user_path; i++)
    {
        cin >> user_input[i];
    }
    // Breadth_First_Search(user_input[no_of_paths]);
    // cout<<depth<<endl;
    // Input Done

    queue<int> q;
    q.push(user_input[no_of_user_path]);
    depth[user_input[no_of_user_path]] = 1;

    //BFS
    while (!q.empty())
    {
        // cout << "Looping" << endl;
        int t = q.front();
        q.pop();

        for (auto x : reverse_graph[t])
        {
            if (depth[x] != 0)
                continue;

            depth[x] = depth[t] + 1;
            q.push(x);
        }
    }

    // for (int i = 1; i <= no_of_nodes; i++)
    // {
    //     cout << depth[i] << " ";
    // }
    // cout << endl;

    //OK

    int minimum = 0, maximum = 0;
    int c = 0;

    for (int i = 1; i < no_of_user_path; i++)
    {
        if (depth[user_input[i]]-1 < depth[user_input[i + 1]] )
            minimum++;

        for (auto x : graph[user_input[i]])
        {
            if (x != user_input[i + 1] && depth[user_input[i]] == depth[x] + 1)
            {
                maximum++;
                break;
            }
        }
    }
    cout << minimum << " " << maximum << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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