iuscr_coo(int m, int n, int *val, int *indx, int *jndx, int nnz, int prpty, int *istat, int *a)
{
    int nmb, ierr, options, base, nnz;
    int COPY; //
    char message;
    ispmat *dsp_data; //sparse matrix format
    options = *istat;
    *istat = -1; //
    *a = 0;
    new_isp(nmb, &ierr);
    //
    accessdata(dsp_data, nmb, ierr);
    //
    dsp_data->FIDA = 'COO'; //
    dsp_data->M = m; // rows of matrix
    dsp_data->K = n; ;//cols of matrix 
    set_descra(dsp_ata->DESCRA, prpty, ierr);
    set_infoa(dsp_dat->INFOA, 'b', base, ierr);
    get_descra(dsp_ata->DESCRA, 'b',message,  ierr); //base
    //
    if (mesage == 'C')
        base = C_BASE;
    else
        base = F_BASE;
    set_infoa(dsp_dat->INFOA, 'b', base, ierr);
    //check bound
    //
    if (options  == 0)
    {
        set_infoa(sp_data->INFOA, 'c', REF_OF_SOURCE, ierr);
        dsp_data ->A = val;
        dsp_data->IA1 = indx;
        dsp_data->IA2 = jndx;
    }
    else
    {
        //allocate memory
    }
}
