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
class Edges{
    public:
    int source;
    int desti;
    int weight;
};
void bellman_ford(Edges edges[],int n,int e){
    int distance[n];
    
    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    //algo yahi h ki jitni vertex h ussa ekkaam bar lagega
    // n-1 times sari edges pa necha wala formula lga do
    for(int i=0;i<n-1;i++){
        //first iteration m apn koi node ka ek pahale wali node sa kitna ho sakta h min vo nikal rhe 
        // dusri m do node travel karke kitna min ho sakta h vo nikal rhe h
        for(int j=0;j<e;j++){
           
            if(distance[edges[j].source]!=INT_MAX&&distance[edges[j].desti]>distance[edges[j].source]+edges[j].weight){
              distance[edges[j].desti]=distance[edges[j].source]+edges[j].weight;
            }
        }
    } ////////////////     IMPORTANT     //////////////////////////////////////
        /*in case check karna h ki negative cycle h ya nhi toh ek bar or lga do loop
        agar array m value chng hui toh negative cycle h and shortedt path nhi nikal sakte
        */
       //and can also be applied on a undirected graph just add one more edge opposite to that 
       //and with same weight
       bool flag=false;
       for(int j=0;j<e;j++){
           
            if(distance[edges[j].source]!=INT_MAX&&distance[edges[j].desti]>distance[edges[j].source]+edges[j].weight){
                flag=true;
                break;
            }
        }
        if(flag)cout << "negative cycle is present ";
        else cout << "print the array";

    // for(int i=0;i<n;i++){
    //  cout <<   distance[i]<<" ";
    // }


}

int main()
{  functemp();
  int n,e;
  cin >>n>>e;
  Edges edges[e];
  for(int i=0 ; i<e;i++){
    int a,b,c;
    cin >> a>>b>>c;
    edges[i].source=a;
    edges[i].desti=b;
    edges[i].weight=c;
  }
    bellman_ford(edges,n,e);
    
}
