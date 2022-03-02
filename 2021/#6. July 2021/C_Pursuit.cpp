//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-18 10:37:23
// Hard Implementation
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

int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};

void solve()
{

    ll N, input;
    cin >> N;

    vector<ll> Me;
    vector<ll> Ilya;

    Me.pb(0);
    Ilya.pb(0);

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        Me.pb(input);
    }

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        Ilya.pb(input);
    }

    sort(All(Me));
    sort(All(Ilya));
    partial_sum(All(Me), Me.begin());
    partial_sum(All(Ilya), Ilya.begin());

    ll cur_stage = N;
    ll top_count = (N / 4); //Top Jotogula Score Count hobe. //3
    ll answer = 0;
    ll MePoints = Me.back() - Me[top_count];
    ll IlyaPoints = Ilya.back() - Ilya[top_count];

    if (MePoints >= IlyaPoints)
    {
        cout << 0 << endl;
    }
    else
    {
        // cout << "Me : " << MePoints << "| Ilya : " << IlyaPoints << endl;
        while (MePoints < IlyaPoints)
        {
            cur_stage++;
            top_count = (cur_stage / 4);
            Me.pb(Me.back() + 100);
            MePoints = Me.back() - Me[top_count];
            //Extra Zero for Ilya

            if (cur_stage - top_count >= N)
                IlyaPoints = Ilya.back();
            // cout << "Me : " << MePoints << "| Ilya : " << IlyaPoints << endl;
        }
        cout << cur_stage - N << endl;
    }
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