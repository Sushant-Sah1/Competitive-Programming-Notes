# BFS


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


### BFS envolving only traversal and NO sorting of points on the basis of levels
```cpp
void bfs(vector<vector<ll>>adj,ll cur){
    queue<pair<ll,ll>>q;
    q.push({cur,-1});
    while(!q.empty()){
        auto [node,par]=q.front();
        q.pop();
        for(auto i:adj[cur]){
            if(i!=par){
                q.push({i,cur});
            }
        }
    }
}
```

### BFS envolving only traversal and sorting of points on the basis of levels
```cpp
void bfs(vector<vector<ll>>adj,ll root){
    queue<vector<ll>>q;
    vector<vector<ll>>v;
    v.push_back({root});
    q.push({root,-1,0});
    while(!q.empty()){
        vector<ll>x=q.front();
        q.pop();
        ll node=x[0],par=x[1],l=x[2];
        for(auto i:adj[node]){
            if(i!=par){
                if(l+2>v.size()){
                    v.push_back({i});
                }else{
                    v[l+1].push_back(i);
                }
                q.push({i,node,l+1});
            }
        }
    }
}
```