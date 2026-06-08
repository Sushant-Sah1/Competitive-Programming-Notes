- sometimes when in game theory questions take a basic case a see condition of winning or losing . IF FOUND , u can try creating it in first few steps.

# EXAMPLE =>
# Product Positive

## Problem Statement

**This is very similar to the Product Negative problem, the only difference is you delete subarrays with product $1$ instead of $-1$.**

Alice and Bob are playing a game on an array $A$ of size $N$. It is guaranteed that either $A_i = 1$ or $A_i = -1$.

In a single move, the current player does the following:

- choose $(L, R)$ satisfying
  - $1 \le L \le R \le |A|$
  - $A_L \times A_{L + 1} \times \ldots \times A_R = 1$
- delete the subarray $A[L, R]$ from the array, concatenating the arrays formed, in the same order.

The player who cannot make a move, loses. Alice goes first and the turns alternate. Predict the winner of the game. Further, as a proof of concept, if Alice wins the game; you have to provide a valid winning choice of $L$ and $R$ for the first move of Alice.

## Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input.
  - The first line of each test case contains a single integer $N$.
  - The second line contains $N$ integers - $A_1, A_2, \ldots, A_N$.

## Output Format
For each test case, output the following:
- `Alice` or `Bob` depending on who wins
- If your answer is `Alice`, you should also print $2$ integers $L$ and $R$, such that $(L, R)$ is a valid winning choice for Alice's first move.

## Constraints
- $1 \le T \le 10^4$
- $1 \le N \le 2 \cdot 10^5$
- $A_i = 1$ or $A_i = -1$.
- The sum of $N$ over all test cases does not exceed $2 \cdot 10^5$.

## Sample Input
```text
4
3
-1 -1 -1
3
1 -1 -1
1
-1
5
1 -1 -1 -1 1
```

## Sample Output
```text
Alice
1 2
Alice
1 3
Bob
Alice
2 3
```

```cpp
#include <bits/stdc++.h>
using namespace std;

void f(){
    long long n;cin>>n;
    vector<long long>a;
    long long cn=0;
    for(int i=0;i<n;i++){
        long long x;cin>>x;
        a.push_back(x);
        if(x==-1){
            cn++;
        }
    }
    if(cn%2==0){
        cout<<"Alice"<<endl;
        cout<<1<<' '<<n<<endl;
        return;
    }
    long long l=0,r=0;
    while(a[l]!=-1){
        l++;
    }
    while(a[n-1-r]!=-1){
        r++;
    }
    if(cn==1 && l==r){
        cout<<"Bob"<<endl;
    }else{
        cout<<"Alice"<<endl;
        if(l>r){
            cout<<(r+1)<<' '<<(n-r-1)<<endl;
        }else{
            cout<<(l+2)<<' '<<(n-l)<<endl;
        }
    }
}

int main() {
    long long t;cin>>t;
    for(int i=0;i<t;i++){
        f();
    }
	// your code goes here

}
```