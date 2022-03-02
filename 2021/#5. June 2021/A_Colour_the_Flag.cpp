/******************************************************************************
 
                         بسم الله الرحمن الرحيم
                     Author: Mst: Mhamuda Khatun
                               RUCSE27
 
*******************************************************************************/
 
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
#define MAX 100004
#define N 305
 
int main()
{
    fastio;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //OrderSetTree ost;
 
    ll i,j,t,n,m;
    cin>>t;
 
    while(t--)
    {    
        
        cin>>n>>m;
        char v[n][m],x[n][m],ch;
        bool flag=true,flag2=true;
 
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>v[i][j];
                x[i][j]=v[i][j];
            }
        }
 
        for(i=0;i<n;i++)
        {   
            if(i&1)
                ch='R';
            else
                ch='W';
 
            for(j=0;j<m;j++)
            {
                if(v[i][j]=='.')
                    v[i][j]=ch;
                else
                {
                    if(ch!=v[i][j])
                    {   
                        //cout<<i<<" "<<j<<"\n";
                        flag=false;
                        break;                       
                    }
                }
                
                if(ch=='R')
                    ch='W';
                else
                    ch='R';
                
            }
 
            if(!flag)
                break;
        }
 
        if(!flag)
        {
            for(i=0;i<n;i++)
            {   
                if(i&1)
                    ch='W';
                else if(i%2==0)
                    ch='R';
 
                for(j=0;j<m;j++)
                {
                    if(x[i][j]=='.')
                        x[i][j]=ch;
                    else
                    {
                        if(ch!=x[i][j])
                        {   
                            //cout<<i<<" "<<j<<"\n";
                            flag2=false;
                            break;                       
                        }
                    }
                    
                    if(ch=='R')
                        ch='W';
                    else
                        ch='R';
                    
                }
                if(!flag2)
                    break;
            }
        }
 
        if(flag)
        {
            yes;
            cout<<"\n";
 
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                    cout<<v[i][j];
 
                cout<<"\n";
            }
        }
        else if(flag2)
        {
            yes;
            cout<<"\n";
 
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                    cout<<x[i][j];
 
                cout<<"\n";
            }
        }
        else
        {
            no;
            cout<<"\n";
        }
        
    }
    
    return 0;   //:D
}