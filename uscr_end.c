uscr_end(INOUT int *a, INOUT int *istat)
{
    i_matrix *ipmatrix; 
    d_matrix *dpmatrix; 
    s_matrix *spmatrix; 
    c_matrix *cpmatrix; 
    z_matrix *zpmatrix; 
    int prpty, rest, b;
    b = -*a;
    rest = b % no_of_bytes;
    switch(rest)
    {
        case ISP_MARTIX:
            *istat = -1;
            access_matrix(ipmatrix, *a, istat); //where to get a ?
            prpty = ipmatrix->property;
            switch (ipmatrix->format)
            {
                case 'block':
                    iuscr_blockend(a, prpty, istat);
                case 'vlbock':
                    iuscr_varend(a,prpty, istat);
                case 'normal':
                    iuscr_normend(a, prpty,istat);
                case default:
            }
    case SSP_MATRIX:
    }
}
