#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
pair<int,int> parentCell[1005][1005];
char pathDir[1005][1005];

int n,m;

vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
char dirChar[] = {'U','D','L','R'};

bool valid(int i,int j)
{
    return (i>=0 && i<n && j>=0 && j<m);
}

int main()
{
    cin >> n >> m;

    pair<int,int> start, target;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> grid[i][j];
            if(grid[i][j]=='A') start={i,j};
            if(grid[i][j]=='B') target={i,j};
        }
    }

    memset(vis,false,sizeof(vis));

    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = true;

    bool found = false;

    while(!q.empty())
    {
        auto par = q.front();
        q.pop();

        if(par == target)
        {
            found = true;
            break;
        }

        for(int i=0;i<4;i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;

            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            {
                vis[ci][cj] = true;
                parentCell[ci][cj] = par;
                pathDir[ci][cj] = dirChar[i];
                q.push({ci,cj});
            }
        }
    }

    if(!found)
    {
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";

 
    string path="";
    pair<int,int> cur = target;

    while(cur != start)
    {
        path += pathDir[cur.first][cur.second];
        cur = parentCell[cur.first][cur.second];
    }

    reverse(path.begin(),path.end());

    cout<<path.size()<<"\n";
    cout<<path<<"\n";
}