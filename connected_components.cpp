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

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  vector<bool>vis(n,false);
  for(int i=0;i<n;i++){
    if(!vis[i]){
      dfs(adj,i,vis);
      res++;
    }
  }
  return res;
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
  cout << number_of_components(adj);
}
