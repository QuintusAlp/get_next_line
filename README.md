# get_next_line

## GRADES 125/100

## Introduction
`get_next_line` is a project from the 42 programming school designed to implement a function that reads a line from a file descriptor. This project helps in understanding file I/O, buffer management, and dynamic memory allocation in C.

## Purpose
- **File I/O Mastery**: By implementing `get_next_line`, we learn how to read from file descriptors efficiently.
- **Buffer Management**: Gain experience in managing buffers to handle variable-length input.
- **Dynamic Memory Allocation**: Develop skills in dynamic memory management, ensuring memory is properly allocated and freed to prevent leaks.

## Features
The `get_next_line` function reads a line from a file descriptor and returns it, ensuring that subsequent calls continue reading from where the previous call left off.
## Bonus Features
Bonus of gnl is the gestion of severall file descriptors. you can read the first line of a file first and in an other and so on.

### Function Prototype
```c
int get_next_line(int fd);

