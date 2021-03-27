#include<bits/stdc++.h>
using namespace std;
const int N = 5;

vector<char> graph[N];
map<int,char> mp;
bool visited [N];

void build_graph() {
    //Making a Graph

    graph[1].push_back(2);
    graph[1].push_back(3);

    graph[2].push_back(4);
    graph[4].push_back(3);

    //Just to Mapping 1 --> A, 2 --> B ... :
    mp.insert(make_pair(1,'A'));
    mp.insert(make_pair(2,'B'));
    mp.insert(make_pair(3,'C'));
    mp.insert(make_pair(4,'D'));

    //Declaring All Visited Array Value to False
    memset(visited, false, sizeof(visited));




}

void bfs() {

    queue<int> Q;

    //Start Node : 1 (A)

    Q.push(1);
    visited[1] = true;

    while(!Q.empty()) {
        int cur = Q.front();
        cout<<mp[Q.front()]<<endl;
        Q.pop();



        for (int i = 0; i < graph[cur].size() ; i++) {
            if(!visited[graph[cur][i]]) {
                //True means Visited
                visited[graph[cur][i]]= true;
                Q.push(graph[cur][i]);
            }
        }
    }

}
int main() {
    build_graph();
    //Just Traversing the Graph
    bfs();

}
