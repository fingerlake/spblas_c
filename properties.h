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

      contains      

      subroutine get_descra(descra,descriptor,message,ierr)
      implicit none
      character*11, intent(in) :: descra
      character, intent(in) :: descriptor
      character, intent(out) :: message
      integer, intent(out) :: ierr

void get_descra(char *descra,char descriptor, char &message,int &ierr)
{
    
    ierr = -1;
    message = '';
    switch (descriptor) {
        case('a') //lower,upper or both parts
            message = descra(3:3);break;
        case('b') //base
            message = descra(5:5);break;
        case('d') //unity diagonal stored or not
            message = descra(1:1);break;
        case('f') //internal block storage is row- or column-wise
            message = descra(7:7);break;
        case('r') //repeated indices
            message = descra(2:2);break;
        case('s') //structure of matrix
            message = descra(4:4);break;
        case('t') //matrix type
            message = descra(6:6);break;
        default:return;
            break;
            ierr=0;
    }
    
}



      subroutine set_descra(descra,prpty,ierr)
      character*11, intent(out) :: descra
      integer, intent(in) :: prpty
      integer, intent(out) :: ierr


void set_descra(char *descra,int prpty,int &ierr)
{
    int dummy;
    descra = ''
    ierr = -1
    dummy = prpty;
      //check, if matrix has unstored unity diagonal
      if (dummy%2==1) then
         descra(1:1) = 'U';
      else
          descra(1:1) = 'N';//DEFAULT
    dummy = dummy -dummy%2;
      //repeated indices 
      if (dummy%4==2) then
         descra(2:2) = 'R';
      else
         descra(2:2) = 'U';//DEFAULT
    dummy = dummy - dummy%4;      
      //both/lower/upper half of matrix specified
      select case(mod(dummy,16))
      case(0)
         descra(3:3) = 'B' //DEFAULT
      case(4)
         descra(3:3) = 'U'
      case(8)
         descra(3:3) = 'L'
      case default
         return
      end select
      dummy = dummy - mod(dummy,16)      
      //matrix is irregular/regular/unassembled
      select case(mod(dummy,64))
      case(0)
         descra(4:4) = 'I' //DEFAULT
      case(16)
         descra(4:4) = 'R'
      case(32)
         descra(4:4) = 'U'
      case default
         return
      end select
      dummy = dummy - mod(dummy,64)      
      //index base
      if (mod(dummy,128).eq.64) then
         descra(5:5) = 'C' 
      else 
         descra(5:5) = 'F' //DEFAULT
      end if
      dummy = dummy - mod(dummy,128)      
      // matrix type
      select case(mod(dummy,1024))
      case (0)
         descra(6:6) = 'G' //DEFAULT
      case(128)
         descra(6:6) = 'S'
      case(256)
         descra(6:6) = 'H'
      case(512)
         descra(6:6) = 'T'
      case default
         return
      end select
      dummy = dummy - mod(dummy,1024)      
      //internal block storage
      if (mod(dummy,2048).eq.1024) then
         descra(7:7) = 'R' 
      else 
         descra(7:7) = 'C' //DEFAULT
      end if
      dummy = dummy - mod(dummy,2048)      
      ierr = 0
}
      subroutine get_infoa(infoa,descr,val,ierr)
      implicit none
      integer, dimension(10), intent(in) :: infoa
      character, intent(in) :: descr
      integer, intent(out) :: val,ierr
      val = -1
      ierr = -1
      select case(descr)
      case('b') //base of array indices
         val = infoa(2)
      case('c') //copy or not
         val = infoa(9)
      case('d') //multidim array:row-dim of block
         val = infoa(3)
      case('e') //multidim array:col-dim of block
         val = infoa(4)
      case('f') //Block structure array:row-dim in blocks
         val = infoa(5)
      case('g') //Block structure array:col-dim in blocks
         val = infoa(6)
      case('n') //nnz
         val = infoa(1)
      case default
         return
      end select
      ierr = 0
      end subroutine get_infoa

      subroutine set_infoa(infoa,descr,val,ierr)
      implicit none
      integer, dimension(10), intent(inout) :: infoa
      character*1, intent(in) :: descr
      integer, intent(in) :: val
      integer, intent(out) :: ierr
      ierr = -1
      if (val.lt.0) return 
      select case(descr)
      case('b') //base of array indices
         infoa(2) = val
      case('c') //copy or not
         infoa(9) = val
      case('d') //multidim array:row-dim of blocks
         infoa(3) = val
      case('e') //multidim array:col-dim of blocks
         infoa(4) = val
      case('f') //Block structure array:row-dim in blocks
         infoa(5) = val
      case('g') //Block structure array:col-dim in blocks
         infoa(6) = val
      case('n') //nnz
         infoa(1) = val
      case default
         return
      end select
      ierr = 0
      end subroutine set_infoa
      end module properties
