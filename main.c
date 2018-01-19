#include <stdio.h>
#include <stdlib.h>

/*****************************************************/
/* We will declare all of our function prototypes here.
 * The functions themselves are written below int main. */
void testRoot();
/*****************************************************/
/* Main: Begin!! */

int main () {
  testRoot();

  char * config_file;
  return 0;
}

/* Main: G'bye! */
/*****************************************************/
/* Below this line, we will  flesh out our functions. 
 * Make sure they're declared! */
/*****************************************************/
# This tests to see if we are running as root actual and not sudo.
# We need to actually be root or we cannot grab all the system health
# data we actually need.
void testRoot() {
  uid_t uid=getuid(), euid=geteuid();
  if (uid<0 || uid!=euid) {
    printf("Error: \"UID\"<0 or \"UID\"!=\"EUID\". Ending. Check your user prileges.\n(You must be actual root and not running with sudo.)\n");
    printf("UID=%d, EUID=%d\n",uid,euid);
    exit(-1);
    }
  else {
    printf("UID = %d, EUID = %d\n",uid,euid);
    }
}
