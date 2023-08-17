#include <bits/stdc++.h>
#define ll long long 
#define mod 1000000007;
using namespace std;
void functemp(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
void dfs(int sv ,int parent,vector<int>& disc,vector<int> &low,unordered_map<int,bool> &vis ,unordered_map<int,list<int>> &adj, vector<int> & ap,int timer){
    vis[sv]=true;
    low[sv]=disc[sv]=timer++;
    int child=0;
    for(auto i: adl[sv]){
        if(i==parent)continue;
        if(!visited[i]){
            dfs(i,sv,disc,low,vis,adj,ap,timer);
            low[sv]=min(low[sv],low[i]);
            //check AP 
            if(low[i]>= disc[sv]&&parent!=-1){
                ap[sv]=1;
            }
            child++;    // ya cheez uske subtree count kar rha h na ki adj list k element 
            //kyuki root k liya agar ek sa zada dfs tree honge toh vo articulation point hoga 
        }
        else{
            low[sv]=min(low[sv],disc[i]);
        }
    }
    if(parent==-1&&child>1){
        ap[sv]=1;
    }
}


int main()
{  functemp();
   
unordered_map<int,list<int>> adj;

    int timer=0;
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int,bool> vis;
    vector<int> ap(n,0);

    for(int i=0;i<n;i++){
        if(!vis[i])
        dfs(i,-1,disc,low,vis,adj,ap,timer);
    }
    
}
