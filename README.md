# Binary Conversion System

A simple **C programming project** that converts text into binary and binary sequences back into text.

This project was developed as a practical exercise to reinforce fundamental concepts of the C language, such as **strings, loops, functions, character manipulation, bitwise operations, and input handling**.

## Features

- Convert text/phrases into 8-bit binary.
- Convert binary sequences back into text.
- Accept both uppercase and lowercase menu options.
- Validate whether the binary input contains a number of bits divisible by 8.
- Handle spaces between binary bytes.

## Example

### Text → Binary

**Input:**
```text
Hello
```

**Output:**
```text
01001000 01100101 01101100 01101100 01101111
```

### Binary → Text

**Input:**
```text
01001000 01100101 01101100 01101100 01101111
```

**Output:**
```text
Hello
```

## How It Works

### Text to Binary

The program reads each character of the phrase and treats it as an `unsigned char`.

It then uses **bitwise operations** to examine each of the character's 8 bits, from the most significant bit to the least significant bit.

```c
for (int bit = 7; bit >= 0; bit--) {
    putchar((c >> bit) & 1 ? '1' : '0');
}
```

### Binary to Text

The program reads the binary digits one at a time and builds each character by shifting the current value one bit to the left:

```c
c = (c << 1) | (binary[i] - '0');
```

Every 8 bits represent one character, which is then printed.

## 🧠 Concepts Practiced

This project helped practice several fundamental C concepts:

- Variables and data types
- `char` and `unsigned char`
- Strings and character arrays
- `for` and `while` loops
- Functions
- `if/else` conditionals
- `fgets()` and `getchar()`
- `strlen()` and `sscanf()`
- ASCII character representation
- Bitwise operators
- Input validation
- Basic program structure

## 🚀 How to Compile

You need a C compiler such as **GCC**.

### Linux / macOS

```bash
gcc main.c -o binary_converter
```

Then run:

```bash
./binary_converter
```

### Windows

With GCC installed:

```bash
gcc main.c -o binary_converter.exe
```

Then:

```bash
binary_converter.exe
```

## Project Structure

```text
binary-conversion-system/
│
├── main.c
└── README.md
```

## Future Improvements

Possible improvements for future versions:

- Add a loop so the user can perform multiple conversions without restarting the program.
- Improve input validation for invalid binary characters.
- Support larger inputs more robustly.
- Add support for extended character encodings such as UTF-8.
- Improve the user interface.
- Separate the conversion functions into their own source/header files as the project grows.
- Add automated tests for the conversion functions.

## About the Project

This project was created as part of my learning process in **Information Systems**, with the goal of practicing C programming and understanding how text is represented at the binary level.

It is a beginner-level project and serves as a foundation for exploring more advanced programming concepts in future projects.

---

**Language:** C  
**Status:** Completed — initial version
