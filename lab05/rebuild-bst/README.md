# Lab 5 - Doom at the Loom

[Ctrl + Shift + V to see the rendered version of this file]

## Background (You can skip this if you want >:()

After learning how a Binary Search Tree works in Lab 3, Loki realized the Sacred Timeline wasn't how things were meant to be. He and Sylvie uncovered the "real" timekeeper by breaching the Citadel at the End of Time, where they slew "He Who Remains." 

Loki then rearranged the timelines into a BST, aka Yggdrasil. Sitting on his throne at the End of Time, he has been keeping the multiverse alive with his bare hands. 

But Victor Von Doom came to know of his plan. 

Breaching the Citadel, Doom unleashed a devastating blast of dark magic that struck the temporal core and entirely shattered the World Tree. The physical branches of the multiverse instantly began to unravel, turning black and withering away into nothingness. 

Standing amidst the wreckage of reality, Doom looked down at the fallen God. "Is this it?" Doom mocked, his metal mask gleaming in the dying light of the timelines. "What can a mere God of Mischief do now? Nothing." Thinking the multiverse was permanently broken and his victory assured, Dr. Doom turned his back and left the TVA to go fight the Avengers on Earth.

But Doom made a critical mistake. He didn't know Loki had a backup. 

Clutched in Loki's hand is a crumpled, miles-long TVA printout—a pruning log he kept detailing the exact structure of Yggdrasil before it fell. Because of how the timelines were grown, the log recorded the branches in a perfect **postorder traversal**—left sub-branches, right sub-branches, and finally the central trunks.

Loki is desperately short on time. The unraveled timelines are dying fast, and Doom will inevitably return once he realizes reality hasn't completely collapsed. Help Loki rebuild Yggdrasil from this printout before Doom arrives again!

## Problem Statement

You are given a sequence of `N` distinct integers that is guaranteed to be
the postorder traversal of *some* binary search tree. Reconstruct that BST.
Because it came from a BST, its shape is uniquely determined by the
sequence. (Lecture 14).

Reading the input, calling your reconstruction function, printing the
result as a level-order traversal, and freeing the tree are already done
for you in `main.cpp`. You write `build_bst_from_postorder`.

## Your Task

Write your code in `rebuild_bst.cpp`, inside the body of the function:

```cpp
Node *build_bst_from_postorder(const vector<int> &postorder) {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
    ...
    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}
```

Do not delete or move the marker comments, do not write anything outside
them, and do not change any other file.

## Directory Structure

```
rebuild_bst.cpp                 # write your solution here
rebuild_bst.h                   # declaration of build_bst_from_postorder (DO NOT MODIFY)
common.h                # the headers and Node struct you are allowed to use (DO NOT MODIFY)
main.cpp                # reads input, calls your function, prints the result (DO NOT MODIFY)
README.md               # this file (DO NOT MODIFY)
Makefile                # build automation
```

## Rules of the Problem

### Function Specification

#### `Node *build_bst_from_postorder(const vector<int> &postorder)`

Given `postorder`, the postorder traversal of some BST with all-distinct
keys, builds and returns the root of that tree.

### Constraints

| Resource | Limit |
|---|---|
| Time | `O(N)` |
| Auxiliary space | `O(N)` (besides the `N` nodes of the output tree itself) |

Recursive solution may fail some testcase, try to write an interative solution.

### Input and Output

Input format:

```
T
N_1
postorder_1
N_2
postorder_2
...
```

- `T` is the number of independent test cases
- For each test case: `N`, then the `N` integers of the postorder sequence
  on one line

Output format: for each test case, one line holding the **level-order**
traversal (breadth-first, left to right within each level) of the
reconstructed tree, values separated by single spaces.

Example input:

```
1
7
20 40 30 60 80 70 50
```

Example output:

```
50 30 70 20 40 60 80
```

Walkthrough: `50` is the root (it's last in a postorder). Everything before
the first value greater than `50` belongs to its left subtree: `20, 40, 30`
(all `< 50`); everything from there up to (but not including) the root
belongs to its right subtree: `60, 80, 70` (all `> 50`). Recursing the same
way on each side gives:

```
          50
        /    \
      30      70
     /  \    /  \
   20   40  60   80
```

### Assumptions

- `1 <= N <= 10*6` per test case (sum across all test cases fits
  comfortably within the time limit *for an `O(N)` solution*)
- all `N` values in one test case are distinct and fit in a 32-bit signed
  integer
- `postorder` is always guaranteed to actually be the postorder traversal
  of some valid BST
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
- Click on `Terminal` > `Run Task` > `Run all rebuild-bst tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
