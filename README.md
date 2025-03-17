# **Get Next Line**

<p align="center">
  <img src="https://user-images.githubusercontent.com/94384240/170166839-7f99093f-c242-4973-bc06-dfbaf88dee59.jpeg" alt="42 School Logo" width="300">
</p>

## 🏛 **42 Cursus - Get_Next_Line**  

This was the third project I completed at 42 Lisbon!  

After spending a long time trying to understand the goal of the `get_next_line` function, [Ezequiel](https://github.com/zico15) explained it to me in the simplest way.  
This project was an essential step in learning how to read from file descriptors efficiently.  

📝 **To see the project subject,** [click here](https://github.com/jlebre/get_next_line/blob/main/get_next_line.pdf)!

---

## 🚀 **Implemented Functions**

### 📌 **Mandatory Part**

| Function | Description |
|----------|------------|
| [get_next_line](https://github.com/jlebre/get_next_line/blob/main/get_next_line.c) | Reads a line from a file descriptor |
| [get_next_line_utils](https://github.com/jlebre/get_next_line/blob/main/get_next_line_utils.c) | Utility functions for `get_next_line` |
| [get_next_line.h](https://github.com/jlebre/get_next_line/blob/main/get_next_line.h) | Header file |

---

### 🎁 **Bonus Part**

| Function | Description |
|----------|------------|
| [get_next_line_bonus](https://github.com/jlebre/get_next_line/blob/main/get_next_line_bonus.c) | Extended version for multiple file descriptors |
| [get_next_line_utils_bonus](https://github.com/jlebre/get_next_line/blob/main/get_next_line_utils_bonus.c) | Utility functions for the bonus version |
| [get_next_line_bonus.h](https://github.com/jlebre/get_next_line/blob/main/get_next_line_bonus.h) | Header file for the bonus version |

---

## ✅ **Testing**

This project passed Moulinette and the following tester:

- [gnlTester](https://github.com/Tripouille/gnlTester)

![125](https://user-images.githubusercontent.com/94384240/170167072-f880e8a2-b5cb-4f85-9c19-870f9c42235f.png)

---

## 🛠 **How to Use**

### 1️⃣ **Compiling the Library**  
First, compile the library by running:

```bash
make
```

This will generate the `get_next_line.a` file.

---

### 2️⃣ **Using `get_next_line` in Your Own Code**
Once compiled, you can include `get_next_line` in your C project.

1. **Include the header file** in your program:
   ```c
   #include "get_next_line.h"
   ```
   This will give access to the `get_next_line` function.

2. **Compile your program with `get_next_line.a`**:
   ```bash
   gcc -Wall -Wextra -Werror main.c -L. -lgnl -o program
   ```
   Explanation of flags:
   - `-Wall -Wextra -Werror` → Enables warnings and strict error checking
   - `main.c` → Your C file where you use `get_next_line`
   - `-L.` → Tells the compiler to look for libraries in the current directory (`.`)
   - `-lgnl` → Links your program with `get_next_line.a`
   - `-o program` → Specifies the output executable name (`program`)

---

### 3️⃣ **Example Usage**
Here’s a simple example of how to use `get_next_line`:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

#### 📌 **Expected Behavior**
- The program reads and prints one line at a time from `example.txt`.
- The loop continues until the entire file is read.

---

### 4️⃣ **Bonus Version**
- The **bonus version** of `get_next_line` allows reading from multiple file descriptors simultaneously.
- Just use the same `get_next_line_bonus.h` and replace the normal function calls with `get_next_line_bonus.c`.

---

📝 **Project completed at 42 Lisbon!** 🚀  

