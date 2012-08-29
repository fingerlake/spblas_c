#ifndef USCR_INSERT_ENTRIES_H
#define USCR_INSERT_ENTRIES_H
#include "../handlermanagement/blas_enum.h"

int BLAS_iuscr_insert_entries(blas_sparse_matrix A,int nz,const ARRAY val,const int *indx,const int *jndx);


int BLAS_suscr_insert_entries(blas_sparse_matrix A,int nz,const ARRAY val,const int *indx,const int *jndx);


int BLAS_duscr_insert_entries(blas_sparse_matrix A,int nz,const ARRAY val,const int *indx,const int *jndx);


int BLAS_cuscr_insert_entries(blas_sparse_matrix A,int nz,const ARRAY val,const int *indx,const int *jndx);


int BLAS_zuscr_insert_entries(blas_sparse_matrix A,int nz,const ARRAY val,const int *indx,const int *jndx);
#endif // USCR_INSERT_ENTRIES_H
