
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "tool.c"


int main(int argc,char* argv[]){
	if(argc != 2){
		dump("Parameter Wrong! Please input like php.o test.php!",1);
	}
	char * text = read_file(argv[1]);
	dump(text,0);

}