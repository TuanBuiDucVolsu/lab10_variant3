#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void InputArray(int **a, int size);
void OutputArray(int **a, int size);
void Function3(int **a,int size);
void Function4(int **a,int size);
int main(int argc, char *argv[]) {
	printf("---------------------------------\n");
	printf("-------------Lab10---------------\n");
	printf("---------------------------------\n");
	int **a = NULL, size;
    int i;
    printf("+Size = ");
    scanf("%d", &size);
  
    a = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        // Cap phát cho tung con tro cap 1
        a[i] = (int *)malloc(size * sizeof(int));
    }
    InputArray(a, size);
    OutputArray(a, size);
    Function3(a,size);
    Function4(a,size);
   
    for (i = 0; i < size; i++)
    {
        free(a[i]);
    }
    free(a);
	return 0;
}
void InputArray(int **a, int size)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
        {
            a[i][j]= rand()%100;
        }
}
void OutputArray(int **a, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        printf("%5d", a[i][j]);
        printf("\n");
    }
}
void Function3(int **a,int size)
{
    int success = 0; 
    int i,j;
    for (i = 0; i < size; i++)   
    {
    for (j = 0; j < size; j++) 
	{
        if (i != j) {
            if (a[i][j] == a[j][i]) {
                success = 1;
            } else {
                success = 0;
                break;
            }
        }
    }
}
 
            if (success) 
			{
               printf("symmetry");
            }
            else 
			{
                printf("unsymmetrical");
            }

}
void Function4(int **a,int size)
{
	int i,j,max,ind,zamena;
	for (i = 0; i < size; i++)
    {
        max = a[i][0];
        ind = 0;
        for (j = 1; j < size; j++)
        if (a[i][j] > max)
        {
            max = a[i][j];
            ind = j;
        }
        zamena = a[i][i];
        a[i][i] = a[i][ind];
        a[i][ind] = zamena;
    }
    printf("\nzadanie4 Rezultat : \n") ;      //Задание 4
    for (i = 0; i < size; i++)
    {
        printf("\n");
        for (j = 0; j < size; j++)
        printf("%5d", a[i][j]);
        printf("\n");
    }
    printf("\n");  
}

