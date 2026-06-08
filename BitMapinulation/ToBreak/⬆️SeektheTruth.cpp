// MISSED THE FACT THAT  WHEN ALL BITS ON , XOR , || GIVES THE SAAMTHING WHEN OPERATED WITH ALL BITS ON 
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
    long long response;
    long long p=1,q=1;
    long long k=0,c=0;
    for(int i=0;i<n-1;i++){
        p=p*2;
        q+=p;
    }
    cout<<0<<endl;
    cout<<"I "<<0<<endl;
    cin>>response;
    if(response==1){
        k=1;
        cout<<"I "<<q<<endl;
        cin>>response;
        cout<<"I "<<q<<endl;
        cin>>response;
        for(int i=0;i<n;i++){
            c+=p;
            cout<<"Q "<<c<<endl;
            cin>>response;
            if(response==0){
                c-=p;
            }
            p=p/2;
        }
    }else{
        for(int i=0;i<n;i++){
            c+=p;
            cout<<"Q "<<c<<endl;
            cin>>response;
            if(response==0){
                c-=p;
            }
            p=p/2;
        }
        cout<<"I "<<q<<endl;
        cin>>response;
        if(response==2){
            cout<<"I "<<1<<endl;
            cin>>response;
            if(response==2){
                k=2;
            }else{
                k=3;
            }
        }else{
            cout<<"Q "<<q<<endl;
            cin>>response;
            if(response==1){
                k=2;
            }else{
                k=3;
            }
        }
    }

    cout<<"A "<<k<<' '<<c<<endl;
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