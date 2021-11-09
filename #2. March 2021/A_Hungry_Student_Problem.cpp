#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int x;
        cin>>x;
        
        bool isPossible = false;
        for (int i = 0; i < 34; i++)
        {
            for (int j = 0; j < 34; j++)
            {
                if(i*3+j*7 == x) {
                    isPossible = true;
                    break;
                }
            }
            if(isPossible) break;
            
        }
        if(isPossible) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        
    }
}