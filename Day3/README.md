# Day 3

I finished Day 3 of *Advent of Code 2025* using C++.

## Part 1

Given a list of strings representing numbers, each of them has a length of $n$. The task is to compute the sum of the maximum values that can be formed by selecting two different digits (can be the same value but different positions) from each string and concatenating them.

My approach involves maintaining the maximum value among the prefixes of the string and iterating through the string to find the best possible pairs. The solution has a time complexity of $O(n)$ for each string.

## Part 2

Given a list of strings representing numbers, each of them has a length of $n$. The task is to compute the sum of the maximum values that can be formed by selecting 12 different digits (can be the same value but different positions) from each string and concatenating them.

My approach involves using dynamic programming to keep track of the maximum values that can be formed with different lengths of selected digits. Denote $f(i, j)$ as the maximum value that can be formed by selecting $j$ digits from the first $i$ digits of the string, ending with the $i$-th digit. Then

$$
f(i, j) \gets \max_{k < i}\{10 \cdot f(k, j-1) + s_i\},
$$

where $s_i$ is the $i$-th digit of the string. The corner cases are $f(i, 1) \gets s_i$ for all $i$. 

Finally, the answer for each string is $\max_{i} f(i, 12)$. Summing these values for all strings gives the final result. The solution has a time complexity of $O(n^2)$ for each string.
