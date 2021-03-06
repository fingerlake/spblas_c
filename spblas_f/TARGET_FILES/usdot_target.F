      module mod_usdot
      use blas_sparse_namedconstants
      interface usdot
      module procedure iusdot
      module procedure susdot
      module procedure dusdot
      module procedure cusdot
      module procedure zusdot
      end interface

      contains
! **********************************************************************
!
! **********************************************************************
#include "integerusdot_source.F"
! **********************************************************************
!
! **********************************************************************
#include "singlePrecisionusdot_source.F"
! **********************************************************************
!
! **********************************************************************
#include "doublePrecisionusdot_source.F"
! **********************************************************************
!
! **********************************************************************
#include "singleComplexusdot_source.F"
! **********************************************************************
!
! **********************************************************************
#include "doubleComplexusdot_source.F"
! **********************************************************************
!
! **********************************************************************
      end module mod_usdot
