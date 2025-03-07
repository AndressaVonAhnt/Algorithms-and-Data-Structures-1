Author
===================================
Andressa Von Ahnt - M1


README - Most Frequent Subtree Sum
===================================

Overview
--------
This program calculates the most frequent subtree sums in a binary tree.
A subtree sum is the sum of all node values in a subtree, including the root node of that subtree.

The program is written in C and follows Doom Engine coding standards where applicable,
including function naming conventions, formatting, and recursive function naming.

Problem Description
-------------------
Given a binary tree, the goal is to:
- Compute the sum for each subtree.
- Track how frequently each sum appears.
- Identify the most frequent sum(s).
- If there is a tie (multiple sums appear the same number of times), all of them should be returned.

Code Structure
--------------
The program is organized into the following functions:

PutOrUpdateArray
    Adds a subtree sum to a dynamically allocated array or updates its frequency count if already present.

FindFrequentHelper_r
    Recursive helper function to compute subtree sums and update the frequency array.

FindFrequentTreeSum
    Main function to calculate the most frequent subtree sums and return them as a dynamically allocated array.

CreateNode
    Allocates and initializes a new tree node.

FreeTree_r
    Recursively frees the entire binary tree.

main
    Builds a small test tree, computes the most frequent subtree sums, prints them to the console, 
    and then frees all allocated memory.

Example Tree
------------
The tree in main() looks like:

        5
       / \
      2  -5

- Subtree sum at node 2: 2
- Subtree sum at node -5: -5
- Subtree sum at node 5: 5 + 2 + (-5) = 2

The sums are:
    [2, -5, 2]

The most frequent sum is:
    2 (appears twice)


Memory Management
-----------------
- All nodes are allocated dynamically using malloc.
- All dynamically allocated arrays (for subtree sums) are properly freed.
- The entire tree is freed at the end using a recursive FreeTree_r() function.
- The code avoids memory leaks when executed correctly.


License
-------
This code is provided for educational purposes.
