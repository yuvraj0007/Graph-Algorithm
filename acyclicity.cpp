#include <bits/stdc++.h>
using namespace std;
int n, m;
int pst[1001];
static int clk=1;
void post_visit(int &s){
	pst[s]=clk;
	clk=clk+1;
}
void dfs(vector<vector<int>>&adj,int s,vector<bool>&vis){
	vis[s]=true;
	for(int x:adj[s])
		if(!vis[x])
			dfs(adj,x,vis);

	post_visit(s);
}

int acyclic(vector<vector<int> > &adj) {
  vector<bool>vis(n,false);
  for(int i=0;i<n;i++)
    if(!vis[i])
      dfs(adj,i,vis);

  for(int i=0;i<n;i++){
  	for(int x:adj[i]){
  		if(pst[i]<pst[x])
  			return 1;
  	}
  }
  return 0;
}

int main() {
  
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  cout << acyclic(adj);
}
