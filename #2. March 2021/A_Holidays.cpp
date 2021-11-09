#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    if(n%7 == 0)
    cout<<(n/7)*2<<" "<<(n/7)*2<<endl;

    else {
        //8 Days
        //Answer would be Max 4 Days
        // Minimum
        int temp = n%7;
        
        if(temp<=2) cout<<(n/7)*2<<" "<<(n/7)*2 +temp <<endl;
        else if (temp==6) cout<<(n/7)*2+1<<" "<<(n/7)*2+2<<endl;
        else cout<<(n/7)*2<<" "<<(n/7)*2+2<<endl;
    }
}