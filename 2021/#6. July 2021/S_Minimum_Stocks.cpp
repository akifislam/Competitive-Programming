//Akif Islam (__SHERLOCK__)
//Date: 2021-07-31 10:18:32

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
    ll N;
    cin >> N;

    //Product Name & Availability (True means Available)
    map<string, ll> StockAvailability;
    priority_queue<pair<ll, string>> PQ;

    ll type, price;
    string product_name;

    for (int i = 0; i < N; i++)
    {
        cin >> type;

        if (type == 1 || type == 2)
        {
            cin >> product_name >> price;
            StockAvailability[product_name] = price;
            PQ.push({-price, product_name});
        }

        else
        {
            cin >> product_name; //BUY

            while (!PQ.empty())
            {
                auto cur = PQ.top();
                ll cur_price = cur.first;
                string cur_product = cur.second;

                //Jodi Current Product Market e Thake
                if (StockAvailability[cur_product] == -cur_price)
                {
                    cout << cur_product << " " << i + 1 << endl;
                    StockAvailability[cur_product] = -1;
                    break;
                }
                PQ.pop();
            }
        }
    }
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