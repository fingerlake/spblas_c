#ifndef USDOT_H
#define USDOT_H
#include "handlermanagement/blas_enum.h"
// **********************************************************************
//     Author : luoyulong
//
//     Date of last modification : 8.22.2012
//
//     Description : sparse dot product
//
// **********************************************************************

void BLAS_iusdote(enmu_blas_conj_type conj,int nz,const ARRAY x,const int *index, const ARRAY ,int incy,SCALAR_INOUT r,enmu_blas_base_type index_base);


void BLAS_susdote(enmu_blas_conj_type conj,int nz,const ARRAY x,const int *index, const ARRAY ,int incy,SCALAR_INOUT r,enmu_blas_base_type index_base);

void BLAS_dusdote(enmu_blas_conj_type conj,int nz,const ARRAY x,const int *index, const ARRAY ,int incy,SCALAR_INOUT r,enmu_blas_base_type index_base);

void BLAS_cusdote(enmu_blas_conj_type conj,int nz,const ARRAY x,const int *index, const ARRAY ,int incy,SCALAR_INOUT r,enmu_blas_base_type index_base);

void BLAS_zusdote(enmu_blas_conj_type conj,int nz,const ARRAY x,const int *index, const ARRAY ,int incy,SCALAR_INOUT r,enmu_blas_base_type index_base);
#endif // USDOT_H
