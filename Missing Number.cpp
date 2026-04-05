#include <bits/stdc++.h>
using namespace std;


void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fast_io();
    long long int n;
    cin>>n;
    long long int arr[n-1];
    long long int sum =0;
    long long int s   = (n*(n+1))/2;
   
    for(long long int  i=0;i<n-1;i++)
    {
       cin >> arr[i];             
       sum += arr[i];
    }

    cout<<s-sum<<endl;
    return 0;
}

// PRASANJIT ROY , CS learner
