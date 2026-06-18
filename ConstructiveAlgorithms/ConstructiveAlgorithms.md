- constructive algorothm questions are the problem asks for an object satisfying some conditions and you need to provide an example of said object.
- practise proving ur constructive algorithm approach , not formal , just check rough proof, like can u see a problem in big cases , like do small acceptable constaints pile up and become unacceptable in big cases

- dont throw away logic of constructive until u prove it wrong , NOT THAT U JUST FOCUS ON THAT LOGIC , U R OPEN TO THINK ABOUT OTHERS.but if u cant prove working of one logic move on to another one or try to think about it
> like here i was doing a correct thing logic but without proving wrong i threw that logic and tried something which i was able to roughly see wrong but still thinking about it.... https://codeforces.com/problemset/problem/2171/E

- to think about logic , think about non trivial cases or something , like in this https://codeforces.com/problemset/problem/2171/E , try make as much part of array possible as non bad which can be by _ x x _ x x.. where x denote gcd not equal to 0.  IF I WOULD HAVE FURTHER THOUGHT NON TRIVIAL THAT WHY NOT KEEP ALL MULTIPLES OF SOME NUMBER TOGETHER AS IN X, I COULD HAVE SOLVED THE QUESTION ..

- THINK ABOUT NON TRIVAL CASES, COMBINATIONS .

- proves are mostly by contradiction with some maths axioms or question constraints or observations.


# Different Distances [https://codeforces.com/contest/2233/problem/B]
- lets say i know how to make array for n==2  (make array of lenght 8), 
        => then i can find answer for even n , just appended n==2 for (1,2), (3,4) ,(5,6) ..
- what about n is odd .
-    lets say i can make answer array for n==3 , then odd number can be made by combining 1 n==3 array and rest of n==2
        >example : n==7 -> (1,2,3) , (4,5) , (6,7)
>type of questions where u can find soltuion for some smaller parts and then combine them to get answer of bigger part  
> CONDITION => EACH PART ANSWER OF INDEPENDENT OF EACH OTHER.


# Longest Max Min Subsequence [https://codeforces.com/problemset/problem/2001/D]
- here we need to find an specific type of subsequence and best out of all subsequence satisfying conditions.
- given we require unique elements, maintain a vector bool for ensure we dont take them again,
- vector v with ptr m , ensureing a limit on region we can take suitable elements from ,cuz we might skip element that we havent taken and as a result not take it at all.
- priority_queues to get the best array satisfying specific type of condition. 
>type of questions where u r given a condition and form a suitable optimal algorithm about it