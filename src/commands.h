/*
This file contains the functions for all the commands
*/

#include <stdio.h>
#include <string.h>

char printHolder[2000];

// int get() {
//     printf("get\n");
//     return 0;
// }
int get(char* filename) {
    sprintf(printHolder, "get, filename=%s\n", filename);
    return 0;
}
int put(char* filename) {
    sprintf(printHolder, "put, filename=%s\n", filename);
    return 0;
}
int ls(char* filename) {
    sprintf(printHolder, "ls, filename=%s\n", filename);
    return 0;
}
int cd(char* filename) {
    sprintf(printHolder, "cd, filename=%s\n", filename);
    return 0;
}
int pwd(char* filename) {
    sprintf(printHolder, "pwd, filename=%s\n", filename);
    return 0;
}
int mymkdir(char* filename) {
    sprintf(printHolder, "mymkdir, filename=%s\n", filename);
    return 0;
}
int myrmdir(char* filename) {
    sprintf(printHolder, "myrmdir, filename=%s\n", filename);
    return 0;
}
int rm(char* filename) {
    sprintf(printHolder, "rm, filename=%s\n", filename);
    return 0;
}
int lcat(char* filename) {
    sprintf(printHolder, "lcat, filename=%s\n", filename);
    return 0;
}
int lls(char* filename) {
    sprintf(printHolder, "lls, filename=%s\n", filename);
    return 0;
}
int lcd(char* filename) {
    sprintf(printHolder, "lcd, filename=%s\n", filename);
    return 0;
}
int lpwd(char* filename) {
    sprintf(printHolder, "lpwd, filename=%s\n", filename);
    return 0;
}
int lmkdir(char* filename) {
    sprintf(printHolder, "lmkdir, filename=%s\n", filename);
    return 0;
}
int lrmdir(char* filename) {
    sprintf(printHolder, "lrmdir, filename=%s\n", filename);
    return 0;
}
int lrm(char* filename) {
    sprintf(printHolder, "lrm, filename=%s\n", filename);
    return 0;
}
