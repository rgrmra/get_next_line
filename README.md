# Get Next Line

A functions that reads from a file descriptor and returns a string until the new line character or the end of the file.

#### How does it work?

This function works with a list of characters and allocates memory for every character. When the function find a new line character (_'\n'_), it returns an allocated string until the new line character followed by a null character (_'\0'_).

## How to use it?

Clone the repository to your project directory:

```shell
git clone https://github.com/rgrmra/get_next_line.git get_next_line
```

Then compile the files.

#### Mandatory:

Reads from just one file descriptor.

```shell
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o get_next_line
```

#### Bonus:

Reads from multiple file descriptors.

```shell
cc -Wall -Wextra -Werror main.c get_next_linei_bonus.c get_next_line_utils_bonus.c -o get_next_line
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

#### Prototype:

```c
char    *get_next_line(int fd);
```
