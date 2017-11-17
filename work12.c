#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
int main(){
  printf("pp id b4: %d\n",getpid());
  int frk=fork();
  if(frk==0){
    printf("pid of child:%d\n", getpid());
    srand(time(NULL));
    int s= rand() % 16 + 5;//rand() % (max +1 -min) + min
    sleep(s);
    printf("pid: %d is finished after %d seconds\n",getpid(),s);
    exit(0);
  }
  if(frk){
    int i;
    int pid= wait( &i );
    printf("status: %d\n", pid);
  }


  return 0;

}
