# there are 3 types of knapsacks

## 0/1 knapsack 
>here given n items <mark>SUCH THAT EACH ITEM CAN BE TAKEN ONLY ONCE</mark> with wieght w[i] and value v[i] and a knapsack of wieght W. we wanna find maximum value we can obtain suh that total wt is less than equal to W

>TC = O(n*W);
>SC = O(W);
(1 based indexing here of i)
```cpp

for (int i = 1; i <= n; i++)
  for (int j = W; j >= w[i]; j--)
    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

```

## Complete knapsack 
>here given n items <mark>SUCH THAT EACH ITEM CAN BE TAKEN AS MANY TIMES AS U WANT TIMES</mark> with wieght w[i] and value v[i] and a knapsack of wieght W. we wanna find maximum value we can obtain suh that total wt is less than equal to W

>TC = O(n*W);
>SC = O(W);
(1 based indexing here of i)
```cpp

for (int i = 1; i <= n; i++)
  for (int j = w[i]; j <=W; j++)
    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

```

## Multiple knapsack 
>here given n items <mark>SUCH THAT EACH ITEM CAN BE TAKEN ATMOST FIXED NUMBER OF TIMES</mark> with wieght w[i] and value v[i] and a knapsack of wieght W. we wanna find maximum value we can obtain suh that total wt is less than equal to W

>here easiest way is to make each each exist as many times as it can be taken in the array

>TC = O((sum of times each item can be taken)*W);
>SC = O(W);
(1 based indexing here of i)
```cpp

for (int i = 1; i <= n; i++)
  for (int j = w[i]; j <=W; j++)
    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

```
or
(0 based indexing here of i)
```cpp

for (ll i = 0; i < n; i++) {
	ll cnt = freq[i];
	for (ll rep = 0; rep < cnt; rep++) {
		for (ll j = W; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
		}
	}
}
```

## Some common questions that can be used to solve it
### Subset Sum  (similiar to target sum)
> there are n items each with value v[i] find/check if we can find a set with sum of values is C
(here i have written code for only taking item once (0/1) , we can write it for complete/ multiple also)
(1 based indexing here of i)
```cpp

for (int i = 1; i <= n; i++)
  for (int j = C; j >=w[i]; j--)
    if(dp[j-v[i]]){
        dp[j]=true;
    }

```

# KNAPSACK OPTIMIZATION  (FOR 0/1 KNAPSACK)
>here is a knapsack optimization <mark>SPECIFICALLY FOR JUST CHECKING IF WE CAN OBTAIN A VALUE OR NOT (SUBSET SUM) </mark> using bitset

>it is easy to do just observe that when we are at v[i], it just makes dp[i] true if dp[i-v[i]] is true (THAT IS WE CAN SOMEWHAT CORRESPOND IT TO SHIFTING OF DP ARRAY TO RIGHT BY v[i]). And ofcourse , we must all the points that were already true wont be affect and will stay the same , so to retain orginal dp array and incoperate the shift , we do operation similiar to bitwise or . 

>TC = O(((sum of times each item can be taken)*W)/ω); where ω depends on machine (usually 64)
>SC = O(W);

- this isnt much but just enough to pass some time limits

(0 based indexing here of i)
```cpp
bitset<C+1>dp
dp[0]=1;
for (int i = 0; i < n; i++)
  dp=dp|(dp<<v[i]);
// check if we can achive C or not
if(dp[C]==1){
    cout<<"Yes"<<endl;
}else{
    cout<<"No"<<endl;
}
```
### INDEXING AND IMPORTANT FACTS IN BITSET  

- bitset<k+1> is invalid here because k is runtime input. (k must be a constant)
- std::bitset<N> requires N to be a compile-time constant.

>    std::bitset<4> bs("1000"); 
>    // In this bitset:
>    // bs[0] is 0 (rightmost)
>    // bs[1] is 0
>    // bs[2] is 0
>    // bs[3] is 1 (leftmost)

#### USE CASE OF KNAPSACK OPTIMIZATION
- https://codeforces.com/contest/2138/problem/C1
```cpp
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll=long long;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

ll dfs(vector<vector<ll>>&adj,ll cur,ll par,ll d,vector<ll>&depth){
    if(depth.size()<d){
        depth.push_back(1);
    }else{
        depth[d-1]++;
    }
    ll mind=LLONG_MAX;
    for(auto i:adj[cur]){
        if(i!=par){
            mind=min(mind,dfs(adj,i,cur,d+1,depth));
        }
    }
    if(mind==LLONG_MAX){
        return d;
    }else{
        return mind;
    }
}

void f(){
    long long n;cin>>n;
    ll k;cin>>k;
    vector<ll>p;
    vector<vector<ll>>adj(n+1);
    for(int i=0;i<n-1;i++){
        ll x;cin>>x;
        p.push_back(x);
        adj[i+2].push_back(x);
        adj[x].push_back(i+2);
    }
    vector<ll>depth;
    ll mind=dfs(adj,1,-1,1,depth);
    while(depth.size()>mind){
        depth.pop_back();
    }
    ll tr=0;
    for(auto i:depth){
        tr+=i;
    }
    vector<bool>dp(k+1,false);
    dp[0]=true;
    ll maxic=0;
    for(auto i:depth){
        for(ll j=k;j>=0;j--){
            if((i+j)<=k){
                if(dp[j]){
                    dp[i+j]=true;
                    maxic=(max(maxic,(i+j)));
                }
            }
        }
    }
    if((tr-maxic)<=(n-k)){
        cout<<mind<<endl;
    }else{
        cout<<(mind-1)<<endl;
    }
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f();
    }
}
```
- https://codeforces.com/problemset/problem/2138/C2
```cpp
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll=long long;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

const ll MAXK = 2*1e5+1;


ll dfs(vector<vector<ll>>&adj,ll cur,ll par,ll d,vector<ll>&depth){
    if(depth.size()<d){
        depth.push_back(1);
    }else{
        depth[d-1]++;
    }
    ll mind=LLONG_MAX;
    for(auto i:adj[cur]){
        if(i!=par){
            mind=min(mind,dfs(adj,i,cur,d+1,depth));
        }
    }
    if(mind==LLONG_MAX){
        return d;
    }else{
        return mind;
    }
}

void f(){
    long long n;cin>>n;
    ll k;cin>>k;
    vector<ll>p;
    vector<vector<ll>>adj(n+1);
    for(int i=0;i<n-1;i++){
        ll x;cin>>x;
        p.push_back(x);
        adj[i+2].push_back(x);
        adj[x].push_back(i+2);
    }
    vector<ll>depth;
    ll mind=dfs(adj,1,-1,1,depth);
    while(depth.size()>mind){
        depth.pop_back();
    }
    ll tr=0;
    for(auto i:depth){
        tr+=i;
    }
    bitset<MAXK>dp;
    dp[0]=1;
    ll maxic=0;
    for(auto i:depth){
        dp=(dp|(dp<<i));
    }
    ll ans=mind;
    for(ll i=0;i<=k;i++){
        if(dp[i]){
            maxic=i;
        }
    }
    if((tr-maxic)<=(n-k)){
        cout<<mind<<endl;
    }else{
        cout<<(mind-1)<<endl;
    }
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f();
    }
}
```

# KNAPSACK OPTIMIZATION  (FOR 0/k KNAPSACK)
> currently we have tc is O(w*(sum of frequence)), we can do better by decomposing the freq[i] into its power of 2 and remainder, each with its own cost and weight. this optimization will make it O(w*(sum of log(frequence)))
>eg> here, say the frequency of some item is 13, it's value is 3 and the weight of each one of it is 4 here I would represent each item as (frequency,weight,value)
>we decompose the frequency into smaller items then we get this (1,4,3),(2,4⋅2,3⋅2),(4,4⋅4,3⋅4) now there is a problem the remaining frequency is 6 which is not a power of 2 so we can just (again split it in power of 2 ) ,or leave it as it is (best) =  (1,4,3),(2,4⋅2,3⋅2),(4,4⋅4,3⋅4),(6,4⋅6,3⋅6)or just (1,4,3),(2,8,6),(4,16,12),(6,24,18)

```cpp
vector<ll> dp(W+1, 0);
for (ll i = 0; i < n; i++) {
	ll cnt = freq[i];
	for (ll b = 1; cnt > 0; b *= 2) {
		ll take = min(b, cnt);
		ll c = w[i] * take;
		ll val = v[i] * take;
		for (ll j = W; j >= c; j--) {
			dp[j] = max(dp[j], dp[j-c] + val);
		}
		cnt -= take;
	}
}
```