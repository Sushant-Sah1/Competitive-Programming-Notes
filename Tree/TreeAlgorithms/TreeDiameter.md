> path distance between any 2 nodes is indepedent of the root of the tree.

> there is only 1 path between at 1 nodes and it is the shortest path between them

> diameter of a tree is the maximum distance between any 2 nodes

```cpp
ll treediameter(vector<vector<ll>>&adj,ll cur,ll par,ll&ans){

    // note we do this because , the longest path must have a node which is highest among all the nodes in the path

    // at each node we consider it to pace though diameter and is the highest point in the path , 
    // and hence add the paths sum of atmost 2 maximum paths from it to its children

    ll m1=0,m2=0;   // note the initialization  -> in infernos internship contest , i messed up the initialization
    ll c=0;

    for(auto i:adj[cur]){
        if(i!=par){
            ll x=treediameter(adj,i,cur,ans);
            c=max(c,x);
            if(x>=m1){
                m2=m1;
                m1=x;
            }else if(x>m2){
                m2=x;
            }
        }
    }
    
    // note if no child then maximum path towards it is 0;

    ans=max(ans,m1+m2);

    // to parent of cur , return maximum path from it. it should be singular cuz diameter only involveseach edge being traversed once.
    // so we can only send in maximum of all children paths

    return (c+1);

}
```