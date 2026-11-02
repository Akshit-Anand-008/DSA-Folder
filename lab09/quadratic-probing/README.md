# Lab 08 - Hashing with Quadratic Probing

[Ctrl + Shift + V to see the rendered version of this file]

## Problem Statement

Implement a hash table using open addressing with quadratic probing. The table
stores distinct integer keys in a table whose capacity `M` is supplied as the first input integer. Commands insert,
delete, update, search for keys, and display the table.

The driver in `main.cpp` reads commands and calls your functions. Initialization,
hashing, update, and display are provided. You implement insertion, deletion,
and search.

## Your Task

Write your solution only inside the three marked function bodies in
`quadratic-probing.cpp`:

```cpp
void insertKey(HashTable &table, int key);
void deleteKey(HashTable &table, int key);
int searchKey(const HashTable &table, int key);
```

Each body contains these markers:

```cpp
// Your code starts from here -- DO NOT EDIT ANYTHING ABOVE

// Your code ends here -- DO NOT EDIT ANYTHING BELOW
```

Do not delete or move the markers. Do not write outside them or modify any other
file. Local variables and local lambdas inside the marked bodies are allowed.
You may call the provided `hashFunction(key, table.capacity)` helper. Once you
implement `searchKey(table, key)`, you may call it from insertion and deletion.
The provided helpers are implemented in `helpers.h`. The update function also
calls your search function.

## Directory Structure

```text
quadratic-probing.cpp   # implement the three marked functions
quadratic-probing.h     # student function declarations (DO NOT MODIFY)
helpers.h              # initialization, hashing, update, display (DO NOT MODIFY)
common.h               # capacity, slot states, and HashTable (DO NOT MODIFY)
main.cpp               # command driver (DO NOT MODIFY)
README.md              # this question (DO NOT MODIFY)
Makefile               # build and run tests (DO NOT MODIFY)
tests/
    test1/input.txt     # commands for the first test
    test1/output.txt    # expected output
    ...
    test20/input.txt
    test20/output.txt
```

## Rules of the Problem

### Hashing and probing

Use the provided `hashFunction(key, table.capacity)`, which normalizes the C++
remainder to an index in `[0, M-1]`, including for negative keys:

```text
h(key) = ((key % M) + M) % M
index(i) = (h(key) + i*i) % M, for i = 0, 1, ..., M-1
```

Do not use linear probing or resize the table. The sequence may revisit slots and
need not reach every index. For example, with `M = 11`, it reaches six distinct
indices for a given hash. Insertion can fail even
when other slots are empty. Do not stop merely because an index repeats; bound
each probe pass by `table.capacity` attempts.

### Table structure

```cpp
struct HashTable {
    int capacity = 0;
    std::vector<int> keys;
    std::vector<int> status;
};
```

The driver calls `initializeTable(table, M)` to allocate the vectors and mark
every slot empty. Capacity remains constant for that input file. Students must
use indexing into the provided vectors; do not resize them.

A slot is `EMPTY` (never occupied), `OCCUPIED` (contains a valid key), or `DELETED`
(previously occupied). Only `OCCUPIED` slots contain valid keys. Zero and negative
numbers are valid keys; do not use a key value as an empty-slot sentinel.

A search continues past `DELETED` and may stop at `EMPTY`.

### Function Specifications

#### `void insertKey(HashTable &table, int key)`

- If the key exists, print `Duplicate` and leave the table unchanged.
- Otherwise, insert at the first `EMPTY` or `DELETED` slot in probe order and
  print `Inserted`.
- A deleted slot may precede an existing copy: verify absence before inserting.
  Calling `searchKey` first is allowed.
- If all reachable slots are occupied, print `Insertion failed` and leave the
  table unchanged.

#### `void deleteKey(HashTable &table, int key)`

- If the key exists, mark its slot `DELETED` and print `Deleted`.
- Otherwise, print `Not found` and leave the table unchanged.
- Never turn a deleted slot into `EMPTY`. The unused key value may remain.

#### `int searchKey(const HashTable &table, int key)`

- Follow the key's quadratic probe sequence for at most `table.capacity` probes.
- Return the index if an `OCCUPIED` slot contains the key.
- Continue past `DELETED` slots; their stored key values are invalid.
- Return `-1` when an `EMPTY` slot is reached, or when all allowed probes have
  been tried without finding the key.
- Leave the table unchanged and print nothing. The driver prints the returned
  value for a `SEARCH` command.

### Provided Update Function

You do not implement or modify `updateKey`. Its behavior is specified below so
that you can understand the commands and tests. It uses your `searchKey` function.

#### `void updateKey(HashTable &table, int oldKey, int newKey)`

Apply these rules in order:

1. If `oldKey` does not exist, print `Not found` and change nothing.
2. If `oldKey == newKey`, print `Updated` and change nothing.
3. If `newKey` already exists, print `Duplicate` and change nothing.
4. Otherwise, replace `oldKey` by inserting `newKey` at the first available slot
   in its probe sequence, treating the old slot as `DELETED` during this operation.
   Mark the old slot `DELETED`, unless the new key occupies that same slot.
   Print `Updated`.
5. If replacement is impossible, print `Insertion failed`. Preserve the entire
   original table, including its slot states and keys.

The provided update function prints exactly one line per command.

### Constraints and Assumptions

- `1 <= M <= 46340`. Both prime and composite capacities are allowed.
- Use `(h + i * i) % table.capacity` with `0 <= i < M`.
  The capacity bound keeps both the square and the sum within signed 32-bit `int`.

- Keys are signed 32-bit integers: `-2147483648 <= key <= 2147483647`.
- Input contains valid commands and the required integer arguments.
- Each input file represents one initially empty table of the supplied capacity; commands run until `END`
  or end of input. There are at most `10000` commands per file.
- Time per insert, delete, update, or search: `O(M)`.
- Auxiliary space per operation: at most `O(M)`; the provided vectors allocate storage during initialization. Multiple bounded probe passes are allowed.
- `DISPLAY` takes `O(M)` time. No operation may change `table.capacity` or the vector sizes.

## Input and Output

The first line contains capacity `M`. The remaining input consists of
case-sensitive commands:

| Command | Output |
|---|---|
| `INSERT key` | `Inserted`, `Duplicate`, or `Insertion failed` |
| `DELETE key` | `Deleted` or `Not found` |
| `UPDATE oldKey newKey` | `Updated`, `Not found`, `Duplicate`, or `Insertion failed` |
| `SEARCH key` | key's index, or `-1` |
| `DISPLAY` | `M` lines, from index 0 through `M-1` |
| `END` | no output; stop processing |

Each operation prints exactly one line, except `DISPLAY` and `END`. Display
lines are exactly `index: EMPTY`, `index: DELETED`, or `index: key`, with one
space after the colon. Do not print prompts or extra messages.

### Example Input

```text
11
INSERT 10
INSERT 21
INSERT 32
SEARCH 32
DELETE 21
SEARCH 32
INSERT 43
UPDATE 32 50
SEARCH 50
SEARCH 32
DISPLAY
END
```

### Example Output

```text
Inserted
Inserted
Inserted
3
Deleted
3
Inserted
Updated
6
-1
0: 43
1: EMPTY
2: EMPTY
3: DELETED
4: EMPTY
5: EMPTY
6: 50
7: EMPTY
8: EMPTY
9: EMPTY
10: 10
```

### Explanation

Keys `10`, `21`, and `32` all hash to `10`. Their first available probe slots are
`10`, `0`, and `3`. Deleting `21` leaves slot `0` deleted, so searching for `32`
still reaches slot `3`. Inserting `43` reuses slot `0`. Updating `32` to `50`
marks slot `3` deleted and inserts `50` at its hash index `6`.

## Build and Test

```bash
make                 # build and run all 20 tests
make build           # build only
make runtests        # compare actual and expected output
make run             # read commands from standard input
./quadratic-probing tests/test1/input.txt
make clean           # remove build files
```

The incomplete starter is expected to fail tests. Each test starts a new process
with an empty table. Each process has a five-second time limit. The runner uses `timeout` or
`gtimeout` when available, otherwise Python 3 (included in the course setup).
The test runner reports failures through its exit status.
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
- Click on `Terminal` > `Run Task` > `Run all quadratic-probing tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
