# Lab 10 - The Undo Button

[Ctrl + Shift + V to see the rendered version of this file]

## Background (You can skip this if you want >:()

Long long ago in a temple so far,\
there was an old ascetic in his old fancy car.\
An eyepatch covered one eye, a scarred face full of grit,\
a master spy and spymaster, with secrets to fit.\
He'd led a secret agency from the shadows for years,\
recruiting Earth's mightiest heroes to face their worst fears.\
His neighbours were shapeshifters, green-skinned and sly,\
who wore other folks' faces and fooled every eye.

So the old spy kept a ledger of each disguise,\
tracking which beings were the same underneath their lies.\
Whenever two sightings revealed one creature in disguise,\
he fused their records together, to keep the truth alive.

But one fateful day, he made a terrible mistake:\
two different shapeshifters got merged for goodness' sake!\
The ledger couldn't reverse what he'd done,\
and rebuilding from scratch wasn't much fun.

So the eyepatched spymaster devised a clever endeavour:\
undo each recent fusion, one by one, in reverse order,\
until the last trusted entry was restored forever.

The fusing part of the ledger is already written.\
The part that finds which entry a shapeshifter belongs to,\
and the part that rolls back a fusion, are left for you.

Side Quest - Who do you think the old ascetic is?

## Problem Statement

You maintain a collection of `n` elements, numbered `0` to `n-1`, using a
**Union-Find (Disjoint Set Union) forest with union by size**. Initially every element is in a set of its own. You must
support these operations:

- `UNITE x y` - merge the set containing `x` with the set containing `y`.
  (If they are already in the same set, nothing is merged, but the call
  still counts as one `UNITE` for the purposes of `UNDO`.)
- `UNDO` - reverse the most recent `UNITE` that has not already been
  undone, restoring the forest to **exactly** the state it was in before
  that call: the same parent of every element, the same root of every set,
  the same set sizes. Calling `UNDO` repeatedly walks back further and
  further; there is no redo.
- `FIND x` - report the root of the set containing `x`.
- `SIZE x` - report the size of the set containing `x`.

**There is no path compression, and `find` may not change the forest in any
other way either.** A `find` only walks parent pointers up to the root.
(Path compression rewrites parents during `find`, which would make it
impossible to undo a `UNITE` by touching only the nodes that `UNITE`
changed.)

## Your Task

Most of the structure is provided (Ik easy lab it is). You implement exactly two functions in
`dsu.cpp`: `find` and `undo`. Everything else - including `unite`, which
already does union by size and records what it did on an undo stack - is
given to you and must not be changed.

```cpp
int RollbackDSU::find(int x) const {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
    ...
    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}

void RollbackDSU::undo() {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
    ...
    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}
```

Do not delete or move the marker comments, do not write anything outside
them, and do not change any other file.

## Directory Structure

```
dsu.cpp                         # write your solution here (find and undo)
dsu.h                           # class declaration and the Record struct (DO NOT MODIFY)
common.h                        # headers you are allowed to use (DO NOT MODIFY)
main.cpp                        # reads input, calls your functions, prints results (DO NOT MODIFY)
README.md                       # this file (DO NOT MODIFY)
Makefile                        # build automation
```

## Rules of the Problem

### How the forest is stored

The forest is a single `vector<int> A`:

- if `A[i] >= 0`, then `i` is not a root and its parent is `A[i]`;
- if `A[i] < 0`, then `i` is a root and its tree has `-A[i]` elements.

### What `unite` does (provided - read this, `undo` depends on it)

`unite(x, y)` finds the two roots `a` and `b`.

- If `a == b`, nothing is merged. It pushes `Record{a, a, 0}` (note
  `child == parent`) onto the stack `history` and returns `false`.
- Otherwise it makes `a` the root of the larger tree (ties keep `x`'s
  root), then pushes `Record{b, a, A[b]}` onto `history` - "`b` was attached
  under `a`, and `A[b]` was this value before" - and performs

  ```cpp
  A[a] += A[b];   // a's tree absorbs b's
  A[b] = a;       // b now points to a
  ```

  and returns `true`.

So every call to `unite` pushes **exactly one** `Record`, whether or not
anything was merged.

### Function Specification

#### `int RollbackDSU::find(int x) const`

Return the root of the set containing `x`. The method is `const`: it must
not modify the forest (the compiler will reject any attempt).

#### `void RollbackDSU::undo()`

Pop the most recent `Record` from `history` and reverse that `unite` call,
so that `A` is exactly as it was before it. If that `unite` merged nothing,
`A` must be left unchanged (the `Record` is still popped).

### Constraints

| Operation | Time |
|---|---|
| `find` | `O(log n)` |
| `undo` | `O(1)` |

### Input and Output

Input format:

```
T
n_1 q_1
<q_1 operations, one per line>
n_2 q_2
...
```

- `T` is the number of independent test cases; each starts with a fresh
  forest of `n` singletons.
- Each operation is one of `UNITE x y`, `UNDO`, `FIND x`, `SIZE x`.

Output: one line per `UNITE` (`1` if two different sets were merged, `0`
otherwise), one line per `FIND` (the root), and one line per `SIZE` (the
size). `UNDO` prints nothing.

Example input:

```
1
6 12
UNITE 0 1
UNITE 2 3
UNITE 0 2
SIZE 3
FIND 3
UNDO
SIZE 3
FIND 3
UNITE 1 0
UNDO
UNDO
SIZE 1
```

Example output:

```
1
1
1
4
0
2
2
0
2
```

Walkthrough: the first two `UNITE`s build `{0,1}` and `{2,3}` (roots `0` and
`2`). `UNITE 0 2` merges two trees of size 2; ties keep `x`'s root, so `2`
goes under `0`: `SIZE 3` is `4` and `FIND 3` is `0`. `UNDO` pops that merge,
so `2` is a root again: `SIZE 3` is `2`, `FIND 3` is `2`. `UNITE 1 0`
merges nothing (prints `0`) but still pushes a `Record`. The next `UNDO`
pops that no-op, the one after it pops `UNITE 2 3`, leaving `{0,1}`, so
`SIZE 1` is `2`.

### Assumptions

- `1 <= n <= 200000`, and the total number of operations across all test
  cases is at most `400000`
- `0 <= x, y < n`
- `UNDO` is never called when there is no `UNITE` left to undo

## Possible Extensions 

-  checkpoint()    : returns the current stack depth
-  rollback_to(cp) : undo until the stack is that deep# Make Commands

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
- Click on `Terminal` > `Run Task` > `Run all dsu tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
