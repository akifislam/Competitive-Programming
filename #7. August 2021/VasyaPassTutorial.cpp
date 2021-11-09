#include<bits/stdc++.h>
using namespace std;
 
string s;
int freq[3],q,len;
char b[3]={'0','A','a'};
 
int check(char c)
{
    if(c<='9')
        return 0;
    if(c<='Z')
        return 1;
    return 2;
}
int main()
{
    cin>>q;
    while(q--)
    {
        cin>>s;
        
        freq[0]=freq[1]=freq[2]=0;
        len=s.length();
        
        for(int i=0;i<len;++i)
            ++freq[check(s[i])];
        
        for(int i=0;i<3;++i)
            for(int j=0;!freq[i];++j)
                if(freq[check(s[j])]>1)
                    s[j]=b[i],freq[i]=1;
        
        cout<<s<<endl;
    }
}