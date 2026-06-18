# Bridge Renovation [https://codeforces.com/problemset/problem/2038/L]
- here we need to use minimum planks. 1 plank can be used to get 2 -25 lenght board.
- also now onbserve 1 plank can be used to bet 2- 21 lenght and 1- 18 lenght board.
- also 1 plank can be used to get 3- 18 lenght board.
- so for answer take (n/2){for 25 lenght} + (n/2){for 2 21 and 1 18 lenght} + ((n-(n/2))/3){(n/2) will be taken from 21 lenght boards and rest need separate boards}    => note in expression i am using floor division