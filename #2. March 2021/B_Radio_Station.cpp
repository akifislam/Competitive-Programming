#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    map<string, string> mp;
    string server_name, IP;

    while (n--)
    {

        cin >> server_name >> IP;

        mp.insert(make_pair(IP+";", server_name));
    }
    // cout << "End" << endl;

    while (m--)
    {
        cin >> server_name >> IP;
        cout << server_name << " " <<IP<<" #"<<mp[IP]<<endl;
    }
}