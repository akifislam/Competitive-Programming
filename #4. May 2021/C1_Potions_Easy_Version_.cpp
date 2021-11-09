#include <bits/stdc++.h>
using namespace std;

#define int long long int 
void printQueue( priority_queue<int, vector<int>, greater<int>> Q)
{
    cout << endl;
    cout << "---P. QUEUE---" << endl;
    while (!Q.empty())
    {
        cout << Q.top() << " ";
        Q.pop();
    }

    cout << endl;
    cout << "------" << endl;
    cout << endl;
}

const int N = 2e5 + 5;

int n;
int a[N];

int32_t main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    // Syntax to create a min heap for priority queue
    // priority_queue <int, vector<int>, greater<int>> g = gq;

    priority_queue<int, vector<int>, greater<int>> pq;
    int point = 0;

    for (int i = 1; i <= n; i++)
    {

        // printQueue(pq);
        point += a[i];
        ans++;
        pq.push(a[i]);

        while (pq.size() and point < 0)
        {
            point -= pq.top();
            pq.pop();
            ans--;
        }
    }

    cout << ans;

    return 0;
}