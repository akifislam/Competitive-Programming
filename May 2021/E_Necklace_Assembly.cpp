/HovalHaq!
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t; cin >> t;
	while(t--) {
		int n, k, r = 1; cin >> n >> k;
		vector<int> C(26);
		for(int i = 0; i < n; i++) {
			char c; cin >> c;
			C[c - 'a']++;
		}
		for(int i = 1; i <= n; i++) {
			int l = __gcd(i, k), x = i / l, a = 0;
			for(int c : C) a += c / x;
			if(a >= l) r = max(r, i);
		}
		cout << r << "\n";
	}
}