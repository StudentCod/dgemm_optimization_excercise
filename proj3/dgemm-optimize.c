#include <string.h>
#include <stdlib.h>

void dgemm( int m, int n, float *A, float *C )
{
// FILL-IN 

// Loop Unrolling
 int i = 0;
 if((m % 2) != 0){
     for( int k = 0; k < n; k++ ) 
       for( int j = 0; j < m; j++){ 
 	    C[j*m] += A[k*m] * A[j+k*m];
       }

     i++;
 }

 for(; i < m; i = i + 2 )
     for( int k = 0; k < n; k++ ) 
       for( int j = 0; j < m; j++){ 
 	    C[i+j*m] += A[i+k*m] * A[j+k*m];
         C[(i + 1)+j*m] += A[(i + 1)+k*m] * A[j+k*m];
       }
  

// Reordering

    
    // for( int j = 0; j < m; j++ ) 
    //     for( int k = 0; k < n; k++ )
    //         for( int i = 0; i < m; i++ ) 
	//             C[i+j*m] += A[i+k*m] * A[j+k*m];




// Register Blocking - use no optimization

// float* beta;

// for( int i = 0; i < m; i++ ){
//     for( int k = 0; k < n; k++ ){
//       beta = &A[i + k*m]; 
//       for( int j = 0; j < m; j++ ){ 
// 	    C[i+j*m] += *beta * A[j+k*m];
//       }
//     }
// }




// Padding Matrices - Failed

// if((n % 2) != 0){ //if m and n are odd
//     float *B = (float*) malloc( m * (n + 1) * sizeof(float) );

//     memset(B, 0, sizeof(float) * m *(n + 1));
//         for( int l = 0; l < n; l++ ) 
//             for( int p = 0; p < m; p++ ) 
// 	            B[p+l*m] = A[p+l*m];

//     A = B;

//     for( int i = 0; i < m; i++ )
//         for( int k = 0; k < (n + 1); k++ ) 
//             for( int j = 0; j < m; j++ ) 
// 	            C[i+j*m] += A[i+k*m] * A[j+k*m];

// }

// else{


//     for( int i = 0; i < m; i++ )
//         for( int k = 0; k < n; k++ ) 
//             for( int j = 0; j < m; j++ ) 
// 	            C[i+j*m] += A[i+k*m] * A[j+k*m];

// }



}
