// #include <queue>



// bool iscycle(vector<vector<int>>& edges, int n,bool* visited,int sv,int* parent ){
//     parent[sv]=-1;
//     queue<int> q;
//     q.push(sv);
//     visited[sv]=true;
//     while(!q.empty()){
//         int front=q.front();
//         q.pop();
//         for(int i=1;i<=n;i++){
//             if(edges[front][i]==1){
//               if (!visited[i]) {
//                 q.push(i);
//                 visited[i]=true;
//                 parent[i] = front;
//               }
//               else if(visited[i]&&parent[front]!=i){
//                   return true;
//               }
//             }
//         return false;
//         }
//     }
// }

// string cycleDetection (vector<vector<int>>& edges, int n, int e)
// {
//     // Write your code here.    
//     bool visited[n+1];
//     for(int i=1;i<=n;i++){
//         visited[i]=false;
//     }
//     int parent[n+1];

//     for(int i=1;i<=n;i++){
//         if(!visited[i]){
//             if(iscycle(edges, n, visited, i,parent)){
//                 return "Yes";
//             }
//         }
//     }
//     return "No";

   
// }
