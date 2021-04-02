#include <bits/stdc++.h>

using namespace std;
using ll = long long;
//void showpq(priority_queue<pair<int,int>> gq)
//{
//    cout<<"-----PQ------"<<endl;
//    priority_queue<int> g = gq;
//    while (!g.empty()) {
//        cout << '\t' << g.top();
//        g.pop();
//    }
//    cout << '\n';
//    cout<<"-----------"<<endl;
//
//}

void solve() {
    priority_queue<pair<int, int>> Q;

    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    //Map Print
//    cout<<"------Map-----"<<endl;
//    for(auto it = mp.begin(); it!=mp.end(); it++) {
//        cout<<it->first<<" "<<it->second<<endl;
//    }
//    cout<<"------Map-----"<<endl;
    //-----------------//

    for (auto [x, y] : mp) {
        Q.push({y, x});
    }

    int sz = n;
    while (Q.size() >= 2) {
//        showpq(Q);
        auto [cnt1, x1] = Q.top();
        Q.pop();
        auto [cnt2, x2] = Q.top();
        Q.pop();
        cnt1--;
        cnt2--;
        sz -= 2;
        if (cnt1) {
            Q.push({cnt1, x1});
        }
        if (cnt2) {
            Q.push({cnt2, x2});
        }
    }
    cout << sz << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}