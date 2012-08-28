int iINS_entry(IN i_matrix * pmatrix, IN int val, IN int i, IN int j, OUT int *istat)
{
    i_inelement *pelement;
    int nmb_element, ind;
    *istat = -1;
    if ( i > pmatrix->DIM[0] | j > pmatrix->DIM[1])
    {
        *istat = blas_error_param;
        return -1;
    }
    else
    {
        new_i_element(pmatrix, nmb_element, istat);
    if ( !*istat )
        return -1;
    i_element_num(&ind, pmatrix, i,j,istat);
    if (ind == 0) //doesnot need to insert
    {
        access_element(pelement, nmb_element, pmatrix,istat);
        if (*istat != 0)
            return -1;
        pelement->pntin.value = val;
        pelement->pntin.row_ind = i;
        pelement->pntin.col_ind = j;
    }
    else // ?
    {
        access_element(pelement, ind, pmatrix, istat);
        if (*istat != 0)
            return -1;
        pelement->pntin.value = pelement->pntin.value + val;
        dealloc_i_element(nmb_element, pmatrix, istat);
        if ( ! *istat)
            return -1;
    }
    }
    return 0;
}

int iINS_block(IN i_matrix pmatrix, int **value, int i, int j, int *stat)
{
    int nmb_element, ind, ierr;
    int tmp;
    int **vv; //
    i_inelement * pelement;
    int s_row, s_cols;
    *istat = -1;
    //s_rows = row of val//
    //s_cols = col of val 
    vv = (int **)malloc(sizeof(int)*s_rows);
    for (tmp =0 ; tmp < s_rows; tmp ++)
        vv[i] = (int *)malloc(sizeof(int)*s_cols);
    //set ierr flag
    if ( ierr != 0)
        *istat =  blas_error_memalloc;
        return -1;
    if (i >  pmatrix->DIM[2] | j > pmatrix->DIM[3] | s_rows != pmatrix->DIM[4] |s_cols != pmatrix->DIM[5])
    {
        *istat = blas_error_param
        return -1;
    }
    else
    {
        new_i_element(pmatrix, nmb_element, istat);
        i_element_num (ind, pmatrix,i,j,istat);
        if (ind == 0) //doesnot need to insert
        {
            access_element(pelement, nmb_element, pmatrix,istat);
            if (*istat != 0)
                return -1;
            pelement->blin.value = val;
            pelement->blin.row_ind = i;
            pelement->blin.col_ind = j;
    }
    else // ?
    {
        access_element(pelement, ind, pmatrix, istat);
        if (*istat != 0)
            return -1;
        vv = vv + val; //all the elements are added ?
        pelement->blin.value = pelement->blin.value + val;
   //     dealloc_i_element(nmb_element, pmatrix, istat);
        if ( ! *istat)
            return -1;
    }
    }
     //   free();
}

int i_INs_bl_entr (IN i_matrix pmatrix, int val, int i, int j, int *stat)
{
    
}

iINS_varblock(i_matrix vpmatrix, int **val, int i, int j, int *stat)
{
    int nmb_element, int ind;
    int ierr;
    int **vv;
    i_inelement

    int nmb_element, ind, ierr;
    int tmp;
    int **vv; //
    i_inelement * pelement;
    int s_row, s_cols;
    *istat = -1;
    //s_rows = row of val//
    //s_cols = col of val 
    vv = (int **)malloc(sizeof(int)*s_rows);
    for (tmp =0 ; tmp < s_rows; tmp ++)
        vv[i] = (int *)malloc(sizeof(int)*s_cols);
    //set ierr flag
    if ( ierr != 0)
        *istat =  blas_error_memalloc;
        return -1;
    if (i >  pmatrix->DIM[2] | j > pmatrix->DIM[3] |s_rows != vpmatrix->sub_rows[i-1]  | s_cols != vpmatrix->sub_cols[j-1]) 
    {
        *istat = blas_error_param
        return -1;
    }
    else
    {
        new_i_element(pmatrix, nmb_element, istat);
        i_element_num (ind, vpmatrix,i,j,istat);
        if (ind == 0) //doesnot need to insert
        {
            access_element(pelement, nmb_element, pmatrix,istat);
            if (*istat != 0)
                return -1;
            pelement->blin.value = val;
            pelement->blin.row_ind = i;
            pelement->blin.col_ind = j;
            for(k=i; k <vpmatix->DIM[2]; k++)
                vpmatrix->trb[k]=vpmarix->trb[k] + 1; //
            for (k=1; k<vpmatrix->DIM[2] -1; k++)
                vpmatrix->tre[k] = vpmatrix->trb[k+1];
            vpmatrix->tre[vpmatrix->DIM[2]]=nmb_element +1;
        }
        else // ? ind != 0
        {
            access_element(pelement, ind, pmatrix, istat);
            if (*istat != 0)
                return -1;
            vv = vv + val; //all the elements are added ?
            pelement->blin.value = pelement->blin.value + val;
    //     dealloc_i_element(nmb_element, pmatrix, istat);
            if ( ! *istat)
                return -1;
        }
    }
}

iINS_varbl_entr(i_matrix vpmatrix, int val ,int i, int j, int *istat)
{
    int **vall;
    int ii,jj,k,p,ind1, ind2, vall_ind2, ierr;
    ind1 = 0;
    //determine the row of block entring
    for(k=0; k<vpmatrix->DIM[2]; k++)
    {
        ind1 = ind1 + vpmatrix->subrows[k]; //subrows should be the row of each block
        if(ind1 > = i)
            return -1;
    }
    if (k <= vpmatrix->DIM[2])
    {
        ii = k;
        vall_indx1 = i - (ind1 -vpmatrix->sub_row[k]);
    }
    else
    {
        *istat = blas_error_param;
        return -1;
    }
    //determine the col of block entring
    ind2 = 0;
    for (p=1; p<vpmatrix->DIM[2]; p++)
    {
       ind2 = ind2 + vpmatrix->sub_cols[p];
      if(ind2 >= j)
          return -1; //break not return
    }
    if (p <= vpmatrix->DIM[3])
    {
        jj = p;
        vall_ind2 = j - (ind2 -vpmatrix->sub_cols[p]);
    }
    else
    {

    }
    //vall = (int **)malloc(sizeof(int)*sub_rows[ii]);
    //two dimmension
    vall();

    
}

iuscr_varend(int *a, int prpty, int *istat)
{
    int m,n, ierr, ind, kb, mb;
    int *blindx, indx, rpntr, cpntr, bpntrb, bpntre;
    int *val;
    int size_val, val_ind, indx_ind, bind_ind, ii, jj, i,j;
    i_matrix pmatrix;
    i_inelement pelement;
    *istat = -1;
    access(pamtrix, *a, istat);
    //
    mb = pmatrix->DIM[2];
    kb = pmatrix->DIM[3];
    //determine sizeof  val, m, n
    size_val = 0;
    m = 0;
    n = 0;
    for (i=1; i<pmatrix->DIM[2])
    {
        for(j=1; j<pmatrix->DIM[3])
        {
            i_element_num(ind, pmatrix, i, j, ierr)
            {
                if(ind == 0)
                {
                    access_element(pelement, ind, pmatrix, istat);
                    //
                    size_val = size_val + pamtrix->sub_rows[i]*pmatrix->sub_cols[j];
                }

            }
        }
    }    
    for(i=1; i< pmatrix->DIM[2]; i++)
    {
        m = m+pmatrix->sub_rows[i];
    }
    for(j=1; j < pmatrix->DIM[3]; j++)
    {
        n = n + pmatrix->sub_cols[j];
    }
    //allocate 3 varaibles
    //val size_val
    //indx 
    val = 0;
    //fill val, ind, blindx
    val_ind = 0;
    blindx_ind = 0;
    for (i = 1; i<pmatrix->DIM[2], i++) //how many blocks in row 
    {
        for(j=1; j<pmatrix->DIM[3]; j++) // how many blocks in col
        {
            i_element_num(ind, pmatrix,i, j,istat);
            //
            if (ind != 0)
            {
                access_element(pelement, ind, pmatrix, istat);
                //
                for(jj = 1; jj < pmatrix->sub_cols[j]; jj++)
                    for(ii = 1; ii < pmatrix->sub_rows[i]; ii++)
                    {
                        val_ind = val_ind + 1;
                        val[val_ind] = pelement->vblin->val[ii][jj];
                    }

                bindx_ind =  blindx_inx + 1;
                bindx[blinx_ind] = j;
                indx_ind = indx_ind + 1;
                indx[indx_ind] = indx[indx_ind - 1] + pmatrix->sub_rows[i]*pmatrix->sub_cols[j];
            }
        }
    }
    //fill rpntr, cpntr, bpntrb, bpntre
    rpntr=(int *)malloc(sizeof(int) * (pmatrix->DIM[2] + 1)); //row
    cpntr=(int *)malloc(sizeof(int) * (pmatrix->DIM[3] + 1)); //col 
    bpntrb=(int *)malloc(sizeof(int) * (pmatrix->DIM[2] ));
    bpntre=(int *)malloc(sizeof(int) * (pmatrix->DIM[2] ));
    //
    rpntr[0] = 1;
    for (i = 2; i<pmatrix->DIM[2] + 1; i++)
        rpntr[i] = rpntr[i-1] + pmatrix->sub-rows[i-1]; //row start 
    cpntr[0] = 1;
    for (j = 2; j<pmatrix->DIM[3] + 1; j++)
        cpntr[i] = cpntr[j-1] + pmatrix->sub-cols[j-1]; //row start 
    for(i = 1; i < pmatrix->trb[i]; i++)
    {
        bpntrb[i] = pmatrix->trb[i];
        bpntre[i] = pmatrix->tre[i]; //where
    }
    //release
      iuscr_vbr (m,n,val,indx,bindx,rpntr,cpntr, bpntrb,bpntre,mb,kb,prpty,istat,a);

}

iuscr_normend(int *a , int prpty, int *istat)
{
    int m, n, nnz;
    int *indx, *jndx;
    int *val;
    int nmb_element, i, ierr;
    i_matrix *pmatrix;
    i_inelement * pelement;
    access_matrix(pmatrix, a, istat);
    m = pmatrix->DIM[0]; //number of rows
    n = pmatrix->DIM[1]; //number of cols
    nnz = patrix->i_element_start ->number;
    val = (int *)malloc(sizeof(int)*nnz);
    indx = (int *)malloc(sizeof(int)*nnz);
    jndx = (int *)malloc(sizeof(int)*nnz);
    //
    nmb_element = nnz +1;
    for (i = 0; i < nnz; i++)
    {
        access_element(pelement, nmb_element - i, pmatrix, istat);
        val[i] = pelement->pntin.value;
        indx[i] = pelement->pntin.row_ind;
        jndx[i] = pelment->pntin.col_ind;
    }
    //free a istat
    //
    //creating a matrix in coo format
    iuscr_coo (m,n,val,indx,jndx,nnz,prpty,istat,a); 
}

iuscr_blockend(int 8a, int prpty, int *istat)
{
    int m,n, ierr, ind, kb, mb;
    int *blindx, indx, rpntr, cpntr, bpntrb, bpntre;
    int *val;
    int size_val, val_ind, indx_ind, bind_ind, ii, jj, i,j;
    i_matrix pmatrix;
    i_inelement pelement;
    *istat = -1;
    access(pamtrix, *a, istat);
    //
    mb = pmatrix->DIM[2];
    kb = pmatrix->DIM[3];
    //determine sizeof  val, m, n
    size_val = 0;
    m = 0;
    n = 0;
    for (i=1; i<pmatrix->DIM[2])
    {
        for(j=1; j<pmatrix->DIM[3])
        {
            i_element_num(ind, pmatrix, i, j, ierr)
            {
                if(ind == 0)
                {
                    access_element(pelement, ind, pmatrix, istat);
                    //
                    size_val = size_val + pamtrix->sub_rows[i]*pmatrix->sub_cols[j];
                }

            }
        }
    }    
    for(i=1; i< pmatrix->DIM[2]; i++)
    {
        m = m+pmatrix->sub_rows[i];
    }
    for(j=1; j < pmatrix->DIM[3]; j++)
    {
        n = n + pmatrix->sub_cols[j];
    }
    //allocate 3 varaibles
    //val size_val
    //indx 
    val = 0;
    //fill val, ind, blindx
    val_ind = 0;
    blindx_ind = 0;
    for (i = 1; i<pmatrix->DIM[2], i++) //how many blocks in row 
    {
        for(j=1; j<pmatrix->DIM[3]; j++) // how many blocks in col
        {
            i_element_num(ind, pmatrix,i, j,istat);
            //
            if (ind != 0)
            {
                access_element(pelement, ind, pmatrix, istat);
                //
                for(jj = 1; jj < pmatrix->sub_cols[j]; jj++)
                    for(ii = 1; ii < pmatrix->sub_rows[i]; ii++)
                    {
                        val_ind = val_ind + 1;
                        val[val_ind] = pelement->vblin->val[ii][jj];
                    }

                bindx_ind =  blindx_inx + 1;
                bindx[blinx_ind] = j;
                indx_ind = indx_ind + 1;
                indx[indx_ind] = indx[indx_ind - 1] + pmatrix->sub_rows[i]*pmatrix->sub_cols[j];
            }
        }
    }
    //fill rpntr, cpntr, bpntrb, bpntre
    rpntr=(int *)malloc(sizeof(int) * (pmatrix->DIM[2] + 1)); //row
    cpntr=(int *)malloc(sizeof(int) * (pmatrix->DIM[3] + 1)); //col 
    bpntrb=(int *)malloc(sizeof(int) * (pmatrix->DIM[2] ));
    bpntre=(int *)malloc(sizeof(int) * (pmatrix->DIM[2] ));
    //
    rpntr[0] = 1;
    for (i = 2; i<pmatrix->DIM[2] + 1; i++)
        rpntr[i] = rpntr[i-1] + pmatrix->sub-rows[i-1]; //row start 
    cpntr[0] = 1;
    for (j = 2; j<pmatrix->DIM[3] + 1; j++)
        cpntr[i] = cpntr[j-1] + pmatrix->sub-cols[j-1]; //row start 
    for(i = 1; i < pmatrix->trb[i]; i++)
    {
        bpntrb[i] = pmatrix->trb[i];
        bpntre[i] = pmatrix->tre[i]; //where
    }
    //release
      iuscr_vbr (m,n,val,indx,bindx,rpntr,cpntr, bpntrb,bpntre,mb,kb,prpty,istat,a);
}
