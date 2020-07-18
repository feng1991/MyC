#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include <windows.h>
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <signal.h>  
#include "tool.c"
#include "memcache.c"

#define BUFFER_SIZE 1024

//keep running to listen and response with socket
void build_socket(){
        int server_sockfd = -1;  
        int server_len = 0;  
        int client_len = 0;  
        char buffer[BUFFER_SIZE];  
        int result = 0;  
        int port  = 9739;
        struct sockaddr_in server_addr;  
        struct sockaddr_in client_addr;  
        //create udp socket
        server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);  
        //set ip and port
        server_addr.sin_family = AF_INET;  
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);  
        server_addr.sin_port = htons(port);  
        //bind socket
        bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));  
        //ignore child process exit signal  
       //signal(SIGCHLD, SIG_IGN);  
      
        char s[] = " ";
        char* oper;
        char* key;
        char* value;
        int mem_result = 0;
        while(1)  
        {     
            memset(buffer,0,BUFFER_SIZE);
            //receive data and source  
            result = recvfrom(server_sockfd, buffer, sizeof(buffer), 0,  (struct sockaddr*)&client_addr, &client_len);  
            //if(fork() == 0)  
            //{  
                 printf("Get from client:%s\n",buffer);
                 oper = strtok(buffer,s);
                 key = strtok(NULL,s);
	   if(0 == strcmp(oper,"set")){
	   	value = strtok(NULL,s);
		mem_result = mem_set(key,value);
		if(mem_result == -1){
			strcpy(buffer,"Sorry,operation fail");
		}else{
			strcpy(buffer,"ok");
		}
	   }else if(0 == strcmp(oper,"get")){		
		strcpy(buffer,mem_get(key));
	   }
	   printf("Send to client:%s\n",buffer);
                //send response 
                sendto(server_sockfd, buffer, sizeof(buffer),0 , (struct sockaddr*)&client_addr, client_len); 
                mem_dump();
                //exit(0);  
            //}  
        }  
        //close socket 
        close(server_sockfd);  
}




int main()
{
    while(1){
    	mem_set("test","yes");
	build_socket();
	 //Sleep(1000);
    }
   return 0;
}




