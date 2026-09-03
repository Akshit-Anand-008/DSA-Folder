# 🕸️ Lab 03 — Brand New Day

[Ctrl + Shift + V to see the rendered version of this file]

## Background

During experimental cross-species genetic trials, a highly volatile radioactive arachnid sequence—made of the bases `A`, `C`, `G` and `T` has forcefully spliced itself into a human subject's chromosomes. This anomalous DNA inserts itself at random, sometimes multiple times or stacked within itself, causing unstable mutations. We're trying to inhibit the powers using a universal inhibitor and prevent a full-blown Man-Spider situation. The arachnid sequence was never part of the original human chromosome, so wherever it shows up, it's a post-bite mutation.

You are writing the firmware for a specialized medical nanobot injected directly into the subject's bloodstream. The nanobot must seek out and undo this rogue genetic contamination before it reports a clean sequence. 

## Problem Statement

You are given a contaminated DNA sequence of length `N`, represented as a singly linked list of `Node`s whose head pointer is `head`, and a contaminant string `pattern` of length `M`.

The given sequence was formed from an **original chromosome** by inserting the
complete sequence `pattern` one or more times at arbitrary positions. Several
insertions may have occurred, including consecutive insertions.

Recover the **original chromosome** by removing the inserted contaminant
sequences.

Removing a contaminant can cause two portions of the original chromosome to
become adjacent, potentially forming another occurrence of `pattern`. Such
occurrences are also part of the contamination and must be removed.

The original chromosome is guaranteed to be uniquely recoverable.


## Your Task

Write your code in `contaminant.cpp`, inside the body of `recover_original`:

```cpp
int recover_original(Node *&head, const string &pattern) {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
    ...
    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}
```
The function must:

- update `head` so it points to the first node of the recovered chromosome;
- `delete` every node removed as part of the contamination;
- preserve the relative order of every node that remains;
- return the number of nodes in the recovered chromosome;
- allocate no new `Node`s;

Do not delete or move the two marker comments, do not write anything outside
them, and do not change any other file. Everything this problem needs fits
inside the function body, so you do not need helper functions here.


## Directory Structure

```
contaminant.cpp   # write your solution here
contaminant.h     # declaration of recover_original (DO NOT MODIFY)
common.h          # the headers and Node struct you are allowed to use (DO NOT MODIFY)
main.cpp          # reads input, calls your function, prints the result (DO NOT MODIFY)
README.md         # this file (DO NOT MODIFY)
Makefile          # build automation
```

## Constraints

| Resource | Requirement |
|---|---|
| Time | `O(N * M)`|
| Auxiliary space | `O(N)` |
| `1 <= M <= N <= 10^7` | |
| Alphabet | `A`, `C`, `G`, `T` |
|M*N <= 10^8||

### Input and Output 

(Handled in main.cpp)

Input format:

```
Q
N_1
sequence_1
pattern_1
N_2
sequence_2
pattern_2
...
```

- `Q` is the number of independent test cases
- For each test case: the length `N`, then the `N` bases on their own line,
  then the contaminant string on the next line

The bases are read one at a time and linked into a list of `N` `Node`s;
that part is already written for you.

Output format: one line per test case, holding the recovered sequence with
no separators.

Example input:

```
2
8
ATGGACAT
GGA
8
ATATCCTA
ATC
```

Example output:

```
ATCAT
TA
```

### Assumptions
- every node's `base` and every character of `pattern` is one of the bases
  `A`, `C`, `G` and `T`
- `pattern` is guaranteed not to occur anywhere in the true, uncontaminated
  chromosome
- `pattern` is guaranteed to be non-self-overlapping, meaning no proper
  prefix of `pattern` is also a suffix of it

## Follow-up

Can you solve the same problem using only **`O(1)` auxiliary space**?# Make Commands

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
- Click on `Terminal` > `Run Task` > `Run all contaminant tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
