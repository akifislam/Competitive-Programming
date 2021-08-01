//Akif Islam (__SHERLOCK__)
//Date: 2021-07-29 16:49:36

#include <bits/stdc++.h>

using namespace std;

char gap = 32;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << gap << x;
    return os << '}';
}

#define ll long long
#define pb push_back
#define All(x) (x).begin(), (x).end()

void solve()
{
    int input, temp, nb1, nb2;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // 9 10 2 5 1 18 -1
    //5
    while (scanf("%d", &input) != EOF)
    {
        if (input == 0)
            break;
        else if (input == -1)
        {
            printf("%d\n", maxHeap.top());
            maxHeap.pop();

            if (maxHeap.size() < minHeap.size())
            {
                temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
            }
        }

        else
        {
            if (maxHeap.size() == 0 && minHeap.size() == 0)
                maxHeap.push(input);
            else
            {
                nb1 = maxHeap.top();
                if (input >= nb1)
                    minHeap.push(input);
                else
                    maxHeap.push(input);

                if (maxHeap.size() < minHeap.size())
                {
                
                    temp = minHeap.top();
                    minHeap.pop();
                
                    maxHeap.push(temp);
                
                }
                else if (maxHeap.size() > minHeap.size() + 1)
                {
                
                    temp = maxHeap.top();
                
                
                    maxHeap.pop();
                    minHeap.push(temp);
                }
            }
        }
    }
}
int32_t main()
{
    //   ios_base::sync_with_stdio(false);
    //   cin.tie(0);

    int test = 1;
    scanf("%d", &test);
    while (test--)
    {
        solve();
    }
    return 0;
}