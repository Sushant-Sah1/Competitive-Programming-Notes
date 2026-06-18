# Goods on the Shelf [https://codeforces.com/contest/2233/problem/D]
- why solving in contest i stumbled upon too many cases on  WHAT ALL ARRANGMENTS CAN MAKE REQUIRED CONITNOUS SEGEMENT ARRAY. like bcbc , bcbcb bcbcbc,axa etc. getting too many cases , too complex code couldnt handle it.
- instead of that , try thinking the other way , WHAT WILL HAPPEN TO THE REQUIRED CONTINOUS SEGEMENT ARRAY ON APPLY THE SWAP OPERATION. this make the problem more staright forward and easy 


- observe atmost 3 segements can be made.
- note that swapped element must be furthest from the main body.
- now it can be in ...^||||^..^|||^... before swapping where || are main body elements and . are unlike elements and ^ are the    places it can be swapped in.
- now just use the furtherst 2 elements and swap them in these positions and check if it correct continous segement

>when trying to solve a question from one way and getting too many cases to accommodate (looking at possibilities / starting from one end) , instead of that try to solve question from the other end , like in this what will happen when all segments are continous (end case) and i performa  swap (operation)