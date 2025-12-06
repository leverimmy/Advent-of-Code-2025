# Day 6

I finished Day 6 of *Advent of Code 2025* using C++.

## Part 1

Given a list of operands and operators (+, *), evaluate the expressions and add the results together. Each problem's numbers are arranged vertically (that is to say, the digits of each number are in the same row); at the bottom of the problem is the symbol for the operation that needs to be performed. Problems are separated by a full column of only spaces. The left/right alignment of numbers within each problem can be ignored.

```
123 328  51 64 
 45 64  387 23 
  6 98  215 314
*   +   *   +  
```

Then the answer is `(123 * 45 * 6) + (328 + 64 + 98) + (51 * 387 * 215) + (64 + 23 + 314) = 4277556`.

My approach is to read the input line by line into a vector of strings. Then, iterate the index through the last line (which contains the operators). For each operator, iterate through the previous lines to get the corresponding number (if any) at that index. Perform the operation accordingly, and add the result to a running total.

## Part 2

Similar to Part 1, the numbers are arranged **horizontally** this time (that is to say, the digits of each number are in the same column). Then the answer for the example above would be `(1 * 24 * 356) + （369 + 248 + 8） + （32 * 581 * 175） + （623 + 431 + 4) = 3263827`.

My approach is similar to Part 1, but this time I parse the input numbers horizontally. Add up the results similarly.