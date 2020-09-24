#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
#define ll long long
const ll large=1e15;
int n, m;
long long distance(vector<vector<int>>&adj,vector<vector<int>>&cost,int s, int t) {
  vector<long long>dist(n,large);
  vector<bool>vis(n,false);
  priority_queue<pi,vector<pi>,greater<pi>>pq;
  pq.push(make_pair(0,s));
  dist[s]=0;
  while(!pq.empty()){
    pair<int,int>tp = pq.top();
    pq.pop();
    if(!vis[tp.second]){
      vis[tp.second]=true;
      int j=0;
      for(int x:adj[tp.second]){
        if(dist[x]>dist[tp.second]+cost[tp.second][j]){
          dist[x]=dist[tp.second]+cost[tp.second][j];
          pq.push(make_pair(dist[x],x));
        }
        j++;
      }
    }
  }
  return ((dist[t]==large)?-1:dist[t]);
}

int main() {
  cin>>n>>m;
  vector<vector<int>>adj(n, vector<int>());
  vector<vector<int>>cost(n, vector<int>());
  for (int i=0;i<m;i++) {
    int x,y,w;
    cin>>x>>y>>w;
    adj[x-1].push_back(y-1);
    cost[x-1].push_back(w);
  }
  int s,t;
  cin>>s>>t;
  s--,t--;
  cout << distance(adj,cost,s,t);
}
