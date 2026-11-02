# Radix Tree

## Problem Statement

Given a set of strings, implement a Radix Tree to store and search strings efficiently using path compression.

You must implement the solution to support the following four operations:

1. **Insert Operation:** Insert a string into the Radix Tree. If the string already exists, do not insert a duplicate.
2. **Search Operation:** Search for a string in the Radix Tree and determine whether it is present as a complete stored string.
3. **Prefix Search Operation:** Check whether at least one stored string starts with a given prefix.
4. **Delete Operation:** Delete a string from the Radix Tree if it exists.

## Rules of the Problem

### Insertion

- Insert the given string into the Radix Tree.
- Each edge must be labelled with a non-empty string.
- Use path compression to avoid unnecessary single-child nodes.
- If the inserted string differs within an existing edge label, split the edge at the longest common prefix.
- Handle cases where one stored string is a prefix of another.
- Do not insert duplicate strings.

### Search

- Search for the exact string in the Radix Tree.
- Print `YES` if the string is present as a complete stored string.
- Print `NO` otherwise.
- Matching only a prefix of a stored string is not sufficient for a successful search.

### Prefix Search

- Check whether at least one stored string begins with the given prefix.
- Print `YES` if such a string exists and `NO` otherwise.
- The prefix may end at a node or in the middle of an edge label.

### Deletion

- Delete the exact string if it exists in the Radix Tree.
- Print `DELETED` if the deletion is successful.
- Print `NOT FOUND` if the string does not exist.
- After deletion, merge adjacent edge labels whenever a non-root node has only one child and does not represent a complete stored string.
- Ensure that other stored strings remain accessible after deletion.

### General

- Use a Radix Tree with path compression, not a standard Trie with one character per edge.
- Handle strings with common prefixes correctly.
- Handle duplicate insertions and deletion of non-existent strings.
- All operations must work correctly after any sequence of insertions and deletions.

---

## Examples

### Example 1

**Input:**

```text
8
I bear
I bell
I bid
S bell
S be
D bear
S bear
S bid
```

**Explanation:**

The strings `bear`, `bell`, and `bid` are inserted into the Radix Tree.

The search operation for `bell` returns `YES` because the string is present. The search operation for `be` returns `NO` because it is not stored as a complete string.

The deletion operation removes `bear` from the tree. A subsequent search for `bear` returns `NO`, while the search for `bid` returns `YES`.

**Output:**

```text
YES
NO
DELETED
NO
YES
```

---

### Example 2

**Input:**

```text
10
I apple
I application
I apply
S apple
S app
P app
D application
S application
S apply
S apple
```

**Explanation:**

The strings `apple`, `application`, and `apply` are inserted into the Radix Tree.

The search operation for `apple` returns `YES`. The search operation for `app` returns `NO` because it is not stored as a complete string.

The prefix search operation for `app` returns `YES` because the stored strings begin with `app`.

The deletion operation removes `application` from the tree. A subsequent search for `application` returns `NO`, while the searches for `apply` and `apple` return `YES`.

**Output:**

```text
YES
NO
YES
DELETED
NO
YES
YES
```

---

## Input Format

- **Line 1:** An integer `Q` denoting the number of operations.
- **Next Q lines:** Each line contains an operation and a string `X`, separated by a space.
- The operation is one of the following:
  - `I X`: Insert string `X`.
  - `S X`: Search for string `X`.
  - `P X`: Search for the prefix `X`.
  - `D X`: Delete string `X`.

## Output Format

Print the result of each search, prefix search, and delete operation on a separate line.

- **Search (`S`):** Print `YES` or `NO`.
- **Prefix Search (`P`):** Print `YES` or `NO`.
- **Delete (`D`):** Print `DELETED` or `NOT FOUND`.
- **Insert (`I`):** No output.

## Constraints

- `1 ≤ Q ≤ 10⁴`
- `1 ≤ |X| ≤ 100`
- All strings consist of lowercase English letters (`a`–`z`).

## Your Task

You must write your implementation in:

```text
radix-tree.cpp
```

Implement all four operations:

1. Insert a string using path compression and edge splitting where necessary.
2. Search for an exact stored string.
3. Search for a given prefix.
4. Delete a string and merge edges where necessary.

Ensure that the Radix Tree maintains its path-compressed structure after every insertion and deletion.

Write your code only between the markers in `radix-tree.cpp`:

```cpp
// Your code starts from here -- DO NOT EDIT ANYTHING ABOVE

// Your code ends here -- DO NOT EDIT ANYTHING BELOW
```

You may define your own node structure and helper functions inside the first
marked region at the top of the file. Do not delete or move the markers, and do
not modify any other file.

## Directory Structure

```text
radix-tree.cpp   # implement the four operations (YOUR TASK - edit only the marked sections)
radix-tree.h     # function declarations (DO NOT MODIFY)
common.h         # shared includes (DO NOT MODIFY)
main.cpp         # reads operations and calls your functions (DO NOT MODIFY)
README.md        # this file
Makefile         # build / run / runtests / clean
tests/
    test1/input.txt    # operations for the first test
    test1/output.txt   # expected output
    ...
    test10/input.txt
    test10/output.txt
```

## Build and Test

```bash
make             # build and run all 10 tests
make build       # build only
make runtests    # compare actual and expected output
make run         # read operations from standard input
./radix-tree tests/test1/input.txt
make clean       # remove build files
```

Each test has a one-second time limit.
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
- Click on `Terminal` > `Run Task` > `Run all radix-tree tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
