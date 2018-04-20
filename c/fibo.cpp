#include<stdio.h>
#include<malloc.h>
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
int main()
{
    int n;
 scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*3000000);
    a=fibo(n*n*2);
    for(int i=0;i<3000000;i++)
    {
        if(a[i]!=0)
        {
          printf("\n %d %d ",a[i],i);
        }

    }

}
