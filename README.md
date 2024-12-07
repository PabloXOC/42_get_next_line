# 42 Get Next Line

**Get Next Line** is a C project that implements a function, `get_next_line()`, which reads a file descriptor and returns one line at a time. The function allows for repeated calls to read lines from files or standard input until the end of the file is reached. The project aims to familiarize you with low-level file handling, memory management, and the interaction between system calls in C.

## Project Overview

The goal of this project is to implement a function that can read a file line by line. The function, `get_next_line()`, takes a file descriptor (`fd`) as input and returns a line from the file each time it is called. It handles various scenarios, including reaching the end of the file (EOF) and managing memory efficiently.

### Key Features
- **Reads one line at a time** from the file descriptor.
- **Handles standard input** as well as file input.
- Returns the line, including the terminating newline (`\n`), unless the end of the file is reached without a newline.
- **Handles multiple calls** to read lines sequentially from the file.
- Uses `malloc()` and `free()` to manage memory dynamically.
- Configurable buffer size using the `-D BUFFER_SIZE=n` compiler flag.

## Functionality

The core function of the project is `get_next_line()`:

```c
char *get_next_line(int fd);
```

### Parameters
- **fd**: The file descriptor to read from. It can represent files, standard input, or other streams.

### Return Value
- **Success**: The function returns the next line from the file, including the newline character (`\n`) unless EOF is reached without a newline.
- **Failure**: It returns `NULL` if the end of the file is reached or if an error occurs during reading.

### External Functions Used
- `read()` — to read from the file descriptor.
- `malloc()` — to allocate memory for each line.
- `free()` — to release memory after use.

## Files

### Mandatory Files
- **get_next_line.c**: Contains the main implementation of `get_next_line()`.
- **get_next_line_utils.c**: Contains helper functions needed by `get_next_line()`.
- **get_next_line.h**: Header file with the prototype of the `get_next_line()` function.

### Bonus Files
- **get_next_line_bonus.c**: Contains the implementation for the bonus functionality.
- **get_next_line_bonus.h**: Header file for the bonus functions.
- **get_next_line_utils_bonus.c**: Helper functions for the bonus part of the project.

## Features of the Bonus Part

The bonus part of the project introduces the following features:
1. **Single Static Variable**: The `get_next_line()` function is implemented using only a single static variable to manage the reading process.
2. **Multiple File Descriptors**: The function can handle multiple file descriptors simultaneously, allowing you to read from different files or streams in an interleaved manner without losing track of each file’s state.

## Compilation

To compile the project, use the following command (with the `-D BUFFER_SIZE=n` flag to set the buffer size for `read()`):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

For the bonus part, use:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Buffer Size
The buffer size is configurable at compile time using the `-D BUFFER_SIZE=n` flag, where `n` is the buffer size you choose. The value of `n` can be modified during evaluation to test the robustness of your code.

## Usage

Once compiled, you can use `get_next_line()` to read lines from a file or from standard input.

Example usage to read from a file:

```c
#include "get_next_line.h"

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);  // Print the line
        free(line);           // Free the memory
    }

    close(fd);  // Close the file descriptor
    return 0;
}
```

### Multiple File Descriptors
In the bonus version, you can use `get_next_line()` with multiple file descriptors. For example, you can read from different files one after the other without mixing up the lines:

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

char *line1 = get_next_line(fd1);
char *line2 = get_next_line(fd2);

// Process lines from different files
```

## License

This project is licensed under the MIT License.

