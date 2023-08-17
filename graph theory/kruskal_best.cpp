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

const int N=2e3+5; // const is very important
int par[N];
int size[N];


void make(int v){// used to make a new independent node 
    par[v]=v;
    size[v]=1;
}

int find(int v){// find ultimate parent
//improve by path compression
    if(par[v]==v)return v;
    //path compression
    else return par[v]=find(par[v]);

}

// void merge(int a,int b){
//     // ya func Q k according hoga union m call kardo isko, usko still rahne do 
// }



void Union(int v,int u){// do union of two node 
// isko improve size and rank do sa kar sakte h rank m depth sa karta h and size m component k size sa
    v=find(v);
    u=find(u);
    // m hamesha a ko bade size ka man rha hu
    if(v!=u){
    if(size[v]<size[u])swap(v,u); // hamesha v ka size bada h 
    par[u]=v;// jiska size chota h usko add kar rha hu hamesha
    size[v]+=size[u];
    }
}
int main()
{  functemp();
     int  n,m;
     cin>>n>>m;
     vector<pair<int,pair<int,int>>> edges;
     for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u>>v>>w;
        edges.push_back({w,{u,v}});
     }
     sort(edges.begin(),edges.end());
     for(int i=1;i<=n;i++)make(i);
     int cost=0;
     for(auto &edge:  edges){
        int wt=edge.first;
        int a=edge.second.first;
        int b=edge.second.second;
        if(find(a)==find(b))continue;
        Union(a,b);
        cost+=w;
        cout << a<<" "<<b;
     }
     cout << cost<<endl;
}   

