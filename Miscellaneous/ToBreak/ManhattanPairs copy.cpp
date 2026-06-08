// https://codeforces.com/problemset/problem/2122/C

// WE CANT FIND GREEDILY THEN MAXIMUM MANHATTAN DISTANCE OF 2 POINTS EACH TIME AND GIVE THE ANSWER CANT EVEN PASS TEST CASES GIVEN IN QUESTION
// BETTER INSIGHT ON THE 1D CASE , THAT IS IF WE HAVE A PARTTION WITH EQUAL NUMBER ELEMENTS ON EITHER SIDES OF IT , CHOOSING ANY ONE OF ONE SIDE TO OTHER ALWAYS HAVE THE TOTAL SUM OF ALL PAIRS MAXIMUM.
// NUMBER OF POINTS IS A BETTER INDICATOR THAN VALUE OF POINT WHIHC ABOUT WHICH IT DIVIDES INTO 2 PARTS WITH EQUAL NUMBER OF ELEMENMTS.
// NUMBER OF POINTS HANDLES THE CASE WITH POINTS WITH OVERLAPPING VALUES MORE EFFICIENTLY.

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
    vector<pair<long long,long long>>xcoor;
    vector<pair<long long,long long>>ycoor;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        long long y;cin>>y;
        xcoor.push_back({x,i});
        ycoor.push_back({y,i});
    }
    sort(xcoor.begin(),xcoor.end());
    sort(ycoor.begin(),ycoor.end());
    vector<long long>sortedxpos(n);
    vector<long long>sortedypos(n);
    for(int i=0;i<n;i++){
        // cout<<i<<' '<<xcoor[i].second<<' '<<ycoor[i].second<<' '<<n<<endl;
        sortedxpos[xcoor[i].second]=i;
        sortedypos[ycoor[i].second]=i;
    }
    vector<long long>q1;
    vector<long long>q2;
    vector<long long>q3;
    vector<long long>q4;
    for(int i=0;i<n;i++){
        if(sortedxpos[i]<(n/2) && sortedypos[i]<(n/2)){
            q1.push_back(i);
        }else if(sortedxpos[i]>=(n/2) && sortedypos[i]<(n/2)){
            q2.push_back(i);
        }else if(sortedxpos[i]<(n/2) && sortedypos[i]>=(n/2)){
            q3.push_back(i);
        }else{
            q4.push_back(i);
        }
    }
    for(int i=0;i<q1.size();i++){
        cout<<q1[i]+1<<' '<<q4[i]+1<<endl;
    }
    for(int i=0;i<q2.size();i++){
        cout<<q2[i]+1<<' '<<q3[i]+1<<endl;
    }
}

int main(){ 
    long long k;
    cin>>k;
    for(int i=0;i<k;i++){
        f();
    }
}