#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mx=1e18;
int n, m, s;
void shortest_paths(vector<vector<int>>&adj,vector<vector<int>>&cost,int s,vector<long long>&distance,vector<int>&reachable,vector<int>&shortest) {
  distance[s]=0;
  queue<int>q;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int k=0;
      for(int x:adj[j]){
        if(distance[x]>distance[j]+cost[j][k]){
          if(i==n-1) {
            q.push(x); continue;}
          distance[x]=distance[j]+cost[j][k];
        }
      }
    }
  }
  set<int>st;
  vector<bool>visi(n,false);
  while(!q.empty()){
    st.insert(q.front());
    int x=q.front();
    visi[x]=true;
    q.pop();
    for(int t:adj[x]){
      if(!visi[t]){
        visi[t]=true;
        st.insert(t);
        q.push(t);
      }
    }

  }
  for(int t:st)
    shortest[t]=0;
  vector<bool>vis(n,false);
  queue<int>pq;
  pq.push(s);
  while(!pq.empty()){
    int x=pq.front();
    vis[x]=true;
    pq.pop();
    reachable[x]=1;
    for(int t:adj[x]){
      if(!vis[t]){
        vis[t]=true;pq.push(t);reachable[t]=1;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  vector<vector<int>>adj(n,vector<int>());
  vector<vector<int>>cost(n,vector<int>());
  for (int i=0;i<m;i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  cin >> s;
  s--;
  vector<long long> distance(n,mx);
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      cout << "*\n";
    } else if (!shortest[i]) {
      cout << "-\n";
    } else {
      cout << distance[i] << "\n";
    }
  }
}
