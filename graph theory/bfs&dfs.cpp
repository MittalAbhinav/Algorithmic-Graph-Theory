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


void printdfs ( int ** edges, int n, int sv,bool* visited){
    cout << sv<<" ";
    visited[sv]=true;
    for ( int i=0;i<n;i++){
        if(edges[sv][i]==1&&!visited[i])printdfs(edges,n,i,visited);
    }
}

void printbfs( int ** edges, int n, int sv,bool* visited){
    queue<int> q;
    q.push(sv);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        cout << top<< " ";
        visited[top]=true;
        for(int i=0;i<n;i++){
          if (edges[top][i] == 1 && !visited[i]) {
            q.push(i);
            visited[i] = true;
          }        }
    }
}


int main()
{  functemp();
   int n,e;
   cin >> n>>e;
   int ** edges =new int *[n];
   for(int i=0;i<n;i++){
    edges[i]=new int [n];
    for (int j=0;j<n;j++){
        edges[i][j]=0;
    }
   }
   for (int i=0;i<e;i++){
    int a,b;
    cin >>a>>b;
    edges[a][b]=1;
    edges[b][a]=1;
   }

   bool* visited = new bool [n];
   for(int i=0;i<n;i++){
    visited[i]=false;
   }

   for(int i=0;i<n;i++){
    if(!visited[i])printbfs(edges,n,0,visited);
   }
   
}
