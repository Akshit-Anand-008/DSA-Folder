# Lab - 2-3-4 Tree

## Background

A 2-3-4 tree is a search tree in which every node has 2, 3 or 4 children. A
node with `d` children holds `d-1` keys in increasing order. Child `0` holds
the keys smaller than the first key, child `i` holds the keys between key `i`
and key `i+1`, and the last child holds the keys larger than the last key. All
leaves are at the same depth.

In the code, the empty leaves are not stored. A node is

```cpp
struct Node {
    vector<int> keys;       // in increasing order
    vector<Node*> children; // empty for a bottom-most node, else keys.size() + 1
};
```

Lecture 30 inserts a key `x` like this. Start at the root and go down, each
time into the child whose range contains `x`, until you reach a bottom-most
node. Put `x` into that node. To put a key `y` into a node `u`:

1. If `u` has 1 or 2 keys, add `y` to `u`.
2. If `u` has 3 keys `a < b < c`, split `u` into a node with `a` and a new node
   with `c`. Add `y` to the first node if `y < b`, and to the new node
   otherwise. Then put `b` into the parent of `u` the same way, with the two
   nodes as the children just left and just right of `b`. If `u` is the root,
   `b` goes into a new root.

Lecture 30 deletes a key `x` like this. If `x` is not in a bottom-most node,
replace it by its successor, the smallest key in the subtree of the child just
right of `x`, and delete the successor from its bottom-most node instead.
After a key is removed, a node may be left with no keys. Such a node is fixed
with the first rule that applies:

1. Its right sibling has 2 or more keys. Borrow a key from it through the
   parent.
2. Its left sibling has 2 or more keys. Borrow a key from it through the
   parent.
3. It has a right sibling. Merge the node, the parent key between them and
   the right sibling into one node.
4. Otherwise, merge the left sibling, the parent key between them and the
   node into one node.

A merge takes a key out of the parent, so the parent may now have no keys and
is fixed the same way. If the root is left with no keys, its child becomes
the new root.

The functions `insert` and `remove` in `234-tree.cpp` already do all of this.
They call three functions, `addKey`, `split` and `merge`, that you will
write.

## Your Task

Write your code in `234-tree.cpp`, inside the bodies of `addKey`, `split` and
`merge`. Do not delete or move the marker comments, do not write anything
outside them, and do not touch `insert`, `remove` or any other file or you will be `awarded 0 marks with no cribs`

## Directory Structure

```
234-tree.cpp             # write your solution here (insert and remove are given, don't touch them)
234-tree.h               # Node and the declarations (DO NOT MODIFY)
common.h                 # headers you are allowed to use (DO NOT MODIFY)
main.cpp                 # reads the input, calls insert and remove, prints the tree (DO NOT MODIFY)
README.md                # this file (DO NOT MODIFY)
Makefile                 # build automation
```

## Rules of the Problem

### Function Specification

#### `void addKey(Node* u, int key, Node* right)`

`u` has 1 or 2 keys, and `key` is not in `u`. Add `key` to `u->keys`, keeping
the keys in increasing order. If `right` is not `nullptr`, add it to
`u->children` as the child just right of `key`. If `right` is `nullptr`, do
not change `u->children`.

#### `Node* split(Node* u, int& up)`

`u` has 3 keys `a < b < c`. Leave `a` and the first two children of `u` in `u`.
Make a new node with `c` and the last two children of `u`, and return it. Set
`up` to `b`. If `u` is bottom-most, both nodes have no children.

#### `void merge(Node* p, int i)`

Children `i` and `i+1` of `p` hold one key in total: one of them has no keys
and the other has one key. Replace these two children and key `i` of `p` by
one node. Its keys are the keys of child `i`, then key `i` of `p`, then the
keys of child `i+1`. Its children are the children of child `i`, then the
children of child `i+1`. Remove key `i` from `p`, and free the node you do not
keep with `delete`.

### Input and Output

Input format:

```
T
n_1
keys to insert in case 1
m_1
keys to delete in case 1
n_2
...
```

- `T` is the number of independent test cases
- for each test case: `n`, then `n` keys on one line, then `m`, then `m` keys
  on one line (an empty line if `m` is `0`)

For each test case, `main.cpp` starts with an empty tree, inserts the `n` keys
one by one in the given order, deletes the `m` keys one by one in the given
order, and prints the tree on one line. The levels go from the root down and
are separated by ` | `. In each level the nodes go from left to right,
separated by a space. A node is printed as its keys inside square brackets. An
empty tree is printed as `EMPTY`.

Example input:

```
6
3
10 20 30
0

4
10 20 30 40
0

4
12 17 19 13
0

4
12 17 19 20
0

4
10 20 30 40
1
10
4
10 20 30 40
2
10 40
```

Example output:

```
[10 20 30]
[20] | [10] [30 40]
[17] | [12 13] [19]
[17] | [12] [19 20]
[30] | [20] [40]
[20 30]
```

In the third and fourth cases, the root `[12 17 19]` splits when the fourth key comes.
`17` moves up into a new root. `13` is smaller than `17`, so it goes into the
node of `12`. `20` is larger than `17`, so it goes into the node of `19`.

In the fifth case, deleting `10` leaves its node with no keys. Its right
sibling `[30 40]` has 2 keys, so rule 1 moves `20` down and `30` up. In the
last case, deleting `40` next leaves its node with no keys. It has no right
sibling and its left sibling `[20]` has one key, so rule 4 calls `merge` on
`[20]` and the empty node, which gives `[20 30]`. The root is now left with no
keys, so `[20 30]` becomes the root.

### Assumptions

- `1 <= T`, `1 <= n`, `0 <= m <= n`, and the sums of `n` and of `m` over all
  test cases are each at most `2*10^5`
- the keys inserted in a test case are all different, and every key is between
  `0` and `10^9`
- the keys deleted in a test case are all different, and each of them is one
  of the inserted keys
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
- Click on `Terminal` > `Run Task` > `Run all 234-tree tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
