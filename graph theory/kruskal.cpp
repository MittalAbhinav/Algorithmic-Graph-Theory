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

bool compare( Edges e1,Edges e2){
    return e1.weight<e2.weight;
}

int find(int* parent,int child){
    if (parent[child]==child)return child;
    return find( parent,parent[child]);
}

void kruskal(Edges * edges, int n, int e ){
    sort( edges,edges+e,compare);
    Edges * output =new Edges[n-1];
    int * parent =new int [n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int count =0,i=0;
    while(count <n-1){
        Edges current= edges[i];
        int srcpar= find(parent,edges[i].source);
        int despar= find( parent,edges[i].desti);
        if(srcpar!=despar){
            output[count]=edges[i];
            count ++;
            parent[srcpar]= despar;
        }
        i++;
    }
    for(int i=0;i<n-1;i++){
        cout << min(output[i].source,output[i].desti)<<" "<< max(output[i].source,output[i].desti)<<" "<< output[i].weight;
        cout << endl;
    }
}
/*basically ya h ki pahale sari node ko independent man lo and aab edges ko weight k sorted order m 
store kar lo phir min weight wali vertex lo and agar usko add karne se loop add nhi ho rha toh add
kar do varna ignore kar do 
aab kab loop ban rha h vo apn DSU sa dekhenge ki agar dono vertices ka parent same h toh mat add kar 
else kar do  */
int main()
{  functemp();
    
    int n,e;
    cin >> n>>e;
    Edges * edges = new Edges[e];
    for( int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges[i].source=s;
        edges[i].desti=d;
        edges[i].weight=w;
    }
    //for finding MST but complexity is eloge + ve by using union find algo for cycle detection can 
    // be improves by using advances version of this union by rank and path compression
    kruskal(edges, n, e);
}

//input
// 6 11
// 3 4 11
// 2 5 10
// 2 4 9
// 2 1 8
// 3 5 7
// 2 3 6
// 4 5 5
// 0 2 4
// 0 3 3
// 0 1 2
// 1 3 1
//output
// 1 3 1
// 0 1 2
// 0 2 4
// 4 5 5
// 3 5 7

