//Akif Islam (__SHERLOCK__)
//Date: 2021-07-25 13:02:27

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
    //Trying with my simple idea :(

    ll N;
    cin >> N;
    N = N * 2;

    stack<int> stk;
    // priority_queue<int> pq;

    string command;
    int value;
    int answer = 0;
    int remove_count = 0;
    int max_added_values = 0;
    while (N--)
    {
        command = "";

        cin >> command;

        if (command == "add")
        {
            cin >> value;
            stk.push(value);
        }

        else
        {
            remove_count++;
            if (!stk.empty())
            {

                if (stk.top() == remove_count)
                {
                    stk.pop();
                }

                else
                {
                    answer++;
                    //Clearing Stack
                    while (!stk.empty())
                        stk.pop();
                }
            }
        }
    }
    cout << answer << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}