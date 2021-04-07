//SHERLOCK

//What is Substring Function?

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int length;
    cin >> length;

    string str;
    cin >> str;

    str.push_back('*');

    int res = 0;
    string ans;

    for (int i = 0; i < length - 1; i++)
    {
        int cur = 0;
        for (int j = 0; j < length - 1; j++)
        {
            if (str[j] == str[i] && str[j + 1] == str[i + 1])
                cur++;
        }
        if(res<cur){
            res = cur;
            ans = string(1,str[i]) + string(1,str[i+1]);
            //  ans = str.substr(i,i+2);
        }
    }
    cout<<ans<<endl;
}