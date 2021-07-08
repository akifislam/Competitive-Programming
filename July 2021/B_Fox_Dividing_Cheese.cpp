 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ull unsigned long long
#define OrderSetTree tree<ll,null_type/*mapped_type*/,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define gap ' '
#define yes cout<<"YES"
#define no cout<<"NO"
#define all(v) v.begin(),v.end()
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define mod 1000000007
#define MAX 33000
#define N 305
 
int main()
{
    fastio;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //OrderSetTree ost;
 
    ll i,j,t,n,p,q,ans=1;
    map<ll,ll>mp;
    cin>>n;
    
    for(i=0;i<n;i++)
    {   
        cin>>p;
        q=p;
 
        for(j=2;j*j<=p;j++)
        {
            if(q%j==0)
            {
                mp[j]++;
 
                while (q%j==0)
                    q/=j;
            }
        }
 
        if(q>1)
            mp[q]++;
    }
 
    for(auto i=mp.begin(); i!=mp.end(); i++)
        ans=max(ans,i->second);
 
    cout<<ans;
    cout<<"\n";
    return 0;   //:D
}