// WHEN SECOND PARMETER (HERE NUMBER OF INTEL POINTS) IS SMALL (CAN BE STORED WITH EACH INDX), WE GENERALLY CALCULATE FOR EACH INDX 
// BEST VALUE FOR EACH OF ITS SECOND PARAMETER AND USE THIS TO GET VALUE FOR NEXT FIRST PARAMTER. 

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
    long long m;cin>>m;
    vector<long long>a;
    long long indx=-1;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        a.push_back(x);
        if(indx==-1 && a[i]==0){
            indx=i;
        }
    }
    vector<vector<long long>>dp(m+1,vector<long long>(m+1,-1e9));
    dp[0][0]=0;
    long long c=1;
    // dp[i][j]=> intel, total pts available
    // map<long long,long long>mps,mpi;
    vector<long long>vs,vi;
    while(indx<n){
        indx++;
        while(indx<n){
            if(a[indx]<0){
                vs.push_back(-a[indx]);
            }else if(a[indx]>0){
                vi.push_back(a[indx]);
            }else{
                break;
            }
            indx++;
        }
        sort(vs.begin(),vs.end());
        sort(vi.begin(),vi.end());
        for(int j=0;j<=c;j++){
            // ci+=mpi[j];
            long long ci=upper_bound(vi.begin(),vi.end(),j)-vi.begin();
            long long cs=upper_bound(vs.begin(),vs.end(),c-j)-vs.begin();
            if(j-1>=0){
                dp[c][j]=max(dp[c][j],dp[c-1][j-1]+ci+cs);
            }
            dp[c][j]=max(dp[c][j],dp[c-1][j]+ci+cs);
        }
        // mps.clear();
        // mpi.clear();
        vs.clear();
        vi.clear();
        c++;
    }
    long long ans=-1e9;
    for(int i=0;i<=m;i++){
        ans=max(ans,dp[m][i]);
    }
    cout<<ans<<endl;
}

int main(){ 
    // long long k;
    // cin>>k;
    // for(int i=0;i<k;i++){
    f();
    // }
}