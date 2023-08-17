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

int minvertex(int *weight,int n,bool* visited){
    int minweight=INT_MAX;
    int minindex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i]&&weight[i]<minweight){
            minweight=weight[i];
            minindex=i;
        }
    }
    return minindex;
    /*
    int minindex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i]&&(minindex==-1||weight[i]<weight[minindex])){
            minindex=i;
        }
    }
    return minindex;
    */
}


void prims(int** edges, int n){
    bool* visited= new bool[n];
    int * parent= new int [n];
    int * weight = new int [n];
    for(int i=0;i<n;i++){
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    weight[0]=0;
    parent[0]=-1;
    for(int i=0;i<n-1;i++){
        int min=minvertex(weight,n,visited);
        visited[min]=true;
        for(int j=0;j<n;j++){
            if(!visited[j]&&edges[min][j]){
                if(weight[j]>edges[min][j]){
                    weight[j]=edges[min][j];
                    parent[j]=min;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        if(parent[i]<i){
            cout << parent[i]<< " "<< i<< " "<<weight[i];
        }
        else {
            cout << i<<" "<< parent[i]<<" "<<weight[i];
        }
        cout << endl;
    }
}
//AVOID THIS USE NEW KRUSKAL //////////////////////////////
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
//used to find MST complexity is n^2 but can be improved by using adjancy list and priority list


    prims(edges,n);
}
