//
//  types.h
//  spblas_c
//
//  Created by tuyoo on 12-8-21.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef spblas_c_types_h
#define spblas_c_types_h
#include "blas_sparse_namedconstants.h"
// **********************************************************************
//    Author : luoyulong 
//
//    Date of last modification : 2012.08.22
//      
//     Description : CONTAINS THE BASIC TYPES FOR SPARSE MATRICES/VECTORS
// **********************************************************************
template <typename T>
struct COMPLEX
{
    T x;
    T y;
}

struct ISPMAT
{
    int M,K;
    char FIDA[5] ;
    char DESCRA[11];
    int INFOA[10];
    int * * A;
    int * IA1,IA2,PB,PE,BP1,BP2;
}

struct DSPMAT
{
    int M,K;
    char FIDA[5] ;
    char DESCRA[11];
    int INFOA[10];
    double * * A;
    int * IA1,IA2,PB,PE,BP1,BP2;
}


struct SSPMAT
{
    int M,K;
    char FIDA[5] ;
    char DESCRA[11];
    int INFOA[10];
    float * * A;
    int * IA1,IA2,PB,PE,BP1,BP2;
}

struct CSPMAT
{
    int M,K;
    char FIDA[5] ;
    char DESCRA[11];
    int INFOA[10];
    COMPLEX<float> * * A;
    int * IA1,IA2,PB,PE,BP1,BP2;
}
struct ZSPMAT
{
    int M,K;
    char FIDA[5] ;
    char DESCRA[11];
    int INFOA[10];
    COMPLEX<double> * * A;
    int * IA1,IA2,PB,PE,BP1,BP2;
}

#endif
