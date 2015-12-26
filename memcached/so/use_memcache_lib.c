
#include "memcache_lib.h"

int main(){
	mem_connect("192.168.1.104",9739);
    	printf("res=%s\n",mem_get("name"));
    	printf("res=%s\n",mem_set("sex","male"));
	return 0;
}