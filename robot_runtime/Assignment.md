# Robot Runtime — C Programming Assignment

## Overview

This assignment implements a small **robot command-line runtime** in C.

The program simulates a robot console that can:

- receive **sensor readings**
- store **movement commands**
- maintain an **event log**

The goal of this project is to practice core C programming concepts including:

- loops
- conditionals
- arrays
- stacks (FILO)
- linked lists
- memory allocation
- multi-file C programs

The program runs in the terminal and accepts commands from **standard input**.

---

# Learning Objectives

After completing this assignment, you should be comfortable with:

- writing multi-file C programs
- using `struct` to represent data
- implementing a **ring buffer**
- implementing a **stack**
- implementing a **linked list**
- allocating and freeing memory with `malloc()` and `free()`
- parsing input from the terminal

These are foundational skills required for **C++ and robotics software development**.

---

# Program Behavior

The program reads **commands from the terminal** until the user enters `QUIT`.

Example usage:

```
./robot_runtime

SAMPLE 10
SAMPLE 4
STATS
PUSH F
POP
LOG
QUIT
```

---

# System Components

The program contains three main subsystems.

---

# 1. Telemetry System (Ring Buffer)

The telemetry system stores the **last 10 sensor readings**.

If more than 10 readings are added, the **oldest value is overwritten**.

Example:

```
SAMPLE 1
SAMPLE 2
...
SAMPLE 10
SAMPLE 11
```

Buffer contents:

```
2 3 4 5 6 7 8 9 10 11
```

## Commands

### SAMPLE <value>

Adds a new sensor reading.

Example:

```
SAMPLE 12
```

---

### STATS

Print statistics of stored readings.

Example output:

```
COUNT=3 MIN=4 MAX=10 AVG=7.00
```

If no readings exist:

```
EMPTY
```

---

### DUMP

Print all stored samples.

Example:

```
SAMPLES: 10 4 7
```

If empty:

```
SAMPLES:
```

---

# 2. Command Stack

The program maintains a stack of robot movement commands.

Commands are stored using **Last In First Out (FILO)** behavior.

Valid commands:

```
F  Forward
B  Backward
L  Left
R  Right
S  Stop
```

## Commands

### PUSH <command>

Adds a command to the stack.

Example:

```
PUSH F
```

If the command is invalid:

```
ERROR
```

---

### POP

Removes the most recent command.

Example output:

```
POPPED=F
```

If the stack is empty:

```
EMPTY
```

---

### PEEK

Shows the top command without removing it.

Example:

```
TOP=F
```

If empty:

```
EMPTY
```

---

# 3. Event Log (Linked List)

Every successful operation should be recorded in an **event log**.

Example:

```
1: SAMPLE 10
2: SAMPLE 4
3: PUSH F
4: POP F
```

The log must be implemented using a **singly linked list**.

---

## Commands

### LOG

Print the entire event log.

Example:

```
1: SAMPLE 10
2: SAMPLE 4
3: PUSH F
4: POP F
```

If empty:

```
NO EVENTS
```

---

### CLEARLOG

Deletes the entire log and frees memory.

Output:

```
CLEARED
```

---

# Program Termination

### QUIT

Stops the program.

Before exiting:

- all allocated memory must be freed

Output:

```
BYE
```

---

# File Structure

The project should be organized into multiple source files.

```
robot_runtime/
│
├── main.c
├── telemetry.c
├── telemetry.h
├── cmdstack.c
├── cmdstack.h
├── eventlog.c
├── eventlog.h
└── README.md
```

---

# Compilation

Compile using:

```
gcc -Wall -Wextra -std=c11 main.c telemetry.c cmdstack.c eventlog.c -o robot_runtime
```

Run using:

```
./robot_runtime
```

---

# Example Session

Input:

```
SAMPLE 10
SAMPLE 4
SAMPLE 7
STATS
DUMP
PUSH F
PUSH X
PEEK
POP
POP
LOG
CLEARLOG
LOG
QUIT
```

Output:

```
COUNT=3 MIN=4 MAX=10 AVG=7.00
SAMPLES: 10 4 7
ERROR
TOP=F
POPPED=F
EMPTY
1: SAMPLE 10
2: SAMPLE 4
3: SAMPLE 7
4: PUSH F
5: POP F
CLEARED
NO EVENTS
BYE
```

---

# Implementation Requirements

Your solution must:

- use `struct` for all data structures
- use `malloc()` and `free()` for the event log
- avoid global variables where possible
- split logic across multiple `.c` files
- compile with no warnings using `-Wall`

---

# Optional Enhancements (Not Required)

If you want to extend the project:

- add a **REPLAY** command that executes commands from the stack
- add a **SAVELOG** command that writes the log to a file
- support **sensor noise filtering**

---

# Time Expectation

Estimated completion time:

```
10–16 hours
```

Suggested schedule:

Weekend 1
- telemetry system
- command parsing

Weekend 2
- stack
- linked list
- debugging

---

# Goal of the Assignment

The purpose of this project is to build intuition for:

- data structures
- memory management
- program structure in C

These concepts are essential foundations for:

- **C++ programming**
- **robotics software development**
- **embedded systems**