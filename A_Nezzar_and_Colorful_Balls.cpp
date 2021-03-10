#include <bits/stdc++.h>
using namespace std;

int main()
{
    int days,sumTime,minTime,maxTime;
    cin>>days>>sumTime>>minTime>>maxTime;

    if(minTime*days > sumTime) cout<<"NO"<<endl;
    else if(maxTime*days<sumTime) cout<<"NO"<<endl; 
}