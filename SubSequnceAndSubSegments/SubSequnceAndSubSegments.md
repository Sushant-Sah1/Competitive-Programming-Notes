# Longest Max Min Subsequence [https://codeforces.com/problemset/problem/2001/D]
- here we need to find an specific type of subsequence and best out of all subsequence satisfying conditions.
- given we require unique elements, maintain a vector bool for ensure we dont take them again,
- vector v with ptr m , ensureing a limit on region we can take suitable elements from ,cuz we might skip element that we havent taken and as a result not take it at all.
- priority_queues to get the best array satisfying specific type of condition. 


# Valuable Cards [https://codeforces.com/problemset/problem/1992/F]
- ##### for the first time , i read the question wrong
- here brute force way = iterate through all the previously stored elements and see if we get product x.if not store the new ones along with old ones (complexity around exponential {incearse in the lenght of prev by mutliplying by 2})
- but in brute for we r storing many useless values. NOTICE THAT ONLY DIVISORS OF X SHOULD BE STORED AS THEY ONLY CAN MUTLIPLE TO GIVE X.
- SO INSTEAD CHECK IF DIVSORS CAN BE ONLY FORMED OR NOT. this is a simple observation but makes it for n*(exponential) to n*d(x) where d is divisors of x