```cpp
class DisjointSet{
    vector<int>parent; 
    vector<int>size; 
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v){
            return;
        }else if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
```

# The Infero Selection Mystery [https://codeforces.com/group/NpnwJNnkjM/contest/696453/problem/E]
- notice that we need to take one of a[i],b[i]  . as it is a permuation other must be also taken. so it goes to other a[j],b[j] where one of them is the one not taken . so it must be taken . then again the other goes and chain continous till it reach again at a[i],b[i] (that is rounds up to a[k],b[k] where the one not taken is already taken).=> forms a cycle always.
- these cycles only have 2 ways to put elements of the indexes in the cycle.
- note if a[i]==b[i] its a cycle of 1 element => it has only 1 way to to put elements of the indexes in the cycle in the permuation. 
- also note if in some cycle c[i] is non zero (fixed) => then that cycle will only contribute to 1
- use dsu and separate and unite them (indexes in the same cycle) then for answer cycle contributes of each cycle.