#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h> 

void testRoot () {
  uid_t uid=getuid(), euid=geteuid();
  if (uid<0 || uid!=euid) {
    printf("Error: UID<0 or UID != EUID. Ending. Check your user prileges. (You must be root and not use sudo.)\n");
    printf("UID=%d, EUID=%d",uid,euid);
    exit();
    }
  else {
    printf("UID = %d, EUID = %d",uid,euid);
    }
}

int main () {
  testRoot();

char * config_file;

}
