/*
This file contains the functions for all the commands
*/

#include <stdio.h>
#include <string.h>

// int get() {
//     printf("get\n");
//     return 0;
// }
int get(char* filename) {
    printf("get, filename=%s\n", filename);
    return 0;
}
int put(char* filename) {
    printf("put, filename=%s\n", filename);
    return 0;
}
int ls(char* filename) {
    printf("ls, filename=%s\n", filename);
    return 0;
}
int cd(char* filename) {
    printf("cd, filename=%s\n", filename);
    return 0;
}
int pwd(char* filename) {
    printf("pwd, filename=%s\n", filename);
    return 0;
}
int mymkdir(char* filename) {
    printf("mymkdir, filename=%s\n", filename);
    return 0;
}
int myrmdir(char* filename) {
    printf("myrmdir, filename=%s\n", filename);
    return 0;
}
int rm(char* filename) {
    printf("rm, filename=%s\n", filename);
    return 0;
}
int lcat(char* filename) {
    printf("lcat, filename=%s\n", filename);
    return 0;
}
int lls(char* filename) {
    printf("lls, filename=%s\n", filename);
    return 0;
}
int lcd(char* filename) {
    printf("lcd, filename=%s\n", filename);
    return 0;
}
int lpwd(char* filename) {
    printf("lpwd, filename=%s\n", filename);
    return 0;
}
int lmkdir(char* filename) {
    printf("lmkdir, filename=%s\n", filename);
    return 0;
}
int lrmdir(char* filename) {
    printf("lrmdir, filename=%s\n", filename);
    return 0;
}
int lrm(char* filename) {
    printf("lrm, filename=%s\n", filename);
    return 0;
}