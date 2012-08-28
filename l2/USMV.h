#ifndef USMV_H
#define USMV_H
#include "../handlermanagement/blas_enum.h"
#include "USMV.h"

int BLAS_iusmv(enum blas_trans_type transa,SCALAR_IN alpha,blas_sparse_matrix A,const ARRAY x,int incx, ARRAY y,int incy);
int BLAS_susmv(enum blas_trans_type transa,SCALAR_IN alpha,blas_sparse_matrix A,const ARRAY x,int incx, ARRAY y,int incy);
int BLAS_dusmv(enum blas_trans_type transa,SCALAR_IN alpha,blas_sparse_matrix A,const ARRAY x,int incx, ARRAY y,int incy);
int BLAS_cusmv(enum blas_trans_type transa,SCALAR_IN alpha,blas_sparse_matrix A,const ARRAY x,int incx, ARRAY y,int incy);
int BLAS_zusmv(enum blas_trans_type transa,SCALAR_IN alpha,blas_sparse_matrix A,const ARRAY x,int incx, ARRAY y,int incy);
#endif // USMV_H
