#include<iostream>
using namespace std;
int a[200005];
bool b;

int main()
{
	int i,n;
	cin>>n;
	for(i=0;i<n;++i)cin>>a[i];

	for(i=0;i<=n;++i)
	{
		if(a[i]<0) b = true;
		if(a[i]%2!=0)a[i+1]--;
	}
	if(b)cout<<"NO";
	else cout<<"YES";
}