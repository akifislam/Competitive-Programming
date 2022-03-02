// __SHERLOCK__ in Action
// 08 August 2021
// Commented Problem

#include <bits/stdc++.h>
using namespace std;

int main()
{

    //  Nodes, Edges No. Input Nilam
    int nodes, edges;
    cin >> nodes >> edges;

    // Graph of Set
    vector<set<int>> graph(nodes + 1);

    int from, to;

    // Input
    for (int i = 0; i < edges; i++)
    {
        cin >> from >> to;
        graph[from].insert(to);
        graph[to].insert(from);
    }

    int answer = 0;

    // Node ta Vulnerable hole False, Bhalo hole True
    bool isOK[nodes + 1];
    memset(isOK, 0, sizeof(0));

    //Initial State Count kore nicchi jodi shurutei Print korte bole
    for (int i = 1; i <= nodes; i++)
    {
        if (graph[i].lower_bound(i) == graph[i].end())
        {
            answer++;
            isOK[i] = true;
        }
    }

    // cout << "Initial Answer : " << answer << endl;

    int Q;
    cin >> Q;

    while (Q--)
    {
        int type;
        cin >> type;

        // Type 3 hole Direct Answer 

        if (type == 3)
        {
            cout << answer << endl;
        }
        else
        {
            cin >> from >> to;

            //Jodi From/to er Node gulo OK thake, tahole NotOK kore dibo. Vulnerable Check dibo.
            if (isOK[from])
                answer--;
            if (isOK[to])
                answer--;


            //Adding
            if (type == 1)
            {
                graph[from].insert(to);
                graph[to].insert(from);
            }
            //Removing
            else
            {
                graph[from].erase(to);
                graph[to].erase(from);
            }

            //Process
            // JOdi From node er cheye boro kew na thake, tahole Ota Finish, Gaya, GoodBye
            if (graph[from].lower_bound(from) != graph[from].end())
                isOK[from] = false;
            else
                isOK[from] = true;

            // Jodi to node er cheye boro kew na thake, tahole Ota Finish, Gaya, GoodBye

            if (graph[to].lower_bound(to) != graph[to].end())
                isOK[to] = false;
            else
                isOK[to] = true;

            //Finally, Jodi isOK hoy, tahole answer ++
            if (isOK[from])
                answer++;
            if (isOK[to])
                answer++;
        }
    }
}