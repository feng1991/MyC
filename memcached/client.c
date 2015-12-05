
    #include <unistd.h>  
    #include <sys/types.h>  
    #include <sys/socket.h>  
    #include <netinet/in.h>  
    #include <stdlib.h>  
    #include <stdio.h>
    #include <string.h>  
      



    int main(int argc, char *argv[])  
    {  
        // prepare the string which will be send to the server
        char c[] = "set:name:feng"; 
        //char c[] = "get:name";
        if(argc > 1){
            strcpy(c,argv[1]);
        }
        printf("send to server = %s\n", c);

        // socket
        char ip[] = "127.0.0.1";
        int port  = 9739;
        struct sockaddr_in server_addr;  
        int server_len = 0;  
        int sockfd = -1;  
        int result = 0; 
        //create udp socket
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);  
        //set ip and port 
        server_addr.sin_family = AF_INET;  
        server_addr.sin_addr.s_addr = inet_addr(ip);  
        server_addr.sin_port = htons(port);  
        //send socket
        sendto(sockfd, &c, sizeof(c), 0,  (struct sockaddr*)&server_addr, sizeof(server_addr));  
        //receive  
        recvfrom(sockfd, &c, sizeof(c), 0, 0, 0);  
        printf("result from server = %s\n", c);  
        //close socket 
        close(sockfd);  
        exit(0);   
    }  
