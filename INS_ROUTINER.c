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

iINS_varblock()
