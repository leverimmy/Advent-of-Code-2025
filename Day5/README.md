# Day 5

I finished Day 5 of *Advent of Code 2025* using Python.

## Part 1

Given a list of ranges of length $n$, and then a list of queries of length $m$, determine how many integers are covered by at least one range. Here $n = 190, m = 1000$.

I use an $O(n^2m)$ brute-force solution for Part 1, which is sufficient for the input size. For each query, I check each range to see if the query integer was covered by that range. Then I sum up the number of queries that are covered by at least one range.

## Part 2

Given a list of ranges of length $n$, determine the total number of integers covered by at least one range. Here $n = 190$.

I use an $O(n \log n)$ solution for Part 2. First, I sorted the ranges by their starting values (and by their ending values in case of ties). Then I use a sliding window approach to merge overlapping ranges and count the total number of unique integers covered by the ranges. For current range being processed, if it overlaps with the previous merged range, I extend the end of the merged range if necessary. If it does not overlap, I add the length of the previous merged range to the result and start a new merged range. Finally, I add the length of the last merged range to the result.
