> sometime we need to form expressions to actually solve a problem .
> forming expression gives us an idea on what to do , either search or minimize/maximize something etc.

# Strange Test [https://codeforces.com/problemset/problem/1632/C]
- let maximum possible ans is abs(a-b).if a>=b , we use this maximum possible answer as b cant be substituted with or.
- also observe that c=a|b, then c>=a && c>=b, so the we can 3rd operation atmost 1 time then cuz b cant be substituted witth |. 
- but we can definately do 1st and 2nd operation before 3rd operation , then after that only 2nd operation.
- so mathematically for total operations=> let A>=a and b>=b before 3rd op. then =>
total operation= (A-a)+(B-b)+1+((A|B)-B);
simplifying we get (A+(A|B))+(1-a-b) , as (1-a-b) is constant we need to minimize (A+(A|B))
- note that we iterate from a to b as if iterate greater than b , (>=b)+(>=b), but if between (<b)+(>=b) , so suitable for minimizing.
> NOTE IN BIT MANIPULATION IT IS ALWAYS SUITABLE TO SEE CASES BIT BY BIT LIKE THIS
- also note for getting suitable b , we go from highest to lowest bit and use this cases =>
    - if A is 0 and b is 1 set B 1
    - if A is 1 and b is 1 set B 1
    - if A is 0 and b is 0 set B 0
    - if A is 1 and b is 0 set B 1 and stop

    
> another answer-> O(b)
- answer is either 
    - abs(a-b)
    - (ops to make a submask of b) +1   (iterate a->b and check if i&b==i)
    - (ops to make b supermask of a) +1  (iterate b->2*b and check if i&b==i)