//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-16 15:20:05

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

int N;
bool visited[5002];
bool visited_R[5002];

int get_nearest_chair_L(int x)
{

    int ans_left = -1;
    int ans_right = -1;

    //Search for Left
    for (int i = x; i >= 0; i--)
    {
        if (!visited[i])
        {
            // visited[i] = true;
            ans_left = i;
            break;
        }
    }

    //Search for Right
    for (int i = x; i < N; i++)
    {
        if (!visited[i])
        {
            // visited[i] = true;
            ans_right = i;
            break;
        }
    }

    int final_answer = min(ans_left, ans_right);
    if (final_answer == -1)
    {
        if (ans_left != -1)
        {
            visited[ans_left] = true;
            return abs(ans_left - x);
        }
        else
        {
            visited[ans_right] = true;
            return abs(ans_right - x);
        }
    }
    else
        return abs(final_answer - x);
}

// int get_nearest_chair_R(int x)
// {
//     int ans = -1;
//     //Search for Right
//     for (int i = x; i < N; i++)
//     {
//         if (!visited_R[i])
//         {
//             visited_R[i] = true;
//             ans = i;
//             break;
//         }
//     }

//     if (ans != -1)
//     {
//         // cout << "Returning Position : " << ans << endl;
//         return abs(ans - x);
//     }

//     //Search for Left
//     for (int i = x; i >= 0; i--)
//     {
//         if (!visited_R[i])
//         {
//             visited_R[i] = true;
//             ans = i;
//             break;
//         }
//     }

//     // cout << "Returning Position : " << ans << endl;
//     return abs(ans - x);
// }

void solve()
{
    cin >> N;
    vector<int> vec(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
        if (vec[i] == 1)
        {
            visited[i] = 1;
            visited_R[i] = 1;
        }
    }

    //Process
    int answer_1 = 0;
    int answer_2 = 0;
    int answer = -1;

    for (int i = 0; i < N; i++)
    {
        if (vec[i] == 1)
            answer_1 += (get_nearest_chair_L(i));
    }

    // for (int i = N - 1; i >= 0; i--)
    // {
    //     if (vec[i] == 1)
    //         answer_2 += (get_nearest_chair_R(i));
    // }

    cout << answer_1 << endl;
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