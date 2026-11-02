# Lab - The Duplicate and the Missing Number

## Background

An array `A` of `N` integers was supposed to hold every number from `1` to
`N` exactly once. By mistake, one number was overwritten with a copy of
another number. So now one number appears twice and one number does not
appear at all.

For example, `A = [4, 1, 5, 4, 3]` should have held `1 2 3 4 5`. The number
`4` appears twice and `2` is missing.

If the array had no mistake, number `k` could sit at index `k-1`, and every
index would be used exactly once. Call index `k-1` the home of `k`. With the
mistake, both copies of the duplicate have the same home, and the home of the
missing number has nobody to fill it.

Your job is to move every number to its home, inside `A` itself, and then
report the duplicate and the missing number.

Reading the input, calling `findDuplicateAndMissing`, checking the result, and
printing it are already done for you in `main.cpp`.

## Your Task

Write your code in `duplicate-missing.cpp`, inside the body of the function:

```cpp
void findDuplicateAndMissing(vector<int> &A, int &duplicate, int &missing) {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
    ...
    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}
```

Do not delete or move the marker comments, do not write anything outside
them, and do not touch any other file or you will be `awarded 0 marks with no cribs`

## Directory Structure

```
duplicate-missing.cpp    # write your solution here
duplicate-missing.h      # declarations (DO NOT MODIFY)
common.h                 # headers you are allowed to use (DO NOT MODIFY)
main.cpp                 # reads input, calls your function, checks and prints the result (DO NOT MODIFY)
README.md                # this file (DO NOT MODIFY)
Makefile                 # build automation
```

## Rules of the Problem

### Function Specification

#### `void findDuplicateAndMissing(vector<int> &A, int &duplicate, int &missing)`

Set `duplicate` to the number that appears twice and `missing` to the number
that does not appear.

When the function returns, `A` must be rearranged so that every number `k`
other than `missing` is at index `k-1`. The second copy of the duplicate goes
to the one index left over, which is `missing-1`.

For the example above, `A` must end up as `[1, 4, 3, 4, 5]`: numbers `1`, `3`,
`4` and `5` are at their homes, and the second `4` is at index `1`, the home of
the missing `2`. The function sets `duplicate = 4` and `missing = 2`.

### Constraints

| Resource | Limit |
|---|---|
| Time | `O(N)` for each call |
| Auxiliary space | `O(1)` extra space (besides `A` itself) |
| Approach | You must not use any extra array, vector, or other container, whatever its size |
| Approach | You must not use `sort()` or any other library function that rearranges `A` |

`main.cpp` checks each call. If your function allocates memory that grows with
`N`, it prints `EXTRA MEMORY USED`. If `A` is not in the arrangement described
above, it prints `WRONG ARRANGEMENT`. An `O(N^2)` solution will time out on the
large test cases, even if its answers are correct.

### Input and Output

Input format:

```
T
N_1
A_1
N_2
A_2
...
```

- `T` is the number of independent test cases
- for each test case: `N`, then the `N` integers of the array on one line

Output format: for each test case, one line holding the duplicate and the
missing number, separated by a single space.

Example input:

```
1
5
4 1 5 4 3
```

Example output:

```
4 2
```

### Assumptions

- `2 <= N <= 3*10^5` per test case
- the sum of `N` over all test cases in one input is at most `10^6`
- every input has exactly one duplicate and exactly one missing number, and
  every value is between `1` and `N`
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
- Click on `Terminal` > `Run Task` > `Run all duplicate-missing tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
