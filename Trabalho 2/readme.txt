# Max Heap for Maximizing Average Ratio
# Andressa Von Ahnt

## Overview
This project implements a **Max Heap** to solve the problem of **maximizing the average pass ratio** of classes by distributing extra students optimally. The heap is used to prioritize the class where adding an extra student has the greatest impact.

## How It Works
- A **Max Heap** is used to store classes, prioritizing them based on the impact of adding an extra student.
- The class with the highest **difference in ratio** (benefit) is **extracted** (`PopNode`) and **updated** with an additional student.
- The updated class is **reinserted** (`PushNode`) into the heap.
- This process continues until all **extra students** are distributed.
- Finally, the **maximum possible average pass ratio** is calculated.

## Features
- **Heap Operations:**
  - `PushNode()`: Inserts a class into the Max Heap while maintaining heap properties.
  - `PopNode()`: Removes the class with the highest impact.
- **Memory Management:** Dynamically allocated structures for optimal performance.
- **Efficiency:** Uses **O(n log n)** operations for heap insertions and deletions.

### Example Usage
Enter the pass and total values for each class:
1 2
3 5
2 2

Output:
0.783333
