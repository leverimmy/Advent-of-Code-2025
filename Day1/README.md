# Day 1

I finished Day 1 of *Advent of Code 2025* using C.

## Part 1

Given a cyclic track with positions numbered from 0 to 99, starting at position 50, you receive a series of movement instructions of length $n$. Each instruction consists of a direction ('L' for left or 'R' for right) followed by a number indicating how many positions to move. The track wraps around, so moving left from position 0 takes you to position 99, and moving right from position 99 takes you to position 0. Count the number of times where you landed exactly on position 0 after executing a movement instruction.

I perform an $O(n)$ simulation of the movements, updating the current position and checking if it equals 0 after each move.

## Part 2

Given the same cyclic track and movement instructions as in Part 1, count the total number of times you cross position 0 while executing the movement instructions. Crossing position 0 means moving from a position greater than 0 to a position less than or equal to 0 when moving left, or from a position less than 99 to a position greater than or equal to 99 when moving right. Note that rotating multiple times in a single instruction counts as multiple crossings.

To solve this, I again perform an $O(n)$ simulation of the movements. For each instruction, I calculate how many times position 0 was crossed based on the current position and the number of steps moved in the given direction. **The corner cases are handled smoothly by using integer division and modulo operations.**
