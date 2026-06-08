// CLEVER BRUTE FORCE WHEN DP , GREEDY AND BINARY SEARCH IS NOT WORKING 
// INSTEAD OF NAIVE BRUTE FORCE , FOR EACH POSSIBLE POSSIBLE NEW TAG VALUE FIND ANSWER. THIS OPTIMIZATION CONVERTS FROM N^2 TO NLOGN
// ALSO WE WILL OBSERVE THAT USING FREQUENCY VECTOR INSTEAD OF FREQUENCY MAP IS MUCH MUCH MUCH FASTER BECAUSE MAP HAS TC OF LOGN FOR GETTING ELEMENT BUT 
// FREQUENCY VECTOR IS CONSTANT TC


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
    long long y;cin>>y;
    vector<long long>c;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        c.push_back(x);
    }
    vector<long long>coinc(2*1e6+1,0);
    vector<long long>mp(2*1e6+1,0);
    // map<long long,long long>mp;
    for(auto i:c){
        coinc[i]++;
        mp[i]++;
    }
    for(int i=1;i<=2*1e6;i++){
        coinc[i]+=coinc[i-1];
    }
    long long ans=LLONG_MIN;
    for(long long i=2;i<=2*1e5;i++){
        long long t=0;
        // cout<<"I>"<<i<<endl;
        for(long long j=1;j<=((2*1e5+i-1)/i);j++){
            // cout<<j<<' '<<j-1<<' '<<endl;
            // if(i==3){
            //     cout<<j<<' '<<j-1<<' '<<endl;
            // }
            long long tags=coinc[j*i]-coinc[(j-1)*i];
            t+=tags*j;
            long long avail=min(mp[j],tags);
            t-=y*(tags-avail);
        }
        ans=max(ans,t);
    }
    // cout<<"Ans->";
    cout<<ans<<endl;
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