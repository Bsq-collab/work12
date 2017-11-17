#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
int main(){
  printf("pp id b4: %d\n",getpid());
  int frk=fork();
  // If child
  if(!frk){
    printf("pid of child:%d\n", getpid());
    srand(time(NULL));
    int s= rand() % 16 + 5;//rand() % (max +1 -min) + min
    sleep(s);
    printf("pid: %d is finished after %d seconds\n",getpid(),s);
    // Uh something tells me this isn't the professional way to do it
    exit(s);
  } else {
    int status;
    int pid= wait( &status );
    printf("Received child exit signal. TIME: %d\n", WEXITSTATUS(status));
    printf("Done! status: %d\n", pid);
  }

  return 0;

}
