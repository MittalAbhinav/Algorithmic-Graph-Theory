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

/*
what is does is find the min edge and select it then it choose min from the neighbour edges of
choose vertex till now that simple
*/


int MST( int n,vector<vector<int>> adj[]){
    priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;// stores the weght and node
    vector<int> vis(n,0);
    pq.push({0,0});// initial weight and node 
    int sum =0;
    while(!pq.empty()){
        auto it =pq.top();// take the first element 
        pq.pop();
        int node = it.second;
        int wt=it.first;
        if(vis[node]==1)continue;//agar visited h toh age bado
        //add it to mst
        vis[node]=1;
        sum+=wt;
        for(auto it : adj[node]){// ussa connected sari nodes jo vis nhi h unko pq m dal do
            int adjnode=it[0];
            int edw=it[1];
            if(!vis[adjnode]){
                pq.push({edw,adjnode});
            }
        }
    }
    return sum ;// this function returns the sum of MST
}
// agar MST chahiya toh pq ko pair of pair bana lo and parent maintain kar lo and agar node vis nhi h toh 
// kisi vector m store karate jao parent and node 

int main()
{  functemp();
   // i am writing only the function 
    
    
}
