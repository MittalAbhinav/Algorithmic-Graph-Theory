#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds; 
#define ll long long 
#define mod 1000000007;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
void functemp(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
vector<int> bellman_ford(vector<vector<int>> &edges,int n,int s){
    vector<int> dis(n,1e8);
    dis[s]=0;
    for(int i=0;i<n-1;i++){
        for( auto id: edges){
            int u=id[0];
            int v=id[1];
            int wt=id[2];
            if(dis[u]!=1e8&& dis[v]>dis[u]+wt){
                dis[v]=dis[u]+wt;
            }
        }
    }
    //for cycle detection
    for(auto i:edges){
         int u=i[0];
            int v=i[1];
            int wt=t[2];
            if(dis[u]!=1e8&& dis[v]>dis[u]+wt){
                return {-1};
            }
    }
    return dis;
}
int main()
{  functemp();
      int n,e;
  cin >>n>>e;
  vector<vector<int>> edges(e);
  for(int i=0 ; i<e;i++){
    int a,b,c;
    cin >> a>>b>>c;
    a--;b--;
    edges[i].push_back(a);
    edges[i].push_back(b);
    edges[i].push_back(c);//weight
  }
   vector<int>ans= bellman_ford(edges,n,0);
}   

