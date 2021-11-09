#include <bits/stdc++.h>
using namespace std;

#define ll long long int 




void solve()
{
    ll NO_OF_INPUT;



    scanf("%lld", &NO_OF_INPUT);

    vector<ll> V(NO_OF_INPUT);


    //OK
    
    ll totalSum = 0;

    for (int i = 0; i < NO_OF_INPUT; i++)
    {
        scanf("%lld", &V[i]);



        totalSum += V[i];
    }

    sort(V.begin(),V.end());
    
    //Back [n-1]


    totalSum -= V.back();


    double ANS;
    ANS  = (double)totalSum / (NO_OF_INPUT - 1);

    printf("%.9lf\n", V.back() + ANS);


}

int32_t main()
{
 
    int TTT = 100;


    scanf("%d",&TTT);
    while (TTT--)
    {
        solve();
    }
    return 0;
}