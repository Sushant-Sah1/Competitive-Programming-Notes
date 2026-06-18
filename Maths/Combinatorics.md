# Dominos are fun [https://codeforces.com/group/NpnwJNnkjM/contest/696453/problem/I]
- idea is that this is similar to chess board problem (ITS VARIATION WHERE WE COMBINE PARTS TOGETHER (1*1*4 RODS)  AND SEE IF THEY FIT IN SOME 3D SPACE) . instead of separately considering piece , try to combine them together.
- here we combine into 2*2 piece (2 horizontal or 2 vertical).
-  note int his problem 1 side is always even 
- if both sides even then yes if even number of vertical and horizontal
- lets say rows are odd , then (m/2) horizontal will be used to full them making the rest even*even. make sure that horizontals and enoguh and there are even number of vertical horizontal.
- similiar for the column being odd.


# Total Matching Pairs [https://codeforces.com/group/NpnwJNnkjM/contest/696453/problem/DI]
- standard technique of problem solving . instead of trying to find score for each subarray , count in how many windows a given pair comes. 
>[THIS IS PRETTY SIMILAR TO FINDING EXPECTATION VALUE IN SOME QUESTIONS {GIVEN X MEN AND Y WOMEN STIING IN (X+Y) CHAIRS LINED TOGETHER , WHAT IS THE EXPECTATION VALUE OF THE NUMBER PAIRS SITTING TOGETHER .=> HERE FOR EACH PAIR FIND EXPECTATION OF TIMES A PAIR OF OPPOSITE GENDER WILL SIT ON IT . BY LINEARITY OF EXPECTATION VALUE WE FIND THE EXPECTATION OF NUMBER OPPOSITE GENDERS SITTING SIDE BY SIDE AS SUM OF EXPECTATION OF EACH ADJACENT SEATS}]
- now the for counting the number of windows this pair will be present is use this concept ->
[st,....i,....,j....,end]; lets number of elements from [st,i] be x and from [j,end] be y , then number of windows having i and j inside then is x*y.
- now if we go by naive way , we get tc n^2 ... we cant do it...
- SO finally to convert it to n , we will use map . at each i ans+=count(i to end)*mp[a[i]],in map[a[i]] add (i+1)-> number ofelements from st to ith indx .
- why ? => lets i , j be same as k . ans= [st,i]*[k,end]+[st,j]*[k,end]=> ([st,i]+[st,j])*[k,end] . now for next same a[idx] . we will also place [st,k] in map so we could directly mutliple.


# Abhinav's Lost Array [https://codeforces.com/group/NpnwJNnkjM/contest/696453/problem/G]
- easy to see we only care about the raimder of k with 3 where k belongs to [l,r], count the number of elements with remainders 0,1,2 and use then in counting.

->THINKING ABOUT COMBINATORICS SOLTUION WITH LOOPS (THAT IS TRYING LETS SAY X ELEMENTS TO BE TRIPLETS AND Y LETS TO BE DOUBLES AND Z BE SINGLES . THEN I WAS THINKING OF HOW TO COUNT THEM FOR EACH LENGHT AND THEN HOW TO INCLUDE PERMUATION => GETTING WAY TO COMPLEX COULDNT DO IT)

=> SOLUTION WAY (MUCH BETTER):-
    USE DP:-
    - dp state till i indx , number of distinct permuations such that remainder is j {j vary from 0 to 2}.
    - FOR EACH J OF I DP[I][J] USE-> if using remainder 0 -> DP[I-1][j]
                                        if using remainder 1 -> DP[I-1][J-1]
                                        if using remainder 2 -> DP[I-1][J-2]
                                            NOT FOR EACH EXACT TRANSITION IS ->
                                                DP[I][J]+=DP[I-1][(J-remainder+3)%3]*(number of elements having this remainder)
- note that this method of dp directly calculates distinct permuations.so no need to exclusively multiply something to get permuation eg for i=1, calculates reminader 1 first separately and 2 remainder separately and i-2 , for remaidner 2 , prev remainder 1 is included and for remainder 1 , prev reminader 2 is include => handles permuation =>[1]->[1,2] ; [2]->[2,1]

> why dp ? => if we can get all distinct permuations for arr till i-1 having raminder (J-remainder+3)%3 , we can get distinct permuations for arr till i having remainder j.

> knapsack variant