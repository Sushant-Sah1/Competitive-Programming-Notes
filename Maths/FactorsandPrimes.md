- an important thing to note is that while finding factors of a number n, we just need to check till sqrt(n), the other factors greater than sqrt(n) can be just found by dividing n but this factors less than sqrt(n).

- we can extend this idea for finding primes factors or prime factorization.oberse that there can be atmost 1 prime number greater than sqrt(n), if there r more then the product will be greater than n , which is not possible.
n=p1^x1*p2^x2....pn^x2.so for prime factorization , check for prime factors till sqrt(n), then till these n is divisible by prime factor , divide it and store it or something . then after all the primes before and equal to sqrt(n) if n!=1 , then there exist a prime number greater than sqrt(n) and n will have that value. For primes ,as we r prime factorization we already getting the primes factors so do whatever is needed.
```cpp
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    vector<long long>primes(1e6+1,true);
    primes[0]=false;
    primes[1]=false;
    for(long long i=0;i<=1e6;i++){
        if(primes[i]){
            for(long long j=2*i;j<=1e6;j+=i){
                primes[j]=false;
            }
        }
    }
    // for(int i=0;i<40;i++){
    //     cout<<primes[i]<<' ';
    // }
    // cout<<endl;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        long long ans=0,t=n;
        for(long long i=1;i*i<=t;i++){
            if(primes[i] && t%i==0){
                ans=max(ans,i);
                while(t%i==0){
                    t=t/i;
                }
            }
        }
        if(t!=1){
            ans=max(ans,t);
        }
        cout<<ans<<endl;
    }
    return 0;
}

```

- the number is perffect square , if the number of factors it has is odd , else it is not a perfect square. for perfect sqaure , there must exist m, such that m*m==n and m,(n/m) will only contribute 1 to increase in factors.other factors  100% are paired (one before sqrt(n) and other after sqrt(n)), oth unequal increasing number of factors by 2.

- all prime numbers greater than 3 are in the form 6*k-1 or 6*k+1

- number of primes numbers less than or equal to n is n/ln(n)

- the kth prime number is approximately k*ln(k)