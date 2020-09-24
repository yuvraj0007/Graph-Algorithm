#include <bits/stdc++.h>
using namespace std;
const int c=1e8;
int n, m;
int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  vector<int>dist(n,c);
  dist[0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int k=0;
      for(int x:adj[j]){
          if(dist[x]>dist[j]+cost[j][k]){
           if(i==n-1) return 1;
            dist[x]=dist[j]+cost[j][k];
          }
          k++;
      }
    }
  }


  return 0;
}

int main() {
  
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  cout << negative_cycle(adj, cost);
}
