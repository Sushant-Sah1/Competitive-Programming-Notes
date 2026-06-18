- easy way to iterate in bracket sequence is to take t=0, and t++ when '(' or when ')' t--;

- only way a bracket sequence becomes irregular is then at a particular point if ')' then there is no '(' in its left that is t<=0(if we traverse from left to right). or when at some point we have '(' and no ')' on right to accomodate it that is t>=0 (when we traverse from right to left.)


# Cost of a Bracket Sequence [https://codeforces.com/contest/2233/problem/C]
- CAN I CONSTRUCT RBS SUCH THAT INSIDE A GROUP OF RBS THERE IS NO NON RBS -> (()()():0000010 ->(())(|) (NON RBS INSIDE)-> NO RBS INSIDE THIS ;(()()():0000001 -> |()()()
    - note that non rbs will be inside if take previous ( that was furthest from the current )
    => YES BY USING STACK AND TAKING RECENT ( ENTRIES [from top of the stack] FOR EACH ).
=> NOTICE THAT WE GET => ))..[RBS]..))..[RBS]..)((((..[RBS]..(((..[RBS]..
    =>SO FOR ALL RBS BEFORE LAST NON RBS CLOSING BRACKET WE CAN TAKE OPENING BRACKETS IN RBS
            AND AFTER THAT ALL CLOSING BRACKETS IN RBS

>note if we have a bracket sequence and we pick elements to construct a rbs such that for every ) we pick the nearest previous ( , we can make  something like this = ))..[RBS]..))..[RBS]..)((((..[RBS]..(((..[RBS].. .AND NOTE THE THIS WILL ALWAYS HAPPEN AND TILL SOME PART WE WILL ALWAYS HAVE ) WHICH IS NON RBS AND AFTER THAT ( WHICH IS NON RBS .

>THIS HAPPENS BECAUSE IF THERE WERE A NON RBS SUCH THAT LEFT THERE IS ( AND RIGHT THERE IS ) , THEN THEY MAY AS WELL BE IN RBS