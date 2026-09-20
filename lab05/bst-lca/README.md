# Lab - BST Lowest Common Ancestor (LCA)

## Problem Statement

You are given a Binary Search Tree (BST) and two integer values, `u` and `v`, which are guaranteed to exist within the tree. Your task is to find the **Lowest Common Ancestor (LCA)** of these two nodes.

The LCA of two nodes `u` and `v` in a tree is defined as the lowest node (deepest in the tree) that has both `u` and `v` as descendants (where we allow a node to be a descendant of itself).

You must implement **two** member functions of the `BST` class:

1. **`insert`** — inserts a value into the BST, maintaining the BST property.
2. **`findLCA`** — finds the LCA of two given values, exploiting the BST property.

---

## Rules of the Problem

### `insert`
- Must maintain the BST property: everything in a node's left subtree is smaller, everything in its right subtree is larger.
- Duplicate values (inserting a value already present in the tree) must be **ignored** — the tree should not change.
- Must be implemented **iteratively** (walk a pointer down from the root), not recursively.
- **Time Complexity:** `O(h)`, where `h` is the height of the tree.

### `findLCA`
- **BST Property Only:** You must leverage the ordering property of a Binary Search Tree to find the LCA. Do **not** compare left/right subtree membership generically — use value comparisons against the current node.
- **Single Downward Pass:** Start at the root and move strictly downward (left or right) until you find the split point. Do not backtrack, and do not recurse into both subtrees.
- **Time Complexity:** `O(h)`, where `h` is the height of the tree.
- **Space Constraints:** `O(1)` auxiliary space. Do **not** store paths, ancestors, or ancestor chains in arrays/vectors. Do **not** use the generic binary-tree LCA algorithm (the one that recurses into both children and checks return values) — that approach ignores BST ordering entirely and will not be accepted even if the output is correct.
- Recursive implementations are allowed **only** if they still represent a single downward path (i.e., exactly one recursive call per level, never two). An iterative `while` loop is the simplest way to guarantee this and is recommended.

### General
- Do not modify `main.cpp`, `common.h`, or the class/function signatures in `bst-lca.h`.

---

## Core Idea (BST-property exploitation)

At any node `curr` while descending:
- If **both** `u` and `v` are strictly less than `curr->val`, the LCA must lie in the **left** subtree — move left.
- If **both** `u` and `v` are strictly greater than `curr->val`, the LCA must lie in the **right** subtree — move right.
- Otherwise (one is ≤ `curr->val` and the other is ≥ `curr->val`, including the case where `curr->val` equals `u` or `v`), you have found the **split point** — `curr` is the LCA.

---

### Example

**Tree Structure:**
```text
        20
       /  \
     10    30
    /  \   /  \
   5   15 25  35
```

* `LCA(5, 15)` → **10** (Both are in the left subtree of 20, but split at 10)
* `LCA(5, 35)` → **20** (They split immediately at the root)
* `LCA(25, 35)` → **30** (Both are in the right subtree of 20, split at 30)

---

## Input Format

* The first line contains a single integer `n`, the number of nodes to insert into the BST.
* The second line contains `n` space-separated integers, representing the values to insert.
* The third line contains a single integer `q`, the number of LCA queries.
* The next `q` lines each contain two integers, `u` and `v`, representing the nodes for the query.

## Output Format

* For each query, output a single line:
  `LCA(u, v) = <value>`

---

## Your Task

You must write your implementation in the following file:

```text
bst-lca.cpp
```

Implement both `insert` and `findLCA`. Each function has its own marked area — please edit the code only between that function's `Your code starts from here` and `Your code ends here` comments. Do not edit anywhere else in this file. You must not edit `bst-lca.h`, `common.h`, or `main.cpp`.# Make Commands

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
- Click on `Terminal` > `Run Task` > `Run all bst-lca tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
