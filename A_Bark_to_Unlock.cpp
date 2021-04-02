#include<bits/stdc++.h>
using namespace  std;
int main() {
    
    string password;
    cin>>password;

    int n;
    cin>>n;

    bool gotFirstLetter = false;
    bool gotLastLetter = false;
    bool gotPassword = false;

    while(n--) {
        string s;
        cin>>s;
        if(s == password) {
            gotFirstLetter = true;
            gotLastLetter = true;
        }
        if(s[1]==password[0]) gotFirstLetter = true;
        if(s[0]==password[1]) gotLastLetter = true;

    }

    if(gotFirstLetter && gotLastLetter) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}