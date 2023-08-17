// #include <bits/stdc++.h>

// bool dfs(unordered_map<int ,list<int> > adj,int n,unordered_map<int,int>& visited,int sv){
	
// 	visited[sv]=1;
// 	for(auto i: adj[sv]){
// 		if(visited[i]==0){
// 			if(dfs(adj,n,visited,i))return true;
// 		}
// 		else if(visited[i]==1)
// 		return true;
// 	}
// 	visited[sv]=2;
// 	return false;


// }

/*make a visited list  which has 3 values 
0 means not visited
1 means currently under process
2 means deadend
    not use of parent concept visited array will do it 
    if somewhere you find visited[i]==1
    means its a cycle 

*/


// bool isCyclic(vector<vector<int>>& edges, int n, int e)
// {
// 	// Write your code here
// 	unordered_map<int ,list<int> > adj;
// 	for(int i=0;i<e;i++){
// 		adj[edges[i][0]].push_back(edges[i][1]);
// 	}


// 	unordered_map<int,int> visited;
// 	for(int i=0;i<n;i++){
// 		visited[i]=0;
// 	}
// 	for(int i=0;i<n;i++){
// 		if(visited[i]==0){
// 			if(dfs(adj,n,visited,i))return true;
// 		}
// 	}
// 	return false;

// }
