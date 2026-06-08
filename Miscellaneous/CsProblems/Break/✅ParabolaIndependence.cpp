// READ EDUTORIAL

// originally i was going for only sorting on basis of vertex ,but sorting also along sign of is important(think about it more)
// cuz what i am doing is total parabolas it is in independence with on right +left, if we only do it wrt vertex , like in testcase 1
// -ve a with vertex upper of +ve a with lower vertex  wont be counted if they r independent 

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll=long long;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

struct para{
    ll a,b,c,indx;
    bool operator<(const para& other){
        if(a*other.a<0){
            return a<other.a;
        }
        return (other.a*((b*b)-(4*a*c)))>(a*(((other.b)*(other.b))-(4*(other.a)*(other.c))));
    }
};

void f(){
    long long n;cin>>n;
    vector<para>v;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        ll b;cin>>b;
        ll c;cin>>c;
        v.push_back({a,b,c,i});
    }
    sort(v.begin(),v.end());
    // reverse(v.begin(),v.end());
    // for(auto i:v){
    //     cout<<"I_>"<<i.indx<<' '<<i.a<<' '<<i.b<<' '<<i.c<<endl;
    // }
    vector<ll>dpl(n,1);
    for(int i=0;i<n;i++){
        ll ans=0;
        for(int j=0;j<i;j++){
            ll b=(v[i].b-v[j].b);
            ll c=(v[i].c-v[j].c);
            ll a=(v[i].a-v[j].a);
            if((b*b-4*a*c)<0 || (b==0 && a==0)){
                ans=max(ans,dpl[j]);
            }
        }
        dpl[i]+=ans;
    }
    vector<ll>dpr(n,1);
    for(int i=n-1;i>=0;i--){
        ll ans=0;
        for(int j=n-1;j>i;j--){
            ll b=(v[i].b-v[j].b);
            ll c=(v[i].c-v[j].c);
            ll a=(v[i].a-v[j].a);
            if((b*b-4*a*c)<0 || (b==0 && a==0)){
                ans=max(ans,dpr[j]);
            }
        }
        dpr[i]+=ans;
    }
    vector<ll>ans(n);
    for(int i=0;i<n;i++){
        // cout<<(dpr[i.indx]+dpl[i.indx]-1)<<' ';
        ans[v[i].indx]=dpr[i]+dpl[i]-1;
    }
    // cout<<"ans->";
    for(auto i:ans){
        cout<<i<<' ';
    }
    cout<<endl;
    
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
