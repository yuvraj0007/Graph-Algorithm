#include <bits/stdc++.h>
using namespace std;
int n, m;


int distance(vector<vector<int> > &adj, int s, int t) {
  if(s==t) return 0;
  vector<int>dp(n,0);
  vector<bool>vis(n,false);
  queue<int>q;
  q.push(s);
  vis[s]=true;
  while(!q.empty()){
    int x=q.front();
    q.pop();
    for(int i:adj[x]){
      if(!vis[i]){
        vis[i]=true;
        q.push(i);
        dp[i]=dp[x]+1;
      }
    }
  }
  return (dp[t]==0)?-1:dp[t];
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
  int s, t;
  cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
