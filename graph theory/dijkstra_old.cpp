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

int minvertex(int* distance,bool*visited,int n){
    int minvertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i]&&(minvertex==-1||distance[i]<distance[minvertex])){
            minvertex=i;
        }
    }
    return minvertex;
}

void dijkstra(int** edges,int n){
    int * distance = new int [n];
    bool * visited= new bool[n];

    for(int i=0;i<n;i++){
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;

    for(int i=0;i<n-1;i++){
        int min= minvertex(distance,visited,n);
        visited[min]=true;
        for(int j=0;j<n;j++){
            if(!visited[j]&&edges[min][j]){
                int dist=distance[min]+edges[min][j];
                if(dist<distance[j]){
                    distance[j]=dist;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        cout << 0 <<" "<< i<< " "<<distance[i];
        cout <<endl;
    }    
}

int main()
{  functemp();
   int n,e;
   cin >> n>>e;
   int ** edges= new int * [n];
   for(int i=0;i<n;i++){
    edges[i]= new int [n];
    for(int j=0;j<n;j++){
        edges[i][j]=0;
    }
    }
    for (int i=0;i<e;i++){
        int a,b,w;
        cin >> a>>b>>w;
        edges[a][b]=w;
        edges[b][a]=w;
    }

// for finding min distance from A SINGLE SOURCE node , here we have set it as 1 but you can also change it accordingly
 //IMPORTANT///
 //this is not applid on negative weighted algo//
 //for negative weight we use BELLMAN FORD //
 //IMPORTANT//
 //IF THERE IS A CYCLE WITH TOTAL NEGATIVE WEIGHT THEN 
 //WE CANNOT FIND ITS SHORTEST PATH//

 
    dijkstra(edges,n);
}