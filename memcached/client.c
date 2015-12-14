
    #include <unistd.h>  
    #include <sys/types.h>  
    #include <sys/socket.h>  
    #include <netinet/in.h>  
    #include <stdlib.h>  
    #include <stdio.h>
    #include <string.h>  
    #include "tool.c"



   // format the input string
    int getArgv(int argc, char *argv[],char* c){
        if(argc < 2){
            return -1;
        }
        char* oper = strtolower(argv[1]);
        if(0 == strcmp(oper,"set")){
            if(argc != 4){
                    return -1;
            }
        }else if(0 == strcmp(oper,"get")){
            if(argc != 3){
                    return -1;
            }
        }else{
            return -1;
        }
        int i = 0;
        for(i = 1;i < argc;i ++){
            strcat(c,argv[i]);
            strcat(c," ");
        }
        return 1;
    }



   //build socket
   void build_socket(char* s){
        //it not strcpy then wrong ?????
        char c[1024];
        strcpy(c,s);
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
        printf("Result from server = %s\n", c);  
        //close socket 
        close(sockfd);  
   }



    int main(int argc, char *argv[])  
    {  
        // prepare the string which will be send to the server
        char c[1024] = ""; 
        int res = getArgv(argc,argv,c);
        if(res == -1){
            printf("Wrong paramer!\n");
            exit(0);
        }else{
            printf("Send to server = %s\n", c);
        }
        return 0;
        build_socket(c);
        return 0;  
    }  
