#ifndef HASH_H
#define HASH_H
#include "blas_sparse_namedconstants.h"
#include <malloc.h>
#include <iostream>
// **********************************************************************
//     Author : C. Voemel
//
//     Date of last modification : 3.1.2002
//
//     Description : A hash table for 'COO' and 'BCO' triangular solver
// **********************************************************************




typedef struct
{
  int jndx,val_pos;
  capsule* pntr;
}capsule;
typedef struct
{
  capsule* pntr;
}cappntr;



capsule* hash;
cappntr* hash_top;


void setup_hash(int n,int &ierr){
  int i;
  ierr=-1;
  hash=(capsule *)malloc (sizeof(capsule)*n);
  if(hash!=NULL) ierr=0;//ierr=0 if malloc failed
  if (ierr!=0)
    {
      ierr=blas_error_memalloc;
      return;
    }
  hash_top=(cappntr *)malloc (sizeof(cappntr)*n);
  if (ierr!=0)
    {
      ierr=blas_error_memalloc;
      return;
    }
  for(i=0;i<n;i++)
    {     hash[i]->pntr=NULL;
      hash->jndx= -1;
      hash->val_pos= -1;
      hash_top[i]->pntr=hash[i];
    }
  ierr = 0;
}

void new_capsule_main(int indx,int jndx,int pos,int &ierr){
  capsule* cap;
  int ierr = -1;
  //判断indx是否越界
  if ((indx<lbound(hash,1))||(indx>ubound(hash,1))) then
      return;

  if(indx==jndx)
    {      hash[indx]->val_pos = pos;
      hash[indx]->jndx = jndx;
    }
  else
    {
      cap=(capsule *)malloc(sizeof(capsule));
      if(cap!=NULL) ierr=0;
      if (ierr!=0)
        {
          ierr=blas_error_memalloc;
          return;
        }
      cap->val_pos = pos;
      cap->jndx = jndx;
      cap->pntr=NULL;
      hash_top[indx]->pntr->pntr =cap;
      hash_top[indx]->pntr =cap;
    }
  ierr = 0;
}


void print_hash(){
  int i;
  capsule* dummy;
  do i=lbound(hash,1),ubound(hash,1)
  {
    write(*,*)'print hash(',i,') '
        dummy => hash(i)
        while(dummy->pntr)!=NULL)
    {
        write(*,*)'jndx : ', dummy%jndx
        write(*,*)'val_pos : ',dummy%val_pos
        dummy => dummy%pntr
        end do
  }
    write(*,*)'jndx : ', dummy%jndx
        write(*,*)'val_pos : ',dummy%val_pos
}
}
void remove_hash(ierr)
implicit none
integer, intent(out) :: ierr
integer :: i
ierr = -1
    do i=lbound(hash,1),ubound(hash,1)
do while(.not.associated(hash_top(i)%pntr,hash(i)))
call del_capsule(i,ierr)
if (ierr.ne.0) then
ierr=blas_error_memdeloc
    return
    end if
    end do
    end do
    deallocate(hash,hash_top,STAT=ierr)
    if (ierr.ne.0) then
    ierr=blas_error_memdeloc
    return
    end if
    } remove_hash

void del_capsule(nmb,ierr)
implicit none
integer, intent(in) :: nmb
integer, intent(out) :: ierr
capsule* dummy
dummy => hash(nmb)
    if (associated(dummy,hash_top(nmb)%pntr)) then
    ierr = -1
    return
    end if
    do while(.not.associated(dummy%pntr,hash_top(nmb)%pntr))
    dummy => dummy%pntr
    end do
    hash_top(nmb)%pntr => dummy
    deallocate(dummy%pntr,STAT=ierr)
    if(ierr.ne.0) then
    ierr=blas_error_memdeloc
    return
    end if
    } del_capsule

end module mod_hash




#endif // HASH_H
