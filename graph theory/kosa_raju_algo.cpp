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
void dfs( unordered_map<int,list<int>>& adj,unordered_map<int,bool> &visited,stack<int> & s,int sv){
    visited[sv]=true;

        for(auto i:adj[sv]){
            if(!visited[i])dfs(adj,visited,s,i);
        }
        s.push(sv);
}

void newdfs(int sv, unordered_map<int,list<int>> &transpose,unordered_map<int,bool> &visited){
        visited[sv]=true;
    for(auto i:transpose[sv]){
        if(!visited[i])newdfs(i,transpose,visited);
    }
}

int SCC(int n,vector<vector<int>> &edges){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
    }

    //topo sort //
    stack<int> s;
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,visited,s,i)
        }
    }


        //transpose
        unordered_map<int,list<int>> transpose;
        for(int i=0;i<n;i++){
            visited[i]=false;
            for(auto j:adj[i]){
                transpose[j].push_back(i);
            }
        }
        //dfs call using topo sort
        // we are writing this to return number of SCC
        /// can modify to get vector of vector to store that SCC acc to the topo ordering
       int count =0;
        while(!s.empty()){
            int top=s.top();
            s.pop();
            if(!visited[top]){
                count ++;
                newdfs(top,transpose,visited);
            }
        }
        return count ;

}




int main()
{  functemp();
    //doing all this to find strongly connected components in a directed graph//
   /*
   work to do 
   1---find topological sort of the graph
    2--- transpose the graph
    3--travel dfs/bfs ,all diffrent components are SSC
   */
    
    
    
}
