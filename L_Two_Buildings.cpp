#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int answer = -1;
    int height = 0;

    for (int i = 0,j = n-1; i < j; i++,j--)
    {
        height = (arr[i]+arr[j])*(j-i);
        answer = max(answer,height);
    }
    
    cout<<answer<<endl;
    
}