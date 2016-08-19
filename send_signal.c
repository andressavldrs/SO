#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

void handler(int sinal){
  printf("Recebi o sinal %d que o filho mandou!", sinal);
  
}
int main(){
  pid_t proc_ID, ppid;
  
  signal(SIGUSR1, handler);
   proc_ID = fork();

   if(proc_ID < 0){
     printf("Erro na criação do processo\n");
     return -1;
   }
   else if(proc_ID == 0){
     printf("Vou enviar o sinal SIGUSR1 ao pai e MATÁ-LO MUAHAHHAHA\n") ;
     ppid = getppid();
     kill(ppid, SIGUSR1);
   }
   else{
     waitpid(proc_ID, NULL, 0);
  }
   
    return 0;

}