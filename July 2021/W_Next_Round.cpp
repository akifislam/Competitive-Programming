#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> vec(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), greater<int>());

    int kth_score = vec[K - 1];

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (vec[i] >= kth_score && vec[i] > 0)
            count++;
        else
            break;
    }
    cout << count << endl;
}