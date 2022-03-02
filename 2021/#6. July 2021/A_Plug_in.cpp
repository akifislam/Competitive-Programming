#include<bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
 
char c[222222];
vector<char> v;
 
int main(){
	gets(c);
	int n=strlen(c);
	// reallazy
	REP(i,n){
		if(v.size()&&v.back()==c[i])
			v.pop_back();
		else v.push_back(c[i]);
	}
	REP(i,v.size())printf("%c",v[i]);
	puts("");
	return 0;
}