typedef struct
{
	int row_ind,col_ind;
	int value;
}i_inpnt1;

typedef struct{
int row_block_ind,col_block_ind;
int **value;
}i_inblock;

typedef struct {
	int row_vblock_ind,col_vblock_ind;
	int **value;
}i_invblock;


typedef struct{
	i_inblock blin;
	i_inpnt1 pntin;
	i_invblock vblin;
}i_inelement;

typedef struct{
	i_inelement contents;
	i_element pntr;
}i_ele

