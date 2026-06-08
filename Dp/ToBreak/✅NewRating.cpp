//  USE OF DP IF GREEDY ISNT WORKING . REMEMBER THIS USE OF DP ALWAYS AND ALWAYS WHERE U ASSUME U KNOW ANSWER OF ARRAY
//  TILL WHOLE LEFT PART/ RIIGHT PART AND THEN WHAT WILL U DO TO CONTINUE THE ANSWER 
// THIS IS SIMILIAR TO RABBITS DP QUESTION

//  ALWAYS AND ALWAYS REMBER THIS DP THINKING PROCESS AND KEEP IT IN MIND ALWAYS.


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

long long func(long long x,long long ai){
    if(x>ai){
        x--;
    }else if(x<ai){
        x++;
    }
    return x;
}


void f(){
    long long n;cin>>n;
    vector<long long>a;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        a.push_back(x);
    }
    // if(n==1){
    //     cout<<0<<endl;
    //     return;
    // }
    vector<vector<long long>>dp(n,vector<long long>(5,-1));
    // 0->|||  1->... 2->..||| 3->||...|| 4-> ||..
    dp[0][0]=1;
    dp[0][1]=0;
    dp[0][2]=0;
    dp[0][3]=0;
    dp[0][4]=0;
    for(int i=1;i<n;i++){
        dp[i][0]=func(dp[i-1][0],a[i]);
        dp[i][1]=0;
        dp[i][2]=max(func(dp[i-1][2],a[i]),func(dp[i-1][1],a[i]));
        dp[i][3]=max(func(dp[i-1][3],a[i]),func(dp[i-1][4],a[i]));
        dp[i][4]=max(dp[i-1][4],dp[i-1][0]);
        // long long n0,n1,n2,n3,n4;
        // if(a[i]>dp[i-1][0]){
        //     n0=dp[i-1][0]+1;
        // }else if(a[i]<dp[i-1][0]){
        //     n0=dp[i-1][0]-1;
        // }
        // n1=1;
        // if(a[i]>dp[i-1][2]){
        //     n2=dp[i-1][2]+1;
        // }else if(a[i]<dp[i-1][2]){
        //     n2=dp[i-1][2]-1;
        // }
        // if(a[i]>dp[i-1][3]){
        //     n3=dp[i-1][3]+1;
        // }else if(a[i]<dp[i-1][3]){
        //     n3=dp[i-1][3]-1;
        // }
    }
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<"Ans->";
    cout<<max(max(dp[n-1][1],dp[n-1][2]),max(dp[n-1][3],dp[n-1][4]))<<endl;;
}

int main(){ 
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f();
    }
}