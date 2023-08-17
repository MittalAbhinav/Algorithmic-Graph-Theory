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



bool cyclebfs(unordered_map<int,list<int>>& adj,
unordered_map<int,bool>& visited,int parent[],int n,int sv){
    queue<int> q;
    q.push(sv);
    parent[sv]=-1;
    visited[sv]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i: adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
                parent[i]=front;
            }
            else if(visited[i]&&parent[front]!=i){
                return true;
            }
        }

    }
    return false;
}

bool cycledfs(unordered_map<int,list<int>>& adj,
unordered_map<int,bool>& visited,int parent,int n,int sv){
    visited[sv]=true;
    for(auto i: adj[sv]){
        if(!visited[i]){
            if(cycledfs(adj,visited,sv,n,i)){
                return true;
            }
        }
        else if (visited[i]&&i!=parent){
            return true;
        }
    }
    return false;
}







int main()
{  functemp();
   int n,e;
   cin >> n>>e;
   unordered_map<int,list<int>> adj;
   for(int i=0;i<e;i++){
    int a,b;
    cin >> a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }

    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    //for bfs we need parent array but for dfs we can do it just by passing parent as a int //

    // int parent[n];
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(/*cyclebfs(adj,visited,parent,n,i)*/ cycledfs(adj,visited,-1,n,i)  ){
                cout << "true"<<endl;
                return 1;
            }
        }
    }
    cout << "false"<<endl;



    
    
}
