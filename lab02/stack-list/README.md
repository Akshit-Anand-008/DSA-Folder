# Lab03 - De-Amortized Stack List

## Problem Statement

Implement a modified **Stack List**. A standard Stack List is a hybrid data structure that implements a stack using a linked list, but instead of each node holding a single element, each node contains a fixed-size array (a "block"). This combines the cache locality and low memory overhead of arrays with the dynamic, infinite-growth capabilities of a linked list. 

In this lab, we will use a **de-amortized** version. To avoid the expensive overhead of allocating and deallocating blocks repeatedly when pushes and pops strictly alternate at a block boundary, we will implement a delayed-deletion rule. 

You must implement the `push` and `pop` member functions of the `stackList` class.

---

## **Rules of the Problem**

- **Pushing:** Add a new block on top when the current top block is full (like a standard block-stack). 
- **Popping:** Do **not** delete the top block when it turns empty. Instead, allow it to remain as the `head`. 
- **Deletion:** Delete the top block *only* when the block **below** it becomes empty. This ensures we keep a maximum of one empty block on top to absorb alternating push/pop operations.
- **Top Location:** Because we keep an empty block around, allow for the possibility that the `head` block is empty, and the actual "top" element is in the block below it (`head->below`).
- Do not modify `main.cpp`, `common.h`, or the class/function signatures in `stack-list.h`.

---

### Example Trace (Block Size = 3)
*Note: The left-most block represents the `head` node.*

- `PUSH A` -> Blocks: `[A]` 
- `PUSH B`, `PUSH C` -> Blocks: `[A, B, C]` *(head is now full)*
- `PUSH D` -> Blocks: `[D]` `[A, B, C]` *(new block added, head has 1 item, below has 3)*
- `POP` (Pops D) -> Blocks: `[]` `[A, B, C]` *(**Top block is empty but NOT deleted**)*
- `POP` (Pops C) -> Blocks: `[]` `[A, B]` *(Popped from the block below)*
- `PUSH E` -> Blocks: `[E]` `[A, B]` *(Empty head block is reused!)*

---

## Your Task

You must write your implementation in the following file:
```text
stack-list.cpp# Make Commands

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
- Click on `Terminal` > `Run Task` > `Run all stack-list tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
