//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-02 22:07:10

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;
char gap = 32;

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

void solve()
{

    ll no_of_piles, no_of_towers, difference;
    cin >> no_of_piles >> no_of_towers >> difference;

    vector<pair<ll, ll>> vec;
    ll input;

    for (int i = 0; i < no_of_piles; i++)
    {
        cin >> input;
        vec.pb(make_pair(input, i));
    }
    sort(vec.begin(), vec.end(), greater<>());

    ll first_tower = 0;
    ll last_tower = 0;

    ll answer[no_of_piles];

    ll k = 1LL;

    for (int i = 0; i < no_of_piles; i++)
    {
        // cout << "K = " << k << endl;
        answer[vec[i].second] = k;

        if (k == 1)
        {
            first_tower += vec[i].first;
        }

        if (k == no_of_towers)
        {
            last_tower += vec[i].first;
            k = 0;
        }
        k++;
    }

    // cout << "First Tower Got :" << first_tower << endl;
    // cout << "Last Tower Got : " << last_tower << endl;

    if (last_tower - first_tower > difference){
        cout<<"NO"<<endl;
        return;
    }
    else {
        cout<<"YES"<<endl;
        for (int i = 0; i < no_of_piles; i++)
        {
            cout<<answer[i]<<" ";
        }
        cout<<endl;
        
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