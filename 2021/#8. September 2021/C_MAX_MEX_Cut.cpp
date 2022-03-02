//Akif Islam (__SHERLOCK__)
//Date: 2021-09-12 21:24:32
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

char str[3][100005];

int stTOint(char x)
{
    return x - '0';
}

void solve()
{
    int N;
    cin >> N;

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> str[i][j];
        }
    }

    int answer = 0;
    int val;

    for (int i = 1; i <= N; i++)
    {
        // cout << "i = " << i << " ans : " << answer << endl;
        val = stTOint(str[1][i]) + stTOint(str[2][i]);
        // cout << "val : " << val << endl;
        //Case : if both are 1 and 1
        if (val == 2)
        {
            if (i < N)
            {
                int val2 = stTOint(str[1][i + 1]) + stTOint(str[2][i + 1]);
                if (val2 == 0)
                {
                    answer += 2;
                    i++;
                    continue;
                }
            }

        }
        //#Case : if both are 0 and 0 ;
        else if (val == 0)
        {
            if (i < N)
            {
                int val2 = stTOint(str[1][i + 1]) + stTOint(str[2][i + 1]);
                if (val2 == 2)
                {
                    answer += 2;
                    i++;
                    continue;
                }
            }
            answer++;
        }

        // #Case : if there is 1 and 0 both
        else if (val == 1)
        {
            answer += 2;
        }
    }
    cout << answer << endl;
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