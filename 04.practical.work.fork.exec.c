#include<stdio.h>
#include<unistd.h>
int main()
 {
   printf("Main before fork \n");
   int pid = fork();
   if (pid == 0)
   {
    int pid2 = fork();
    if (pid2 ==0)
    {
    printf("Child is priting ");
    char *args[] = {"/bin/ps", "-ef", NULL};
    execvp("/bin/ps", args); 
    }
    else
     {
       printf("Child is free \n");
       char *args[] = {"free", "-h", NULL};
       execvp("free", args);
     }
    
   }
 }
