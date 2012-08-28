/*
 *
 *Description : PERFORMS MV MULT. WITH MATRIX IN 'CSR'-STORAGE
 *rmbv = Right Multiplication By Vector: y=Ax
 */
irmbv_csr(ispmat mat, int *x, int n, INOUT int *y, int m, int *ierr)
{
    int m, n, base, ofs, i, pntr;
    char diag, type, part;
    *ierr = -1;
    //m
    //n
   // if (mat
    ofs = 1 - base;
    get_infoa(mat->INFOA,'b',base, ierr);
    //
    get_infoa(mat->DESCRA,'d',diag, ierr);
    //
    get_infoa(mat->DESCRA,'t',type, ierr);
    //
    get_infoa(mat->DESCRA,'a',part, ierr);
    //
    memset(y,0, m*sizeof(int));
    if(diag == 'U') //unstored diagonal
    {
        if (m == n )
        {
            memcpy(y, x, sizeof(int)*m);
        }
        else
        {
                //error 
        }
    }
    if (type == 'S' && part != 'B' && m == n ) // S :symetic  B:both lower and upper are specified  !B means either upper or lower are specified
    {
            if (part == 'U') //upper are specified 
            {
                for (i=0; i < mat->M; i ++)
                {
                    pntr = mat->pb[i]; //begin 
                    while (pntr < mat->pe[i]) //end
                    {
                        if (i == mat->IA1[pntr + ofs] + ofs )   // IA1 may be col idx
                            y[i] = y[i] + mat->A[pntr + ofs] * x[mat->IA1[pntr + ofs]+ofs]; 
                        else if (i < mat->IA1[pntr + ofs] +ofs ) //
                        {
                            y[i] = y[i] + mat->A[pntr + ofs] * x[mat->IA1[pntr + ofs]+ofs]; 
                            y[mat->IA1[pntr + ofs] +ofs] + = mat->A[pntr + ofs] * x[i];
                        }
                        pntr += pntr;
                    }
                }
            }
            else //lower
            {
                for (i=0; i < mat->M; i ++)
                {
                    pntr = mat->pb[i]; //begin 
                    while (pntr < mat->pe[i]) //end
                    {
                        if (i == mat->IA1[pntr + ofs] + ofs )   // IA1 may be col idx
                            y[i] = y[i] + mat->A[pntr + ofs] * x[mat->IA1[pntr + ofs]+ofs]; 
                        else if (i > mat->IA1[pntr + ofs] +ofs ) //
                        {
                            y[i] = y[i] + mat->A[pntr + ofs] * x[mat->IA1[pntr + ofs]+ofs]; 
                            y[mat->IA1[pntr + ofs] +ofs] + = mat->A[pntr + ofs] * x[i];
                        }
                        pntr += pntr;
                    }
                }

            }
            //
    } 
    else if (type == 'H' && part != 'B' && m==n ) //Hermitian matrix ,whose tranpa equal to itself  
    {
            if (part == 'U') //upper are specified 
            {
                for (i=0; i < mat->M; i ++)
                {
                    pntr = mat->pb[i]; //begin 
                    while (pntr < mat->pe[i]) //end
                    {
                        if (i == mat->IA1[pntr + ofs] + ofs )   // IA1 may be col idx
                            y[i] = y[i] + mat->A[pntr + ofs] * x[mat->IA1[pntr + ofs]+ofs]; 
                        else if (i < mat->IA1[pntr + ofs] +ofs ) //
                        {
                            y[i] = y[i] + mat->A[pntr + ofs] * x[mat->IA1[pntr + ofs]+ofs]; 
                            y[mat->IA1[pntr + ofs] +ofs] + = mat->A[pntr + ofs] * x[i];
                        }
                        pntr += pntr;
                    }
                }
            }
            else //lower
            {
                for (i=0; i < mat->M; i ++)
                {
                    pntr = mat->pb[i]; //begin 
                    while (pntr < mat->pe[i]) //end
                    {
                        if (i == mat->IA1[pntr + ofs] + ofs )   // IA1 may be col idx
                            y[i] = y[i] + mat->A[pntr + ofs] * x[mat->IA1[pntr + ofs]+ofs]; 
                        else if (i > mat->IA1[pntr + ofs] +ofs ) //
                        {
                            y[i] = y[i] + mat->A[pntr + ofs] * x[mat->IA1[pntr + ofs]+ofs]; 
                            y[mat->IA1[pntr + ofs] +ofs] + = mat->A[pntr + ofs] * x[i];
                        }
                        pntr += pntr;
                    }
                }

            }
    }
    else //general pattern
    {
        for (i=0; i < mat->M; i ++)
        {
            pntr = mat->pb[i];
            while (pntr < mat->pe[i])
            {
               y[i] = y[i] + mat->A[pntr + ofs] * x[mat->IA1[pntr + ofs]+ofs]; 
               pntr ++;
            }
        }

    }
}
