/*
This file contains the functionality needed to execute each command, such as the cmdList and
table of function pointers, as well as the related functions. 
*/
#include <stddef.h> //for NULL 
#include <stdio.h>
#include <string.h>

#define MAX 256

#include "commands.h" //contains the functions for each command

const char* const cmdList[] = {
    "get","put","ls","cd","pwd","mkdir","rmdir","rm",
    "lcat","lls","lcd","lpwd","lmkdir","lrmdir","lrm",0
};

//finds command's number in list
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

//figures out if command is local, server, or invalid
int checkType(char* line){
    char delim = ' ', cpyLine[MAX];
    char* token;
    int cmdNum = -1;
    strcpy(cpyLine, line);
    token = strtok(cpyLine, &delim);
    cmdNum = findCmd(token);
    if (cmdList >= 0 && cmdList <= 7){
        return 0; //0 server
    }
    else if (cmdList >= 8 && cmdList <=14){
        return 1; //1 local
    }
    else{
        return -1; //invalid command
    }
}
