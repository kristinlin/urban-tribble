#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args( char * line ) {
  //allocate an array with 6 slots to store char pointers in
  char ** parsed = (char **) calloc(6, sizeof(char *));
  int index = 0;
  //hold the remaining line to parse; while there is more...
  char * seg = line; 
  while (seg) {
    //set the slot in parsed as the returned string segment by strsep
    parsed[index] = strsep(&seg, " ");
    printf("adding: %s\n", parsed[index]);
    printf("left: %s\n", seg);
    index++;
  }
  //if all slots have args, last should be NULL
  return parsed;
}

int main( int argc, char * argv[]) {
  char args[500] = "ls -a -l";
  char ** command = parse_args(args);
  execvp(command[0], command);
  //memory should be freed after other process takes over?
  
}
