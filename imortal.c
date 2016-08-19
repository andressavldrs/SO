#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handler(int sinal){
  printf("SOU IMORTAL!");
  
}
int main(){
 
  signal(SIGTERM, handler);
  signal(SIGINT, handler);
   
  while(1)
  {
    sleep(1);
  }
   
    return 0;

}