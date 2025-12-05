# Day 4

I finished Day 4 of *Advent of Code 2025* using Java.

## Part 1

Given a 2D grid, the task is to count the number of "valid" positions in the grid. A position is considered valid if it is a paper ('@') and there is fewer than 4 surrounding papers in the adjacent 8 directions (horizontally, vertically, and diagonally).

My approach is simple. For each position in the grid, I check if it is a paper. If it is, I count the number of surrounding papers in the 8 directions. If the count is less than 4, I increment the valid position count. Finally, I print the total count of valid positions.

## Part 2

Given a 2D grid, the task is to repeatedly remove all "valid" positions (as defined in Part 1) until no more valid positions can be removed. The final result is the total number of positions removed.

The upperbound on the number of iterations is limited by initial number of papers. In each iteration, I update the grid by removing all valid positions. Finally, I check the final count of remaining papers after all possible removals and subtract it from the initial count to get the total number of removed positions.
