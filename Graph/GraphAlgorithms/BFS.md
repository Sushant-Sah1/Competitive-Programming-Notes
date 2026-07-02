# BFS

>note if not connected graph , trverse through each node and if not visited , traverse it
```cpp
    // ... previous code...
    vector<bool>vis(n+1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            traversalAlgorithm(i);
        }
    }
    // ... next code...
```


## General BFS Algorithm
```cpp
    // ... previous code...
    queue<ll>q;
    q.push(cur);
    while(!q.empty()){
        ll x=q.front();   // x has states , like node (for example shortest path bfs , lenght of path till here)
        q.pop();
        // check if the current state is suitable on this node (like if doing shortest path bfs , is it suitable value or not (mean if it is equal or not))
        if(condition){
            for(auto i:adj[cur]){
                // check if the the state generated from this node to next is suitable or not (again if doing shortest path bfs , is using this giving smaller value of not)

                if(condition){
                    // update the states of the next node
                    update states of next node

                    // push the states in the q
                    q.push(states);
                }
            }
        }
    }
    // ... next code...
```


### BFS traversal
```cpp
void bfs(vector<vector<ll>>adj,vector<bool>&vis,ll cur){
    queue<ll>q;
    vis[cur]=true;
    q.push(cur);
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        for(auto i:adj[cur]){
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
    }
}
```