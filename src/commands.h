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
struct stat mystat, *sp;
char *t1 = "xwrxwrxwr-------";
char *t2 = "----------------";

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
    DIR* temp;
    struct dirent* holder;
    memset(printHolder, NULL, strlen(printHolder));
    if (!filename) {
        filename = ".";
    }
    temp = opendir(filename);
    holder = readdir(temp);
    while (holder != NULL){
        slsFile(holder->d_name);
        holder = readdir(temp);
    }
    return 0;
}
int slsFile(char* fname){
    struct stat fstat, *sp;
    int r, i;
    char ftime[64], printBuffer[64];
    sp = &fstat;
    if ( (r = lstat(fname, &fstat)) < 0){
        sprintf(printBuffer, "can’t stat %s\n", fname);
        strcat(printHolder, printBuffer);
        exit(1);
    }
    if ((sp->st_mode & 0xF000) == 0x8000){ // if (S_ISREG())
        sprintf(printBuffer, "%c",'-');
        strcat(printHolder, printBuffer);
    }
    if ((sp->st_mode & 0xF000) == 0x4000){ // if (S_ISDIR())
        sprintf(printBuffer, "%c",'d');
        strcat(printHolder, printBuffer);
    }
    if ((sp->st_mode & 0xF000) == 0xA000){ // if (S_ISLNK())
        sprintf(printBuffer, "%c",'l');
        strcat(printHolder, printBuffer);
    }
    for (i=8; i >= 0; i--){
        if (sp->st_mode & (1 << i)){ // print r|w|x
            sprintf(printBuffer, "%c", t1[i]);
            strcat(printHolder, printBuffer);
        }
        else{
            sprintf(printBuffer,"%c", t2[i]); // or print -
            strcat(printHolder, printBuffer);
        }
    }
    sprintf(printBuffer, "%4d ",sp->st_nlink); // link count
    strcat(printHolder, printBuffer);
    sprintf(printBuffer, "%4d ",sp->st_gid); // gid
    strcat(printHolder, printBuffer);
    sprintf(printBuffer, "%4d ",sp->st_uid); // uid
    strcat(printHolder, printBuffer);
    sprintf(printBuffer, "%8d ",sp->st_size); // file size
    strcat(printHolder, printBuffer);
    // print time
    strcpy(ftime, ctime(&sp->st_ctime)); // print time in calendar form
    ftime[strlen(ftime)-1] = 0; // kill \n at end
    sprintf(printBuffer, "%s ",ftime);
    strcat(printHolder, printBuffer);
    // print name
    sprintf(printBuffer, "%s", basename(fname)); // print file basename
    strcat(printHolder, printBuffer);
    // print -> linkname if symbolic file
    if ((sp->st_mode & 0xF000)== 0xA000){
        char linkname[FILENAME_MAX];
        readlink(sp, linkname, FILENAME_MAX);
        sprintf(printBuffer, " -> %s", linkname); // print linked name
        strcat(printHolder, printBuffer);
    }
    sprintf(printBuffer, "\n");
    strcat(printHolder, printBuffer);
}
int cd(char* filename) {
    lcd(filename);
    return 0;
}
int pwd(char* filename) {
    lpwd(filename);
    return 0;
}
int mymkdir(char* filename) {
    lmkdir(filename);
    return 0;
}
int myrmdir(char* filename) {
    lrmdir(filename);
    return 0;
}
int rm(char* filename) {
    lrm(filename);
    return 0;
}
int lcat(char* filename) {
    sprintf(printHolder, "lcat, filename=%s\n", filename);
    return 0;
}
int lls(char* filename) {
    DIR* temp;
    struct dirent* holder;
    if (!filename) {
        filename = ".";
    }
    temp = opendir(filename);
    holder = readdir(temp);
    while (holder != NULL){
        lsFile(holder->d_name);
        holder = readdir(temp);
    }
    return 0;
}
int lsFile(char* fname){
    struct stat fstat, *sp;
    int r, i;
    char ftime[64];
    sp = &fstat;
    if ( (r = lstat(fname, &fstat)) < 0){
        printf("can’t stat %s\n", fname);
        exit(1);
    }
    if ((sp->st_mode & 0xF000) == 0x8000) // if (S_ISREG())
        printf("%c",'-');
    if ((sp->st_mode & 0xF000) == 0x4000) // if (S_ISDIR())
        printf("%c",'d');
    if ((sp->st_mode & 0xF000) == 0xA000) // if (S_ISLNK())
        printf("%c",'l');
    for (i=8; i >= 0; i--){
        if (sp->st_mode & (1 << i)) // print r|w|x
            printf("%c", t1[i]);
        else
        printf("%c", t2[i]); // or print -
    }
    printf("%4d ",sp->st_nlink); // link count
    printf("%4d ",sp->st_gid); // gid
    printf("%4d ",sp->st_uid); // uid
    printf("%8d ",sp->st_size); // file size
    // print time
    strcpy(ftime, ctime(&sp->st_ctime)); // print time in calendar form
    ftime[strlen(ftime)-1] = 0; // kill \n at end
    printf("%s ",ftime);
    // print name
    printf("%s", basename(fname)); // print file basename
    // print -> linkname if symbolic file
    if ((sp->st_mode & 0xF000)== 0xA000){
        char linkname[FILENAME_MAX];
        readlink(sp, linkname, FILENAME_MAX);
        printf(" -> %s", linkname); // print linked name
    }
    printf("\n");
}
int lrmdir(char* filename) {
    int r = rmdir(filename); 
    if (r < 0) {
        sprintf(printHolder, "lrmdir error, directory %s does not exist\n", filename);
    } else {
        sprintf(printHolder, "lrmdir success, filename=%s\n", filename);
    }
    return 0;
}
int lrm(char* filename) {
    int r = unlink(filename);
    if (r < 0) {
        sprintf(printHolder, "lrm error, file %s does not exist\n", filename);
    } else {
        sprintf(printHolder, "lrm success, filename=%s\n", filename);
    }
    return 0;
}
int lcd(char* filename) {
    int r = chdir(filename);
    if (r < 0) {
        sprintf(printHolder, "lcd error\n");
    } else {
        sprintf(printHolder, "lcd success\n");
    }
    return 0;
}
int lpwd(char* filename) {
    char buf[128];
    getcwd(buf, 128);
    sprintf(printHolder, "lpwd=%s\n", buf);
    return 0;
}
int lmkdir(char* filename) {
    int r = mkdir(filename, 0755);
    if (r < 0) {
        sprintf(printHolder, "lmkdir ERROR, (r=%d) directory: %s already exists\n", r, filename);
    } else {
        sprintf(printHolder, "lmkdir success, (r=%d) made directory %s\n", r, filename);
    }
    return 0;
}