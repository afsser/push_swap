# Push_swap Project Overview

## Overview
The **push_swap** project focuses on writing a sorting algorithm, a crucial step in a developer's journey, as it introduces the concept of algorithmic complexity. Understanding sorting algorithms and their efficiencies is vital for technical interviews and real-world applications. In this project, you will work with two stacks, implementing various operations to sort a list of integers with the least number of commands. 

The algorithm I chose to implement is the **radix sort**. To adapt this algorithm for use with only two stacks, my code operates on the numbers in binary form. This approach allows for efficient sorting by processing each bit of the numbers, as they end with either 0 or 1.

## Learning Objectives
- **Algorithm Complexity**: Gain a deep understanding of sorting algorithms and their complexities.
- **Rigorous Coding**: Enhance your coding skills in C, with a focus on creating efficient algorithms.
- **Basic Algorithm Usage**: Learn to apply fundamental algorithms to achieve the desired outcomes in sorting tasks.

## Program Specifications
The **push_swap** program must comply with the following requirements:

- **Stacks**: You will utilize two stacks named `a` and `b`. Stack `a` starts with a random amount of unique integers (negative and/or positive), while stack `b` begins empty.
- **Operations Available**: Implement the following operations to manipulate the stacks:
  - `sa`: Swap the first two elements of stack `a`.
  - `sb`: Swap the first two elements of stack `b`.
  - `ss`: Perform `sa` and `sb` simultaneously.
  - `pa`: Push the top element of stack `b` to stack `a`.
  - `pb`: Push the top element of stack `a` to stack `b`.
  - `ra`: Rotate stack `a` upwards.
  - `rb`: Rotate stack `b` upwards.
  - `rr`: Perform `ra` and `rb` simultaneously.
  - `rra`: Reverse rotate stack `a` downwards.
  - `rrb`: Reverse rotate stack `b` downwards.
  - `rrr`: Perform `rra` and `rrb` simultaneously.

## Usage
To run the program, use the following command:

./push_swap <list_of_integers>

Copiar código

For example:

$> ./push_swap 2 1 3 6 5 8

Should return:

sa
pb
pb
pb
sa
pa
pa
pa

## Project Requirements
- **Files**: Submit the following files: `Makefile`, `*.h`, and `*.c`.
- **Makefile**: Must include rules for `NAME`, `all`, `clean`, `fclean`, and `re`.
- **Error Handling**: Your program should handle errors gracefully and print "Error" to the standard error if invalid arguments are provided (e.g., non-integer values, duplicates, integers larger than allowed).
- **Output**: The program must output the shortest sequence of operations needed to sort stack `a`, with the smallest number on top. Each instruction should be separated by a newline.
- **No Global Variables**: Global variables are prohibited in your implementation.
- **Memory Management**: Ensure there are no memory leaks and that all allocated memory is freed appropriately.

## External Functions
We are allowed to use the following external functions:
- `read`, `write`, `malloc`, `free`, `exit`, and any equivalent functions we have coded.
- Our own implementation of `ft_printf` or similar.

By completing this project, you will not only reinforce your understanding of sorting algorithms but also improve your ability to manage stack operations efficiently in C. The skills gained here will be instrumental in your development journey.
