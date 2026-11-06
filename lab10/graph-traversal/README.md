# Lab - Graph Traversal with a Stack and a Queue

## Background

Lecture should have given a generic template for traversing a graph using any container
that supports `push` and `extract`:

```
push(start)
while the container is not empty:
    u = extract()
    if u is already visited: continue
    mark u visited
    for each neighbor v of u:
        push(v)
```

A node can be pushed more than once (once for every edge that discovers it,
before it is marked visited), but it is marked visited, and processed,
exactly once: the first time it is extracted while still unvisited. Every
later extraction of the same node is discarded.

The order in which nodes come out of this loop depends only on which
container `push`/`extract` use. A **stack** (`push` = push to the back,
`extract` = pop from the back) gives one order. A **queue** (`push` = push to
the back, `extract` = pop from the front) gives a different order.

## Your Task

Write your code in `graph-traversal.cpp`, inside the bodies of
`traverseStack` and `traverseQueue`. Do not touch any other file.

Both functions take a graph given as an adjacency list `adj` (undirected,
`adj[u]` lists the neighbors of `u` in the order their edges were given) and
a starting vertex `start`. Run the generic template above, using a stack in
`traverseStack` and a queue in `traverseQueue`. Append every node to `pushed`
at the moment it is pushed (so `pushed` can contain repeats), and append
every node to `visited` at the moment it is marked visited (so `visited`
contains each reachable node exactly once, in the order it was first
visited).

## Directory Structure

```
graph-traversal.cpp      # write your solution here
graph-traversal.h        # declarations (DO NOT MODIFY)
common.h                 # headers you are allowed to use (DO NOT MODIFY)
main.cpp                 # reads the input, calls both functions, prints the output (DO NOT MODIFY)
README.md                # this file (DO NOT MODIFY)
Makefile                 # build automation
```

## Rules of the Problem

### Function Specification

#### `void traverseStack(const vector<vector<int>>& adj, int start, vector<int>& pushed, vector<int>& visited)`

Run the generic template with a stack as the container: `push` adds to the
back, `extract` removes from the back. Start by pushing `start`. Append to
`pushed` every node exactly when it is pushed, and to `visited` every node
exactly when it is marked visited.

#### `void traverseQueue(const vector<vector<int>>& adj, int start, vector<int>& pushed, vector<int>& visited)`

Same template, but with a queue as the container: `push` adds to the back,
`extract` removes from the front.

### Input and Output

Input format:

```
T
n_1 m_1 start_1
m_1 edges of case 1, one "u v" per line
n_2 m_2 start_2
...
```

- `T` is the number of independent test cases
- for each test case: `n`, `m` and `start` on one line, then `m` lines each
  with one undirected edge `u v`

For each test case, `main.cpp` builds the adjacency list from the `m` edges
in the order given, calls `traverseStack` then `traverseQueue` starting from
`start`, and prints 4 lines: the stack's `pushed`, the stack's `visited`,
the queue's `pushed`, the queue's `visited`, each as space-separated vertex
numbers.

Example input:

```
1
5 5 0
0 1
0 2
1 3
2 3
3 4
```

Example output:

```
0 1 2 0 3 1 2 4 3 0 3
0 2 3 4 1
0 1 2 0 3 0 3 1 2 4 3
0 1 2 3 4
```

The graph has a 4-cycle `0-1-3-2-0` plus an extra vertex `4` hanging off `3`.
With the stack, vertex `2` is pushed by `0`, sits on top, and is popped
next, so the traversal dives first into `2`'s side of the cycle before ever
reaching `1` — the stack's `visited` order is `0 2 3 4 1`. With the queue,
vertices are visited in order of distance from `0`: `0`, then `1` and `2`
(distance 1), then `3` (distance 2), then `4` (distance 3) — the queue's
`visited` order is `0 1 2 3 4`, the BFS order. Both `pushed` lists contain
repeats, since `0`, `2` and `3` are each discovered more than once before
being marked visited.

### Assumptions

- `1 <= T`, and the sums of `n` and of `m` over all test cases are each at
  most `2*10^5`
- `0 <= start < n`, and every vertex from `0` to `n-1` is numbered, but the
  graph need not be connected and `start` need not reach every vertex
- the graph has no self-loops, but may have multiple edges between the same
  pair of vertices and may contain cycles
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
- Click on `Terminal` > `Run Task` > `Run all graph-traversal tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
