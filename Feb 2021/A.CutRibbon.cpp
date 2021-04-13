//Equation Solve Method
//Source : https://codeforces.com/problemset/problem/189/A
//Cut Ribbon | 1200 Difficulty

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, x, y, z, a, b, c;
    cin >> N >> x >> y >> z;

    // We will solve this with ax+by+cz = n;

    int answer = 1; //Minimum Ribbon
    int i, j;
    for (i = 0; i * x <= N; i++)
    {
        for (j = 0; (i * x + j * y) <= N; j++)
        {
            // ax + by + cz = N;
            // cz = N - ax - by;
            // c = (N-ax-by)/z;

            c = (N - a * x - b * y) / z;

            if (i * x + j * y + c * z == N)
                answer = max(i + j + c, answer);
        }
    }

    cout << answer << endl;
}