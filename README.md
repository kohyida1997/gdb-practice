# Using GDB for debugging
## Common Pre-requisites
* Need to compile the binary to run with debug symbols:
    * Turn on debug symbols when compiling with `gcc`
    * `-g` or `-ggdb` (debug symbols optimized for the gdb GNU debugger)
    * Can additionally add optimization levels as well. (ie. `-ggdb -O0`)
    * In **CMake**, you can add this compile options (and other compile options) using `target_compile_options()`
    * You can check if debug symbols are included in a particular (`.ELF`) binary by doing `file MyBin` in Linux. Look for "**with debug_info**"

## Option 1: Running binary directly inside GDB
### Setting up and Running
* Execute `gdb [your_binary_file]` on the terminal to start a GDB session using this particular binary. Eg `gdb MyBin`
* **Before** running the binary *inside GDB*, **set a breakpoint** using the `break` command inside GDB. (eg. `break main` to put a breakpoint in the `main()` function)
* Use `run` *inside GDB* to start running. The program should pause at the first breakpoint

## Option 2: Running GDB with Core Dumps
### Setting up and Running
* As usual, ensure your binary was compiled with debug symbols.
* Find out where the core dumps are! 
    * Good starting point is to search for directories with "coredump" in the name: `find /var -name "*coredump*" -type d`
    * If the **core dumps don't seem to have been produced**, you might need to set `ulimit -c` to allow the terminal process to create core files. This may require **root permissions** (`sudo su`)
    * *(**Ubuntu 20.04** and **22.04 LTS**) Core dumps are at `/var/lib/apport/coredump` by default it seems
* Know where the binary (that crashed and created the core dump) is created, we need it when running GDB on the core file
* Execute `gdb [your_binary_file] [your_core_file]` on the terminal to get started. Eg. `gdb MyBin MyCrashedCore`

## Inside GDB: Stepping and Examining State
### Stepping
* Note that you must have a binary running to be stepping (duh!). (ie. Must have executed `run` inside GDB)
* Use `next` to **step through the next logical line** (as in the source code)
* Use `nexti` to **step through the next instruction** (as in the assembly)
* Use `step` to **step INTO the next logical line**. If the next line is a function, Stepping *into* will step into a particular function call, while stepping *through* will execute the function but not enter it.
### Examining State
* Use `info` command to examine the state of variables
    * `info args` to list "Arguments of the current stack frame" (names and values).
    * `info locals` to list "Local variables of current stack frame" (names and values), including static variables in that function.
    * `info variables` to list "All global and static variable names" (huge list)
    * `info registers` to list values inside registers
* Use `x` [command](https://visualgdb.com/gdbreference/commands/x) to examine contents at an address 
    * Eg. `x/i $pc` to examine the *program counter* at the current execution point. This is useful especially when finding out exactly which assembly instruction caused the program to crash.
* Use `p` command to print variables
    * eg. Suppose there is some `int d = 2`. Use `p d` to print value of `int d` at the current state

## Inside GDB: Managing the UI
* Use `lay` to change the **layout** of the GDB Terminal UI (TUI). Use `lay split` to split view between **source** and the **asm**
    * After using `lay`, use `tui [disable/enable]` OR `ctrl-x+a` to toggle the visibility of `TUI`
* Use `shell clear` to clear the shell (like `clear` on normal Linux terminal)
* Use `ref` to refresh the terminal (printing to stdout can mess up the GDB ui)

## Helpful Links
1. Using GDB with Ubuntu: core dump locations, using GDB, debug symbols etc. ([Stackoverflow](https://askubuntu.com/questions/1349047/where-do-i-find-core-dump-files-and-how-do-i-view-and-analyze-the-backtrace-st))
2. Printing variables and state in GDB ([Stackoverflow](https://stackoverflow.com/questions/6261392/printing-all-global-variables-local-variables))
3. Examining program variables ([Sourceware](https://sourceware.org/gdb/download/onlinedocs/gdb/Variables.html))
4. Setting `ulimit` to allow core dumps to be created. ([StackOverflow](https://superuser.com/questions/867120/linux-change-ulimit-hn))
5. Low Level Learning: Running with GDB ([Youtube](https://www.youtube.com/watch?v=Dq8l1_-QgAc))
6. Low Level Learning: GDB with Core Dumps ([Youtube](https://www.youtube.com/watch?v=3T3ZDquDDVg&t=327s))