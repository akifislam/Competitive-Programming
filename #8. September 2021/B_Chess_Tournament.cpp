//Akif Islam (__SHERLOCK__)
//Date: 2021-09-08 20:51:05
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

char scoreboard[55][55];

int N;

void newGame(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scoreboard[i][j] = '?';
        }
    }

    for (int i = 1; i <= n; i++)
    {
        scoreboard[i][i] = 'X';
    }
}

void makeTIE(int x)
{
    //Row wise
    for (int i = 1; i <= N; i++)
    {
        if (scoreboard[x][i] == '?')
            scoreboard[x][i] = '=';
    }
    //Column wise
    for (int i = 1; i <= N; i++)
    {
        if (scoreboard[i][x] == '?')
            scoreboard[i][x] = '=';
    }
}

bool makeWIN(int x)
{
    //Row wise
    for (int i = 1; i <= N; i++)
    {
        if (scoreboard[x][i] == '?' && scoreboard[i][x] == '?')
        {
            scoreboard[x][i] = '+';
            scoreboard[i][x] = '-';
            // cout << "D1" << endl;
            return true;
        }
    }
    // //Column wise
    // for (int i = 1; i <= N; i++)
    // {
    //     if (scoreboard[i][x] == '?')
    //     {
    //         scoreboard[i][x] = '+';
    //         scoreboard[x][i] = '-';
    //         // cout << "D2" << endl;
    //         return true;
    //     }
    // }
    return false;
}
void solve()
{
    cin >> N;

    string str;
    cin >> str;

    newGame(N);

    for (int i = 0; i < N; i++)
    {
        if (str[i] == '1')
        {
            str[i] = '*';
            makeTIE(i + 1);
        }
    }

    bool isPossible = true;

    for (int i = 0; i < N; i++)
    {
        if (str[i] == '2')
        {
            isPossible = makeWIN(i + 1);
        }

        if (!isPossible)
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (isPossible)
    {
        cout << "YES" << endl;
        //Print
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (scoreboard[i][j] != '?')
                    cout << scoreboard[i][j];
                else
                    cout << "=";
            }
            cout << endl;
        }
    }
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