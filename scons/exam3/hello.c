#include <stdio.h>
int main()
{
    printf("Hello, world!\n");
#ifdef DEBUG
    printf("Debug version\n");
#endif
}
