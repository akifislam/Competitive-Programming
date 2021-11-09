#include <bits/stdc++.h>
#define msg(x) cout << #x << " = " << x << endl
using namespace std;
 
int n, k;
 
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> n >> k;
    cout << n * (n - 1) / 2 << "\n";

    for (int i = 1; i <= n; i++) {
    
        for (int j = i + 1; j <= n; j++) {
    
            if (k) {
                cout << j << " " << i << "\n";
            } else {
                cout << i << " " << j << "\n";
            }
    
        }
    }
    return 0;
}