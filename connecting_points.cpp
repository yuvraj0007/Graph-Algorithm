#include <bits/stdc++.h>
using namespace std;
int n;
int power(int x,int y) 
{ 
    int temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return ((temp)*(temp)); 
    else
        return ((x)*(temp)*(temp)); 
}
double dist(int x1,int y1,int x2,int y2){
  return sqrt(power((x1-x2),2)+power((y1-y2),2));
}
vector<int>par(100000);
vector<int>ran(100000,0);
void init(){
  for(int i=0;i<100000;i++)
    par[i]=i;
}

int find(int x){
  if(x==par[x]) return x;
  par[x]=find(par[x]);
  return par[x];
}

void unionn(int x,int y){
  int x_r=find(x);
  int y_r=find(y);
  if(x_r==y_r) return;
  if(ran[x_r]<ran[y_r]) par[x_r]=y_r;
  else if(ran[x_r]<ran[y_r]) par[y_r]=x_r;
  else {
    par[y_r]=x_r; ran[x_r]++;
  }
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  int si=n*(n+1)/2;
  vector<array<double,3>>arr(si);
  int k=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      arr[k][0]=dist(x[i],y[i],x[j],y[j]);
      arr[k][1]=i;
      arr[k][2]=j;
      k++;
    }
  }
  sort(arr.begin(),arr.end());
  init();
  for(int i=0;i<si;i++){
    if(find(arr[i][1])!=find(arr[i][2])){
      result += arr[i][0];
      unionn(arr[i][1],arr[i][2]);
    }
  }

  return result;
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  cout<<fixed;
  cout <<setprecision(9) << minimum_distance(x, y) << endl;
}
