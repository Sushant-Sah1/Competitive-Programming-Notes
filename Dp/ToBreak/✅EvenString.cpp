//  USE IF TARGET SUM DP
// KNAPSACH SORT OF
// COMBINATIONS

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

long long binPow(long long a,long long b,long long mod){
    long long ans=1;
    long long p=a;
    while(b!=0){
        if(b%2==1){
            ans=(ans*p)%mod;
        }
        b=b/2;
        p=(p*p)%mod;
    }
    return ans;
}

void f(vector<long long>&fact){
    long long mod=998244353;
    vector<long long>c;
    long long sum=0,fpod=1;
    for(int i=0;i<26;i++){
        long long x;cin>>x;
        c.push_back(x);
        sum+=x;
        fpod=(fpod*fact[x])%mod;
    }
    long long tar=sum/2;
    // cout<<tar<<' '<<(sum-tar)<<' '<<sum<<' ';
    long long config=(fact[tar]*fact[(sum-tar)])%mod;
    // cout<<config<<' ';
    config=(config*binPow(fpod,mod-2,mod))%mod;
    // cout<<config<<endl;;
    // find number of ways of get tar
    // kanpsach sort of dp
    vector<long long>dp(tar+1,0);
    dp[0]=1;
    for(int i=0;i<26;i++){
        // cout<<i<<' '<<c[i]<<"->";
        if(c[i]>0){
            for(int j=tar;j>=c[i];j--){
                dp[j]+=dp[j-c[i]];
            }
            
        }
        
    }
    // for(auto i:dp){
    //     cout<<i<<' ';
    // }
    // cout<<endl;
    // cout<<"Ans->";
    cout<<((dp[tar]*config)%mod)<<endl;
}

int main(){ 
    long long n=5*(1e5);
    long long mod=998244353;
    vector<long long>fact;
    fact.push_back(1);
    for(int i=1;i<=n;i++){
        fact.push_back((fact.back()*i)%mod);
    }
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f(fact);
    }
}