>type of questions where u r given a condition and form a suitable optimal algorithm about it

# Longest Max Min Subsequence [https://codeforces.com/problemset/problem/2001/D]
- here we need to find an specific type of subsequence and best out of all subsequence satisfying conditions.
- given we require unique elements, maintain a vector bool for ensure we dont take them again,
- vector v with ptr m , ensureing a limit on region we can take suitable elements from ,cuz we might skip element that we havent taken and as a result not take it at all.
- priority_queues to get the best array satisfying specific type of condition. 