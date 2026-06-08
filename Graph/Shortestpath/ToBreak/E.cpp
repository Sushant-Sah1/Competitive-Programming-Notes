// https://codeforces.com/gym/106084/problem/E

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


    ->NEED TO MOVE THE TILES SO SO THAT CAN MOVE TILES IN BOMB ZONE OUT .
        IF MORE TILES REQUIRED TO MOVE OUT -1
        ELSE
            SEE THAT WE MUST TAKE OUT ALL THE SLABS FROM BLAST ZONE.
                USE THE PATH WITH MINIMUM MAXIMUM SLAB VALUE (SHORTEST PATH)

                SO TILL EMPTY SPACE FIND THIS SHORTEST PATH => PUT SLABS ON THE PATHS TO THIS EMPTY SPACE MAKING EMPTY SPACE CLOSER 
                NEAR BLAST ZONE AND MOVE THE SLABS OUT OF BLAST ZONE

                ==== DJISKTRA
*/

/*
    WHAT WHEN WRONG IN THE CONTEST =>

        GAVE UP ON CONTEST AFTER NOT ABLE TO DO FEW QUESTION
*/

void f(){
    ll n;cin>>n;
    ll m;cin>>m;
    ll k;cin>>k;
    vector<vector<ll>>grid(n+1,vector<ll>(m+1,0)),dp(n+1,vector<ll>(m+1,LLONG_MAX));
    for(int i=1;i<=k;i++){
        ll x;cin>>x;
        ll y;cin>>y;
        grid[x][y]=i;
    }
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
    ll u1;cin>>u1;
    ll v1;cin>>v1;
    ll u2;cin>>u2;
    ll v2;cin>>v2;
    ll req=0;
    ll ans=0;
    for(int i=u1;i<=u2;i++){
        for(int j=v1;j<=v2;j++){
            // cout<<i<<' '<<j<<' '<<u1<<' '<<u2<<' '<<v1<<' '<<v2<<endl;
            // dp[i][j]=0;
            pq.push({0,i,j});
            ans=max(ans,grid[i][j]);
            if(grid[i][j]!=0){
                req++;
            }
        }
    }
    while(!pq.empty()){
        vector<ll>vec=pq.top();
        pq.pop();
        ll v=vec[0],i=vec[1],j=vec[2];
        // cout<<v<<' '<<i<<' '<<j<<' '<<pq.size()<<endl;
        if(dp[i][j]>v){
            dp[i][j]=v;
            if(i-1>0) pq.push({max(grid[i-1][j],v),i-1,j});
            if(i+1<=n) pq.push({max(grid[i+1][j],v),i+1,j});
            if(j-1>0) pq.push({max(grid[i][j-1],v),i,j-1});
            if(j+1<=m) pq.push({max(grid[i][j+1],v),i,j+1});
        }
    }
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;
    // for(auto i:grid){
    //     for(auto j:i){
    //         cout<<j<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;
    priority_queue<ll,vector<ll>,greater<ll>>pqv;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // cout<<i<<' '<<j<<' '<<grid[i][j]<<' '<<(j>=v1 || j<=v2)<<' '<<(i>=u1 && i<=u2)<<' '<<u1<<' '<<u2<<' '<<v1<<' '<<v2<<endl;
            if(grid[i][j]==0 && !((i>=u1 && i<=u2) && (j>=v1 && j<=v2))){
                // cout<<"taking->"<<i<<' '<<j<<endl;
                pqv.push({dp[i][j]});
            }
        }
    }
    if(pqv.size()<req){
        cout<<-1<<endl;
        return;
    }
    // cout<<req<<' '<<ans<<endl;
    // while(!pqv.empty()){
    //     cout<<pqv.top()<<endl;
    //     pqv.pop();
    // }
    while(!pqv.empty() && req>0){
        req--;
        ans=max(ans,pqv.top());
        pqv.pop();
    }
    // cout<<endl;
    cout<<ans<<endl;
}

int main(){ 
   #ifndef ONLINE_JUDGE
       freopen("C:/Users/susha/Desktop/VSCODEFOLDER/input.txt", "r", stdin);
       freopen("C:/Users/susha/Desktop/VSCODEFOLDER/output.txt", "w", stdout);
   #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // long long k;
    // cin>>k;
    // for(int i=0;i<k;i++){
    f();
    // }
}