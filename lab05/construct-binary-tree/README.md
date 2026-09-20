# Lab05 - Construct a Binary Tree from Traversals

## Problem Statement

You are given the preorder and inorder traversals of a binary tree. Reconstruct
the tree and return its postorder traversal.

The tree contains distinct values, and both input arrays describe the same
tree. These conditions guarantee that the tree is unique.

Recall the three depth-first traversal orders:

- Preorder: root, left subtree, right subtree
- Inorder: left subtree, root, right subtree
- Postorder: left subtree, right subtree, root

You must implement both of the following functions:

- `buildTree(preorder, inorder)` reconstructs the tree and returns its root.
- `postorderTraversal(root)` returns the values of the reconstructed tree in
  postorder.

The driver verifies that the tree returned by `buildTree` has exactly the
given preorder and inorder traversals. It prints `invalid` if the constructed
tree does not match them. Otherwise, it prints the result returned by
`postorderTraversal`.

## Constraints

- `1 <= Q <= 10` (number of test cases)
- `1 <= n <= 3000`
- `-10^9 <= preorder[i], inorder[i] <= 10^9`
- All values in each traversal are distinct.
- `preorder` and `inorder` contain the same values.
- The two traversals describe one valid binary tree.

## Limits

| Function | Time | Auxiliary space |
|---|---|---|
| `buildTree` | `O(n)` | `O(n)` |
| `postorderTraversal` | `O(n)` | `O(n)` |

The auxiliary-space limits include the returned data structures and the
recursion stack. A solution that searches the entire inorder array during
every recursive call can take `O(n^2)` time and does not meet the required
limit.

## Input Format

- Line 1: `Q`
- For each test case:
  - A line containing `n`, the number of nodes
  - A line containing `n` space-separated values in preorder
  - A line containing `n` space-separated values in inorder

## Output Format

For each test case, print the postorder traversal on its own line. Values must
be separated by one space.

If the tree returned by `buildTree` does not have the given preorder and
inorder traversals, the provided driver prints `invalid` for that test case.

### Example

#### Sample Input

```text
2
5
3 9 20 15 7
9 3 15 20 7
3
2 1 3
1 2 3
```

#### Sample Output

```text
9 15 7 20 3
1 3 2
```

#### Explanation

The first pair of traversals represents this tree:

```text
    3
   / \
  9   20
     /  \
    15   7
```

Its postorder traversal visits `9`, then `15 7 20`, and finally the root `3`.

For the second test case, `2` is the root, `1` is its left child, and `3` is
its right child. Its postorder traversal is `1 3 2`.

## Hints

Read these only if you are stuck.

1. The first unused value in preorder is the root of the current subtree.
2. Find that root in inorder. Everything to its left belongs to the left
   subtree, and everything to its right belongs to the right subtree.
3. Store every inorder value and its index in an `unordered_map` before the
   recursion starts. This avoids repeatedly searching the inorder array.
4. Build the left subtree before the right subtree because preorder lists the
   entire left subtree first.
5. In a postorder traversal, append a node's value only after visiting both of
   its children.

## Your Task

You must write your implementation in the following file:

```text
construct-binary-tree.cpp
```

Implement `buildTree` and `postorderTraversal`. Please edit code only in the
marked areas (between `Your code starts from here` and `Your code ends here`)
and do not edit anywhere else. You must not edit `construct-binary-tree.h`,
`common.h`, or `main.cpp`.

Every node created by `buildTree` must use `new TreeNode(value)`. The provided
driver deletes the constructed tree after checking and printing it.

## Directory Structure

```text
construct-binary-tree.cpp   # implement your two functions here
construct-binary-tree.h     # TreeNode and function declarations (DO NOT MODIFY)
common.h                    # shared includes (DO NOT MODIFY)
main.cpp                    # reads, checks, and prints results (DO NOT MODIFY)
README.md                   # this file (DO NOT MODIFY)
Makefile                    # build automation
```
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
- Click on `Terminal` > `Run Task` > `Run all construct-binary-tree tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
