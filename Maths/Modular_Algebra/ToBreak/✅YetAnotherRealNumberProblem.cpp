// MODULAR COMPARISON AND NATURE OF 2 AROUND 1E9

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

void f(vector<long long>&ptwo,vector<long long>&ptwo32){
    long long n;cin>>n;
    vector<long long>a;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        a.push_back(x);
    }
    long long ans=0,mod=1e9+7;
    stack<pair<long long,long long>>st;
    for(int i=0;i<n;i++){
        long long t=a[i],pcur=0;
        t=a[i];
        while(t%2==0){
            pcur++;
            t=t/2;
        }
        bool tr=false;
        while(!st.empty()){
            auto [x,y]=st.top();
            if(!tr){
                if(x<=t*ptwo32[pcur]){
                    pcur+=y;
                    ans=(((ans+mod-((x*ptwo[y])%mod))%mod)+x)%mod;
                    st.pop();
                }else{
                    break;
                }
                if(pcur>=30){
                    tr=true;
                    continue;
                }else if(1e9<=ptwo32[pcur]*t){
                    tr=true;
                    continue;
                }
            }else{
                pcur+=y;
                ans=(((ans+mod-((x*ptwo[y])%mod))%mod)+x)%mod;
                st.pop();
            }
            
        }
        st.push({t,pcur});
        ans=(ans+(t*ptwo[pcur])%mod)%mod;
        cout<<ans<<' ';
    }
    cout<<endl;
}

int main(){ 
    vector<long long>ptwo(7*1e6);
    vector<long long>ptwo32(33);
    long long p=1,mod=1e9+7,x=1;
    for(int i=0;i<7*1e6;i++){
        if(i!=0){
            p=(p*2)%mod;
        }
        if(i<=32){
            ptwo32[i]=x;
            x=x*2;
        }
        ptwo[i]=p;
    }
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f(ptwo,ptwo32);
    }
} 