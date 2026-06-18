> most of the tree algorithms involves dfs and we need to tweek them wrt the question


```cpp
void dfs(vector<vector<ll>>&adj,ll cur,ll par){

    // after entering this , we check if the states are fine or not

    for(auto i:adj[cur]){
        if(i!=par){
            ll x=dfs(adj,i,cur);
        }
    }

    // compute after travseing though children and getting required info

}
```