// Martinez, Ruben
// rxm4933
// 2018 July 2
//--------#---------#---------#---------#--------#
#include <stdio.h>

//--------#---------#---------#---------#--------#
#define MISSING (-1)

int binarySearchLeft( int *A, int v, int low, int high ) {
  
    if (high<low)
        return MISSING;
    
    int mid=low+(high-low)/2;
    
    if (v <A[mid])
        return binarySearchLeft(A, v, low, mid-1);
    else if (v>A[mid])
        return binarySearchLeft(A, v, mid+1, high);
    else
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (A[mid] >= v) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
    return low;
}
    


//--------#---------#---------#---------#--------#
#define NUM_VALUES (8)

struct TEST {
    int value;
    int array[ NUM_VALUES ];
};

struct TEST TESTS[] = {
    { 1, { 1, 1, 1, 1, 1, 1, 1, 1 } },
    { 2, { 2, 2, 2, 2, 3, 3, 3, 3 } },
    { 3, { 1, 1, 2, 2, 3, 3, 4, 4 } },
    { 4, { 0, 0, 0, 0, 0, 0, 0, 4 } },
    { 5, { 1, 2, 3, 4, 6, 7, 8, 9 } },
};

#define NUM_TESTS ( sizeof( TESTS ) / sizeof( struct TEST ) )

int main( int argc, char *argv[] ) {
    int v;
    int *A;
    int result;
    
    printf( "=== Binary Search Left ===\n" );
    
    for ( int i = 0; i < NUM_TESTS; i++ ) {
        v = TESTS[ i ].value;
        A = TESTS[ i ].array;
        
        result = binarySearchLeft( A, v, 0, NUM_VALUES-1 );
        
        if ( result == MISSING ) {
            printf( "%d was not in [", v );
            for ( int j = 0; j < NUM_VALUES; j++ ) {
                printf( "%d, ", A[j] );
            }
            printf( "]\n" );
        } else {
            printf( "%d in [", v );
            for ( int j = 0; j < NUM_VALUES; j++ ) {
                printf( "%d, ", A[j] );
            }
            printf( "] is at %d.  A[%d] is %d.\n",
                   result, result, A[result] );
        }
    }
}

//--------#---------#---------#---------#--------#
