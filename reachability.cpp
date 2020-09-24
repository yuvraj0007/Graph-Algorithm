#include <bits/stdc++.h>
using namespace std;
int n, m;
void dfs(vector<vector<int>>&adj,int s,vector<bool>&vis){
    vis[s]=true;
    for(auto x:adj[s]){
      if(!vis[x])
        dfs(adj,x,vis);
    }
}

int reach(vector<vector<int> > &adj, int x, int y) {
    vector<bool>vis(n,false);
    dfs(adj,x,vis);
    if(vis[y])
      return 1;
    return 0;
}

int main() {
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      adj[x - 1].push_back(y - 1);
      adj[y - 1].push_back(x - 1);
    }
    int x, y;
    cin >> x >> y;
    cout << reach(adj, x - 1, y - 1);
    return 0;
}
