#include<bits/stdc++.h>
using namespace std;
array<int,2>arr[100000];
static int clk=1;
static int j=0;
void post_order(int x){
  arr[j][0]=clk;
  arr[j][1]=x;
  j++; clk++;
}

void dfs(vector<vector<int> > &adj, vector<int> &used, int x) {
  used[x]=1;
  for(int i:adj[x])
    if(!used[i])
      dfs(adj,used,i);

  post_order(x);
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  int si=adj.size();
  for(int i=0;i<si;i++){
    if(!used[i])
      dfs(adj,used,i);
  }
  sort(arr,arr+si);
  vector<int> order;
  for(int i=si-1;i>=0;i--)
    order.push_back(arr[i][1]);
  return order;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
