// https://codeforces.com/contest/2018/problem/A

// TO FIND A WAY TO DISTRIBUTE CARDS(THERE ARE MULTIPLE) BUT CARDS WILL ALWAYS BE DISTRIBUTED IF THEY SATISFY A GIVEN CONDITION
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

// MINIMUM NUMBER OF CARD PER DECK=1
// MAXIMUM NUMBER OF CARDS PER DECK=N
// NOW MAXMIM NUMBER OF CARDS THAT CAN BE PARTITIONED IS SUM OF ALL CARDS OF EACH NUMBER + K
// MINIMUM NUMBER OF CARDS FOR PARTITION IS SUM OF CARDS OF EACH NUMBER
// FOR GIVEN CARDS PER DECK ,  = ALL CARDS/CARDS PER DECK
// CONDITION IS THAT NUMBER OF CARDS USE(NUMBER OF DECKS FORMED*CARDS PER DECK) SHOULD BE GREATER THAN MINIMUM NUMBER OF CARDS FOR PARTITION
// ALSO ANOTHER NUMBER OF COMPLETE DECKS GREATER THAN MAXIMUM NUMBER OF CARDS FOR A GIVEN NUMBER

void f(){
    long long n;cin>>n;
    long long k;cin>>k;
    vector<long long>a;
    long long maxi=0,sum=0;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        sum+=x;
        maxi=max(maxi,x);
        a.push_back(x);
    }
    long long ans=n;
    while(true){
        long long decks=(sum+k)/ans;
        if(decks*ans>=sum && decks>=maxi){
            break;
        }
        ans--;
    }
    // cout<<"ans->";
    cout<<ans<<endl;
}

int main(){ 
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f();
    }
}