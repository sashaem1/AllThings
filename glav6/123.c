#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void)
{
int *A;
int counter = 0;
A = (int*) malloc(counter * sizeof(int*));
int a;
int i=0;
int j=0;
int q;
FILE *IN;
IN = fopen("bra.txt", "r");
if (IN == NULL)
{
printf("File ne otrilsya\n");
return -1;
}
while(fscanf(IN, "%d", &a) == 1)
{
A[counter] = a;
counter++;
}
fclose(IN);
Func(A,counter);
// for(i=0;i<counter - 1;i++)
// {
// for(j=0;j<counter - 1-i;j++)
// {
// if(A[j]>A[j+1])
// {
// q=A[j];
// A[j]=A[j+1];
// A[j+1]=q;
// }
// }
// }
for(i=0;i<counter;i++)
{
printf("%d ", A[i]);
}
return 0;
}