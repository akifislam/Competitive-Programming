//Akif Islam (__SHERLOCK__)
//Date: 2021-09-12 20:02:41
// Ask Less, Practise More :)

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

int tc = 1;

void solve()
{
    int N;
    cin >> N;

    string str;
    cin >> str;

    bool left = false;
    bool right = false;

    //Checking first hand
    for (int i = 0; i < N; i++)
    {
        if (str[i] == 'X')
        {
            left = true;
            break;
        }
        else if (str[i] == 'O')
        {
            right = true;
            break;
        }
    }

    //Check
    int answer = 0;

    // if (left)
    // {

    for (int i = 0; i < N; i++)
    {
        if (left && str[i] == 'O')
        {
            right = true;
            left = false;
            answer++;
        }
        else if (right && str[i] == 'X')
        {
            left = true;
            right = false;
            answer++;
        }
    }
    // }
    // else
    // {

    //     for (int i = 0; i < N; i++)
    //     {
    //         if (left && str[i] == 'O')
    //         {
    //             right = true;
    //             left = false;
    //             answer++;
    //         }
    //         else if (right && str[i] == 'X')
    //         {
    //             left = true;
    //             right = false;
    //             answer++;
    //         }
    //     }
    // }

    cout << "Case #" << tc++ << ": " << answer << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}