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

void dfs( int sv, unordered_map<int,list<int>> &adj,unordered_map<int ,bool> & vis,vector<int> & low,
vector<int> &disc,int timer,int parent,vector<vector<int >> &result){
    vis[sv]=true;
    //disc is discover time 
    low[sv]=disc[sv]=timer++;

    for(auto i: adj[sv]){
        if(i==parent)continue;
 
        if(!visited[i]){
            dfs(i,adj,vis,low,disc,timer,sv,result);
            low[sv]=min(low[sv],low[i]); // if it can be reached in less time through child
            //check for bridges
            if(low[i]>disc[sv]){ // pura explore karne k bad be agar low zada hi h toh bridge
                vector<int> ans;
                ans.push_back(sv);
                ans.push_back(i);
                result.push_back(ans);
            }
        }
        else {
            //back edge h ya 
            low[sv]=min(low[sv],disc[i]);// pahale se vis h toh iske dis time se hi update kar do
        }
    }
}




//specific algo h ya sab to detect the same thing 





int main()
{  functemp();
   // take input of adjancecy matrix and n and e
   unordered_map<int,list<int>> adj;
    
    //neede items
    int timer;
    vector<int> disc(v,-1); /// in time 
    vector<int> low(v,-1); // low time 
    int parent=-1;
    unordered_map<int ,bool> vis; // vis array 
    //isme result store karenge staring and ending of bridge
    vector<vector<int >> result ;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            timer =0;
            dfs(i,adj,vis,low,disc,timer,parent,result);
        }
    }
    
    
}
