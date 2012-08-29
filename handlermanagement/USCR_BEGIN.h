#ifndef USCR_BEGIN_H
#define USCR_BEGIN_H
#include "../handlermanagement/blas_enum.h"

blas_sparse_matrix BLAS_iuscr_begin(int m,int n);
blas_sparse_matrix BLAS_suscr_begin(int m,int n);
blas_sparse_matrix BLAS_duscr_begin(int m,int n);
blas_sparse_matrix BLAS_cuscr_begin(int m,int n);
blas_sparse_matrix BLAS_zuscr_begin(int m,int n);
#endif // USCR_BEGIN_H
