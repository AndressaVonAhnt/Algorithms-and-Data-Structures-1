// Andressa Von Ahnt M1

#include <stdio.h>

/*
====================
Partition

  QuickSort partition function that sorts based on profit
====================
*/
int Partition( int arrDifficulty[], int arrProfit[], int low, int high ) {
    int mid = low + (high - low) / 2;  
    int pivot = arrProfit[mid];

    int temp = arrProfit[mid];
    arrProfit[mid] = arrProfit[high];
    arrProfit[high] = temp;

    int temp1 = arrDifficulty[mid];
    arrDifficulty[mid] = arrDifficulty[high];
    arrDifficulty[high] = temp1;

    int i = low - 1;

    for ( int j = low; j < high; j++ ) {
        if ( arrProfit[j] >= pivot ) {  
            i++;
            temp = arrProfit[i];
            arrProfit[i] = arrProfit[j];
            arrProfit[j] = temp;

            temp1 = arrDifficulty[i];
            arrDifficulty[i] = arrDifficulty[j];
            arrDifficulty[j] = temp1;
        }
    }

    temp = arrProfit[i + 1];
    arrProfit[i + 1] = arrProfit[high];
    arrProfit[high] = temp;

    temp1 = arrDifficulty[i + 1];
    arrDifficulty[i + 1] = arrDifficulty[high];
    arrDifficulty[high] = temp1;

    return i + 1;
}

/*
====================
QuickSort

  Sorts arrays using QuickSort
====================
*/
void QuickSort( int arrDifficulty[], int arrProfit[], int low, int high ) {
    if ( low < high ) {
        int pi = Partition( arrDifficulty, arrProfit, low, high );
        QuickSort( arrDifficulty, arrProfit, low, pi - 1 );
        QuickSort( arrDifficulty, arrProfit, pi + 1, high );
    }
}

/*
====================
CheckDifficulty

  Checks the highest difficulty level the worker can handle
====================
*/
int CheckDifficulty( const int *difficulty, int size, int index ) {
    for ( int i = 0; i < size; i++ ) {
        if ( index >= difficulty[i] ) {
            return i;
        }
    }
    return size + 1;
}

/*
====================
MaxProfitAssignment

  Assigns workers to tasks to maximize profit
====================
*/
int MaxProfitAssignment( int *difficulty, int difficultySize, int *profit, int profitSize, int *worker, int workerSize ) {
    QuickSort( difficulty, profit, 0, profitSize - 1 );

    int totalProfit = 0;

    for ( int i = 0; i < workerSize; i++ ) {
        int j = CheckDifficulty( difficulty, difficultySize, worker[i] );
        if ( j <= difficultySize ) {
            totalProfit += profit[j];
        }
    }

    return totalProfit;
}

/*
====================
Main

  Driver function to test the MaxProfitAssignment
====================
*/
int main( void ) {
    int difficulty[] = {2, 4, 6, 8, 10};
    int profit[] = {10, 20, 30, 40, 50};
    int worker[] = {4, 5, 6, 7};

    printf( "%d\n", MaxProfitAssignment( difficulty, 5, profit, 5, worker, 4 ) );
    return 0;
}
