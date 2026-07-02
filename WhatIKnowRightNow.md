# GENERAL
> READ THE QUESTIONS PROPERLY
> ENSURE TO CHECK THE CONSTRAINTS
> SOMETIME U DONT HAVE TO FULLY PROVE THE SOLUTION / MAKE A SOLUTION FOR A QUESTION , JUST ENOUGH TO SATISFY U AND WORK WITH TESTCASES.
> in some questions instead of eyeballing and manually finding cases required suitable information . write a small code and output the cases and then go though it and make observation

> in some questions to see , contradiction / prove ur approach is correct / it is the best one / the algorithm u r using is correct => trying using some other algorithm / approach in some basic case and check
# Duck Surplus [https://codeforces.com/contest/2237/problem/C]
- in this correct method is swapping left to right only , i just couldnt prove it is best and spent to much time on it.
- to check if it is best take a simple basic case A>B>C -> A,B,C and instead of waht u r thinking , try some other way and try to conclude.
- ex(wrong)= A,B,C -> A,C,B+C -> C,A+C,B+C -> C,B+C,A+B+2*C
- ex(correct)= A,B,C -> A,A+B,C -> A,C,A+B+C -> C,A+C,A+B+C  [best] = observe if we use do op on right , instead of left, after the op on left , it will be always greater than right  so another op AND REPETITION ON LEFTMOST ELEMENT
- HENCE PROVED.




# NOTE THAT QUESTIONS ON EACH OF THESE ALGORITHMS USUALLY USE THE GENERAL WAY AND U DONT HAVE TO GO OUT OF UR WAY TO DO SOMETHING ETC. THAT IS JUST TRYING TO APPLY THE ALGORITHMS IN THE WAY U KNOW 
> LIKE IN DFS GO THOUGH THE CHILDREN AND STORE THE VALUES AND RETURN IF NEEDED AND DECIDE WHAT WHICH THING TO FURTHER RETURN AND SO ON. IN THE END IF U HAVE TO SORT U SORT 
> eg=> https://codeforces.com/gym/106185/problem/E here u need to go though the traversal and store the maximum time each node can have and then sort to see if it is possible.U DONT HAVE TO AFTER EACH RETURN SORT RETURN ARR (THE THING I WAS THINKING INITIALLY DURING CONTEST)

- linear search
- sorting 
- binary search
- greedy
- dp
- tree/graph = dfs-bfs
- tree/graph = djistkra
- tree/graph = bipartite graphs
- bitwise & | ^ !
- 2 pointers
- recursion
- combinatorics
- number thoery
- stack
- sets
- ordered set
- priority_queue
- sliding window
- segment tree


> graph/tree algorithms
- dfs
- bfs
- multisource bfs
- dijsktra
- graph to mst (best using dsu -> check if the given edge is required {only if 2 nodes r not connected}) = use Kruskal's Algorithm
- bipartite
- cycle detection
- topographic sort
- diameter
- lowest common ancestor    