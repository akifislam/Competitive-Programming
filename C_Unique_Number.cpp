//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-01 02:50:19


#include <bits/stdc++.h>


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



#define ll long long 
#define pb push_back
#define mp make_pair
typedef pair < int,int> ii;
typedef vector<ii> vii;
typedef vector<ll>vl;
typedef vector<int> vi;
typedef vector<vi> vvi;

int sumOfDigit(int x) {
    int sum = 0;
    while(x>0) {
        sum+= x%10;
        x/=10;
    }
    return sum;
}



void solve(){
    int n;
    cin>>n;

    if(n>45) cout<<-1<<endl;
    else if(n<10) cout<<n<<endl;
    //10 to 40
    else {
        int N = n;//10
        int weight = 1;
        int answer = 0;
        int disDigit = 9;

        while(N>0){
            answer+=min(disDigit,N)*weight;
            N-=disDigit;
            weight*=10;
            disDigit--;
        }
        // if(answer<N) 
        // cout<<-1<<endl;
        // else
         cout<<answer<<endl;
    }
}











int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);


  int test=1;
    cin>>test;
  while(test--){
  solve();
    }
return 0;
}