#include <bits/stdc++.h>
using namespace std;
int n, m;
int bipartite(vector<vector<int> > &adj) {
  vector<int>dp(n,-1);
  queue<int>q;
  for(int i=0;i<n;i++){
    if(adj[i].size()){
      q.push(i); dp[i]=0; break;
    }
  }
  while(!q.empty()){
    int x=q.front();
    q.pop();
    for(int i:adj[x]){
      if(i==x) return 0;
      if(dp[i]==-1){
        dp[i]=1-dp[x];
        q.push(i);
      }
      if(dp[i]==dp[x])
        return 0;
    }

  }
  return 1;
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
  cout << bipartite(adj);
}
