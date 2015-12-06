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








#define MAX_MEM_LENGTH 255

//the key struct which store the key-value variables
typedef struct Mem{
	char key[255];
	char value[255];
	int ctime;
	int utime;
}Mem;

//global 
Mem mem[MAX_MEM_LENGTH];
int mem_len = 0;

//add a key-value to mem
int mem_add(char* key,char* value){
	if(mem_len >= MAX_MEM_LENGTH){
		return -1;
	}
	strcpy(mem[mem_len].key,key);
	strcpy(mem[mem_len].value,value);
	int t = time(0);
	mem[mem_len].ctime  = t;
	mem[mem_len].utime  = t;
	mem_len ++;
	return 0;
}

//get a value in mem from a designated key
char* mem_get(char* key){
	int i;
	for(i = 0;i < mem_len;i ++){
		if(0 == strcmp(key,mem[i].key)){
			return mem[i].value;
		}
	}
	return NULL;
}

//get the location of a key in mem
int mem_get_location(char* key){
	int i;
	for(i = 0;i < mem_len;i ++){
		if(0 == strcmp(key,mem[i].key)){
			return i;
		}
	}
	return -1;
}

//set a key-value to mem,if key exists,update the value
int mem_set(char* key,char* value){
	int location = mem_get_location(key);
	if(-1 == location){
		return mem_add(key,value);
	}else{
		strcpy(mem[location].value,value);
		mem[location].utime = time(0);
		return 0;
	}
}

//print all the key-value in men
void mem_dump(){
	int i;
	printf("\nstart dumping from mem\n");
	for(i =0 ;i < mem_len;i ++){
		printf("%s : %s\n",mem[i].key,mem[i].value);
	}
	printf("stop dumping from mem\n\n");
}











// printf string
void dump(char* str){
	if(str == NULL){
		printf("NULL\n");	
	}else{
		printf("%s\n",str);
	}
}

// printf int
void dump_d(int i){
	printf("%d\n",i);
}











//keep running to listen and response with socket
void build_socket(){
        int server_sockfd = -1;  
        int server_len = 0;  
        int client_len = 0;  
        char buffer[512];  
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
      
        char s[] = ":";
        char oper[255];
        char key[255];
        char value[255];
        while(1)  
        {     
            memset(buffer,0,512);
            //receive data and source  
            result = recvfrom(server_sockfd, buffer, sizeof(buffer), 0,  (struct sockaddr*)&client_addr, &client_len);  
            //if(fork() == 0)  
            //{  
                 printf("Get from client:%s\n",buffer);
                 //mem_dump();  
                 //oper = strtok(buffer,s);
                 //key = strtok(NULL,s);
                 strcpy(oper,strtok(buffer,s));
                 strcpy(key,strtok(NULL,s));
	   if(0 == strcmp(oper,"set")){
	   	//value = strtok(NULL,s);
	   	strcpy(value,strtok(NULL,s));
		mem_set(key,value);
		strcpy(buffer,"ok");
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




