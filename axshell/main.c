#include<stdio.h>
#include<string.h>
#define MAX 3

int main(){
 char command[100];
char filename[1000];
int arr[MAX];
int front=0;
int rear=0;
int run_idx=0;
int pid=1;

while(1){
printf("submit\n");
printf("run\n");
printf("kill\n");
printf("exit\n");
printf("tell the command to proceed: ");
scanf("%s",command);

if(strcmp(command,"submit")==0){
     if(rear==MAX) printf("array is full delete few program \n");
    else{
    printf("type the filename: ");
    scanf("%s",filename);
    arr[rear]=pid;
    ++rear;
    ++pid;
    printf("pid %d submitted in %s \n",arr[rear-1],filename);
    }
   
}
else if(strcmp(command,"run")==0){
    if(run_idx<rear) {
        printf("pid %d running \n",arr[run_idx]); 
        ++run_idx;
    }
    else
    printf("add the program to run \n");
}
else if(strcmp(command,"kill")==0){
    if(front<run_idx) {
        printf("pid %d killed \n",arr[front]);
        ++front;  
    }
    else 
     printf("no program to kill \n");

//reset block 
if(front==run_idx && run_idx==rear && front>0){
    front=0;
    run_idx=0;
    rear=0;
    pid=1;
}
}
else if(strcmp(command,"exit")==0){
    printf("\n");
    break;

}

}


    return 0;
}
