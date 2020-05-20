#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void InputArray(int **a, int row, int col);
void OutputArray(int **a, int row, int col);
int Function1(int **a,int row,int col);
int Function2(int **a,int row,int col);
int main(int argc, char *argv[]) {
	printf("---------------------------------\n");
	printf("-------------Lab10---------------\n");
	printf("---------------------------------\n");
	int **a = NULL, row, col;
    int i;
    printf("+Row = ");
    scanf("%d", &row);
    printf("+Col = ");
    scanf("%d", &col);
    a = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < row; i++)
    {
        a[i] = (int *)malloc(col * sizeof(int));
    }
    InputArray(a, row, col);
    OutputArray(a, row, col);
    Function1(a, row, col);
    Function2(a, row, col);  

    for (i = 0; i < row; i++)
    {
        free(a[i]);
    }
    
    free(a);
	return 0;
}
void InputArray(int **a, int row, int col)
{
    int i, j;
    int tansuat[row][col];
    srand(time(NULL));
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
        {
            int d = rand()&1 ?  -1 : 1;
            a[i][j]= d * rand()%9 +1;
         
        }
}
void OutputArray(int **a, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
}
int Function1(int **a,int row,int col)
{
	int i,j;
    int count = 0;
    for( j = 0;j < row; j++)
    {
    	int s = 0;
    	for( i = 0; i < col; i++)
    	{
    		if(a[j][i] == 0)
    		s++;                    //    
		}
		if(s != 0)
		count++;
	}
    printf("So cot chua phan tu 0 la : %d",count);  //    0
    printf("\n");
    return count;
}
int Function2(int **a,int row,int col)
{
	int i,j;
	int m[row];
	int numstr = 0;
        for (i = 0; i < row; i++)
        {
            m[i] = 0;
            for ( j = 0; j < col; j++)
            {
                if(a[i][j] == a[i][j+1])
                {
                    m[i]++;
                }
            }
        printf("%d ",m[i]);
        int max = m[0];
        if(max < m[i])
            {
                max = m[i];
                numstr = i;
            }
        }
        printf("\nDong la : %d",numstr);
}


