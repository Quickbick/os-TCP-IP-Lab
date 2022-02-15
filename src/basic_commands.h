#include <stddef.h> //for NULL 
#include <stdio.h>
#include <string.h>

const char* const cmdList[] = {
    "get","put","ls","cd","pwd","mkdir","rmdir","rm",
    "lcat","lls","lcd","lpwd","lmkdir","lrmdir","lrm",0
};
int get() {
    printf("get\n");
    return 0;
}
//table of function pointers for the functions that take a char* as an argument and return an int
int (*fptr[])(char*)={(int(*)())
    get
};

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
int executeCommand(char* cmdLine) { 
    if (cmdLine == NULL) {
        printf("ERROR: NULL command\n");
        return -1;
    }
    int cmdIndex = findCmd(cmdLine);
    if (cmdIndex >= 0) {
        int r = fptr[cmdIndex](cmdLine);    //calls the function at the given command index for a command
        printf("r=%d\n", r);
    } else {
        printf("Error: command %s not found", cmdLine);
    }
    printf("end of processCommand\n");
}
