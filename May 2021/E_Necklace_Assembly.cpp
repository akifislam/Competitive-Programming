//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-29 18:11:17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
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

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
	return os << '(' << p.first << gap << p.second << ')';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
	cerr << ' ' << H;
	dbg_out(T...);
}

#ifdef AKIF
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')' << ':', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ll long long
#define lll __int128_t
#define pb push_back
#define mp make_pair
#define All(x) (x).begin(), (x).end()
#define sz(z) (int)((z).size())
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
	int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	ordered_set;
mt19937 rng((uint_fast32_t)chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;

void solve()
{
	int N, K;
	cin >> N >> K;

	string str;
	cin >> str;

	map<int, int> mp;

	//Storing Frequency of Each Character
	for (int i = 0; i < str.length(); i++)
	{
		mp[(str[i] - 'a')]++;
	}

	// Printing Count
	for (auto x : mp)
	{
		cout << (char)(x.first + 97) << " has " << x.second << " PCs" << endl;
	}

	//BruteForce
	int answer = 0;
	int count = 0;
	int occur = 0;

	for (int i = 1; i <= N; i++)
	{
		count = 0;

		for (int j = 0; j < 26; j++)
		{
			count += (mp[j] / i);
		}

		while (count > 0 && K % count != 0)
			count--;
		cout << "Possible Ways : " << count << endl;

		answer = max(answer, count * i);
		cout << "Total Char Used : " << count * i << endl;
	}
	cout << "F Answer : " << answer << endl;

	// cout << "Answer String : " << endl;

	// 	int p = 0;

	// int same_letter = occur; // no of same letters

	// for (auto xx : mp)
	// {
	// 	if (xx.second >= same_letter)
	// 	{
	// 		cout << xx.first;
	// 	}
	// }
	// cout << endl;

	// cout << answer << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef AKIF
#endif
	int test = 1;
	cin >> test;
	while (test--)
	{
		solve();
	}
	return 0;
}