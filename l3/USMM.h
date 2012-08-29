#ifndef USMM_H
#define USMM_H

#include "../handlermanagement/blas_enum.h"
int BLAS_iusmm(enum blas_order_type order,enum blas_trans_type transa,int nrhs,SCALAR_IN alpha,blas_sparse_matrix A,const ARRAY B,int ldb,ARRAY C,int ldc);

int BLAS_susmm(enum blas_order_type order,enum blas_trans_type transa,int nrhs,SCALAR_IN alpha,blas_sparse_matrix A,const ARRAY B,int ldb,ARRAY C,int ldc);

int BLAS_dusmm(enum blas_order_type order,enum blas_trans_type transa,int nrhs,SCALAR_IN alpha,blas_sparse_matrix A,const ARRAY B,int ldb,ARRAY C,int ldc);

int BLAS_cusmm(enum blas_order_type order,enum blas_trans_type transa,int nrhs,SCALAR_IN alpha,blas_sparse_matrix A,const ARRAY B,int ldb,ARRAY C,int ldc);

int BLAS_zusmm(enum blas_order_type order,enum blas_trans_type transa,int nrhs,SCALAR_IN alpha,blas_sparse_matrix A,const ARRAY B,int ldb,ARRAY C,int ldc);
#endif // USMM_H
