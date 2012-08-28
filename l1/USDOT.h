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

void BLAS_xusdote(enmu_blas_conj_type conj,int nz,const ARRAY x,const int *index, const ARRAY ,int incy,SCALAR_INOUT r,enmu_blas_base_type index_base);


#endif // USDOT_H
