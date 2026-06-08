// PRUNING !!
// IN THIS QUESTION I GOT THE LOGIC RIGHT BUT IMPLEMENTATION ERROR CAUSED TLE.
// PRUNING IS STOPPING THE ITERATIONS OR RECURSION IF IT IS GAURENTTED THAT FOR FURTHER DOWN THE ITERATION THE THE WE WONT GET A BETTER ANSWER SO WE CUT THE LOOP OFF
// HERE IF T GETS LESS THAN POSSIBLE BCUR, AS XB IS 100% GREATER THAN ACUR HENCE WE WONT GET BETTER DIFFERENCE EVEN IF WE FIND A PAIR SO WE JUST PRUNE THE LOOP
// WITHOUT PRUNING I AM GETTING TLE , WITH PRUNING IT GETS ACCEPTED

#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<numeric>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

void f(){
    long long l;cin>>l;
    long long r;cin>>r;
    long long g;cin>>g;
    long long a=((l+(g-1))/g)*g;
    if(a>r){
        cout<<-1<<' '<<-1<<endl;
        return;
    }else{
        long long b=(r/g)*g,x=a/g,xn=b/g;
        long long ans=LLONG_MIN,acur=-1,bcur=-1;
        if(x==1 || gcd(x,xn)==1){
            cout<<g*x<<' '<<g*xn<<endl;
            return;
        }
        for(int i=0;i<=53;i++){
            long long xb=x+i,t=xn;
            if(xb<=xn){
                long long xe=(t/xb)*xb;
                while(xb<=t && xe-1<=t){
                    if(gcd(xb,t)==1 && ans<(t-xb)){
                        ans=t-xb;
                        acur=xb;
                        bcur=t;
                        break;
                    }
                    t--;
                    if(t<bcur){
                        break;
                    }
                }   
            }else{
                break;
            }
        }
        if(acur==-1){
            cout<<-1<<' '<<-1<<endl;
        }else{
            cout<<g*acur<<' '<<g*bcur<<endl;
        }
        
    }
}

int main(){ 
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f();
    }
}