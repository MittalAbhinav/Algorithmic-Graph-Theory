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
int main()
{  functemp();
    int n,e;
     cin >>n>>e;
     int dist[n][n];
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)dist[i][j]=0;
            else dist[i][j]=INT_MAX;
            }
     }

     while(e--){
        int a,b,w;
        cin >> a>>b>>w;
        dist[a][b]=w;//incase repeated edges de toh min lelena 
      //  SOME WHAT LIKE THIS
    //      dis[a][b]=min(w,dis[a][b]);
    // dis[b][a]=min(w,dis[b][a]);
     }


     //this is the main algo for floyd_warshell

     for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
     }
        /*isme apn har do node k bech m shortest nikal rhe h
        pahale zero node consider karke nikala then ek , then do and so on
         
        */
        
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]!=INT_MAX)
            cout << dist[i][j]<<" ";
            else cout << "INF"<<" ";
        }
        cout << endl;
    }


    
    
}
