# Hashing with Robin Hood Probing

[Ctrl + Shift + V to see the rendered version of this file]

## Problem Statement

Implement insertion and deletion for a hash table that uses **Robin Hood
hashing** (Lecture 27): open addressing with linear probing, where keys are
reordered while probing so that no key ends up much further from its home slot
than the others. The table stores distinct integer keys in a table whose
capacity `M` is supplied as the first input integer. Commands insert, delete
and search for keys, and display the table.

The driver in `main.cpp` reads commands and calls your functions.
Initialization, hashing, the PSL helper, **search**, and display are provided.
You implement insertion and deletion.

## Your Task

Write your solution only inside the two marked function bodies in
`robin-hood-hashing.cpp`:

```cpp
void insertKey(HashTable &table, int key);
void deleteKey(HashTable &table, int key);
```

Each body contains these markers:

```cpp
// Your code starts from here -- DO NOT EDIT ANYTHING ABOVE

// Your code ends here -- DO NOT EDIT ANYTHING BELOW
```

Do not delete or move the markers. Do not write outside them or modify any other
file. Local variables and local lambdas inside the marked bodies are allowed.
You may call the provided helpers `hashFunction`, `psl` and `searchKey`, which
are implemented in `robin-hood-hashing.h`.

## Directory Structure

```text
robin-hood-hashing.cpp  # implement the two marked functions
robin-hood-hashing.h    # HashTable, your function declarations, and the provided
                        # helpers: hashing, psl, search, display (DO NOT MODIFY)
main.cpp                # command driver (DO NOT MODIFY)
README.md               # this question (DO NOT MODIFY)
tests/
    test1/input.txt     # commands for the first test
    test1/output.txt    # expected output
    ...
    test16/input.txt
    test16/output.txt
```

## Rules of the Problem

### Home slot and PSL

Every key has a **home slot** given by the provided `hashFunction`, which
normalizes the C++ remainder to `[0, M-1]`, including for negative keys:

```text
h(key) = ((key % M) + M) % M
```

Keys are placed by **linear probing** from the home slot, wrapping around from
`M-1` to `0`. The **probe-sequence length (PSL)** of a key stored at slot `i`
is its distance from home:

```text
PSL(i) = (i - h(key) + M) % M
```

A key at its home slot has PSL `0`. A key with a small PSL is "rich", and a key
with a large PSL is "poor". The provided `psl(table, i)` computes this for the
key in the occupied slot `i`.

### Table structure

```cpp
struct HashTable {
    int capacity = 0;
    int size = 0;                 // number of OCCUPIED slots
    std::vector<int> keys;
    std::vector<int> status;      // EMPTY or OCCUPIED
};
```

The driver calls `initializeTable(table, M)` to allocate the vectors, mark
every slot `EMPTY` and set `size` to `0`. Capacity remains constant for that
input file. Use indexing into the provided vectors; do not resize them.

There are only two slot states, `EMPTY` and `OCCUPIED`. **Robin Hood hashing
uses no tombstones**: deletion moves keys instead (see below). Only
`OCCUPIED` slots contain valid keys. Zero and negative numbers are valid keys;
do not use a key value as an empty-slot sentinel.

You must keep `table.size` equal to the number of `OCCUPIED` slots.

### Provided search

You do not implement or modify `searchKey`. It is described here because your
insertion and deletion must keep the table in a state where it works.

#### `int searchKey(const HashTable &table, int key)`

- Probe slots `h(key), h(key)+1, ...` (mod `M`), for at most `M` probes. At the
  `d`-th probe (`d = 0, 1, ...`) the key, if it were stored there, would have
  PSL `d`.
- Return the index if the slot holds `key`.
- Return `-1` at an `EMPTY` slot.
- Return `-1` as soon as the resident's PSL is **smaller than `d`**. The
  resident is richer than our key would be at that slot, and Robin Hood
  insertion would never have let our key pass a richer one, so the key is not
  stored.
- It never changes the table and prints nothing.

### Function Specifications

#### `void insertKey(HashTable &table, int key)`

Apply these rules in order:

1. If the key exists, print `Duplicate` and leave the table unchanged. Use
   `searchKey` for this check before you start moving keys.
2. Otherwise, if the table is full (`size == capacity`), print
   `Insertion failed` and leave the table unchanged.
3. Otherwise, start at the key's home slot, **holding** the key with a current
   PSL of `0`. At each slot:
   - If the slot is `EMPTY`, put the held key there, increase `size`, print
     `Inserted`, and stop.
   - If the resident's PSL is **strictly less** than the held key's current
     PSL, swap them: the held key takes the slot, and you now hold the evicted
     resident, whose current PSL is the PSL it had in that slot.
   - Move to the next slot (mod `M`). The held key's current PSL increases
     by 1.

Ties do **not** swap: if the resident's PSL equals the held key's PSL, keep
probing. The tests compare the exact layout of the table, so this matters.

#### `void deleteKey(HashTable &table, int key)`

1. If the key does not exist, print `Not found` and leave the table unchanged.
2. Otherwise, remove it with a **backward shift**. Starting from the deleted
   key's slot, look at the next slot (mod `M`):
   - If it is `EMPTY`, or holds a key at its home slot (PSL `0`), stop: mark
     the current slot `EMPTY`.
   - Otherwise move that key back one slot (its PSL drops by 1) and continue
     from the slot it came from.
3. Decrease `size` and print `Deleted`.

The backward shift keeps every remaining key reachable by `searchKey` without
tombstones.

### Constraints and Assumptions

- `1 <= M <= 10000`. Both prime and composite capacities are allowed.
- Keys are signed 32-bit integers: `-2147483648 <= key <= 2147483647`.
- Input contains valid commands and the required integer arguments.
- Each input file represents one initially empty table of the supplied
  capacity. Commands run until `END` or end of input. There are at most
  `10000` commands per file.
- Time per insert, delete or search: `O(M)`.
- Auxiliary space per operation: `O(1)`.
- No operation may change `table.capacity` or the vector sizes.

## Input and Output

The first line contains capacity `M`. The remaining input consists of
case-sensitive commands:

| Command | Output |
|---|---|
| `INSERT key` | `Inserted`, `Duplicate`, or `Insertion failed` |
| `DELETE key` | `Deleted` or `Not found` |
| `SEARCH key` | key's index, or `-1` |
| `SIZE` | number of stored keys |
| `DISPLAY` | `M` lines, from index 0 through `M-1` |
| `END` | no output; stop processing |

Each command prints exactly one line, except `DISPLAY` and `END`. Display lines
are exactly `index: EMPTY` or `index: key (psl)`, for example `2: 11 (1)`. Do
not print prompts or extra messages.

### Example Input

```text
10
INSERT 10
INSERT 20
INSERT 11
INSERT 30
SEARCH 11
SEARCH 40
DELETE 20
SEARCH 11
DISPLAY
END
```

### Example Output

```text
Inserted
Inserted
Inserted
Inserted
3
-1
Deleted
2
0: 10 (0)
1: 30 (1)
2: 11 (1)
3: EMPTY
4: EMPTY
5: EMPTY
6: EMPTY
7: EMPTY
8: EMPTY
9: EMPTY
```

### Explanation

Keys `10`, `20` and `30` have home slot `0`, and `11` has home slot `1`.

- `10` goes to slot `0` (PSL 0) and `20` to slot `1` (PSL 1).
- `11` starts at slot `1` with PSL 0. The resident `20` has PSL 1, which is not
  less than 0, so `11` moves on and takes the empty slot `2` with PSL 1.
- `30` starts at slot `0`. At slot `0` the resident `10` has PSL 0 and `30` has
  PSL 0: a tie, so no swap. At slot `1`, `20` has PSL 1 and `30` has PSL 1:
  again a tie. At slot `2`, `11` has PSL 1 but `30` would have PSL 2, so `11`
  is richer: `30` takes slot `2`, and we now hold `11` with PSL 1. At slot `3`
  it has PSL 2 and the slot is empty, so `11` goes there.
- `SEARCH 11` finds it at slot `3`.
- `SEARCH 40` starts at slot `0`. At slot `3` it would have PSL 3, but the
  resident `11` has PSL 2, which is smaller. So `40` cannot be stored, and the
  search returns `-1` without reaching the empty slot `4`.
- `DELETE 20` empties slot `1` by backward shift: `30` moves from slot `2` to
  `1` (PSL 2 → 1), `11` moves from slot `3` to `2` (PSL 2 → 1), and slot `4` is
  empty, so slot `3` becomes `EMPTY`.
- `SEARCH 11` now finds it at slot `2`.
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
- Click on `Terminal` > `Run Task` > `Run all robin-hood-hashing tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
