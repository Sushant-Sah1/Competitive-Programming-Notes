#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

void f(){
    long long n;cin>>n;
    map<long long,long long>mp;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        mp[x]++;
    }
    vector<long long>dp(n+1,0);
    long long mod=998244353;
    dp[0]=1;
    long long maxi=1;
    for(auto i:mp){
        maxi=max(i.second,maxi);
        for(int j=n;j>=i.second;j--){
            dp[j]=(dp[j]+(i.second*dp[j-i.second])%mod)%mod;
        }
    }
    long long ans=0;
    for(int i=maxi;i<=n;i++){
        ans=(ans+dp[i])%mod;
    }
    // cout<<"Ans->";
    cout<<ans<<endl;
    // for(auto i:dp){
    //     cout<<i<<' ';
    // }
    // cout<<endl;
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