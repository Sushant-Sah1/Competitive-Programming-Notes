https://codeforces.com/gym/106084/problem/D

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll=long long;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

/*
   READ THE QUESTION PROPERLY DONT RUSH,
   U R NOT INTELLIGENT ENOUGH TO GRASP THE WHOLE QUESTION IN ONE GO


   IF U R RUSHING U WILL GET WRONG QUESTION REQUIREMENT 
   AND WILL 100% GET IT WRONG, OR WONT BE ABLE TO SOLVE IT
       ->READ THE QUESTION ATLEAST 2 TIMES BEFORE STARTING TO SOLVE 
*/

/*
   got stuck while solving after reading the question ? 
       => RE-READ THE QUESTION 
*/



/*
   WRITE OBSERVATIONS/FLOW OF LOGIC HERE  


*/

/*
    WHAT WHEN WRONG IN THE CONTEST =>
        DIDNT CORRECTLY TOOK ANSWERS FROM DP.
            PALINDROME CAN BE ...||... OR  ...|... SO NEED TO TAKE ANSWERS FROM DP[I-1][I] AND DP[I][I] => MINIMUM OF THEM

    ALSO SPEND TO MUCH TIME IN THINKING ABOUT EDTITING STRING DP => DP TRANSITION FOR INSERTITION/DELETION/CONVERSTION
*/

void f(){
    string s;cin>>s;
    ll n=s.size();
    string t=s;
    reverse(t.begin(),t.end());
    vector<vector<ll>>dp(n+2,vector<ll>(n+2,0));
    for(int i=n+1;i>=0;i--){
        // cout<<i<<' '<<(n+1-i)<<' '<<(n+2)<<endl;
        dp[0][i]=n+1-i;
        dp[i][n+1]=i;
    }
    ll ans=n;
    // for(int i=0;i<n+2;i++){
    //     for(auto j=0;j<n+2;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            if(s[i-1]==s[j-1]){
                dp[i][j]=dp[i-1][j+1];
            }else{
                ll cur=LLONG_MAX;
                cur=min(cur,1+dp[i-1][j+1]);
                cur=min(cur,1+dp[i][j+1]);
                cur=min(cur,1+dp[i-1][j]);
                dp[i][j]=cur;
            }
        }
    }
    // for(int i=0;i<n+2;i++){
    //     for(auto j=0;j<n+2;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<=n+1;i++){
        ans=min(ans,dp[i][i]);
    }
    for(int i=1;i<=n+1;i++){
        ans=min(ans,dp[i-1][i]);
    }
    // cout<<endl<<endl;

    cout<<ans<<endl;
}

int main(){ 
   #ifndef ONLINE_JUDGE
       freopen("C:/Users/susha/Desktop/VSCODEFOLDER/input.txt", "r", stdin);
       freopen("C:/Users/susha/Desktop/VSCODEFOLDER/output.txt", "w", stdout);
   #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f();
    }
}