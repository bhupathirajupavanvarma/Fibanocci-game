#include<stdio.h>
#include<malloc.h>
#include<string.h>
int** transpose(int **board,int n)
{
     int **b=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++)
    {
        b[i]=(int *)malloc(sizeof(int)*n);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[j][i]=board[i][j];
        }
    }
    return b;
}
int* fibo(int n)
{
    int p=1,q=1,c=0;
    int *a=(int *)malloc(sizeof(int)*3000000);
    a[1]=2;
    for(int i=3;i<=n;i++)
    {  int c=p+q;
           p=q;
           q=c;
           a[c]=i;
    }
    return a;
}
int* single_left(int *b,int n)
{  int c=0,fib=0,d[2]={0},k=0;
    int *a=(int *)malloc(sizeof(int)*3000000);
        int *ca=(int *)malloc(sizeof(int)*n);

    a=fibo(32);
   for(int i=0;i<n;i++)
   {
       if(b[i]!=0)
       {   ca[c]=b[i];
         //  printf("%d ",ca[c]);
           c++;
           if(a[b[i]]!=0)
           {  fib++;
               if(fib==1)
               {
                d[k]=b[i];
                k++;
               }else if(fib==2){
                //  printf("%d %d %d %d\n",d[0],b[i],a[d[0]],a[b[i]]);
                  if(abs(a[d[0]]-a[b[i]])==1 || d[0]==1&&b[i]==1)
                  {
                      d[k]=b[i];
                      k++;
                  }
                  else{

                    d[0]=b[i];
                    fib=1;
                  }

               }
           }
           else if(k!=2){
            fib=0;k=0;
           }
       }
   }
  // printf("\n");
   int i;
   for( i=n-1;i>=c;i--)
   {
       b[i]=0;
       // printf("%d %d",i,b[i]);
   }

   if(k==2)
   {
       b[i]=0;
       i--;
   }
  int flag=0,j=i,l=0;
   for(j=0,l=0;j<i,l<c-1;j++,l++)
   {
      if(ca[l]==d[0] && ca[l+1]==d[1] && flag==0)
      {
          b[j]=d[0]+d[1];
          flag=1;
        // printf("%d h",j);
        l++;
      }
      else{
        b[j]=ca[l];
      }
   }
   if(l<c)
   {
       b[j]=ca[l];
   }
  // printf("%d %d",d[0],d[1]);
   return b;
}


int main()
{
    int *b=(int *)malloc(sizeof(int)*4);
    b[4]={0,3,3,3};
    b=up(b,n);
      for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}
