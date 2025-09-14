//take in 1 command line argument = x
//loop x times
//inside the loop:
//print PID, parents PID, what number of the loop it is on, sleep(1), then loop again

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc < 2) {
        fprintf(stderr, "Usage: %s iterations\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int counter = 1;

    for(int i = 0; i < x; i++){
        printf("USER PID:%d PPID:%d Iteration:%d before sleeping\n", getpid(), getppid(), counter);
        sleep(1);
        printf("USER PID:%d PPID:%d Iteration:%d after sleeping\n", getpid(), getppid(), counter);
        counter += 1;

    }

    return 0;
}