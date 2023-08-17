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

bool bipartite( vector<int> * edges. int n){
     if(n==0)return true;
        unordered_set<int> sets[2];
        vector<int> pending ;
        sets[0].insert(0);
        pending.push_back(0);
        while(pending.size()>0){
            int current =pending.back();
            pending.pop_back();
            int currentset= sets[0].count(current)>0 ?0:1;
           for(auto i:edges[current]){
            if(sets[0].count(i)==0&&sets[0].count(i)==0){
                sets[1-currentset].insert(i);
                pending.push_back(i);
            }
            else if (sets[currentset].count(current)>0){
                return false;
            }
           }
        }
        return true;
}

bool bipar(vector<bool> vis,unordered_map<int,list<int>> & adj,int prent_colour,
int sv,vector<int> & colour ){
    vis[sv]=true;
    colour[sv]=prent_colour;
    for(auto i: adj[sv]){
        if(!vis[i]){
            if(bipar(vis,adj,prent_colour^1,i,colour)==false)return false;
        }
        else if(vis[i]==true&&colur[i]==colour[sv])return false;
    }
    return true;
}
// concept is to assign colour as number 0 and 1 and check whether we get the colour of neigh
// same as parent any where then return false better refer codeNcode video for this 


int main()
{  functemp();
   /*just need to pass the adj matrix and the function will return whether it is colourable or not */
    /*bipar wala function easy wala h simple kyuki bas bool hi chahiya isliya set ka kaam nhi h */
    
}
