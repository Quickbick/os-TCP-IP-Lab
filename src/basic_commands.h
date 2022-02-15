/*
This file contains the functionality needed to execute each command, such as the cmdList and
table of function pointers, as well as the related functions. 
*/
#include <stddef.h> //for NULL 
#include <stdio.h>
#include <string.h>

#include "commands.h" //contains the functions for each command

const char* const cmdList[] = {
    "get","put","ls","cd","pwd","mkdir","rmdir","rm",
    "lcat","lls","lcd","lpwd","lmkdir","lrmdir","lrm",0
};
//table of function pointers for the functions that take a char* as an argument and return an int
int (*fptr[])(char*)={(int(*)())
    get,put,ls,cd,pwd,mymkdir,myrmdir,rm,lcat,lls,lcd,lpwd,lmkdir,lrmdir,lrm
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
        printf("Error: command %s not found\n", cmdLine);
    }
    printf("end of processCommand\n");
}
