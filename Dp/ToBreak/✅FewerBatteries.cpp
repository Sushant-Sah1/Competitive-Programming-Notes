// REMEMBER DP ON GRAPHS OR TREES IS NOT AT ALL SOMETHING NEW AND ABSTRACT , IT IS JUST LIKE ARRAYS BUT THE CONNECTIN IS GIVEN BY EDGES, AND WE NORMAL TRAVERAL AND TAKE IN ELEMENTD THAT ARE ALREADY COMPUTED NOTHING MORE NOTHING LESS.
// THIS IS SPECIFICALLY A GOOD PROBLEM AS IT USES MIN-MAX CONECPT(ON BINARY SEARCH PROBLEMS) AND INTERGRATES IT WITH DP.
// THE FACT THAT QUESTIONS ASKS FOR MINIMUM BATTERIES AT THE END BUT WE WANT TO KEEP AS MANY BATTERIES AS POSSIBLE AS IT OPENS UP MORE PATHS MAKES IT A MINMAX PROBLEM.
// MIN MAX PROBLEM IS USED WHEN WANT MAXIMUM/MINIMUM OF A VALUE AND ASKED FOR MINIMUM OF THE MAXIMUM VALUE/MAXIMUM OF THE MINIMUM VALUE

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
    long long m;cin>>m;
    vector<long long>b;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        b.push_back(x);
    }
    vector<vector<pair<long long,long long>>>adj(n+1);
    for(int i=0;i<m;i++){
        long long s;cin>>s;
        long long t;cin>>t;
        long long w;cin>>w;
        adj[t].push_back({s,w});
    }
    long long ans=LLONG_MAX;
    long long l=1,r=1e9;
    while(l<=r){
        long long mid=(l+r)/2;
        vector<long long>dp(n+1,-1);
        dp[1]=min(mid,b[0]);
        for(int i=2;i<=n;i++){
            for(auto j:adj[i]){
                if(dp[j.first]>=j.second){
                    dp[i]=max(dp[i],min(mid,dp[j.first]+b[i-1]));
                }
            }
        }
        if(dp[n]!=-1){
            ans=min(ans,dp[n]);
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    // cout<<"Ans->";
    if(ans==LLONG_MAX){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
}

int main(){ 
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f();
    }
}