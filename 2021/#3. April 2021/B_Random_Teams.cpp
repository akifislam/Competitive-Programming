//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-16 03:03:44


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>


using namespace __gnu_pbds;
using namespace std;
char gap = 32;


template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}


template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first << gap << p.second << ')';
}



void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { 
    cerr << ' ' << H;
     dbg_out(T...); 
}


#ifdef AKIF
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')'<<':', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ll long long 
#define lll __int128_t
#define pb push_back
#define mp make_pair
#define All(x) (x).begin(),(x).end()
#define sz(z) (int)((z).size())
typedef pair < int,int> ii;
typedef vector<ii> vii;
typedef vector<ll>vl;
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

ll fact(ll n);
 
ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
// Returns factorial of n
ll fact(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}


void solve(){
    ll n, r;
    cin>>n>>r;

    if(r==1){
        cout<<nCr(n,2)<<" "<<nCr(n,2)<<endl;
        return;
    }
    //Minimum
    ll et_mem = n/r;
    if(n%r==0){
        cout<<nCr(n/3,2)*r<<" ";
    }
    else {
        cout<<nCr(n/3,2)*(r-1) + nCr((n/r + n%r),2)<<" ";
    }
       //Maximum
    ll max_ans = nCr(n-r+1,2);
    cout<<max_ans<<endl;




}



int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifdef AKIF
#endif
  int test=1;
    // cin>>test;
  while(test--){
  solve();
    }
return 0;
}