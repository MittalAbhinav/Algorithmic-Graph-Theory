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

void merge(int a,int b){
    // ya func Q k according hoga union m call kardo isko, usko still rahne do 
}



void Union(int v,int u){// do union of two node 
// isko improve size and rank do sa kar sakte h rank m depth sa karta h and size m component k size sa
    v=find(v);
    u=find(u);
    // m hamesha a ko bade size ka man rha hu
    if(v!=u){
    if(size[v]<size[u])swap(v,u); // hamesha v ka size bada h 
    par[u]=v;// jiska size chota h usko add kar rha hu hamesha

    // MERGE function yaha call kardo
    size[v]+=size[u];
    }
}



int main()
{  functemp();
   int n,m;
    cin >> n>>m;
    for(int i=1;i<=n;i++)make(i); // can be avoided by directly creaing it
    while(m--){
        int a,b;
        cin>> a>>b;
        Union(a,b);
    }
    // to count connected components number of elemets jo khudk parent h
    
    
}
