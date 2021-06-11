//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-06-06 20:47:43

// :) 

#include <bits/stdc++.h>


using namespace std;
char gap = 32;

#define ll long long
#define pb push_back
#define All(x) (x).begin(), (x).end()

void solve() {
    ll length, x_input;
    cin >> length;
    set<ll> number_set;
    bool AnyNegativeThere = false;

    for (int i = 0; i < length; i++) {
        cin >> x_input;
        number_set.insert(x_input);
        if (x_input < 0)
            AnyNegativeThere = true;
    }
    if (AnyNegativeThere) {
        cout << "NO" << endl;
        return;
    }
    bool AgainAdded = true;

    
    while (AgainAdded && number_set.size() < 300) {
    
    
    
        AgainAdded = false;
    
    
    
        for (auto it = number_set.begin(); it != number_set.end(); it++) {
    
    
            auto xx = it;
    
            xx++;
    
    
            for (auto it2 = xx; it2 != number_set.end(); it2++) {
                // cout << "Checking " << *it << " " << *it2 << endl;
                ll value_dif = abs(*it - *it2);
                if (number_set.count(value_dif) == 0) {
                    AgainAdded = true;

                    number_set.insert(value_dif);
                    
                }
            }
        }
    }
    // OK
    
    if (number_set.size() >= 301)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    cout << number_set.size() << endl;
    
    
    
    
    
    
    for (auto x : number_set) {

        cout << x << " ";
    }


    cout << endl;
}




int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}