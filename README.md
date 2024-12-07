# 42 Get Next Line

The `get_next_line` project implements a function that reads and returns a single line from a file descriptor. This utility is a foundational C programming challenge that enhances skills in file handling, dynamic memory management, and efficient reading of input streams.

---

## Features

- **Line-by-Line Reading**: Repeated calls to `get_next_line` read lines from a file descriptor, one at a time.
- **Handles Multiple Sources**: Works with both files and standard input.
- **Dynamic Buffering**: Uses a customizable buffer size defined at compile-time via the `BUFFER_SIZE` macro.
- **Error Handling**: Returns `NULL` when there is nothing more to read or if an error occurs.
- **Includes the Newline Character**: Lines returned include the `\n` character, except for the last line if the end of the file does not end with one.

---

## Project Files

- **`get_next_line.c`**: Contains the main implementation of the `get_next_line` function.
- **`get_next_line_utils.c`**: Includes all helper functions needed to support the main function.
- **`get_next_line.h`**: Header file containing function prototypes and necessary includes.

---

## Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters
- **`fd`**: The file descriptor to read from.

### Return Value
- **`char *`**: The next line read from the file, including the `\n` if applicable.
- **`NULL`**: If there is nothing left to read or an error occurs.

---

## Compilation Instructions

To compile the code, use the following command, substituting `BUFFER_SIZE` with the desired size (e.g., 42):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

You can also omit the `-D BUFFER_SIZE` flag to use the default buffer size defined in your code.

---

## Usage Example

Here’s an example of using `get_next_line` to read lines from a file:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

## Key Considerations

- **Buffer Size Flexibility**: The buffer size is defined at compile time with the `BUFFER_SIZE` macro, which affects the behavior of the `read` function.
- **Undefined Behaviors**:
  - If the file descriptor changes between calls and `read` has not reached the end of the file.
  - When reading binary files (though you can handle this behavior logically).

---

## Learnings and Reflections

This project deepened my understanding of:
- **Dynamic Memory Management**: Efficiently allocating and freeing memory for varying line lengths.
- **File I/O Operations**: Managing file descriptors and ensuring robust behavior for reading files.
- **Error Handling**: Identifying and handling edge cases and system-level errors gracefully.

By implementing `get_next_line`, I have built a versatile and reusable function that serves as a cornerstone for more complex input-handling programs.

---

## License

This project is open-source and available under the [MIT License](https://opensource.org/licenses/MIT).
```

This README provides a comprehensive overview of the project while keeping it concise and easy to understand. Let me know if you need further adjustments!
