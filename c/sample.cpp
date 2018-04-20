#include<stdio.h>
#include<ctype.h>
#include<malloc.h>
#include<string.h>
void file_read(int **board,char *name,int siz,int steps)
{
        FILE *fptr;
  char *fname=(char *)malloc(sizeof(char*)*51200);
 char tname[34]={'C',':','/','U','s','e','r','s','/','b','p','a','v','a','/','D','e','s','k','t','o','p','/','c','+','+','/','t','e','s','t','/','\0'};
  fname=tname;
    char *format=(char *)malloc(sizeof(char*)*10);
 strcat(fname,name);

  strcat(fname,".txt");
 fptr=fopen(fname,"r");
 char c;
 c = getc(fptr);
 siz=c-'0';
 printf("%d\n",siz);

    for(int i=0;i<siz;i++)
    { c='a';
        for(int j=0;j<siz;j++)
        {
          while(isdigit(c)==0){
            c = getc(fptr);}
          board[i][j]=c-'0';
          printf("%d ",board[i][j]);
        }
        printf("\n");
    }
    while(isdigit(c)==0 && c!= EOF){
            c = getc(fptr);}
    steps=c-'0';
    printf("%d ",steps);
   fclose(fptr);
}
void file_write(int **board,char *name,int siz,int steps)
{
    FILE *fptr;
  char *fname=(char *)malloc(sizeof(char*)*51200);
 char tname[34]={'C',':','/','U','s','e','r','s','/','b','p','a','v','a','/','D','e','s','k','t','o','p','/','c','+','+','/','t','e','s','t','/','\0'};
  fname=tname;
    char *format=(char *)malloc(sizeof(char*)*10);
 strcat(fname,name);

  strcat(fname,".txt");
 fptr=fopen(fname,"w");
  fprintf(fptr,"%d\n",siz);
  for(int i=0;i<siz;i++)
  {
      for(int j=0;j<siz;j++)
      {
          fprintf(fptr,"%d ",board[i][j]);
      }
      fprintf(fptr,"\n");
  }
  fprintf(fptr,"%d\n",steps);
   fclose(fptr);
}

int main()
{
    int n;
    scanf("%d",&n);
    int **b=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++)
    {
        b[i]=(int *)malloc(sizeof(int)*n);
    }


    char *name=(char *)malloc(sizeof(char*)*51200);
     char sname[6]={'p','a','v','a','n','\0'};
     name=sname;

file_read(b,name,n,0);
  printf("Done!!!!!!");
}
