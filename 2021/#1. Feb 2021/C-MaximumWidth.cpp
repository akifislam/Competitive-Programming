#include<bits/stdc++.h>
using namespace std;
 
vector<int> vec;
 
int main() {
 
    int n,m;
    cin>>n>>m;
 
    string s,t;
    cin>>s;
    cin>>t;
 
    //First letter Search
    int firstLetter = -1;
    int lastLetter = -1;
 
    for (int i = 0; i < n; i++) {
        if(t[0]==s[i]){
            firstLetter = i;
            break;
        }
    }
 
    //Last Letter Search
    for (int i = n-1; i>=0; i--) {
        if(t[m-1]==s[i]){
            lastLetter = i;
            break;
        }
    }
 
    if(t.size()==2) {
        cout<<lastLetter-firstLetter<<endl;
        return 0;
    }
 
    //Greater 2
    int answer = 1;
    int prev_letter = firstLetter;
    int new_first_letter ;
 
    for (int i = 1; i < m-1; i++) {
        for (int j = firstLetter+1; j < lastLetter; j++) {
//            cout<<"H"<<endl;
            if(t[i]==s[j]) {
                new_first_letter = j;
                answer = max(j - prev_letter, answer);
//                cout<<"Ans : "  <<answer<<endl;
            }
        }
        firstLetter = new_first_letter;
        prev_letter = new_first_letter;
    }
 
    cout<<answer<<endl;
 
 
}