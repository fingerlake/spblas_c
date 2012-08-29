#ifndef USCR_BLOCK_BEGIN_H
#define USCR_BLOCK_BEGIN_H
#include "../handlermanagement/blas_enum.h"

blas_sparse_matrix BLAS_iuscr_block_begin(int Mb,int Nb,int k,int l);
blas_sparse_matrix BLAS_suscr_block_begin(int Mb,int Nb,int k,int l);
blas_sparse_matrix BLAS_duscr_block_begin(int Mb,int Nb,int k,int l);
blas_sparse_matrix BLAS_cuscr_block_begin(int Mb,int Nb,int k,int l);
blas_sparse_matrix BLAS_zuscr_block_begin(int Mb,int Nb,int k,int l);

#endif // USCR_BLOCK_BEGIN_H
