#include<unordered_map>
#include<queue>
#include<set>
bool isCyclicBFS(int src, unordered_map<int,bool>&visited, unordered_map<int,set<int>>&adj){
    unordered_map<int,int>parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int i : adj[front]){
            if(visited[i] == true && i!= parent[front]){
                return true;
            }
            else if (!visited[i]){
                q.push(i);
                visited[i] = 1;
                parent[i] = front;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //create adjanceny list
    unordered_map<int,set<int>>adj;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].insert(v);
        adj[v].insert(u);
    }

    //to handle disconnected components
    unordered_map<int, bool>visited;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i, visited, adj);
            if(ans == 1)
                return "Yes";
        }
    }
    return "No";
}
