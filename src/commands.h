/*
This file contains the functions for all the commands
*/

#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>

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
    if (!filename) {
        filename = ".";
    }
    sprintf(printHolder, "lls, filename=%s\n", filename);
    sprintf(printHolder, "test");
    struct stat fstat, *sp;
    char *t1 = "xwrxwrxwr-------";
    char *t2 = "----------------";
    int r, i; 
    char ftime[64]; 
    sp = &fstat;
    if ((r = lstat(filename, &fstat)) < 0) {
        printf("can't stat %s\n", filename); 
        exit(1);
    }
    if ((sp->st_mode & 0xF000) == 0x8000) { //if (S_ISREG())
        printf("%c", '-');
    }
    if ((sp->st_mode & 0xF000) == 0x4000) { //if (S_ISDIR())
        printf("%c", 'd');
    }
    if ((sp->st_mode & 0xF000) == 0xA000) { //if (S_ISLNK())
        printf("%c", 'l');
    }
    for (int i = 8; i >= 0; i--) {
        if (sp->st_mode & (1 << i)) { 
            printf("%c", t1[i]); //print r | w | x
        } else { 
            printf("%c", t2[i]); //or print -
        }
    }
    printf("%4d ", sp->st_nlink); //link count 
    printf("%4d ", sp->st_gid); //gid 
    printf("%4d ", sp->st_uid); //uid 
    printf("%8d ", sp->st_size); //file size 
    //print time 
    printf("%s", basename(filename)); //print file basename 
    //print -> linkname if symbolic file 
    // if ((sp->st_mode & 0xF000) == 0xA000) {
    //     //use readlink() to read linkname 
    //     printf(" -> %s", readlink(linkname));
    // }
    printf("\n");

    

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
int lcd(char* filename) {
    sprintf(printHolder, "lrm, filename=%s\n", filename);
}
int lpwd(char* filename) {
    sprintf(printHolder, "lrm, filename=%s\n", filename);
}
int lmkdir(char* filename) {
    sprintf(printHolder, "lrm, filename=%s\n", filename);
}
