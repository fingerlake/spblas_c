#ifndef USCR_INSERT_BLOCK_H
#define USCR_INSERT_BLOCK_H
#include "../handlermanagement/blas_enum.h"

int BLAS_iuscr_insert(blas_sparse_matrix A,SCALAR_IN val ,int i,int j);
int BLAS_suscr_insert(blas_sparse_matrix A,SCALAR_IN val ,int i,int j);
int BLAS_duscr_insert(blas_sparse_matrix A,SCALAR_IN val ,int i,int j);
int BLAS_cuscr_insert(blas_sparse_matrix A,SCALAR_IN val ,int i,int j);
int BLAS_zuscr_insert(blas_sparse_matrix A,SCALAR_IN val ,int i,int j);
#endif // USCR_INSERT_BLOCK_H
