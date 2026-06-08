// WHEN SECOND PARMETER (HERE NUMBER OF PEOPLE IN EACH LANE) IS BIG , WE GENERALLY USE THE CONCEPT THAT FROM POINTS 
// BEOFRE THE CURRENT POINTS, GET THE BEST VALUE USING A SPECIFIC OPERATION (HERE EITHER TAKING ALL LEFT / ALL RIGHT)

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
    vector<long long>a;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        a.push_back(x);
    }
    long long mod=1e9+7;
    // USE OF LDS/LIS TYPE OF THING
    vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(n+1,vector<long long>(n+1,1)));
    // [....  ..|----]
    // dp[i][j][k]  ->number of subsequenes to right of i(may /may not include ),satisfying having lds of lenght 1 with highest element j and lds of lenght 2 with 2nd highest element k from left to i.
    long long ans=0;
    for(long long i=n-1;i>=0;i--){
        for(long long j=0;j<=n;j++){
            for(long long k=0;k<=n;k++){
                long long cur=0;
                // not take
                cur=(cur+dp[i+1][j][k])%mod;
                // take
                if(a[i]>=k){
                    long long x=max(j,a[i]);
                    long long y=k;
                    if(a[i]<j){
                        y=a[i];
                    }
                    cur=(cur+dp[i+1][x][y])%mod;
                }
                dp[i][j][k]=cur;
                // ans+=dp[i][j][k];
            }
        }
        // ans+=dp[i][a[]]
    }

    // cout<<"Ans->";
    cout<<dp[0][0][0]<<endl;
}

int main(){ 
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f();
    }
}