/*
 * Writen by Xiuxia @2012.8.27
 * Description : CREATION ROUTINE FOR MATRIX HANDLE FROM 'VBR'-FORMAT
 * m
 * n
 * mb  row-dim in blocks
 * kb  col-dim in blocks
 * bpntrb  size is mb
 * npntre  size if kb
 * indx : 
 */
iuscr_vbr(int m, int n, int *val, INOUT int *indx, int *bindx, int *rpntr, int *cpntr, int *bpntrb, int *bpntre, int mb, int kb, int prpty, int *istat , int *a)
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
    dsp_data->FIDA = 'VBR'; //
    dsp_data->M = m; // rows of matrix
    dsp_data->K = n; ;//cols of matrix 
    set_descra(dsp_ata->DESCRA, prpty, ierr);
    get_descra(dsp_ata->DESCRA, 'b',message,  ierr); //base
    //
    if (mesage == 'C')
        base = C_BASE;
    else
        base = F_BASE;
    set_infoa(dsp_dat->INFOA, 'b', base, ierr);
  //  nnz = // 
    set_infoa(dsp_data%INFOA,'n',nnz,ierr); //
    set_infoa(dsp_data%INFOA,'d',-1,ierr); // !row-dim of block NOT fixed
    set_infoa(dsp_data%INFOA,'e',-1,ierr);// !col-dim of block NOT fixed
    set_infoa(dsp_data%INFOA,'f',mb,ierr);// !row-dim in blocks
    set_infoa(dsp_data%INFOA,'g',kb,ierr);// !col-dim in blocks
    //bound check
  //  if (mb != )
    {
        //memory release
    }
   //some setting todolater 
    //! create reference to original matrix
    if (options == 0) //reference
    {
        
        set_infoa(dsp_data%INFOA,'c',REF_OF_SOURCE,ierr)
            //
        dsp_data->A = val;
        dsp_data->IA1 = bindx;
        dsp_data->IA2 = indx;
        dsp_data->pb = bpntrb;
        dsp_data->pe = bpntre;
        dsp_data->bp1 = rpntr;
        dsp_data->bp2 = cpntr;
        istat = 0;
    }
    else //copy
    //! The additional required memory is DEALLOCATED later in USDS!
    //need allocate memory
    {

    }

    
}
