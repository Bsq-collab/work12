#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>
#include <signal.h>
#include <string.h>
#include <time.h>

int main(){
  printf("pp id b4: %d\n",getpid());
  fork();
  fork();
  printf("pid after:%d\n", getpid());
  srand(time(NULL));
  int s= rand();
  sleep(s);
  printf("pid: %d is finished\n",getpid());
  int i;
  int pid=wait( &i );
  printf("status: %d\n", pid,s);

}
