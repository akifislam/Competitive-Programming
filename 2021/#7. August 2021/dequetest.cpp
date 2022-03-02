#include <bits/stdc++.h>
using namespace std;

int main()
{

    deque<int> D;

    D.push_back(100);
    D.push_back(201);
    D.push_back(302);
    D.push_back(405);
    D.push_back(809);

    cout << D[3] << endl; // 405
    cout << D[4] << endl; // 809
    cout<<D[100]<<endl; //0
}