#include <stddef.h> //for NULL 
#include <stdio.h>
#include <string.h>

const char* const cmdList[] = {
    "get","put","ls","cd","pwd","mkdir","rmdir","rm",
    "lcat","lls","lcd","lpwd","lmkdir","lrmdir","lrm",0
};


int processCommand(char* cmdLine) {
    if (cmdLine == NULL) {
        printf("ERROR: NULL command\n");
        return -1;
    }

    printf("end of processCommand\n");
}

int findCmd(char* command) { //returns the index of a command 
    int i = 0;
    while (cmdList[i] != 0) {
        if (strcmp(command, cmdList[i]) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}