#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj_list[MAXN];
bool vis[MAXN];
int level[MAXN];
int parent[MAXN];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    parent[src] = -1;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));

    bfs(1);

    if(!vis[n]) {
        cout <<"IMPOSSIBLE"<< "\n"; 
        return 0;
    }

    int node = n;
    vector<int> path;

    while(node != -1) {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(int x : path) cout << x << " ";
    cout << "\n";

    return 0;
}