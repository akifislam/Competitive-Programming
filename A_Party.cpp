//SHERLOCK
//BFS Solution
#include <bits/stdc++.h>

using namespace std;

const int N = 2001;
vector<char> graph[N];
int max_depth = -1;

//bool visited [N];
int visited[N];

void printDepth() {
    cout << "---Depth---" << endl;
    for (int i = 1; i <= 6; i++) {
        cout << visited[i] << " ";
    }
    cout << endl
         << "----" << endl;
}

void bfs(int parent) {
    memset(visited, false, sizeof(visited));
    queue<int> Q;

    //Start Node : 1 (A)

    Q.push(parent);
    //    visited[1] = true;
    visited[parent] = 1;

    while (!Q.empty()) {
        int cur = Q.front();
        // cout << mp[Q.front()] << endl;
        Q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            if (!visited[graph[cur][i]]) {
                //True means Visited
                visited[graph[cur][i]] = visited[cur] + 1;
                Q.push(graph[cur][i]);
//                cout << "Depth of " << graph[cur][i] << " :" << visited[cur] + 1 << endl;
                max_depth = max(max_depth, visited[cur] + 1);
//                cout << "Max Depth : " << max_depth << endl;
            }
        }
    }
//    printDepth();
}

int main() {
    int n;
    cin >> n;
    int input;

    for (int i = 1; i <= n; i++) {
        cin >> input;
        if (input != -1)
            graph[input].push_back(i);
    }

    //Just Traversing the Graph
    for (int i = 1; i <= n; i++)
        bfs(i);

    cout<<max_depth<<endl;


}
