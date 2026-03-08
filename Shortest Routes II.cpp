#include <bits/stdc++.h>
using namespace std;
int main() {
     int n,e,q;
     cin>>n>>e>>q;
    long long int adj_mat[n+1][n+1];
    for(int i=1; i<=n;i++)
    {
        for(int j=1; j<=n;j++)
        {
            if(i==j) adj_mat[i][j]=0;
            else adj_mat[i][j]=LLONG_MAX;

        }
    }

    while(e--)
    {
        long long int a,b,c;
        cin>>a>>b>>c;
        adj_mat[a][b]=min(c,adj_mat[a][b]);
        adj_mat[b][a]=min(c,adj_mat[b][a]); //for undirected graph
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1; i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(adj_mat[i][k]!=LLONG_MAX && adj_mat[k][j]!=LLONG_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j]=adj_mat[i][k] + adj_mat[k][j] ;
                }
            }
        }
    }
    // for(int i=0;i<n;i++)
    //  {
    //     for(int j=0; j<n;j++)
    //     {  if( adj_mat[i][j]==INT_MAX) cout<<"# ";
    //        else  cout<<adj_mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<endl;
    
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(adj_mat[a][b]==LLONG_MAX) cout<<"-1"<<endl;
        else cout<<adj_mat[a][b]<<endl;
    }

    return 0;
}
