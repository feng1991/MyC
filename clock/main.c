#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

int main(){
    int n = 0;
    int l = 5000;
    int i = 0;
    time_t rawtime;

    time(&rawtime);
    printf("Current time : %sPlease input the times and seconds you want to alert: ",
           ctime(&rawtime));
    scanf("%d %d",&n,&l);
    l = (l <= 0) ? 1 : l;
    l = l * 1000;
    n = (n <= 0) ? 1 : n;
    //printf("%d %d",n,l);exit(0);
    while(i < n){
        Sleep(l);
        Beep(500,1000);
        MessageBox(NULL,"title","ok",MB_OK);
        i++;
    }
    return 0;
}
