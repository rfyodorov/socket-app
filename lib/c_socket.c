// Socket function

char message[] = "Hello there!\n";
char buf[sizeof(message)];

void c_socket(int mport, char * buffer)
{
    int sock;
    struct sockaddr_in addr;
 
    printf("Buffer: %s \n", buffer);
    //char *message = &buffer;
    //char buf[sizeof(buffer)];


    //open socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("Status socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(mport); // или любой другой порт...
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    printf("Connect to port: %d\n", mport);

    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("Status connect");
        exit(2);
    }
    // ready to send

//    send(sock, buffer, sizeof(buffer), 0);
//    recv(sock, buf, sizeof(buffer), 0);

    printf("Message: %s \n", message);
    send(sock, buf, sizeof(message), 0);
    recv(sock, buf, sizeof(message), 0);

    close(sock);
}
