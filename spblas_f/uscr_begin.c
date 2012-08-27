int iuscr_begin(IN int m, IN int n, OUT int *a, OUT int *istat)
{
    int nmb, mb;
    i_matrix * ipmatrix; //
    mb = 1;
    *istat = -1;
    if (m <= 0 | n<=0)
    {
        *istat = blas_error_param;
        return -1;
    }
    else
    {
        new_i_matrix(&nmb,mb,istat)
        if ( *istat != 0)
        {
            *istat =  blas_error_memalloc;
            return -1;
        }
        access_matrix(ipmatrix, nmb, istat);
        if ( *istat != 0)
        {
            *istat = blas_error_param;
            return -1;
        }
    }
    ipmatrix->DIM[0] = m; //number of rows
    ipmatrix->DIM[1] = n; //number of cols
    ipmatrix->format = "normal"; //todolater
    *a=nmb;
    return 0;
}
