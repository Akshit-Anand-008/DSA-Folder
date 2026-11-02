# For All Time. Always.

[Ctrl + Shift + V to see the rendered version of this file]

## Background (You can skip this if you want >:()

Loki finally had the binary tree running.

Then Doom finally realised it wasn't a nice idea to assume Loki is a noob.
He has returned with even more force.

Nobody is entirely sure how. One second the registry tree stood there in
its usual shape; the next, the whole vault convulsed and the tree came
down, case files scattering off the shelves and across the floor in
whatever order they happened to land in. No structure left. No branches.
Just a bare line of loose case numbers and a very large problem standing
in the doorway.

Miss Minutes doesn't want the whole tree rebuilt as there's no time for
that now, and honestly no vault left to rebuild it in. Every request she
sends down comes tagged with a `type`, and each type wants a different
pair of facts, but the situation underneath is always the same: hold two
sealed case files up next to each other and Doom's presence degrades them
a little more, and there's a hard, exact limit on how many times this
vault survives that before the files stop being readable at all.

- **Type 1** wants the number of the very **first** timeline this vault
  ever opened a case on, and the number of the **latest** one - the
  smallest and largest case numbers.
- **Type 2** is the request that's actually keeping Loki up at night: not
  the latest timeline, but whichever one opened **immediately after the
  very first** - the smallest and the *second*-smallest case numbers.
  Everything else on the floor can stay lost.


## Problem Statement

You are given `N` distinct integer case numbers, scattered with no
structure, and told which of two things to find:

- **Type 1:** the smallest and the largest.
- **Type 2:** the smallest and the second-smallest.

You are not given the numbers directly - you're given `N` sealed case
files, each wrapping one integer. You cannot read the integer inside a
sealed file. The only operation available to you is holding two sealed
files up against each other, which tells you which one is smaller and
every single time you do this, it counts against a hard total budget,
**different for each type**.

Reading the input, sealing the case numbers, dispatching to the right
function based on the type, and printing the result are already done for
you in `main.cpp`. You write `find_first_and_last` for Type 1 and
`find_smallest_and_second_smallest` for Type 2.

## Your Task

Write your code in `triage.cpp`, inside the body of both functions:

```cpp
pair<SealedCase, SealedCase> find_first_and_last(vector<SealedCase> &cases) {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
    
    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}

pair<SealedCase, SealedCase> find_smallest_and_second_smallest(vector<SealedCase> &cases) {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
    
    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}
```

Do not delete or move the marker comments, do not write anything outside
them, and do not change any other file.

## Directory Structure

```
triage.cpp              # write your solution here
triage.h                 # declarations of both functions (DO NOT MODIFY)
common.h                 # the SealedCase struct you are allowed to use (DO NOT MODIFY)
main.cpp                 # reads input, dispatches by type, prints the result (DO NOT MODIFY)
README.md                # this file (DO NOT MODIFY)
Makefile                 # build automation
generate_testcases.py    # regenerates tests/ from an independent reference implementation
```

## Rules of the Problem

### The `SealedCase` type

```cpp
struct SealedCase {
    bool operator<(const SealedCase &other) const;   // the only thing you can do with one
    static long long comparisons;                     // total operator< calls so far
};
```

There is no way to read the integer inside a `SealedCase`, and no
`operator==`. `operator<` is the only tool you have, and it is being
counted - every call increments `SealedCase::comparisons`, and the
harness checks the total against a hard limit (specific to whichever
type was requested) after your function returns.

### Function Specification

#### Type 1 - `pair<SealedCase, SealedCase> find_first_and_last(vector<SealedCase> &cases)`

Returns `{earliest, latest}`: the `SealedCase` holding the smallest value
in `cases`, and the one holding the largest.

#### Type 2 - `pair<SealedCase, SealedCase> find_smallest_and_second_smallest(vector<SealedCase> &cases)`

Returns `{smallest, second_smallest}`: the `SealedCase` holding the
smallest value in `cases`, and the one holding the second-smallest.
`cases` has at least 2 elements whenever this function is called.

### Constraints

| Type | Comparisons allowed | Auxiliary space |
|---|---|---|
| 1 (min & max) | at most `ceil(3N/2) - 2`, exactly | `O(1)` extra |
| 2 (min & 2nd-min) | at most `N + ceil(log2(N)) - 2`, exactly | `O(N)` extra |

Think of how to reuse information. You are allowed a `TOLERANCE` value of 10 for type 2,
so if you have some solution that is asymptotically close to optimal, 
just off by a few constants, that will still pass this task. 

### Input and Output

Input format:

```
T
type_1 N_1
case_numbers_1
type_2 N_2
case_numbers_2
...
```

- `T` is the number of independent test cases
- For each test case: `type` (`1` or `2`) and `N` on one line, then the
  `N` case numbers on the next line

Output format: for each test case, one line with two integers separated
by a space. For `type 1`: the smallest case number, then the largest. For
`type 2`: the smallest case number, then the second-smallest.

Example input:

```
2
1 6
10 -3 7 0 8 2
2 6
10 -3 7 0 8 2
```

Example output:

```
-3 10
-3 0
```

(Same six case numbers both times -- Type 1 wants the extremes (`-3` and
`10`); Type 2 wants the two smallest (`-3` and `0`).)

### Assumptions

- `1 <= N <= 2*10^5` for type 1; `2 <= N <= 2*10^5` for type 2
- all `N` values in one test case are distinct and fit in a 32-bit signed
  integer
- for type 1 with `N = 1`, the single case is both the earliest and the
  latest, and the allowed comparison budget is exactly `0`
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
- Click on `Terminal` > `Run Task` > `Run all triage tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
