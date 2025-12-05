# Day 2

I finished Day 2 of *Advent of Code 2025* using Rust.

## Part 1

Denote a number as *invalid* if it can be treated as `<num><num>` where `<num>` is a number and `<num>` is the same number. For example, `123123` is invalid because it can be treated as `123` and `123`, while `1234` is valid. Given a list of ranges in the format `start-end`, answer the sum of all invalid numbers within each range (inclusive).

I enumerate all numbers in each range and checked if they are invalid by converting them to strings and splitting them in half. If both halves are equal, the number is invalid and added to the sum.

## Part 2

Denote a number as *invalid* if it canbe treated as `<num>...<num>` where `<num>` is a number and it is **repeated two or more times**. For example, `121212` is invalid  because it can be treated as `12` repeated three times, while `1231234` is valid. Given a list of ranges in the format `start-end`, answer the sum of all invalid numbers within each range (inclusive).

I enumerate all numbers in each range and checked if they are invalid by converting them to strings and checking for all possible lengths of `<num>`. If the length of the number is divisible by the length of `<num>` and repeating `<num>` the required number of times gives back the original number, then it is invalid and added to the sum.
