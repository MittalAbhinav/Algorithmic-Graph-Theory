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
vector<pair<int,int>> adj[1001];// simple adj list with pair to store weight
int main()
{  functemp();
   int n,m,a,b,w;
   while(m--){
    cin>> a>>b>>w;
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});// undircted man rhe h 
   }
   priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>> > pq;//min heap
   vector<int> par(n+1,-1);

   vector<int> dis(n+1,INT_MAX);
    pq.push({0,1});//weight and then vertex
    dis[1]=0;//taking 1 as the source node
    while(!pq.empty()){
        int curr =pq.top().second;// curr vertex
        int curr_d= pq.top().first;//curr min distance
        pq.pop();
       if(dis[curr]<curr_d)continue; ////MORE OSM TIME OPTIMIZATION///////
        // jab push kiya tha pq m agar uske bad dis chng ho gya min toh isko consider karne 
        // ka  koi faida nhi h
        for(pair<int,int > edge: adj[curr]){// pair in adj list first if vertex and sec is weight
            
        //////////////////////////////////////////
            if(edge.first==par[curr])continue; //AGAR ISKO USE NHI KAROGE TOH MEMORY EXCEED
        ///////////////////////////////////////////

            if(curr_d+edge.second < dist[edge.first]){
                par[edge.first]=curr;
                dis[edge.first]=curr_d+edge.second;
                pq.push({dist[edge.first],edge.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << dis[i]<<" ";
    }
    
    // bcz of PQ we dont have to call the min vertex function any more 

    //IMPORTANT//
    //if negative weight cycle hui toh fail ho jaega infinte loop hoga
    //bellman ford fail nhi hoga ,ans toh dega -ve cycle m wrong dega par dega
}
