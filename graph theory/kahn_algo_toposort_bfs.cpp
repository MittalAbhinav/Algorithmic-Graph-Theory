
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
//works for DAG only otherwise if number of output <n then false
// means either cycle or undirected edge is present
void toposort(unordered_map<int,list<int >>& adj,int inarray[],int n ){
    queue<int> q;// for lexigraphicL small use min heap
     for(int i=0;i<n;i++)
        if(inarray[i]==0)
            q.push(i);  
    while (!q.empty()){
        int front=q.front();
        cout <<front << " ";
        q.pop();
        for(auto i :adj[front]){
            inarray[i]--;
            if(inarray[i]==0)q.push(i);
        }
    }                     
    return;
}

/*isme apn basically vo node dal rhe h jo bilkul hi independent h jo kisi pa depend nhi kar rhi
    apni inarray issi cheez a hisab rakh rhi h ki ek value kitno pa dependent h agar 0 
    pa dependent h toh dal do and dali hui value k connection hata do bakiyo sa 
    OPP to DFS based approach usme pahle jo sabpe dependent h usko dalte h stack m
*/


int main()
{  functemp();
   int n,e;
   cin >> n>>e;
   unordered_map<int,list<int >> adj;
   int inarray[n]={0};
   while(e--){
//    cout << "hi";
    int a,b;
    cin >> a>>b;
    adj[a].push_back(b);
    inarray[b]++;
   }
    toposort(adj,inarray,n);
   // if printed element is less than n NON DAG return false
}
