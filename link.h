//
#ifndef spblas_c_link_h
#define spblas_c_link_h
#include <malloc.h>
#include "types.h"
#include "properties.h"
// **********************************************************************
//     Author : luoyulong
//     Date of last modification : 8.29.2012
//     Description : THE PRINCIPAL DATA STRUCTURE
//
//                   new: creates new node WITHOUT initialization
//                   del: frees unused memory, does NOT care if there
//                        is other memory that should be freed first
//                   accessdata:  returns a pointer to the matrix
//                        inside the relevant node
// **********************************************************************

typedef struct
{
  ISPMAT contents;
  int number;
  isp_linknode * pntr;
}isp_linknode;

typedef struct
{
  SSPMAT contents;
  int number;
  ssp_linknode * pntr;
}ssp_linknode;

typedef struct
{
  DSPMAT contents;
  int number;
  dsp_linknode * pntr;
}dsp_linknode;

typedef struct
{
  CSPMAT contents;
  int number;
  csp_linknode * pntr;
}csp_linknode;

typedef struct
{
  ZSPMAT contents;
  int number;
  zsp_linknode * pntr;
}zsp_linknode;


isp_linknode * new_isp(int &ierr)
{
  ierr=-1;
  isp_linknode * sp_l=(isp_linknode *)malloc (sizeof(isp_linknode));
  sp_l->number=ISP_MATRIX;

  sp_l->contents.A=NULL;
  sp_l->contents.IA1=NULL;
  sp_l->contents.IA2=NULL;
  sp_l->contents.PB=NULL;
  sp_l->contents.PE=NULL;
  sp_l->contents.BP1=NULL;
  sp_l->contents.BP2=NULL;

  sp_l->contents.FIDA='';
  sp_l->contents.DESCRA='';
  sp_l->contents.INFOA=0;

  sp_l->pntr=NULL;
return sp_l;
}
void del_isp(isp_linknode * sp_l,int &ierr)
{
  ierr=0;
  if(sp_l!=NULL) delete sp_l;
  else ierr=-1;
}

ISPMAT * accessdata_isp(isp_linknode* sp_l,int &ierr)
{
  if(isp_linknode!=NULL)
    {
      ierr=0;
      return &(sp_l->contents);
    }
  else
    {
      ierr=-1;
      return NULL;
    }
}



ssp_linknode * new_ssp(int &ierr)
{
  ierr=-1;
  ssp_linknode * sp_l=(ssp_linknode *)malloc (sizeof(ssp_linknode));
  sp_l->number=SSP_MATRIX;

  sp_l->contents.A=NULL;
  sp_l->contents.IA1=NULL;
  sp_l->contents.IA2=NULL;
  sp_l->contents.PB=NULL;
  sp_l->contents.PE=NULL;
  sp_l->contents.BP1=NULL;
  sp_l->contents.BP2=NULL;

  sp_l->contents.FIDA='';
  sp_l->contents.DESCRA='';
  sp_l->contents.INFOA=0;

  sp_l->pntr=NULL;
return sp_l;
}
void del_ssp(ssp_linknode * sp_l,int &ierr)
{
  ierr=0;
  if(sp_l!=NULL) delete sp_l;
  else ierr=-1;
}

SSPMAT * accessdata_ssp(ssp_linknode* sp_l,int &ierr)
{
  if(sp_l!=NULL)
    {
      ierr=0;
      return &(sp_l->contents);
    }
  else
    {
      ierr=-1;
      return NULL;
    }
}

dsp_linknode * new_dsp(int &ierr)
{
  ierr=-1;
  dsp_linknode * sp_l=(dsp_linknode *)malloc (sizeof(dsp_linknode));
  sp_l->number=DSP_MATRIX;

  sp_l->contents.A=NULL;
  sp_l->contents.IA1=NULL;
  sp_l->contents.IA2=NULL;
  sp_l->contents.PB=NULL;
  sp_l->contents.PE=NULL;
  sp_l->contents.BP1=NULL;
  sp_l->contents.BP2=NULL;

  sp_l->contents.FIDA='';
  sp_l->contents.DESCRA='';
  sp_l->contents.INFOA=0;

  sp_l->pntr=NULL;
return sp_l;
}
void del_dsp(dsp_linknode * sp_l,int &ierr)
{
  ierr=0;
  if(sp_l!=NULL) delete sp_l;
  else ierr=-1;
}

DSPMAT * accessdata_dsp(dsp_linknode* sp_l,int &ierr)
{
  if(sp_l!=NULL)
    {
      ierr=0;
      return &(sp_l->contents);
    }
  else
    {
      ierr=-1;
      return NULL;
    }
}

csp_linknode * new_csp(int &ierr)
{
  ierr=-1;
  csp_linknode * sp_l=(csp_linknode *)malloc (sizeof(csp_linknode));
  sp_l->number=CSP_MATRIX;

  sp_l->contents.A=NULL;
  sp_l->contents.IA1=NULL;
  sp_l->contents.IA2=NULL;
  sp_l->contents.PB=NULL;
  sp_l->contents.PE=NULL;
  sp_l->contents.BP1=NULL;
  sp_l->contents.BP2=NULL;

  sp_l->contents.FIDA='';
  sp_l->contents.DESCRA='';
  sp_l->contents.INFOA=0;

  sp_l->pntr=NULL;
return sp_l;
}
void del_csp(csp_linknode * sp_l,int &ierr)
{
  ierr=0;
  if(sp_l!=NULL) delete sp_l;
  else ierr=-1;
}

CSPMAT * accessdata_csp(csp_linknode* sp_l,int &ierr)
{
  if(sp_l!=NULL)
    {
      ierr=0;
      return &(sp_l->contents);
    }
  else
    {
      ierr=-1;
      return NULL;
    }
}

zsp_linknode * new_zsp(int &ierr)
{
  ierr=-1;
  zsp_linknode * sp_l=(zsp_linknode *)malloc (sizeof(zsp_linknode));
  sp_l->number=ZSP_MATRIX;

  sp_l->contents.A=NULL;
  sp_l->contents.IA1=NULL;
  sp_l->contents.IA2=NULL;
  sp_l->contents.PB=NULL;
  sp_l->contents.PE=NULL;
  sp_l->contents.BP1=NULL;
  sp_l->contents.BP2=NULL;

  sp_l->contents.FIDA='';
  sp_l->contents.DESCRA='';
  sp_l->contents.INFOA=0;

  sp_l->pntr=NULL;
return sp_l;
}
void del_zsp(zsp_linknode * sp_l,int &ierr)
{
  ierr=0;
  if(sp_l!=NULL) delete sp_l;
  else ierr=-1;
}

ZSPMAT * accessdata_zsp(zsp_linknode* sp_l,int &ierr)
{
  if(sp_l!=NULL)
    {
      ierr=0;
      return &(sp_l->contents);
    }
  else
    {
      ierr=-1;
      return NULL;
    }
}
#endif
