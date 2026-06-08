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
    vector<vector<char>>grid(2,vector<char>(n+1));
    for(int i=0;i<2;i++){
        for(int j=1;j<=n;j++){
            char x;cin>>x;
            grid[i][j]=x;
        }
    }
    vector<vector<long long>>dp(n+1,vector<long long>(3,LLONG_MIN));
    dp[0][0]=0;
    // 0-> X
    //     X
    // 1-> O
    //     X
    // 2-> X
    //     O

    for(int i=1;i<=n;i++){
        // cout<<"I>"<<i<<endl;
        if(i-1>=0){
            // cout<<"YES"<<endl;
            long long a=(grid[0][i]=='A')+(grid[1][i]=='A')+(grid[0][i-1]=='A');
            dp[i][0]=max(dp[i][0],dp[i-1][1]+(a>1));

            a=(grid[0][i]=='A')+(grid[1][i]=='A')+(grid[1][i-1]=='A');
            dp[i][0]=max(dp[i][0],dp[i-1][2]+(a>1));
        }
        if(i-2>=0){
            // cout<<"BRO"<<endl;
            long long a=(grid[0][i-1]=='A')+(grid[1][i-1]=='A')+(grid[0][i]=='A');
            dp[i][2]=max(dp[i][2],dp[i-2][0]+(a>1));

            a=(grid[0][i-1]=='A')+(grid[1][i-1]=='A')+(grid[1][i]=='A');
            dp[i][1]=max(dp[i][1],dp[i-2][0]+(a>1));
        }
        if(i-3>=0){
            // cout<<"COM"<<endl;
            long long a1=(grid[0][i]=='A')+(grid[0][i-1]=='A')+(grid[0][i-2]=='A');
            long long a2=(grid[1][i]=='A')+(grid[1][i-1]=='A')+(grid[1][i-2]=='A');
            dp[i][0]=max(dp[i][0],dp[i-3][0]+(a1>1)+(a2>1));

            a1=(grid[0][i-1]=='A')+(grid[0][i-2]=='A')+(grid[0][i-3]=='A');
            a2=(grid[1][i]=='A')+(grid[1][i-1]=='A')+(grid[1][i-2]=='A');
            dp[i][1]=max(dp[i][1],dp[i-3][1]+(a1>1)+(a2>1));

            a1=(grid[0][i]=='A')+(grid[0][i-1]=='A')+(grid[0][i-2]=='A');
            a2=(grid[1][i-1]=='A')+(grid[1][i-2]=='A')+(grid[1][i-3]=='A');
            dp[i][2]=max(dp[i][2],dp[i-3][2]+(a1>1)+(a2>1));
        }
    }
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // cout<<"Ans->";
    cout<<dp[n][0]<<endl;
}

int main(){ 
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f();
    }
}