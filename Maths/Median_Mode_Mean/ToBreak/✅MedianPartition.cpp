// USING WRONG OBSERVATION
// IF DIVIDING THE WHOLE ARRAY IN SUBARRAYS SUCH THAT EACH ELEMENT IS A PART OF AN SUBARRAY AND EACH SUBARRAY MUST 
// HAVE SAME MEDIAN , THAT MEDIAN IS ALWAYS THE MEDIAN OF THE WHOLE ARRAY !!! <<IMPORTANT

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
    vector<long long>a,s;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        a.push_back(x);
        s.push_back(x);
    }
    sort(s.begin(),s.end());
    long long med=s[n/2];
    vector<vector<long long>>pref;
    long long l=0,e=0,g=0;
    pref.push_back({l,e,g});
    for(auto i:a){
        if(i<med){
            l++;
        }else if(i>med){
            g++;
        }else{
            e++;
        }
        pref.push_back({l,e,g});
    }
    vector<long long>dp(n+1,-1);
    dp[0]=0;
    l=0;e=0;g=0;
    for(int i=1;i<=n;i++){
        if(a[i-1]<med){
            l++;
        }else if(a[i-1]>med){
            g++;
        }else{
            e++;
        }
        for(int j=0;j<i;j++){
            if(dp[j]!=-1){
                long long el=l-pref[j][0];
                long long ee=e-pref[j][1];
                long long eg=g-pref[j][2];
                if(ee-abs(el-eg)>0 && (el+ee+eg)%2==1){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
    }
    // cout<<med<<endl;
    // for(auto i:pref){
    //     cout<<i[0]<<' '<<i[1]<<' '<<i[2]<<endl;;
    // }
    // cout<<endl;
    // cout<<"ans->";
    // for(auto i:dp){
    //     cout<<i<<' ';
    // }   
    // cout<<endl;
    // cout<<"ans->";
    cout<<dp[n]<<endl;
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