#include<stdio.h>
#include<malloc.h>
#include<string.h>
int playgame(int **board,int steps,char *name)
{


}
int main()
{
printf("*-----------------------------------*\n");
printf("-_-_-_-_-_-_Finonacci-_-_-_-_-_-_-_-_\n");
printf("*-----------------------------------*\n");
printf("1)Play Game \n");
Printf("2)Resume Game\n");
printf("3)Leader Board \n");
int option;
scanf("%d",&option);
if(option==1)
{
  char *name;
  name=(char *)malloc(sizeof(char)*51200);
  print("Enter Your name:");
  scanf("%s",&name);
  printf("Enter the size of the board (2 0R 4):")
  int siz;
  scanf("%d",&siz);
  int **board,steps=0;
  board=(int **)malloc(sizeof(int*)*siz);
  for(int i=0;i<siz;i++)
  {
      board[i]=(int *)malloc(sizeof(int)*siz);
  }
 FILE *fptr;
  char *fname=(char *)malloc(sizeof(char*)*51200);
 char tname[34]={'C',':','/','U','s','e','r','s','/','b','p','a','v','a','/','D','e','s','k','t','o','p','/','c','+','+','/','t','e','s','t','/','\0'};
  fname=tname;
  strcat(fname,name);
  strcat(fname,".txt");
  fptr=fopen(fname,"w");

    playgame(board,steps,name);
}
else if(option==2)
{
     name=(char *)malloc(sizeof(char)*51200);
  print("Enter Your name:");
  scanf("%s",&name);
    resumegame(name);
}
else
{
    leader_board();
}
return 0;
}
