<img align="center" src="https://royalbox.com.br/github/get_next_line_banner.png">
<p align="center">
   <img src="https://img.shields.io/github/languages/code-size/rgrmra/get_next_line?color=blue&style=for-the-badge" />
   <img src="https://img.shields.io/github/languages/top/rgrmra/get_next_line?color=blue&style=for-the-badge" />
   <img src="https://img.shields.io/github/last-commit/rgrmra/get_next_line?color=blue&style=for-the-badge" />
   <img src="https://img.shields.io/github/license/rgrmra/get_next_line?color=blue&style=for-the-badge" />
</p>

<p align="center">
  This project is about programming a function that returns a line read from a file descriptor.
</p>

# Project

This is the secound project of the common core at 42 São Paulo. The project wants that you code a function that read from a file descriptor and returns an allocated line. The returned line has a _newline character_ at the end of the string followed by a _null character_.

The **get_next_line** works with all file descriptors, so it's also possible to read from the _Standard Input_, _Standard Output_ and _Standard Error_.

# Documentation

#### NAME

get_next_line - read a line from a file descriptor

#### SYNOPSIS

```c
// MANDATORY: Supports only one file descriptor
#include  "get_next_line.h"

// BONUS: Supports one or more file descriptors at the same time
#include  "get_next_line_bonus.h"
```

#### PROTOTYPE

```c
char    *get_next_line(int fd);
```

#### DESCRIPTION

**get_next_line** will read a line from a file descriptor and return an allocated string. If file descriptor is empty or EOF, a NULL will be returned. The line returned is allocated with malloc; the caller must free it when finished. The line returned has the final newline.

#### RETURN VALUE

**get_next_line** returns the text of the first line read from a file descriptor. A blank line returns a empty string. If **EOF** is encontered while reading a line, and the line is empty, **NULL** is returned.

# How to test it?

Clone this repository:

```shell
git clone https://github.com/rgrmra/get_next_line.git get_next_line
```

Then compile the files as following:

> [!NOTE]
> The `main.c` that I built is limited just to one file descriptor at time; but it's possible to use more file descriptors with the **get_next_line** bonus version.

#### Mandatory:

Reads from just one file descriptor.

```shell
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o get_next_line
```

#### Bonus:

Reads from multiple file descriptors.

```shell
cc -Wall -Wextra -Werror main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line
```

#### Execution:

Reads from the standart output.

```shell
./get_next_line
```

Reads from a file.

```shell
./get_next_line example.txt
```

> [!IMPORTANT]
> The **get_next_line** function has a buffer size of 2048 bits, but is possible to redefine it.<br>
> Use the flag `-D BUFFER_SIZE=<value>` (eg. `-D BUFFER_SIZE=10240`) to redefine the buffer size.

```bash
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o get_next_line -D BUFFER_SIZE=10240
```
