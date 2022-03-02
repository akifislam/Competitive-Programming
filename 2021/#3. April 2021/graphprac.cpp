#include <bits/stdc++.h>
using namespace std;

vector<int> Graph[5];
map<int, char> mp;

bool visited[5];

void DFS(int s)
{
    if (visited[s])
        return;
    visited[s] = true;
    for (auto x : Graph[s])
    {
        DFS(x);
    }
}
int main()
{
    Graph[1].push_back(2);
    Graph[1].push_back(3);
    Graph[2].push_back(4);
    Graph[4].push_back(3);

    mp[1] = 'A';
    mp[2] = 'B';
    mp[3] = 'C';
    mp[4] = 'D';

    DFS(1);



}
