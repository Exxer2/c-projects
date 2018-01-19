#include <stdio.h>
#include <stdlib.h>

/*****************************************************/
/* We will declare all of our function prototypes here.
 * The functions themselves are written below int main. */
void testRoot();
/*****************************************************/
/* Main: Begin!! */

int main () {
  testRoot(); //Test if we're root.
  char * config_file;
  return 0;
}

/* Main: G'bye! */
/*****************************************************/
/* Below this line, we will  flesh out our functions. 
 * Make sure they're declared! */
/*****************************************************/
// This tests to see if we are running as root actual and not sudo.
// We need to actually be root or we cannot grab all the system health
// data we actually need.
void testRoot() {
  uid_t uid=getuid(), euid=geteuid();
    if (uid==0 & uid==euid) { // Check if we're actually root (0)
      break; //Return to Main and continue execution
    }
    elif (uid<0 || uid!=euid) { //UID or EUID below zero or not matching could indicate compromise
      printf("Error: \"UID\"<0 or \"UID\"!=\"EUID\". Ending. Check your user prileges.\n(You must be actual root and not running with sudo.)\n");
        printf("UID=%d, EUID=%d\n",uid,euid);
        exit(1); //Exit if that's the case
    }
    case (uid!=0 || euid!=0) : //Notify the user that they aren't root, but everything else is good
      printf("You must perform this action as actual root, not with sudo.\n");
    default:
      printf("Invalid UID or EUID detected.\n"); //If it fails for unknown reasons...
      printf("UID = %d, EUID = %d\n",uid,euid);
      exit(2);
    }
}
