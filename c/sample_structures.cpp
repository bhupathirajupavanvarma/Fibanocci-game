#include<stdio.h>
#include<malloc.h>
struct user_data
{
 char *name;
 int  **b,size_;
 int steps;
 int count_,high;
}u;
struct user_data fuc(struct user_data e)
{
          scanf("%s",e.name);
       e.size_=10;
    return e;
}
int main()
{
    char *name=(char *) malloc(sizeof(char)*51200);
      scanf("%s",name);
      u.name=name;
      printf("%s",u.name);
      u=fuc(u);
        printf("%s %d",u.name,u.size_);

}

