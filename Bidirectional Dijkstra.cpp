/* Author : Yuvraj Singh -(NIT-Patna)
Key Concepts:
    Develop an algorithm to find distances in the real road networks faster
    Develop Bidirectional Dijkstra
    Develop a solution of the central problem of delivery companies - delivery truck route optimization on real-world road network
    Develop an algorithm to find distances in the real-world road networks thousands of times faster than with the classical approaches

*/
// Date : 9/24/2020
// Place : Patna,Bihar,India







#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pi;
const ll large=1e15;

int n,m;

void solve(){

    // Here n is for the total number of vertices
    // and m is for the total number of edges
    cin>>n>>m;

    // gf is matrix for the actual graph building between given edges and vertices
    // gr is matrix for the reverse graph building exactly reverse of the given graph
    vector<vector<int>>gf(n,vector<int>());
    vector<vector<int>>gr(n,vector<int>());


    // cf is for the cost or the distance between any two given vertices of given edge in actual graph
    // cr is for the cost pr the distance between any two given vertices of given edge in reverse graph
    vector<vector<int>>cf(n,vector<int>());
    vector<vector<int>>cr(n,vector<int>());

    // mat is build according to the actual graph if there is an edge the value between both vertices is non-zero
    // this is buiding for checking perpose in O(1) is between code ...

    vector<vector<int>>mat(n,vector<int>(n,0));


    // this for is for taking the input of two vertices and length between the vertices
    for(int i=0;i<m;i++){

        // u is for the 1st vertex.. v is for the 2nd vertex.. l is for the length between u and v
        int u,v,l; 
        cin>>u>>v>>l;

        mat[u-1][v-1]=l;

        gf[u-1].push_back(v-1);
        gr[v-1].push_back(u-1);

        cf[u-1].push_back(l);
        cr[v-1].push_back(l);
    }

    // q here stands for number of queries
    int q; 
    cin>>q;


    // this while loop will run for q number of queries
    while(q--){

        // here s and t is starting and ending vertices
        int s,t; 

        cin>>s>>t;
        // graph is build 1 based indexing we have to do some of the precalculation and adjusting in 0 based indexing
        s--;
        t--;
        // if the starting and ending is same we simply print distance 0 and continue the function
        if(s==t){
            cout<<0<<"\n"; 
            continue;
        }

        // Here we have declared the two vector of size equals to vertex to keep track that is it visited or not
        // according to which we will check is some vertex visited from reverse or actual graph
        // vis is for the actual graph and rev is for the reverse graph


        vector<bool>vis(n,false);
        vector<bool>rev(n,false);

        // the the two vector frd and bkd to keep track of which vertex visited from which vertex in optimally way
        // frd for the actual graph and bkd for the reverse graph

        vector<int>frd(n,-1);
        vector<int>bkd(n,-1);

        // here we use the priority queue data structure as min heap
        // min heap optimally extract the minimum distance from the priority-queue
        // pf is for the actual graph
        // pr is for the reverse graph

        priority_queue<pi,vector<pi>,greater<pi>>pf;
        priority_queue<pi,vector<pi>,greater<pi>>pr;

        // here df and dr for calculating the distance between the and vertex from source and any vertex fro  end
        // df is for the actual graph which store the minimum possible distance of any vertex from source
        // dr is for the reverse graph which store the minimum possible distance of any vertex from end 


        vector<ll>df(n,large);
        vector<ll>dr(n,large);

        // putting the starting and ending vertex is min heap with distance 0

        pf.push(make_pair(0,s));
        pr.push(make_pair(0,t));

        // assigning the 0 in distance vector
        // df of actual graph start from s thus it will have 0 
        // dt of the reverse graph strart from t thus it will have 0

        df[s]=0;
        dr[t]=0;


        //here i have used the common vector for storing the common vertex that occuring in both graph
        //after each queries we flush the any random data inside it.

        vector<int>common(1);
        common.clear();


        // here we have used two vector pair for storing the minimum value from the min heap
        // tf is for the actual graph 
        // tr is for the reverse graph


        pair<int,int>tf;
        pair<int,int>tr;

        // running the loop upto which we incounter the common vertex in both graph

        while(!pf.empty()||!pr.empty()){
            // this condition is for checking the underflow in case if the heap is empty we are not going to extract anything
            // or pop anything
            if(!pf.empty()){

                tf=pf.top(); 
                pf.pop();
            }

            if(!pr.empty()){

                tr=pr.top(); 
                pr.pop();
            }

            // in actual graph we check if the vertex is not visited then we proceed 
            // otherwise not
            if(!vis[tf.second]){

                vis[tf.second]=true;


                //here i have taken vaiable j for running cost matrix accounding 
                //to the graph 

                int j=0;

                for(int x:gf[tf.second]){

                    // here i have updated the distance vector in actual graph  and store the minimum


                    if(df[x]>df[tf.second]+cf[tf.second][j]){

                        df[x]=df[tf.second]+cf[tf.second][j];

                        frd[x]=tf.second;

                        pf.push(make_pair(df[x],x));
                    }
                    j++;
                }
            }


            // here in reverse graph we check if the vertex is not visited the we proceed otherwise not

            if(!rev[tr.second]){

                rev[tr.second]=true;

                //here i have taken vaiable j for running cost matrix accounding 
                //to the graph 

                int j=0;

                for(int x:gr[tr.second]){

                    // here i have updated the distance in reverse graph

                    if(dr[x]>dr[tr.second]+cr[tr.second][j]){

                        dr[x]=dr[tr.second]+cr[tr.second][j];

                        bkd[x]=tr.second;

                        pf.push(make_pair(dr[x],x));
                    }

                    j++;
                }
            }


            // here we are check if any vertex visited in both actual and reverse graph



            if(rev[tf.second]&&vis[tf.second]){

                common.push_back(tf.second); 
                break;
            }


            else if(rev[tr.second]&&vis[tr.second]){

                common.push_back(tr.second); 
                break;
            }


        }

        //if we have incounter any visited vertex then we actual bidirectional computation starts

        if(!common.empty()){


            //i have assigned the dist. from actual and reverse graph here
            // then i am checking if any other stortest path available from start to end

            ll dist = dr[common[0]]+df[common[0]];

            int i=common[0];
            int j=common[0];

            while(i!=s){

                while(j!=t){

                    if(!mat[i][j]){

                        if(dist>mat[i][j]+dr[j]+df[i]){

                            dist=mat[i][j]+dr[j]+df[i];
                        }

                        j=bkd[j];
                    }
                }

                i=frd[i];
            }
            cout<<dist<<"\n"; 

            continue;
        }


        // if we cannot able to visit the start to end then we are printing -1 as flag showing 
        // it is not possible to visit from source to distination
        cout<<"-1"<<"\n";


    }

}


int main(){
    // remove comment for taking input from input file and giving output in output file
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   /*#ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
   #endif*/
    
    //int t; cin>>t;
    //while(t--)
        solve();
    return 0;
}