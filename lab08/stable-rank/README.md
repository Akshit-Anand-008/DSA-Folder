# Lab - Stable Rank Array

## Background

You are given an array `A` of `N` integers, each in the range `[0, K]`
(`K` is small compared to `N`). For every element `A[i]`, define its
**rank** as the 1-indexed position it would occupy if `A` were sorted
into non-decreasing order **stably** -- i.e. among equal elements, the
one appearing earlier in `A` gets the smaller rank. Every value from `1`
to `N` appears exactly once across the rank array, since it is really
just "counting sort, but output where each element lands instead of
rearranging the values."

Your job is to fill in the two subroutines `stableRank` relies on:
`buildCumulativeCount`, which turns `A` into a cumulative count array
`C` where `C[v]` is the number of elements `<= v`, and `placeRanks`,
which uses `C` to hand each element its final position while keeping
the assignment stable.

Reading the input, calling `stableRank`, and printing the result are
already done for you in `main.cpp`.

## Your Task

Write your code in `stable-rank.cpp`, inside the body of the two functions:

```cpp
vector<int> buildCumulativeCount(const vector<int> &A, int K) {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
    ...
    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}

vector<int> placeRanks(const vector<int> &A, vector<int> C) {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
    ...
    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}
```

Do not delete or move the marker comments, do not write anything outside
them, and do not touch `stableRank` or any other file or you will be `awarded 0 marks with no cribs`

## Directory Structure

```
stable-rank.cpp     # write your solution here (stableRank is given, don't touch it)
stable-rank.h        # declarations (DO NOT MODIFY)
common.h             # headers you are allowed to use (DO NOT MODIFY)
main.cpp             # reads input, calls stableRank, prints the result (DO NOT MODIFY)
README.md            # this file (DO NOT MODIFY)
Makefile             # build automation
```

## Rules of the Problem

### Function Specification

#### `vector<int> buildCumulativeCount(const vector<int> &A, int K)`

Returns an array `C` of size `K + 1` such that `C[v]` equals the number
of elements of `A` whose value is `<= v`, for every `v` in `[0, K]`.
Build it by first counting how many times each value occurs (a
frequency array), then turning that into a running total (a prefix
sum) -- both in a single left-to-right pass each.

#### `vector<int> placeRanks(const vector<int> &A, vector<int> C)`

Given the original array `A` and the cumulative count array `C`
produced by `buildCumulativeCount`, returns the rank array `R` where
`R[i]` is the final, stable, 1-indexed position of `A[i]`. Do this by
scanning `A` from **right to left**: element `A[i]` claims position
`C[A[i]]`, and then `C[A[i]]` is decremented, so that the next (earlier)
occurrence of the same value claims the position just before it. This
right-to-left order is exactly what keeps ties broken in favor of the
element that appears earlier in `A`.

### Constraints

| Resource | Limit |
|---|---|
| Time | `stableRank` (and therefore `buildCumulativeCount` and `placeRanks`) must run in `O(N + K)` overall |
| Approach | You must not use `sort()`, `stable_sort()`, or any other comparison-based sorting function anywhere in your solution |
| Approach | You must not compare pairs of elements against each other to determine rank (no `O(N^2)` or `O(N log N)` comparison-based approach) |

A comparison-based sort, or a solution built around comparing every pair
of elements, will time out on the large test case even if the ranks it
produces are correct.

### Input and Output

Input format:

```
N K
A_1 A_2 ... A_N
```

- `N` is the size of the array (the line of values is empty if `N` is `0`)
- `K` is the maximum possible value in `A`

Output format: `N` integers `R_1 R_2 ... R_N`, space-separated on one
line, where `R_i` is the stable rank of `A_i`.

Example input:

```
5 9
4 1 4 2 4
```

Example output:

```
3 1 4 2 5
```

(Sorted stably, the elements land in order `A_2=1, A_4=2, A_1=4, A_3=4,
A_5=4`, claiming positions `1, 2, 3, 4, 5` respectively -- mapping those
positions back to the original indices gives `R = [3, 1, 4, 2, 5]`.)

### Assumptions

- `0 <= N <= 3*10^5`
- `0 <= A[i] <= K <= 10^5`
- every value from `1` to `N` appears exactly once in the output rank array
# Make Commands

```
make             # Build and Run Tests
make <problem>   # Build
make runtests    # Run Tests
make clean       # Clean Temporary Files
```
Please read Makefile to understand the above commands!

# VS Code interface

## Opening the Correct Folder in VS Code
You can open this folder in VS Code. The problem folder is configured to enable debugging. You must open the main problem folder, not a single file and not any subfolder inside it. The correct folder is the one that contains a folder named `.vscode`, another folder named `tests`, and your source code files. 

## Running the Program Using Debug Mode
- Click `Run and Debug` icon in the left sidebar > select the testcase from the `Launch` dropdown and click `Start Debugging` i.e. the green color play icon. 
- You can switch between different testcases i.e. (test 1), (test 2), etc. using this `Launch` dropdown.
- To run a testcase of your choice i.e. using your desired input, select `Launch ... (custom input)` from the `Launch` dropdown.
- After execution, the program output appears in the `Terminal` panel. Make sure you are viewing the `Terminal`, not the `Debug Console`.
- You may place breakpoints to pause the program at any desired location. To add a breakpoint, click on the left side of the code next to a line number. A red dot will appear. When you run the program, it will stop at that line so you can see how the program is executing step by step.

## Running all Testcases and view status
- Click on `Terminal` > `Run Task` > `Run all stable-rank tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

# Bodhitree - Upload your code (Only for exams)
- Ignore this for practice questions. You must upload your code only for the weekly lab evaluations or lab exams
- Login onto [robin.bodhi.cse.iitb.ac.in](robin.bodhi.cse.iitb.ac.in). Note that Internet is disabled. Type the URL manually
- Navigate to the CS101 course
    - Click `Labs`
    - Choose the desired lab
    - Click `Lab Activities` 
    - Click the program name for today
    - Paste your code in the box
    - Click `Submit`
- Once done, logout from Bodhitree
- That's all for today. See you in the next lab! :thumbsup:

# General Instructions

- Write your code only between the two markers i.e. the comment lines as shown below
    - `// Your code starts from here -- DO NOT EDIT ANYTHING ABOVE`
    - `// Your code ends here -- DO NOT EDIT ANYTHING BELOW`
- Do not delete or change these comment lines
- Do not write code above the first comment or below the second comment
- Read all `.h`, `.cpp` files, and complete problem statement carefully before starting.
- Do not include any additional header files.
- Understand the input and output format and follow it exactly. Do not print extra messages, prompts, or debugging output.
- Do not hardcode values based on sample test cases.
- Do not modify files other than the specified files. Any other changes will not be considered during evaluation.
- Use meaningful variables function names.
- You are expected to submit an efficient implementation. Inefficient solutions will lose marks.
- You may create helper functions and declare global variables within the file.
- We may call your function(s) with with different inputs to test its  correctness and efficiency in a single run. Therefore, ensure that any global state is properly reset between calls if necessary.
