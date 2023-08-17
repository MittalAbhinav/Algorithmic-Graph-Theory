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
int n=10001;//assumging 1e4 nodes
int maxN=log2(n);
int a,b;
int lca[n+1][maxN];//where lca[i][j]=2^j the parent of i
vector<int> adj[10001]//adj list 
vector<int > level(n,-1);
int count ;


void dfs(int sv,int par){// this will fill the 2^0 parent of i( parent of i)
   
    LCA[sv][0]=par;
    for(int i:adj[sv]){
        if(i!=par){
            level[i]=level[sv]+1;
            dfs(i,sv);
        }
    }
}
void built(){// this will fill all power of 2 parent of each node 
    level[1]=0;
    dfs(1,-1);
    for(int j=1;j<=maxN;j++){
        for(int i=1 ;i<=n;i++){
            if(lca[i][j-1]!=-1){
                int par=lca[i][j-1];
                lca[i][j]=lca[par][j-1];
            }
        }
    }
}

int LCA(int a,int b){
    if(level[a]>level[b])swap(a,b);
    int d =level[b]-level[a];
    while(d>0){
        int i=log2(d);
        b=lca[b][i];
        d-=(i<<i);
    }
    if(a==b)return a;
    for(int i=maxN;i>=0;i++){
        if(lca[a][i]!=-1&&(lca[a][i]!=lca[b][i]))
        a=lca[a][i],b=lca[b][i];
    }
    return lca[a][0];
}

int main()
{  functemp();
    cin >> n;
    //edges input lena hoga and adj matrix built karna hoga
    built();
    //ab bas basic LCA ka code 
    cin >> a>> b;// jinka nikalna h 
    int num =LCA(int a,int b);
     
    
    
    
}
