#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef     pair<int,int>       ii;

vector<ii> processes;

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        processes.clear();

        int n;
        scanf("%d", &n);

        int si, ti;

        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &si, &ti);

            processes.push_back(ii(si, 0));
            processes.push_back(ii(ti, 1));
        }

        sort(processes.begin(), processes.end());

        int curr = 0, mx = 0, sz = processes.size();

        for(int i = 0; i < sz; ++i) {
            curr += ((processes[i].second)? -1 : 1);
            mx = max(mx, curr);
        }

        printf("Case %d: %d\n", tc, mx);
    }

    return 0;
}