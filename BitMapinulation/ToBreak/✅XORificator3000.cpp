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
    long long l;cin>>l;
    long long r;cin>>r;
    long long i;cin>>i;
    long long k;cin>>k; 
    long long net0r=0,net0l=0;
    if(r%4==0){
        net0r=r;
    }else if(r%4==1){
        net0r=1;
    }else if(r%4==2){
        net0r=r+1;
    }
    if((l-1)%4==0){
        net0l=(l-1);
    }else if((l-1)%4==1){
        net0l=1;
    }else if((l-1)%4==2){
        net0l=l;
    }




    long long p=1<<i;
    long long left,fr;
    fr=(r+1)/p;
    left=(r+1)-p*fr;
    if(left>=(k+1)){
        fr++;
    }
    long long remr=0,reml=0,remor=0,remol=0;
    if(fr%2==1){
        remr^=k;
    }
    fr--;
    if(fr>=0){
        if(fr%4==0){
            remor^=(fr<<i);
        }else if(fr%4==1){
            remor^=(1<<i);
        }else if(fr%4==2){
            remor^=((fr+1)<<i);
        }
    }
    fr=(l)/p;
    left=l-p*fr;
    if(left>=(k+1)){
        fr++;
    }
    if(fr%2==1){
        reml^=k;
    }
    fr--;
    if(fr>=0){
        if(fr%4==0){
            remol^=((fr)<<i);
        }else if(fr%4==1){
            remol^=(1<<i);

        }else if(fr%4==2){
            remol^=((fr+1)<<i);
        }
    }
    cout<<(net0r^net0l^remr^reml^remor^remol)<<endl;
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