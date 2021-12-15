#include<cstdio>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int SIZE = 2e5+2;
long long a[SIZE],prefix[SIZE],suffix[SIZE];
int main(){
    long long int x,c=0;
	cin>>x;
	while(x)
	{
       c=c+(x & 1);
	   x>>=1;	}
	   cout<<c<<endl;
}