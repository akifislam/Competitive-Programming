// Spin
// Rotation

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char seq[4] = {'^', '>', 'v', '<'}; // Clockwise
    string str;

    getline(cin, str);

    int start;
    int end;

    for (int i = 0; i < 4; i++)
    {
        if (str[0] == seq[i])
            start = i;
        if (str[2] == seq[i])
            end = i;
    }

    int n;
    cin >> n;

    bool isCW = (seq[(start + n) % 4] == seq[end]);
    bool isCCW = (seq[(start + (4 - (n % 4)))] == seq[end]);

    if (isCW && isCCW)
    {
        cout << "undefined" << endl;
    }
    else if (isCW)
    {
        cout << "cw" << endl;
    }
    else
    {
        cout << "ccw" << endl;
    }
}