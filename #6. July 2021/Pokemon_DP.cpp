/*
The easy version of the task can be solved in different ways. For example, you can use the dynamic programming method.

Let 𝑑1𝑖 – be the maximum possible sum of a subsequence on a prefix from the first 
𝑖 elements, provided that the length of the subsequence is odd. 
Similarly enter 𝑑2𝑖, only for subsequences of even length. 
Then 𝑑1𝑖 and 𝑑2𝑖 are easy to recalculate:
𝑑1𝑖+1=max(𝑑1𝑖, 𝑑2𝑖+𝑎𝑖),
.
𝑑2𝑖+1=max(𝑑2𝑖, 𝑑1𝑖−𝑎𝑖).
. The initial values are 𝑑10=−∞, 𝑑20=0. The answer will be stored in max(𝑑1𝑛,𝑑2𝑛).

This solution works for 𝑂(𝑛) in time. 
Its main drawback is that it cannot be used to solve a complex version of a task 
where a different approach is needed.

*/

#include <iostream>
#include <vector>

using namespace std;

inline int64_t calc(const vector<int> &a) {
	int n = a.size();
	vector<int64_t> d1(n+1), d2(n+1);
	d1[0] = -static_cast<int64_t>(1e18);
	d2[0] = 0;
	for (int i = 0; i < n; ++i) {
		d1[i+1] = max(d1[i], d2[i] + a[i]);
		d2[i+1] = max(d2[i], d1[i] - a[i]);
	}
	return max(d1.back(), d2.back());
}

int main() {
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		// int n, q; cin >> n >> q;
		// vector<int> a(n);
		// for (int i = 0; i < n; ++i) {
		// 	cin >> a[i];
		// }
		cout << calc(a) << "\n";
		// for (int i = 0; i < q; ++i) {
		// 	int l, r; cin >> l >> r; --l; --r;
		// 	swap(a[l], a[r]);
		// 	cout << calc(a) << "\n";
		// }
	}
	return 0;
}