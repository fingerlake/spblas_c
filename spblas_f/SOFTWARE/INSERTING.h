/*
 *Writen by zhang Xiuxia @2012-8-24
 *
 */
#ifndef INSERTING_H
#define INSERTING_H
/***************integer matrix*****************/
//a pointer
typedef struct i_inpnt1
{
    int row_ind,col_ind;
    int value;
}i_inpnt1;

//a block
typedef struct i_inblock
{
    int row_block_ind,col_block_ind;
    int **value;
}i_inblock;

typedef struct i_invblock
{
    int row_block_ind,col_block_ind;
    int **value;
}i_invblock;

typedef struct i_inelement
{
    i_inblock blin;
    i_inpnt1 pntin;
    i_invblock vblin;
}i_inelement;

typedef struct i_element
{
    int number;
    i_inelement contents;  //insert block ,pointer or vblock 
    struct i_element *pntr; //linklist to manage what inserted
}i_element;

typedef struct i_matrix
{
    int DIM[6];
    int property, number,new; //
    char format[11];
    int *sub_rows,*sub_cols, *trb,*tre; // meaning ?
    i_element *i_element_start; //insert content start
    struct  i_matrix *pntr; //linklist 
}i_matrix;

/**********************double matrix*********************/
typedef struct d_inpnt1
{
    int row_ind,col_ind;
    double value; //presion is not specified
}d_inpnt1;

typedef struct d_inblock
{
    int row_block_ind,col_block_ind;
    double **value;
}d_inblock;

typedef struct d_invblock
{
    int row_block_ind,col_block_ind;
    double **value;
}d_invblock;

typedef struct d_inelement
{
    d_inblock blin;
    d_inpnt1 pntin;
    d_invblock vblin;
}d_inelement;

typedef struct d_element
{
    int number;
    d_inelement contents;
    struct d_element *pntr;
}d_element;

typedef struct d_matrix
{
    int DIM[6];
    int property, number,new;
    char format[11];
    int *sub_rows,*sub_cols, *trb,*tre;
    d_element *d_element_start;
    struct  d_matrix *pntr;
}d_matrix;
/**********************single matrix*********************/
typedef struct s_inpnt1
{
    int row_ind,col_ind;
    float value; //presion is not specified
}s_inpnt1;

typedef struct s_inblock
{
    int row_block_ind,col_block_ind;
    float **value;
}s_inblock;

typedef struct s_invblock
{
    int row_block_ind,col_block_ind;
    float **value;
}s_invblock;

typedef struct s_inelement
{
    s_inblock blin;
    s_inpnt1 pntin;
    s_invblock vblin;
}s_inelement;

typedef struct s_element
{
    int number;
    s_inelement contents;
    struct s_element *pntr;
}s_element;

typedef struct s_matrix
{
    int DIM[6];
    int property, number,new;
    char format[11];
    int *sub_rows,*sub_cols, *trb,*tre;
    s_element *s_element_start;
    struct  s_matrix *pntr;
}s_matrix;
/**********************complex matrix*********************/
//define later
/**********************z complex  matrix*********************/

//global variable defination, use for linklist
i_matrix * i_matrix_start;
d_matrix * d_matrix_start;
s_matrix * s_matrix_start;

#define  FALSE 0
#define TRUE 1
int iins_init=FALSE
int dins_init=FALSE
int sins_init=FALSE
/*
 *input :
 *output:
 *function:
 */
//note : . shoudle repaced with ->  todolater
void new_i_matrix(OUT int *nmb, IN int Mb,OUT int *ierr)
{
    i_matrix *matrix_insert;
    if(!iins_init)
    {
        i_matrix_start=NULL;
        iins_init=TRUE;
    }
    if(i_matrix_start==NULL)
    {
        
        i_matrix_start = (i_matrix *)malloc(sizeof(i_matrix));
        i_matrix_start.number = ISP_MATRIX;
        i_matrix_start.number =- i_matrix_start.number;
        i_matrix_start.pntr = NULL;
    }
    else
    {
        matrix_insert = (i_matrix *)malloc(sizeof(i_matrix));
        matrix_insert.number = i_matrix_start.number - no_of_types;
        i_matrix_start = matrix_insert;
    }
        i_matrix_start.DIM=0;
        i_matrix_start.property =  blas_general + blas_one_base + blas_col_major; // in c may be row major
        i_matrix_start.new = 1;
        i_matrix_start.format=''; //empty string
        i_matrix_start.new = 1; //!new=0:blas_open_handle, new=1: blas_new_handle
        i_matrix_start.sub_rows = NULL;
        i_matrix_start.sub_cols = NULL;
        i_matrix_start.i_elemetn_start = NULL;
        i_matrix_start.trb= (int *)malloc(sizeof(int)*Mb); //
        i_matrix_start.tre= (int *)malloc(sizeof(int)*Mb); //
        *nmb = i_matrix_start.number; //
        *ierr=0;
}
/*
 * free the matrix node whose number is nmb
 */
int dealloc_i_matrix(IN int nmb, OUT int *ierr)
{
    i_matrix * matrix_precedent, *matrix_tester;
    *ierr = -1;
    if (i_matrix_start.pntr==NULL)  //only one node in the linklist
    {
        if(i_matrix_start.number == nmb )
        {
            free(i_matrix_start.tre);
            free(i_matrix_start.trb); //set ierr flag
            //here set ierror flag
            if (*ierr != 0)
            {
                    ierr = blas_error_memdeloc;
                    //exit(-1); //
                    return -1;
            }
            free(i_matrix_start);
            if (*ierr != 0)
            {
                    ierr = blas_error_memdeloc;
                    //exit(-1); //
                    return -1;
            }
            i_matrix_start = NULL;
            *ierr = 0;
            return 0;
        }
    }
    else //there are multiple nodes in the lists
    {
        matrix_tester = i_matrix_start;
        if ( matrix_tester.number = nmb) //find the desired matrix node
        {
            i_matrix_start = matrix_tester.pntr; //point to the next node
            free(matrix_tester.tre);
            free(matrix_tester.trb);
            //add ierr flag
            if(*ierr)
            {
                *ierr = blas_error_memdeloc;
                return -1;
            }
            free(matrix_tester);
            if(*ierr)
            {
                *ierr = blas_error_memdeloc;
                return -1;
            }
            *ierr=0;
            return 0;
         }
            matrix_precedent = i_matrix_start; //
	    	matrix_tester = i_matrix_start.pntr; //the next node
	    	while (matrix_tester)
            {
                if(matrix_tester.number == nmb)
                {
                    matrix_preceent.pntr = matrix_tester.pntr; //the next node
                    free(matrix_tester.tre);
                    free(matrix_tester.trb);
                    //set ierr flag here
                    if (!*ierr)
                    {
                        *ierr = blas_error_memdeloc;
                        return -1;
                    }
                    free(matrix_tester);
                    //set ierr flag here
                    if (!*ierr)
                    {
                        *ierr = blas_error_memdeloc;
                        return -1;
                    }
                  }
                else
                {
                    matrix_precedent = matrix_tester;
                    matrix_tester = matrix_tester.pntr;
                }
            }
    }
}

/*
 *  access matrix according to its nmb
 */
void iaccess_matrix(OUT i_matrix * pmatrix,IN int nmb, OUT int istat )
{
    i_matrix * matrix_tester;
    *istat = 1;
    matrix_tester = i_matrix_start;
    while (matrix_tester.number != nmb && matrix_tester.pntr)
    {
        matrix_tester = matrix_tester->pntr;
    }
    if ( matrix_tester->number == nmb)
    {
        pmatrix = matrix_tester;
        *istat = 0;
    }
    else
    {
        pmatrix = NULL;
        *istat = blas_error_param;
    }
}

int new_i_element(IN i_matrix * pmatrix,OUT int *nmb_element, OUT int *istat)
{
    i_elemnt *element_insert;
    int ierr;
    *istat =  -1;
    if (!pmatrix->i_element_start) //empty: allocte element start point
    {
        pmatrix->new=0;// status changed to blas_open_handle     
        pmatrix->i_element_start = (i_element *)malloc(sizeof(i_element));
        //ierr flag
        
        if (!*ierr)
        {
         *ierr = blas_error_memdeloc;
          return -1;
        }
        pmatrix->i_element_start->number = 1; //
        pmatrix->i_element_start.pntr = NULL; //next node
    }
    else //already has start point
    {
        element_insert = (i_element *)malloc(sizeof(i_element));
        if (!*ierr)
        {
         *ierr = blas_error_memdeloc;
          return -1;
        }
        element_insert->pntr = pmatrix->i_element_start;
        element_insert->number = pmatrix->i_element_start->number + 1; //number record how many should inserted
        pmatrix->i_element_start = element_insert; //insert from head
    }
    switch (pmatrix->format) //set on begin function
    {
        case ("normal"): //may need to change to integer :todolater
            pmatrix->i_elemnet_start->contents.pntin.value = 0; 
            pmatrix->i_elemnet_start->contents.pntin.row_ind = -1; 
            pmatrix->i_elemnet_start->contents.pntin.col_ind = -1; 
            pmatrix->i_elemnet_start->contents.blin->value = NULL; //will not be used  
            pmatrix->i_elemnet_start->contents.vblin->value = NULL;//will not be used 
            break;
        case ("block"):
            pmatrix->i_elemnet_start->contents.blin.row_block_ind = -1; 
            pmatrix->i_elemnet_start->contents.blin.col_block_ind = -1; 
            pmatrix->i_elemnet_start->contents.blin->value = NULL; 
            pmatrix->i_elemnet_start->contents.vblin->value = NULL;
            break;
        case ("vblock")
            pmatrix->i_elemnet_start->contents.vblin.row_block_ind = -1; 
            pmatrix->i_elemnet_start->contents.vblin.col_block_ind = -1; 
            pmatrix->i_elemnet_start->contents.blin->value = NULL; 
            pmatrix->i_elemnet_start->contents.vblin->value = NULL;
            break;
        case default:
            *istat = blas_error_param;
    }
    *nmb_element = pmatrix->i_element_start->number;
    *istat = 0;
    return 0;
}
//todolater
//subroutine dealloc_i_element  (nmb_element,pmatrix,istat)
//iaccess_element()
//find how many elements being inserted
int i_element_num(OUT int *nmb_element, IN  i_matrix * pmatrix, int i, int j, OUT int *stat)
{
    i_element *element_tester;
    int finder;
    switch (pmatrix->format)
    {
        case("normal")
            element_tester = pmatrix->i_element_start;
            if( !element_tester->pntr) //only one node
            {
                if(element_tester->contents.pntin.row_ind == i && element_tester->contes.pntin.col_ind == j)
                    *num_element = element_tester->number;
                else
                    *num_element =0;
            }
            else
            {
                finder = FALSE;
                while (element_tester->pntr && !finder)
                {
                if(element_tester->contents.pntin.row_ind == i && element_tester->contes.pntin.col_ind == j)
                    finder = TRUE;
                else
                    element_tester = element_tester->pntr;
                }
                if(element_tester->contents.pntin.row_ind == i && element_tester->contes.pntin.col_ind == j)
                    *nmb_element = element_tester->number;
                else
                    *nmb_element = 0;
            }
            break;
            case("block")
            element_tester = pmatrix->i_element_start;
            if( !element_tester->pntr) //only one node
            {
                if(element_tester->contents.blin.row_block_ind == i && element_tester->contes.blin.col_bloock_ind == j)
                    *num_element = element_tester->number;
                else
                    *num_element =0;
            }
            else
            {
                finder = FALSE;
                while (element_tester->pntr && !finder)
                {
                if(element_tester->contents.blin.row_block_ind == i && element_tester->contes.blin.col_block_ind == j)
                    finder = TRUE;
                else
                    element_tester = element_tester->pntr;
                }
                if(element_tester->contents.blin.row_block_ind == i && element_tester->contes.blin.col_block_ind == j)
                    *nmb_element = element_tester->number;
                else
                    *nmb_element = 0;
            }
            break;
            case("vblock")
            element_tester = pmatrix->i_element_start;
            if( !element_tester->pntr) //only one node
            {
                if(element_tester->contents.blin.row_vblock_ind == i && element_tester->contes.blin.col_bloock_ind == j)
                    *num_element = element_tester->number;
                else
                    *num_element =0;
            }
            else
            {
                finder = FALSE;
                while (element_tester->pntr && !finder)
                {
                if(element_tester->contents.blin.row_vblock_ind == i && element_tester->contes.blin.col_vblock_ind == j)
                    finder = TRUE;
                else
                    element_tester = element_tester->pntr;
                }
                if(element_tester->contents.blin.row_vblock_ind == i && element_tester->contes.blin.col_vblock_ind == j)
                    *nmb_element = element_tester->number;
                else
                    *nmb_element = 0;
            }
            break;
        case default:
            *istat = blas_error_param;
    }
    *istat = 0;
    return 0;
}
#endif
