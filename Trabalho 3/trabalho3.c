// Andressa Von Ahnt - turma M1

#include <stdio.h>
#include <stdlib.h>

// ====================
// treeNode_t
//
// Structure for a tree node
// ====================
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// ====================
// sumFreq_t
//
// Structure to store sum frequencies
// ====================
typedef struct {
    int sum;
    int freq;
} sumFreq_t;

// ====================
// PutOrUpdateArray
//
// Add a sum to the frequency array or update its count
// ====================
void PutOrUpdateArray( sumFreq_t **array, int *size, int sum ) {
    for ( int i = 0; i < *size; i++ ) {
        if ( ( *array )[i].sum == sum ) {
            ( *array )[i].freq++;
            return;
        }
    }

    *array = realloc( *array, ( *size + 1 ) * sizeof( sumFreq_t ) );
    if ( *array == NULL ) {
        perror( "Memory allocation failed" );
        exit( 1 );
    }

    ( *array )[ *size ].sum = sum;
    ( *array )[ *size ].freq = 1;
    ( *size )++;
}

// ====================
// FindFrequentHelper_r
//
// Recursive function to calculate subtree sums and update frequency array
// ====================
int FindFrequentHelper_r( struct TreeNode *root, sumFreq_t **array, int *size ) {
    if ( root == NULL ) {
        return 0;
    }

    int leftSum = FindFrequentHelper_r( root->left, array, size );
    int rightSum = FindFrequentHelper_r( root->right, array, size );
    int subtreeSum = root->val + leftSum + rightSum;

    PutOrUpdateArray( array, size, subtreeSum );

    return subtreeSum;
}

// ====================
// FindFrequentTreeSum
//
// Find the most frequent subtree sums
// ====================
int *findFrequentTreeSum( struct TreeNode *root, int *returnSize ) {
    sumFreq_t *array = NULL;
    int size = 0;

    FindFrequentHelper_r( root, &array, &size );

    int maxFreq = 0;
    for ( int i = 0; i < size; i++ ) {
        if ( array[i].freq > maxFreq ) {
            maxFreq = array[i].freq;
        }
    }

    int *result = NULL;
    *returnSize = 0;
    for ( int i = 0; i < size; i++ ) {
        if ( array[i].freq == maxFreq ) {
            result = realloc( result, ( *returnSize + 1 ) * sizeof( int ) );
            result[ *returnSize ] = array[i].sum;
            ( *returnSize )++;
        }
    }

    free( array );
    return result;
}

// ====================
// CreateNode
//
// Create a new tree node
// ====================
struct TreeNode *CreateNode( int value ) {
    struct TreeNode *newNode = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) );
    if ( newNode == NULL ) {
        perror( "Memory allocation failed" );
        exit( 1 );
    }
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ====================
// FreeTree_r
//
// Recursively free the entire tree
// ====================
void FreeTree_r( struct TreeNode *root ) {
    if ( root == NULL ) {
        return;
    }
    FreeTree_r( root->left );
    FreeTree_r( root->right );
    free( root );
}

// ====================
// main
//
// Entry point
// ====================
int main( void ) {
    struct TreeNode *root = CreateNode( 5 );
    root->left = CreateNode( 2 );
    root->right = CreateNode( -5 );

    int size = 0;
    int *array = findFrequentTreeSum( root, &size );

    for ( int i = 0; i < size; i++ ) {
        printf( "%d ", array[i] );
    }
    printf( "\n" );

    free( array );
    FreeTree_r( root );

    return 0;
}
