#include<stdio.h>
#include<string.h>

int main(){

while(1){
    printf("myshell> ");
    char c[100];
    scanf("%s",c);
    if(strcmp(c,"exit")==0) break;
}


    return 0;
}
