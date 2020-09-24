#include <bits/stdc++.h>
using namespace std;
int n, m;
array<int,2>pst[10000];
static int clk=1;
static int j=0;
void post(int s){
  pst[j][0]=clk;
  pst[j][1]=s;
  clk++,j++;
}
void dfs(vector<vector<int>>&rev,vector<bool>&vis,int s){
  vis[s]=true;
  for(int x:rev[s])
    if(!vis[x])
      dfs(rev,vis,x);

  post(s);
}
void dfs_new(vector<vector<int>>&adj,int s,vector<bool>&vis){
  vis[s]=true;
  for(int x:adj[s])
    if(!vis[x])
      dfs_new(adj,x,vis);
}
int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  vector<bool>vis(n,false);
  vector<vector<int>>rev(n,vector<int>());
  for(int i=0;i<n;i++){
    for(int x:adj[i])
      rev[x].push_back(i);
  }
  for(int i=0;i<n;i++){
    if(!vis[i])
      dfs(rev,vis,i);
  }
  vector<bool>visi(n,false);
  sort(pst,pst+n);
  for(int i=n-1;i>=0;i--){
    if(!visi[pst[i][1]]){
      dfs_new(adj,pst[i][1],visi);
      result++;
    }
  }

  return result;
}

int main() {
  
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  cout << number_of_strongly_connected_components(adj);
}
