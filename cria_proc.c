#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
 int i;
  pid_t proc_ID;
  
  for(i = 0; i < 2; i++){
   proc_ID = fork();

   if(proc_ID != 0){
    waitpid(proc_ID, NULL, 0);
    printf("Oi, eu sou o pai do %d\n",proc_ID) ;
   }
   else{
    printf("Oi, eu sou o filho %d\n",getpid()) ;
   }
  
  }
    return 0;

}