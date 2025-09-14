
//accept four command line arguments
//-h output help message, then terminate
//-n proc → Total number of children to launch.
//-s simul → Maximum number of children allowed to run simultaneously.
//-t iter → A number that will be passed as an argument to the user processes 
//(they will use it for their iterations).





#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    int opt;
    int n = 0, t = 0, s = 0;

    //get command line arguments
    while ((opt = getopt(argc, argv, "n:t:s:h")) != -1) {
        switch (opt) {
            case 'n':
                n = atoi(optarg); 
                break;
            case 't':
                t = atoi(optarg);
                break;
            case 's':
                s = atoi(optarg);
                break;
            case 'h':
                printf("Arguments: [-n proc] [-s simul] [-t iter]. ");
                printf("-n : Total number of children to launch.");
                printf("-s : Maximum number of children allowed to run simultaneously.");
                printf("-t : A number that will be passed as an argument to the user processes.");
        }
    }


    int children_launched = 0; 
    int children_running = 0;


    //while children launched is less than n keep launching more
    while(children_launched < n){   

        //while number of children runnning is less than -s make more
        while(children_running < s){

            __pid_t pid = fork();

            //if its a child- run user.c
            if(pid == 0){
                execl("./user", "user",  NULL);
                
            }

            //keep track of children
            else if (pid > 0)
            {
                children_launched++;
                children_running++;
            }
            

        }

    }

    //Wait until all children launched have been terminated
    printf("All children terminated. Total number launched: %d", n);


    return 0;
}
