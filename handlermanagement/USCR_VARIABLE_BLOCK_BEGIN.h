#ifndef USCR_VARIABLE_BLOCK_BEGIN_H
#define USCR_VARIABLE_BLOCK_BEGIN_H
#include "../handlermanagement/blas_enum.h"
blas_sparse_matrix BLAS_iuscr_variable_block_begin(int Mb,int Nb,const int *k,const int *l);
blas_sparse_matrix BLAS_suscr_variable_block_begin(int Mb,int Nb,const int *k,const int *l);
blas_sparse_matrix BLAS_duscr_variable_block_begin(int Mb,int Nb,const int *k,const int *l);
blas_sparse_matrix BLAS_cuscr_variable_block_begin(int Mb,int Nb,const int *k,const int *l);
blas_sparse_matrix BLAS_zuscr_variable_block_begin(int Mb,int Nb,const int *k,const int *l);

#endif // USCR_VARIABLE_BLOCK_BEGIN_H
