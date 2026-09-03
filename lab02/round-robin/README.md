# Lab03 - Round Robin CPU Scheduling

## Problem Statement

Implement a Round Robin (RR) CPU scheduler using the C++ Standard Library Queue (`std::queue`). 

Round Robin is a preemptive scheduling algorithm where each process is assigned a fixed time unit called a **time quantum** (or time slice). The processes are kept in a FIFO (First-In, First-Out) queue. The CPU executes the process at the head of the queue for up to one time quantum. If the process does not finish within the time quantum, it is preempted and put back at the end of the queue.

For the simulation, follow these precise rules:
1. At time $t$, all processes that have arrived by $t$ are in the ready queue.
2. The process at the head of the queue runs for up to `time_quantum` units.
3. If new processes arrive *during* this execution (i.e., in the interval $(t, t + \text{run\_time}]$), they are added to the ready queue in index order of their input.
4. If the running process has remaining time, it is added back to the ready queue *after* the newly arrived processes.
5. If the ready queue is empty, the CPU remains idle until the next process arrives. The current time is then advanced to its arrival time.

You must implement:
- `void simulate_round_robin(Process processes[], int n, int time_quantum)` -- simulates the scheduling and updates the completion time, turnaround time, and waiting time for each process in the array.

---

## Formulas

For each process, you must calculate:
- **Turnaround Time (TAT)**: The total time taken from arrival to completion.
  $$\text{TAT} = \text{Completion Time} - \text{Arrival Time}$$
- **Waiting Time (WT)**: The total time the process spent waiting in the ready queue.
  $$\text{WT} = \text{Turnaround Time} - \text{Burst Time}$$

---

## Constraints

- $1 \le n \le 100$ (Number of processes)
- $1 \le \text{time\_quantum} \le 100$
- $0 \le \text{Arrival Time} \le 10^4$
- $1 \le \text{Burst Time} \le 10^3$
- Process IDs are unique alphanumeric strings (e.g., `P1`, `P2`).

---

## Input Format

- Line 1: `n` (number of processes) and `time_quantum` (space-separated)
- Next `n` lines: Each contains a process `id` (string), `arrival_time` (integer), and `burst_time` (integer) (space-separated).

## Output Format

- For each process (in the order of input), print a line containing:
  `Process <id>: Arrival = <arrival_time>, Burst = <burst_time>, CT = <completion_time>, TAT = <turnaround_time>, WT = <waiting_time>`
- Print the average turnaround time and average waiting time formatted to 2 decimal places:
  `Average Turnaround Time = <avg_tat>`
  `Average Waiting Time = <avg_wt>`

---

### Example

#### Sample Input

```text
4 2
P1 0 5
P2 1 3
P3 2 1
P4 3 2
```

#### Sample Output

```text
Process P1: Arrival = 0, Burst = 5, CT = 11, TAT = 11, WT = 6
Process P2: Arrival = 1, Burst = 3, CT = 10, TAT = 9, WT = 6
Process P3: Arrival = 2, Burst = 1, CT = 5, TAT = 3, WT = 2
Process P4: Arrival = 3, Burst = 2, CT = 8, TAT = 5, WT = 3
Average Turnaround Time = 7.00
Average Waiting Time = 4.25
```

#### Explanation

The time quantum is `2`, so each process can run for at most 2 time units before being moved to the back of the ready queue if it still has work remaining.

At time `0`, only `P1` has arrived, so it runs from `0` to `2`. During this execution, `P2` arrives at time `1`, and `P3` arrives at time `2`. They are added to the queue before `P1` is re-added.

The scheduling then proceeds in FIFO order:

```text
Time:    0    2    4    5    7    8    10   11
         | P1 | P2 | P3 | P4 | P1 | P2 | P1 |
```

`P3` finishes at time `5`, `P4` finishes at time `8`, `P2` finishes at time `10`, and `P1` finishes at time `11`.

For each process:

* `TAT = CT - Arrival Time`
* `WT = TAT - Burst Time`

For example, `P1` completes at time `11`:

```text
TAT = 11 - 0 = 11
WT  = 11 - 5 = 6
```

The scheduler also follows the rule that processes arriving during a time slice are placed in the ready queue before the preempted process is added back.


## Your Task

You must write your implementation in the following file:
```text
round-robin.cpp
```

Please edit the code only in the marked area (between `Your code starts from here` and `Your code ends here`) and do not edit anywhere else in this file. You must not edit `round-robin.h`, `common.h`, or `main.cpp`.
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
- Click on `Terminal` > `Run Task` > `Run all round-robin tests`. All test cases are executed one by one automatically. For each test case, the report displays the test number, whether it passed or failed, the expected output, and the actual output produced by your program in the `Terminal`.

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
