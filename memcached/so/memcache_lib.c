
#include "memcache_lib.h"

char ip[128] = "127.0.0.1";
int port = 9739;


   //build socket
   char* build_socket(char* s){
        static char c[1024];
        strcpy(c,s);
        // socket
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
        //printf("Result from server = %s\n", c);  
        //close socket 
        close(sockfd);  
        return c;
   }

   
   //connet the server with the giving ip and port
   int mem_connect(char* _ip,int _port){
   	strcpy(ip,_ip);
   	port = _port;
   	return 0;
   }


   //get a value of the name on the server
    char* mem_get(char* name){ 
        char* c;
        c = (char*)malloc( sizeof(char*) * strlen(name) + 4 );
        strcpy(c,"get ");
        strcat(c,name);
        char* res = NULL;
        res = build_socket(c);
        free(c);
        return res;  
    }


   //set a key-value to the server
    char* mem_set(char* name,char* value){
        char* c;
        c = (char*)malloc( sizeof(char*) * (strlen(name)+strlen(value)) + 5 );
        strcpy(c,"set ");
        strcat(c,name);
        strcat(c," ");
        strcat(c,value);
        char* res = NULL;
        res = build_socket(c);
        free(c);
        return res;  
    }


    // int main(){
    // 	mem_connect("192.168.1.104",9739);
    // 	printf("res=%s\n",mem_get("name"));
    // 	printf("res=%s\n",mem_set("sex","male"));
    // }
