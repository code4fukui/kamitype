# kamitype

> 日本語のREADMEはこちらです: [README.ja.md](README.ja.md)

A simple, terminal-based typing game designed to help C language beginners familiarize themselves with reserved words and common keywords. The game is built in C and uses keyboard handling features from [liblove.c](liblove.c).

## How It Works

The game presents you with a C keyword and validates your input character by character. After 20 words, it displays your performance statistics.

```text
$ ./a.out
struct (1/20)
struct
volatile (2/20)
volatile
return (3/20)
return
...

-- After 20 words --

time: 25 sec
speed: 132 type/min
ntype: 55
nmiss: 3
score: 129 point (speed - nmiss)
```

## Features

- **Keyword Practice:** Type C language keywords, including reserved words, types, and preprocessor directives, chosen randomly from the list in [words_c.h](words_c.h).
- **Immediate Feedback:** Correct keystrokes are echoed to the screen, while incorrect ones trigger an audible terminal bell.
- **Clear Objective:** The game concludes after you correctly type 20 words.
- **Performance Metrics:** At the end of each session, you receive a summary of your performance, including:
  - Total time taken (seconds)
  - Typing speed (characters per minute)
  - Total correct characters typed
  - Number of mistakes
  - Final score (calculated as `speed - nmiss`)

## Requirements

- A C compiler (e.g., GCC or Clang)
- A POSIX-compliant terminal environment (e.g., on Linux, macOS, or WSL)

## Build and Run

Clone the repository, then compile and run the game with the following commands:

```bash
# Compile the source file
gcc kamitype.c -o kamitype

# Run the executable
./kamitype
```

## License

This project is provided without a license.