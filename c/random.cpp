#include<stdio.h>
#include<stdlib.h>
int** random(int **board,int n)
{
    int a=rand()%n,b=rand()%n;
    while(board[a][b]!=0)
    {
        a=rand()%n;
        b=rand()%n;
   // printf("%d %d\n",a,b);
    }
    board[a][b]=1;
    return board;
}
int coun(int **board,int n)
{
    int coun=0;
       for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            coun=
        }
    }
}
void print(int **board,int n)
{   printf("\n\n");
      for(int i=0;i<n;i++)
    {  printf("             ");
        for(int j=0;j<n;j++)
        {
           printf("%d  ",board[i][j]);
        }
        printf("\n\n");
    }
}
int  main()
{  int n;
scanf("%d",&n);
  int **b=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++)
    {
        b[i]=(int *)malloc(sizeof(int)*n);
    }
for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
          b[i][j]=0;
        }
    }
    for(int i=0;i<100;i++)
    {


    b=random(b,n);
    system("cls");
   print(b,n);
    }

}
