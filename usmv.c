//!     Description : MV MULTIPLICATION, CHOOSES APPROPRIATE SUBROUTINES
/*
 * 
 */
iusmv(int a, int *x, INOUT int *y, int *ierr, int transa, int alpha)
{
    int *z;
    ispmat *dspmtx;
    int transa_work, alpah_work;
    *ierr = -1;
    if ( ) //transa has a value
        transa_work = transa; 
    else
        transa_work = ORIGIN_MATRIX;
    if () //
        alpah_work = alpha;
    else
        alpah_work = 1;
    if(alpah_work == 0)
    ;    //do nothing
    else
    {
        accessdata_isp(dspmtx, a, ierr);
        //z = 
       switch(transa_work)
       {
           case  ORGIN_MATRIX:
               switch (dspmatx->FIDA)
               {
                   case 'COO':
                       rmbv_coo(dspmtx, x, z , ierr);
                   case 'CSC':
                       rmbv_csc(dspmtx, x, z , ierr);
                   case 'DIA':
                       rmbv_dia(dspmtx, x, z , ierr);
                   case 'BCO':
                       rmbv_bco(dspmtx, x, z , ierr);
                   case 'BSC':
                       rmbv_bsc(dspmtx, x, z , ierr);
                   case 'BSR':
                       rmbv_bsr(dspmtx, x, z , ierr);
                   case 'BDI':
                       rmbv_bdi(dspmtx, x, z , ierr);
                   case 'VBR':
                       rmbv_vbr(dspmtx, x, z , ierr);
                    case default:
                       return -1;

               }
               break;
        case TEANSP_MATRIX:
               switch (dspmatx->FIDA)
               {
                   case 'COO':
                       lmbv_coo(dspmtx, x, z , ierr);
                   case 'CSC':
                       lmbv_csc(dspmtx, x, z , ierr);
                   case 'DIA':
                       lmbv_dia(dspmtx, x, z , ierr);
                   case 'BCO':
                       lmbv_bco(dspmtx, x, z , ierr);
                   case 'BSC':
                       lmbv_bsc(dspmtx, x, z , ierr);
                   case 'BSR':
                       lmbv_bsr(dspmtx, x, z , ierr);
                   case 'BDI':
                       lmbv_bdi(dspmtx, x, z , ierr);
                   case 'VBR':
                       lmbv_vbr(dspmtx, x, z , ierr);
                    case default:
                       return -1;
               }
               break;
       } 

         if(transa_work == ORIGIN_MATRIX) 
            y = alpha_work * z + y ; //do each :need a for here
         else
            y = alpha_work * ( (z)) + y ; //is there any difference ?
    }
}
