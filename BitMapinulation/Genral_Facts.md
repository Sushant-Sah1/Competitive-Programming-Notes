- a number with highest bit n, will always be greater than number with highest bit less than n ,even if all the other bits in that number is on . eg 10000 will always be bigger than numbers with highest bit 1000,100,10,1 even 10000 is bigger than 01111 (all lower bits on).

- x|y = x&y + x^y

- x + y ,wrt bitwise involves adding each these 2 bit by bit , eg 110 + 011 => 1001  (last bit justs adds up , second last carry over 1,3rd last include 0+1+carryover(1) , giving 10, which carries over 1, which atlast makes 1+carryover(1)=10).  ENSURE THAT LIKE IN THESE LIKE IF WE GET MUTLIPLE 1+1+1+1 (bits), if the thing may be carried over to multiple bits ahead , example in this case 1+1+1+1 =4 which is 100 , so this bit is set to 0(last), next bits ahead of this willhave 0 carryover(2nd last) and next to that will have 1 carryover(3rd last bit)

- if adding some functions of bitwise eg f(x)+f(y)+f(z) .. where f is a function over something and question is related to bitwise and we wanna make 11001 for example , we can designate each function to give a part of the bit of the number or expression (some specific part of final expression or number , that f(x) will contribute). 
in this example we can do like f(x) will give 10000, f(y)=1001 , f(z)=1 and so one.
also another variation f(x)+f(y)+f(z)=1101+1100 then f(x)=1100 , f(y)=1100 , f(z)=1 , or so on .
WE BREAK PARTS OF EXPRESSION IN MEANINGFULL AND SOLVABLE PARTS .

- to make a bitwise function maximum , we need to maximise the number of on bits(preffrablly higher onces).eg in xor for maximum we want higher bits be odd in count(x^y, x and y higher bits different, x^y^z , count of on higher bits should be odd). to maximise addition , as many higher digits as possible.

- lets say i have a number x , then the using combination of bits we can ensure that , no combination of the bits of this number make a number greater than x . eg> 13 , we can break it into 1, 2, 4, 6 (powers of 2 till remainder is greater than the power and then the remainder), any number from 0 to 13 can be formed by combinations of these  



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
    - (ops to make b supermask of a) +1  (iterate b->2*b and check if i&b==i) (2*b because b is max and 2*b will open new bit)