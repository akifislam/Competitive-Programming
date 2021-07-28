#include <bits/stdc++.h>
using namespace std;

int n, k, j, A[100005];
set<int> Set;
map<int, int> mp;

int main(void)
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
    {

        mp[A[i]]++;

        if (mp[A[i]] == 1)
        {
            Set.insert(A[i]);
        }

        else if (Set.count(A[i]))
            Set.erase(A[i]);

        if (i < k - 1)
            continue;

        if (Set.size())
        {
            cout << *Set.rbegin() << endl;
        }

        else
            puts("Nothing");

        mp[A[j]]--;

        if (mp[A[j]] == 1)
        {
            Set.insert(A[j]);
        }
        
        else if (Set.count(A[j]))
            Set.erase(A[j]);
        j++;
    }
    return 0;
}