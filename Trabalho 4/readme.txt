Max Profit Assignment
Andressa Von Ahnt - M1

Overview

This program implements a solution to maximize the profit earned by assigning workers to jobs based on their skill level. The solution is implemented using QuickSort for sorting the difficulty and profit arrays, and a greedy approach for job allocation. The program follows the Doom Engine Coding Style Guide.


Features

Sorts jobs based on profit using QuickSort.

Assigns workers to the highest-paying job they can handle.

Uses an efficient approach to maximize total profit.



Functions

Partition

int Partition( int arrDifficulty[], int arrProfit[], int low, int high )

Partitions the difficulty and profit arrays for QuickSort.

Sorts the array based on descending order of profit.


QuickSort

void QuickSort( int arrDifficulty[], int arrProfit[], int low, int high )

Implements QuickSort algorithm to sort jobs based on profit.


CheckDifficulty

int CheckDifficulty( const int *difficulty, int size, int index )

Finds the highest difficulty level a worker can handle.


MaxProfitAssignment

int MaxProfitAssignment( int *difficulty, int difficultySize, int *profit, int profitSize, int *worker, int workerSize )

Assigns workers to jobs and calculates the maximum total profit.


main

int main( void )

Defines job difficulties, profits, and worker skill levels.

Calls MaxProfitAssignment and prints the maximum profit.


Usage

The program will output the maximum profit earned by assigning workers to jobs.

Example Output

90

This means the workers earned a total of 90 units in profit.



Author

Andressa Von Ahnt – M1 

