#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

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
char path[1000];
getcwd(path,1000);
printf("\n%s >",path);

/*printf("submit\n");
printf("run\n");
printf("kill\n");
printf("exit\n");
printf("tell the command to proceed: "); */

//scanf("%s",command);
fgets(command,100,stdin);
command[strcspn(command,"\n")]='\0';
char* token=strtok(command," \n"); //delimter is space and \n as we want to broke the token when space comes and /n
    char* args[100];
    int i=0;
     while(token){
        args[i]=token;
        token=strtok(NULL," \n");
        i++;
     }
     args[i]=NULL;




if(strcmp(command,"submit")==0){
    if(args[1]==0) printf("provide the filename first");
    else if(rear==MAX) printf("array is full delete few program \n");
    else{
    //scanf("%s",filename);
    arr[rear]=pid;
    ++rear;
    ++pid;
    printf("pid %d submitted in %s \n",arr[rear-1],args[1]);
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
else if(strcmp(command,"cd")==0){
    if(args[1]==NULL)
     printf(" Can't change the directory as No filename has been given\n");
    else if(chdir(args[1])==-1) 
    printf(" No file exits of that name,insure the correct filename has been provided\n");
    //printf("%s",path);
  
}
else{
    //char* args[]={command,NULL};
    int fid = fork();
    if(fid==0) execvp(args[0],args);
    else if(fid>0) wait(NULL);
    else printf("fork failed");
}

}


    return 0;
}
