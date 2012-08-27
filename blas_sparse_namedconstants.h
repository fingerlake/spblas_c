//
//  blas_sparse_namedconstants.h
//  spblas_c
//
//  Created by tuyoo on 12-8-21.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef spblas_c_blas_sparse_namedconstants_h
#define spblas_c_blas_sparse_namedconstants_h

// *** Diagonal entries
#define blas_non_unit_diag 0
#define blas_unit_diag 1

// *** Indices
#define blas_no_repeated_indices 0
#define blas_repeated_indices 1

// *** Use only one half of the matrix: for sym, herm, triang. matrices
#define blas_upper 4
#define blas_lower 8

// *** structured/unstructured matrix
#define blas_irregular  0 //DEFAULT
#define blas_regular  16
#define blas_block_irregular  0 //DEFAULT
#define blas_block_regular  16
#define blas_unassembled  32



// *** Index basis of matrix elements
#define blas_one_base  0 //DEFAULT
#define blas_zero_base  64

// *** Matrix type
#define blas_general  0 //DEFAULT
#define blas_symmetric  128
#define blas_upper_symmetric  132
#define blas_lower_symmetric  136
#define blas_hermitian  256
#define blas_upper_hermitian  260
#define blas_lower_hermitian  264
#define blas_upper_triangular  516
#define blas_lower_triangular  520

// *** For block matrices: specify block-internal storage
#define blas_col_major  0 //DEFAULT
#define blas_row_major  1024

// *** Other constants
#define blas_valid_handle  -1
#define blas_invalid_handle  -10
#define blas_new_handle  -11
#define blas_open_handle  -12
#define blas_real  -2
#define blas_complex  -3
#define blas_integer  -4
#define blas_single_precision  -5
#define blas_double_precision  -6


#endif
