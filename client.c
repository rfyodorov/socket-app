#include "lib/c_message.c"
#include "lib/c_socket.c"

#include "lib/global.h"

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

    // def message
    char buffer[1024];
    read_wrapper(buffer);
    printf("Text: %s\n", buffer);

    //connect to socket     
    c_socket(mport, buffer);

    return 0;
}
