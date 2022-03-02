// Small Solution Collected from All Submissions.

#include <bits/stdc++.h>
using namespace std;
int t,n;
string a,b;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		bool flag = 0;
		for (int i=0;i<a.size();i++)
		{
			string s1=a.substr(0,i+1),s2=a.substr(0,i);
			reverse(s2.begin(),s2.end());
			s1+=s2;
			if(s1.find(b)!=-1)
			{
				flag=1;
				break;
			}
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}