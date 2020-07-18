
#ifndef MEMCACHE_LIB_H
#define MEMCACHE_LIB_H

#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <stdlib.h>  
#include <stdio.h>
#include <string.h>  

#endif

int mem_connect(char* _ip,int _port);
char* mem_get(char* name);
char* mem_set(char* name,char* value);