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

void topodfs(unordered_map<int,list<int >> &adj, bool visited[],int n, stack<int> & s,int sv){
    visited[sv]=true;
    for(auto i: adj[sv]){
        if(!visited[i]){
            topodfs(adj,visited,n,s,i);
        }
    }
    s.push(sv);
    return;
}
// to make it work for non DAG keep a track of dfs visited in that particular call
// if in a single call, we find a value that is dfsvis then cycle or undirected
// so return false;
// else you can use kahn with non DAG condition


int main()
{  functemp();
   int n ,e;
   cin >> n>>e;
   unordered_map<int,list<int >> adj;
    while(e--){
        int a,b;
        cin >> a>>b;
        adj[a].push_back(b);
    }
    
    bool visited[n]={false};
    stack<int > s;
    for(int i=0;i<n;i++){
        if(!visited[i])topodfs(adj,visited,n,s,i);
    }  

    vector<int> temp;
    while(!s.empty()){
        temp.push_back(s.top());
        s.pop();
    }
    for(auto i: temp)
    cout << i<< " ";
    cout << endl;
}
