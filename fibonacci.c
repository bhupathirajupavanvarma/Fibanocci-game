#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct user_data
{
 char *name;
 int  **b,size_;
 int steps;
 int count_,high;
}u;







void file_write(struct user_data u)
{
    FILE *fptr;
  char *fname=(char *)malloc(sizeof(char*)*51200);
 char tname[34]={'C',':','/','U','s','e','r','s','/','b','p','a','v','a','/','D','e','s','k','t','o','p','/','c','+','+','/','t','e','s','t','/','\0'};
  fname=tname;
    char *format=(char *)malloc(sizeof(char*)*10);
 strcat(fname,u.name);

  strcat(fname,".txt");
 fptr=fopen(fname,"w");
  fprintf(fptr,"%d\n",u.size_);
  int i,j;
  for( i=0;i<u.size_;i++)
  {
      for(j=0;j<u.size_;j++)
      {
          fprintf(fptr,"%d ",u.b[i][j]);
      }
      fprintf(fptr,"\n");
  }
  fprintf(fptr,"%d\n",u.steps);
   fclose(fptr);
}


struct user_data func_count(struct user_data u)
{
    int i,j;
 for(i=0;i<u.size_;i++)
 {
     for(j=0;j<u.size_;j++)
     {
         if(u.b[i][j]>0)
         {
          u.count_++;
         }
         if(u.high<u.b[i][j])
         {
             u.high=u.b[i][j];
         }
     }
 }
 return u;
}
int check(struct user_data u)
{
    u=func_count(u);
    if(u.high >= (u.size_*u.size_*2))
    {
        return 1;
    }
    if(u.count_==u.size_*u.size_)
    {
        return 2;
    }
    return 0;
}
int* fibo(int n)
{
    int p=1,q=1,c=0;
    int *a=(int *)malloc(sizeof(int)*3000000);
    a[1]=2;
    int i=3;
    for(i=3;i<=n;i++)
    {  int c=p+q;
           p=q;
           q=c;
           a[c]=i;
    }
    return a;
}


void print(int **board,int n)
{   printf("\n\n");
  int i,j;
      for( i=0;i<n;i++)
    {  printf("             ");
        for(j=0;j<n;j++)
        {
           printf("%d  ",board[i][j]);
        }
        printf("\n\n");
    }
}

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


int** transpose(int **board,int n)
{
     int **b=(int **)malloc(sizeof(int *)*n);
     int i,j;
    for(i=0;i<n;i++)
    {
        b[i]=(int *)malloc(sizeof(int)*n);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[j][i]=board[i][j];
        }
    }
    return b;
}
int* single_left(int *b,int n)
{  int c=0,fib=0,d[2]={0},k=0;
    int *a=(int *)malloc(sizeof(int)*3000000);
        int *ca=(int *)malloc(sizeof(int)*n);

    a=fibo(32);
    int i=0;
   for(i=0;i<n;i++)
   {   if(b[i]!=0){
          ca[c]=b[i];
           c++;
               if(a[b[i]]!=0){
                  fib++;
                  if(fib==1)
                     {
                       d[k]=b[i];
                        k++;}
                      else if(fib==2){
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
   for( i=n-1;i>=c;i--)
   {
       b[i]=0;
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
   return b;
}


int* single_right(int *b,int n)
{  int c=0,fib=0,d[2]={0},k=0;
    int *a=(int *)malloc(sizeof(int)*3000000);
        int *ca=(int *)malloc(sizeof(int)*n);

    a=fibo(32);
    int i=0;
   for(i=0;i<n;i++)
   {
       if(b[i]!=0)
       {   ca[c]=b[i];
          // printf("%d ",ca[c]);
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
   printf("\n");
   for( i=0;i<n-c;i++)
   {
       b[i]=0;
   }
   if(k==2)
   {
       b[i]=0;
       i++;
   }
  int flag=0,j=i,l=0;
   for(j=i,l=0;j<n,l<c-1;j++,l++)
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



int** right(int **board,int n)
{    int i;
    for(i=0;i<n;i++)
    {
        board[i]=single_right(board[i],n);
    }
    return board;

}


int** left(int **board,int n)
{    int i;
    for(i=0;i<n;i++)
    {
        board[i]=single_left(board[i],n);
    }
    return board;

}


int** up(int **board,int n)
{
    board=transpose(board,n);
     int i;
    for(i=0;i<n;i++)
    {
        board[i]=single_left(board[i],n);
    }
    board=transpose(board,n);
    return board;

}


int** down(int **board,int n)
{
    board=transpose(board,n);
    int i;
    for(i=0;i<n;i++)
    {
        board[i]=single_right(board[i],n);
    }
    board=transpose(board,n);
    return board;

}

struct user_data start(struct user_data u)
{
    char a;
    scanf("%c",&a);
    while(a!='z')
    { int m;
      if(a=='w')
      {
         u.b=up(u.b,u.size_);
          m=check(u);
         if(m!=2 && m!=1){
        u.b=random(u.b,u.size_);
         }
      }
      else if(a=='a')
      {
          u.b=left(u.b,u.size_);
           m=check(u);
         if(m!=2 && m!=1){
        u.b=random(u.b,u.size_);
         }
      }
      else if(a=='d')
      {
          u.b=right(u.b,u.size_);
         m=check(u);
         if(m!=2 && m!=1){
        u.b=random(u.b,u.size_);
         }
      }
      else if(a=='s'){
         u.b=down(u.b,u.size_);
        m=check(u);
        if(m!=2 && m!=1){
        u.b=random(u.b,u.size_);
         }
      }
      u.steps++;
      file_write(u);
      if(m==2)
      {  printf("             ");
         printf("Over and Out!!!!YOU LOST");
         a='z';
      }
      else if(m==1)
      {   printf("             ");
           printf("Over and Out!!!!YOU WON BUDDY");
         a='z';

      }
      else{
       printf("             ");
      printf("Move:");
       scanf("%c",&a);
       system("cls");
       print(u.b,u.size_);
      }

    }

}


struct user_data playgame(struct user_data u)
{   int i,j=0;
   printf("Enter Your name:");
   char *n=(char *)malloc(sizeof(char)*51200);
   scanf("%s",n);
   u.name=n;
    printf("Enter the size of the board :");
    scanf("%d",&u.size_);
    int **b=(int **)malloc(sizeof(int *)*u.size_);
    for( i=0;i<u.size_;i++)
    {
        b[i]=(int *)malloc(sizeof(int)*u.size_);
    }
    u.b=b;
    u.high=0;
    u.steps=0;
    for(i=0;i<u.size_;i++)
    {
        for(j=0;j<u.size_;j++)
        {
           u.b[i][j]=0;
        }
    }
    u.b=random(u.b,u.size_);
    u.b=random(u.b,u.size_);
    file_write(u);
    print(u.b,u.size_);
    u=start(u);

}



struct user_data resumegame(struct user_data u)
{
   printf("Enter Your name:");
   char *n=(char *)malloc(sizeof(char)*51200);
   scanf("%s",n);
   u.name=n;

}


int main()
{
    printf("*-----------------------------------*\n");
    printf("-_-_-_-_-_-_Finonacci-_-_-_-_-_-_-_-_\n");
    printf("*-----------------------------------*\n");
    printf("1)Play Game \n");
    printf("2)Resume Game\n");
    int option;
    scanf("%d",&option);
    if(option==1)
    {
       u=playgame(u);
    }
    else if(option ==2)
    {
        u=resumegame(u);
    }

    return 0;
}
