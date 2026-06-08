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
    long long a=1,b=1,ans=2,c=0;
    vector<pair<long long,long long>>count;
    vector<pair<char,char>>sign;
    for(int i=0;i<n;i++){
        char as;cin>>as;
        long long ac;cin>>ac;
        char bs;cin>>bs;
        long long bc;cin>>bc;
        count.push_back({ac,bc});
        sign.push_back({as,bs});
        // if(as=='+' && bs=='+'){
        //     c+=ac+bc;
        //     ans+=ac+bc;
        // }else if(as=='x' && bs=='+'){
        //     a+=c;
        //     c=0;
        //     c=a*(ac-1)+bc;
        //     ans+=c;
        // }else if(as=='+' && bs=='x'){
        //     b+=c;
        //     c=0;
        //     c=b*(bc-1)+ac;
        //     ans+=c;
        // }else{
        //     if(ac==bc){
        //         if(a>b){
        //             a+=c;
        //             c=0;
        //             c=a*(ac-1)+(bc-1)*b;
        //             ans+=c;
        //         }else{
        //             b+=c;
        //             c=0;
        //             c=a*(ac-1)+(bc-1)*b;
        //             ans+=c;
        //         }
        //     }else if(ac>bc){
        //         a+=c;
        //         c=0;
        //         c=a*(ac-1)+(bc-1)*b;
        //         ans+=c;
        //     }else{
        //         b+=c;
        //         c=0;
        //         c=a*(ac-1)+(bc-1)*b;
        //         ans+=c;
        //     }
        // }
    }
    vector<vector<pair<long long,long long>>>dp(n+1,vector<pair<long long,long long>>(2));
    dp[0]={{1,1},{1,1}};
    // dp[i][j] j=1>a maxi, j=2>b maxi
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            // creating maximum at gate a
            pair<long long,long long>t={LLONG_MIN,LLONG_MIN};
            for(int k=0;k<2;k++){
                auto [x,y]=dp[j][k];
                long long c=0;
                for(int l=j;l<i;l++){
                    if(sign[l].first=='x'){
                        c+=(count[l].first-1)*x;
                    }else{
                        c+=count[l].first;
                    }
                    if(sign[l].second=='x'){
                        c+=(count[l].second-1)*y;
                    }else{
                        c+=count[l].second;
                    }
                    x+=c;
                }
                if(t.first<x){
                    t={x,y};
                }else if(t.second<y && t.first==x){
                    t={x,y};
                }
            }
            dp[i][0]=t;
            t={LLONG_MIN,LLONG_MIN};
            // creating maximum at gate b
            for(int k=0;k<2;k++){
                auto [x,y]=dp[j][k];
                long long c=0;
                for(int l=j;l<i;l++){
                    if(sign[l].first=='x'){
                        c+=(count[l].first-1)*x;
                    }else{
                        c+=count[l].first;
                    }
                    if(sign[l].second=='x'){
                        c+=(count[l].second-1)*y;
                    }else{
                        c+=count[l].second;
                    }
                    y+=c;
                }
                if(t.second<y){
                    t={x,y};
                }else if(t.first<x && t.second==y){
                    t={x,y};
                }
            }
            dp[i][1]=t;
        }
        // cout<<"I> ";
        // long long am=1,bm=1;
        // for(int j=i;j<n;j++){
        //     if(sign[j].first=='x'){
        //         am*=count[j].first;
        //     }
        //     if(sign[j].second=='x'){
        //         bm*=count[j].second;
        //     }
        // }
        // cout<<a<<' '<<b<<' '<<c<<"  ->  ";
        // if(am>bm){
        //     a+=c;
        // }else{
        //     b+=c;
        // }
        // c=0;
        // cout<<a<<' '<<b<<' '<<c<<"  ->  ";
        // if(sign[i].first=='x'){
        //     c+=(count[i].first-1)*a;
        // }else{
        //     c+=count[i].first;
        // }
        // if(sign[i].second=='x'){
        //     c+=(count[i].second-1)*b;
        // }else{
        //     c+=count[i].second;
        // }
        // cout<<a<<' '<<b<<' '<<c<<endl;
    }
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j.first<<' '<<j.second<<"   -   ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"Ans->";
    cout<<max(dp[n][0].first+dp[n][0].second,dp[n][1].first+dp[n][1].second)<<endl;
}

int main(){ 
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f();
    }
}