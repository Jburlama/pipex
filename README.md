![image](https://github.com/user-attachments/assets/2d56350e-8520-46a4-a5be-9307b7414495)


## Pipex is a 42 school project about handling pipes, forks, and redirections of input and output.


On this project, I learned how Unix pipes work. Think of it as learning how to connect different commands together so that the output of one becomes the input of another. Through Pipex, I gained a deeper understanding of how processes communicate and handle files in the Unix environment.
## Mandatory part

- The program will be executed as follows:

        ./pipex file1 cmd1 cmd2 file2

- It must take 4 arguments:

    -- file1 and file2 are file names.

    -- cmd1 and cmd2 are shell commands with their parameters.

- It must behave exactly the same as the shell command below:

         < file1 cmd1 | cmd2 > file2


## Examples

```
  ./pipex infile "ls -l" "wc -l" outfile
```
Should behave like: < infile ls -l | wc -l > outfile

```
  ./pipex infile "grep a1" "wc -w" outfile
```
Should behave like: < infile grep a1 | wc -w > outfile



## Bonus part

 -  Handle multiple pipes:
```
    ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

Should behave like:
```
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

```

- Support « and » when the first parameter is "here_doc".

```
./pipex here_doc LIMITER cmd cmd1 file
```
Should behave like:
```
cmd << LIMITER | cmd1 >> file
```
## Before solving the problem, I had to understand how some key system call functions work:

pipe()
fork()
dup2()
execve()






### pipe()

This function facilitates direct communication between two processes. It establishes a one-way data channel, allowing one process to send its output directly to another process as input.

### fork()

When fork() is called, the operating system duplicates the calling process, resulting in two identical processes, known as the parent and child processes. These processes then continue executing independently, each with its own memory space and execution context. The child process inherits copies of the parent process's resources, including open file descriptors and memory allocations.

### dup2()

With dup2(), a file descriptor can be made to refer to another file descriptor, effectively "duping" or copying it. This capability is particularly useful for managing input and output redirection in processes. For instance, I used it in conjunction with the pipe() function to redirect standard input or output to specific ends of a pipe.

### execve()

When called, execve() replaces the current process image with a new one specified by the given program. This loads the program into memory and begins its execution, effectively transitioning the current process into the desired program.

# 🛠️ Usage

To compile the binaries

```
  make
```
This will compile two executables: pipex and pipex_bonus.

you can also
```
make pipex
```
or
```
make bonus
```
To compile each individually.



https://github.com/user-attachments/assets/55d52e39-f8b9-4b0f-b0f8-54329a1932bc


---------------------------------------

**pipex** must conform to the [42 Norm](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf).

**Install** [norminette](https://github.com/42School/norminette).

