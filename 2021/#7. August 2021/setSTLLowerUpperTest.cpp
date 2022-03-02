#include <bits/stdc++.h>
using namespace std;

int main()
{

    set<int> s;
    s.insert(1);
    s.insert(6);
    s.insert(18);
    s.insert(29);
    s.insert(31);


    // Inputs : 1 6 18 29 31
    cout << *s.lower_bound(6) << endl; // returns 6
    cout << *s.lower_bound(7) << endl; // returns 18

    //How Can I get the index of the s.lowerBound(7)?
    

}