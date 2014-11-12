#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "lib/s_socket.c"

int mport;

int main(int argc, char *argv[])
{
    // define port
    const char *port_arg = NULL;
    if((argc > 1) && (strlen(argv[1]) != 1))
    {
        port_arg = argv[1];
        mport = atoi(port_arg);
        printf("Port: %d\n", mport);
    }
    else
    {
        char str[5];
        do {
            printf("Please enter port number(example 3425):");
            scanf("%s", str);
            mport = atoi(str);
        } while((mport > 65535) || (mport < 1));
    }

    printf("Listen port: %d\n", mport);
    s_socket(mport);

    return 0;
}
