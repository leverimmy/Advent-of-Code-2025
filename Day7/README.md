# Day 7

I finished Day 7 of *Advent of Code 2025* using C.

## Part 1

Given a grid representing beams and splitters, simulate the beam propagation and count the number of times that a beam splits.

My approach is simple. I read the grid into a 2D array, then iterate through each cell. If I encounter a beam (`|`), I check the cell below it. If it's a splitter (`^`), I increment the result counter and propagate the beam to both sides. If it's empty or another beam, I simply propagate the beam downwards. The time complexity is $O(nm)$, where $n$ and $m$ are the dimensions of the grid.

## Part 2

Similar to Part 1, but instead of counting splits, I need to count the number of distinct paths the beam can take to reach the bottom of the grid. I use a dynamic programming approach where `dp[i][j]` represents the number of ways to reach cell `(i, j)`. I initialize `dp[0][j]` to 1 for the starting point `S`. As the beam propagates, I update the `dp` array based on the rules of beam propagation. The final answer is the sum of all `dp` values in the last row of the grid. The time complexity remains $O(nm)$.

