#include <stdio.h>

#include "toolkit.h"


int main(int argc, char *argv[]) {
#ifdef RELEASE 
  puts("Hello release world");
#else
  puts("Hello debug world");
#endif
  toolkit_func();
  return 0;
}
