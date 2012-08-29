#ifndef BLAS_ENUM_H
#define BLAS_ENUM_H

#define blas_conj_type int


#define IN 
#define OUT
#define INOUT

#define TRUE 1
#define FALSE 0

// enum matrix structure 
// coo, csr, etc.

//enum 
#define SCALAR_IN int 
#define ARRAY int *
enum blas_trans_type 
{
  ORIGIN_MATRIX,
  TRANSP_MATRIX
};
enum blas_base_type
{

};
enum blas_order_type
{

};
typedef struct
{

} blas_sparse_matrix ;


#endif // BLAS_ENUM_H
