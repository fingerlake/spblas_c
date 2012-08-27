int iuscr_insert_entry(IN int a, IN int val ,IN int i, IN int j,OUT int *istat)
{
    i_matrix *pmatrix;
    *istat = -1;
    access_matrix(pmatrix, a, istat)
        if(! *istat)
        {
            return -1;
        } 
    switch (pmatrix->format)
    {
        case 'block':
            iINS_bl_entr(pmatrix, val,i,j,istat);
            break;
        case 'vblock':
            iINS_varbl_entr(pmatrix, val,i,j,istat);
            break;
        case 'normal':
            iINS_entry(pmatrix, val,i,j,istat);
            break;
        case default:
            *istat = blas_error_param;
            return -1;
    }
        return 0;
}
