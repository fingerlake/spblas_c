#ifndef USCR_INSERT_COL_H
#define USCR_INSERT_COL_H
#include "../handlermanagement/blas_enum.h"
int BLAS_iuscr_insert_col(blas_sparse_matrix A,int j,int nz,const ARRAY val ,const int *indx);
int BLAS_suscr_insert_col(blas_sparse_matrix A,int j,int nz,const ARRAY val ,const int *indx);
int BLAS_duscr_insert_col(blas_sparse_matrix A,int j,int nz,const ARRAY val ,const int *indx);
int BLAS_cuscr_insert_col(blas_sparse_matrix A,int j,int nz,const ARRAY val ,const int *indx);
int BLAS_zuscr_insert_col(blas_sparse_matrix A,int j,int nz,const ARRAY val ,const int *indx);
#endif // USCR_INSERT_COL_H
