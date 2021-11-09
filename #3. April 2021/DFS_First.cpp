

#include <bits/stdc++.h>
using namespace std;
#define node_count 10
//PreOrder Traversal of a Binary Tree
vector<int> graph[node_count];

void input()
{
    //Root 7 //6 Edges
    graph[7].push_back(4); //Left Child
    graph[7].push_back(9); //Right Child

    graph[4].push_back(1); //Left Child
    graph[4].push_back(6); //Right Child

    graph[9].push_back(8);  //Left Child
    graph[9].push_back(10); //Right Child
}

bool visited[node_count];

//Pre-order Traversal

void PreOrder_Traversal(int root)
{
    cout << root << " " << endl;
    if (visited[root] || graph[root].size() == 0)
        return;

    visited[root] = true;
    PreOrder_Traversal(graph[root][0]);
    PreOrder_Traversal(graph[root][1]);
}

/*
7 
4 
1 
6 
9 
8 
10 
*/

void InOrder_Traversal(int root)
{
    if (visited[root] || graph[root].size() == 0)
        return;

    visited[root] = true;
    PreOrder_Traversal(graph[root][0]);
    PreOrder_Traversal(graph[root][1]);
    cout << root << " " << endl;

}

int main()
{
    input();

    cout << "Pre-order Traversal : " << endl;
    PreOrder_Traversal(7); //Root is 7

    cout << "In-order Traversal : " << endl;
    InOrder_Traversal(7); //Root is 7
}