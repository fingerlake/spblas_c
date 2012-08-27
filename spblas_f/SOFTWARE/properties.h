// **********************************************************************
//     Author : luoyulong
//
//     Date of last modification : 8.22.2012 
//      
//     Description : CONTAINS ALL CONSTANTS USED FROM THE LIBRARY
//                   CONTAINS ROUTINES FOR MANIPULATING THE ARRAYS
//                            INFOA & DESCRA OF THE DERIVED DATATYPE
//                            FOR SPARSE MATRICES
//                   get_descra:returns matrix properties stored as chars
//                   set_descra:translates integer in character descript.
//                             of sparse matrix, used by uscr
//                   get_infoa:returns matrix properties stored as ints
//                   set_infoa:sets matrix properties stored as ints
//
// **********************************************************************

#include "blas_sparse_namedconstants.h"

// *** Description of basic derived data types
#define int no_of_types  5
#define int ISP_MATRIX  0
#define int DSP_MATRIX  1
#define int SSP_MATRIX  2
#define int CSP_MATRIX  3
#define int ZSP_MATRIX  4

// *** Determine, if array indices start at 0 or 1
#define int C_BASE  0
#define int F_BASE  1
// *** Determine, if matrix is reference or copy of original data
#define int REF_OF_SOURCE  0
#define int COP_OF_SOURCE  1
// *** Determine, if the matrix is needed or its (conjugate) transpose
#define int ORIGIN_MATRIX  0
#define int TRANSP_MATRIX  1
#define int HERMIT_MATRIX  2

int get_descra(IN char[] descra, IN int descriptor, OUT char *message, OUT int *ierr)
{
    *ierr = -1;
    message ='';
    switch (descriptor)
    {
        case ('a')
            message=descra[2];
            break;
        case ('b')
            message=descra[4];
            break;
        case ('d')
            message=descra[0];
            break;
        case ('f')
            message=descra[6];
            break;
        case ('r')
            message=descra[1];
            break;
        case('s')
            message=descra[3];
            break;
        case('t')
            message=descra[5];
            break;
        case default:
            return -1;
            *ierr = 0;
            return 0;
    }
}

void set_descra(OUT char[] descra, IN int prpty, OUT int *istat)
{
    int dummy;
    decra = '';
    *ierr = -1;
    dummpy = prpty;
    //check if matrix has unstroed unity diagomal
    if (dummy % 2 == 1)
        decra[0]='U';
    else
        decra[0]='N';
    dummy = dummy - dummy%2;
    // repeated indices
    if (dummy%4 == 2)
        decra[1]='R';
    else
        decra[1]='U' //default
    dummy = dummy - dummy % 4;
    //both/lower/upper half of matrix specified
    switch (dummy % 16)
    {
        case (0):
            decra[2] = 'B' //default
            break;
        case (4):
            decra[2] = 'U' 
            break;
        case (8):
            decra[2] = 'L' 
            break;
        case default:
            return -1;
        dummy = dummy - dummy %16;
    //matrix is irregular/reguarl/unassebmled
    switch (dummy % 64)
    {
        case (0):
            decra[3] = 'I' //default
            break;
        case (16):
            decra[3] = 'R' 
            break;
        case (32):
            decra[3] = 'U' 
            break;
        case default:
            return -1;
    }
    dummy = dummy - dummy % 64;
    //index base
    if (dummy % 128  ==64)
        decra[4]='C';
    eles
        decra[4]='F';
    }
    dummy = dummy - dummy % 128;
    //matrix type
    switch (dummy % 1024)
    {
        case 0:
            decra[5] = 'G';
            break;
        case 128:
            decra[5] = 'S' //default
            break;
        case 256:
            decra[5] = 'H' 
            break;
        case (512):
            decra[5] = 'T' 
            break;
        case default:
            return -1;
    }
    dummy = dummy - dummy % 1024;
    //index base
    if (dummy % 2048 == 1024)
        decra[6]='R';
    eles
        decra[6]='C';
    }
   *ierr = 0; 
}

int get_infoa(IN int[10] infoa, IN int descr, OUT int *val, OUT int *ierr)
{
    *val =  -1;
    *ierr = -1;
    switch (descr)
    {
        case 'b': //base of array indices
            *val = infoa[1];
            break;
        case 'c':  //copy or not
            *val = infoa[8];
            break;
        case 'd':  //multidim array:row-dim of block 
            *val = infoa[2];
            break;
        case 'e': //multidim arrau: col-dim of block 
            *val = infoa[3];
            break;
        case 'f': //block structure array: row-dim inblocks
            *val = infoa[4];
            break;
        case 'g': //block structure array: col-dim inblocks
            *val = infoa[5];
            break;
        case 'n': 
            *val = infoa[0];
            break;
        case default:
            return -1;
    }
    return 0;
}
//todolater
int set_infoa(INOUT char[10] infoa, IN char descr,IN int val,OUT int *ierr)
{
}

