# get_next_line

_This project has been created as part of the 42 curriculum by molasz-a._

> Part of [42 Barcelona — molasz-a](https://github.com/Molasz/42), a monorepo centralizing every project completed at 42 Barcelona.

## Description

`get_next_line` is a fundamental project at 42 that requires creating a function to read a file line by line. This function is essential for many future projects that involve file I/O. The challenge lies in managing the buffer and handling multiple file descriptors efficiently.

The project is divided into a mandatory part, which implements the function for a single file descriptor, and a bonus part, which handles multiple file descriptors simultaneously.

---

## Features

| Function          | Description                                                                 |
| ----------------- | --------------------------------------------------------------------------- |
| `get_next_line`   | Returns the next line from a file descriptor.                               |
| `BUFFER_SIZE`     | Macro to set the size of the buffer used for reading.                       |

### Bonus

The bonus part of the project requires `get_next_line` to be able to handle multiple file descriptors at the same time without losing the reading state of each file.

---

## Architecture

![Skills](https://skillicons.dev/icons?i=c,linux)

The project is structured around the `get_next_line` function, which uses a static variable to keep track of the reading state. The bonus version uses an array of `t_file` structs to handle multiple file descriptors.

```
get_next_line.c         → Main function logic
get_next_line_utils.c   → Utility functions (e.g., ft_strlen, ft_strjoin)
get_next_line_bonus.c     → Bonus: Main function logic for multiple file descriptors
get_next_line_utils_bonus.c → Bonus: Utility functions for the bonus part
```

The `t_file` struct used in the bonus part:

```c
typedef struct s_file
{
    int     fd;
    int     init;
    int     end;
    char    *buff;
}       t_file;
```

---

## ⚙️ Instructions

To use `get_next_line` in another project:

```c
#include "get_next_line.h"
```

Then, compile your project with the `get_next_line.c` and `get_next_line_utils.c` files.

Example of reading a file line by line:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("my_file.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

_molasz-a · 42 Barcelona_
