#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define F_PATH "1.txt"


void append_file(char* file,char* str){
    FILE *pFile = fopen(file,"a");
    fwrite(str,1,strlen(str),pFile);
    fclose(pFile);
}

char* read_file(char* file){
	FILE *fp = fopen(file,"r");
	if(NULL == fp){
		return -1;
	}
	char buf[20];
	fread(buf,1,2,fp);
	fclose(fp);
	fp = null;
	return buf;
}


int main()
{
    while(1){
        char* str = "hello\n";
        append_file(F_PATH,str);
        Sleep(1000);
    }
   return 0;
}


//int main(void)
//{
//    FILE*fp = NULL;
//    fp = fopen(F_PATH,"r");
//    if(NULL == fp)
//    {
//        return -1;
//    }
//    char buf[20];
//    fread(buf,1,2,fp);
//    fclose(fp);
//    fp = NULL;
//    printf("%d\n",strlen(buf));
//    printf("%s\n",buf);
//    getchar();
//    return 0;
//}


