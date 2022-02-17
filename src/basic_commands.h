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

//table of function pointers for the functions that take a char* as an argument and return an int
//the char* is for the argument
int (*fptr[])(char*)={(int(*)()) 
    get,put,ls,cd,pwd,mymkdir,myrmdir,rm,lcat,lls,lcd,lpwd,lmkdir,lrmdir,lrm
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
    if (cmdNum >= 2 && cmdNum <= 7){
        return 0; //0 server
    }
    else if (cmdNum >= 8 && cmdNum <=14){
        return 1; //1 local
    }
    else if (cmdNum >= 0 && cmdNum <= 1){
        return 2; //special
    }
    else{
        return -1; //invalid command
    }
}

//runs basic command
int executeCommand(char* cmdLine) {
    char delim = ' ';
    char* token;
    token = strtok(cmdLine, &delim);
    if (token != NULL){
        token = strtok(NULL, &delim);
    }
    int cmdIndex = findCmd(cmdLine);
    if (cmdIndex >= 0) {
        //calls the function at the given command index
        int r = fptr[cmdIndex](token);
        printf("r=%d\n", r);
    } else {
        printf("Error: command %s not found\n", cmdLine);
    }
    printf("end of processCommand\n");
}