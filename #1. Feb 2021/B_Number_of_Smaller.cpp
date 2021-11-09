#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n,m;
    cin>>n>>m;
 
    long long int arr[n],arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
 
    for (int j  = 0; j < m; j++)
    {
        cin>>arr2[j];
    }
 
    long long int merged[n+m];
    
    int count = 0;
    int i=0,j=0,k=0;
 
    while(j<m) {
        if(arr[i]<arr2[j]) {
            merged[k]=arr[i];
            k++,i++;
            count++;
        }
 
        else {
            merged[k]=arr2[j];
            cout<<count<<" ";
            k++,j++;
        }
       
    }

    
 
    
}