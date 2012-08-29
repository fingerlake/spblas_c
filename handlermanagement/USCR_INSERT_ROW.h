#ifndef USCR_INSERT_ROW_H
#define USCR_INSERT_ROW_H
#include "../handlermanagement/blas_enum.h"
int BLAS_iuscr_insert_row(blas_sparse_matrix A,int i,int nz,const ARRAY val,const int *indx);
int BLAS_suscr_insert_row(blas_sparse_matrix A,int i,int nz,const ARRAY val,const int *indx);
int BLAS_duscr_insert_row(blas_sparse_matrix A,int i,int nz,const ARRAY val,const int *indx);
int BLAS_cuscr_insert_row(blas_sparse_matrix A,int i,int nz,const ARRAY val,const int *indx);
int BLAS_zuscr_insert_row(blas_sparse_matrix A,int i,int nz,const ARRAY val,const int *indx);
#endif // USCR_INSERT_ROW_H
