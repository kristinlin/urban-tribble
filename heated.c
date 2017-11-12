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
    //    printf("%s\n", parsed[index]);
    //    printf("next: %s\n", seg);
    index++;
  }
  //if all slots have args, last should be NULL
  parsed[5] = NULL;
  return parsed;
}

int main( int argc, char * argv[]) {
  char args1[500] = "ls -a -l";
  char ** command = parse_args(args1);
  execvp(command[0], command);
  //remember to free alloc-ed mem
  free(command);
  
}
