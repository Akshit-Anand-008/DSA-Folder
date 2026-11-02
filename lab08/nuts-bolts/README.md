# Lab - Nuts and Bolts

## Background

A box has `N` nuts and `N` bolts, all of different sizes. Each nut fits
exactly one bolt, the bolt of the same size. You cannot see the sizes. The
only thing you can do is try a nut on a bolt, and see whether the bolt is too
small, too large, or a perfect fit. You cannot compare two nuts with each
other, or two bolts with each other.

The nuts are numbered `0` to `N-1`, and so are the bolts. Trying nut `x` on bolt
`y` is the function call `tryFit(x, y)`.

Your job is to find the matching bolt for every nut, using as few tries as you
can. Trying every nut on every bolt takes about `N^2` tries, which is too many.

Reading the input, calling `matchNutsAndBolts`, and printing the result are
already done for you in `main.cpp`.

## Your Task

Write your code in `nuts-bolts.cpp`, inside the body of the function:

```cpp
void matchRange(vector<int> &nuts, vector<int> &bolts, int lo, int hi) {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
    ...
    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}
```

Do not delete or move the marker comments, do not write anything outside
them, and do not touch `matchNutsAndBolts` or any other file or you will be `awarded 0 marks with no cribs`

## Directory Structure

```
nuts-bolts.cpp           # write your solution here (matchNutsAndBolts is given, don't touch it)
nuts-bolts.h             # declarations (DO NOT MODIFY)
common.h                 # headers you are allowed to use (DO NOT MODIFY)
main.cpp                 # reads input, defines tryFit, calls matchNutsAndBolts, prints the result (DO NOT MODIFY)
README.md                # this file (DO NOT MODIFY)
Makefile                 # build automation
```

## Rules of the Problem

### Function Specification

#### `int tryFit(int nut, int bolt)`

Given to you in `main.cpp`. Returns `0` if the nut fits the bolt, `-1` if the
bolt is too small for the nut, and `1` if the bolt is too large for the nut.

#### `void matchRange(vector<int> &nuts, vector<int> &bolts, int lo, int hi)`

`nuts[lo..hi]` and `bolts[lo..hi]` hold nut and bolt numbers, and every nut in
`nuts[lo..hi]` has its matching bolt somewhere in `bolts[lo..hi]`. Rearrange
the two ranges so that `nuts[i]` fits `bolts[i]` for every `i` from `lo` to
`hi`. Do not change anything outside the two ranges.

`main.cpp` fills `nuts` and `bolts` with `0, 1, ..., N-1`. Then
`matchNutsAndBolts` calls `matchRange` on the whole range.

### Constraints

| Resource | Limit |
|---|---|
| Time | `O(N log N)` calls to `tryFit` on average, for any order of the nuts and bolts |

A solution that makes `O(N^2)` calls to `tryFit`, on some inputs or on all of
them, will time out on the large test cases.

### Input and Output

Input format:

```
T
N_1
nut sizes of case 1
bolt sizes of case 1
N_2
...
```

- `T` is the number of independent test cases
- for each test case: `N`, then the sizes of nuts `0` to `N-1` on one line, then
  the sizes of bolts `0` to `N-1` on one line

Your code never sees these sizes. `main.cpp` keeps them and uses them only
inside `tryFit`.

Output format: for each test case, one line with `N` numbers. The number at
position `x` is the bolt that fits nut `x`.

Example input:

```
1
3
30 10 20
20 30 10
```

Example output:

```
1 2 0
```

Nut `0` has size `30` and fits bolt `1`. Nut `1` has size `10` and fits bolt
`2`. Nut `2` has size `20` and fits bolt `0`.

### Assumptions

- `1 <= N <= 10^5` per test case
- the sum of `N` over all test cases in one input is at most `2*10^5`
- the nut sizes are all different, the bolt sizes are the same numbers in
  some order, and every size is between `1` and `10^9`
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
- Click on `Terminal` > `Run Task` > `Run all nuts-bolts tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
