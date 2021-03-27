#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        for (int i = n; i>0; i--)
        {
            if(n%2==1 && i ==(n+1)/2) continue;
            else cout<<i<<" ";
        }
        if(n%2==1) cout<<(n+1)/2<<endl;
        else cout<<endl;
        
    }
}