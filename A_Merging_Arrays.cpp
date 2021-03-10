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
 
    int i=0,j=0,k=0;
 
    while(i<n || j<m) {
        if(arr[i]<arr2[j]) {
            merged[k]=arr[i];
            k++,i++;
        }
 
        else {
            merged[k]=arr2[j];
            k++,j++;
        }
    }
    
    for(int i = 0; i<m+n ; i++) {
        cout<<merged[i]<<" ";
    }
    
 
    
}