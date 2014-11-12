#include "global.h"

void read_wrapper(char * buffer)
{
    //char buf1[sizeof(mess)];

    printf("Enter a message: ");
    scanf("%[^\n]", buffer);
   
}
