#include <bits/stdc++.h>
using namespace std;
int n, m;

int main()

{
    cin >> n >> m;

    int temp_n = n;
    int temp_m = m;

    long long int tp[n], arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> tp[i];
    }

    for (int j = 0; j < m; j++)
    {
        cin >> arr[j];
    }

    int lp = 0, rp = 0;
    int count = 0;
    int answer = 0;

    for (int i = 0; i < m; i++)
    {
        // cout << "Array Index i : " << i << " Answer : " << answer << endl;

        //Two Pointer
        cout << " i = " << i << endl;
        if (i != 0 && arr[i] == arr[i - 1])
        {
            answer += count;
            cout << "Answwwww : " << answer << endl;
            continue;
        }

        if (arr[i] < tp[lp])
            continue;

        count = 0;

        while (arr[i] >= tp[lp])
        {

            cout << "Looping" << endl;
            if (tp[lp] < arr[i])
                lp++;

            while (tp[lp] == arr[i] && lp < n)
            {
                count++;
                cout << "count " << count << endl;
                lp++;
            }

            // cout << "Array Index i : " << i << " Count : " << count << endl;

            answer += count;
            cout << answer << endl;
        }
        // cout << "Array Index i : " << m-1 << " Answer : " << answer << endl;

        cout << answer << endl;
    }
}
