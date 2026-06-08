- easy way to iterate in bracket sequence is to take t=0, and t++ when '(' or when ')' t--;

- only way a bracket sequence becomes irregular is then at a particular point if ')' then there is no '(' in its left that is t<=0(if we traverse from left to right). or when at some point we have '(' and no ')' on right to accomodate it that is t>=0 (when we traverse from right to left.)