#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <libgen.h>     // for dirname()/basename()
#include <time.h> 

#include "../basic_commands.h"

#define MAX 256
#define PORT 1234

char line[MAX], ans[MAX];
int n;

struct sockaddr_in saddr; 
int sfd;

int main(int argc, char *argv[], char *env[]) { 
    int n; char how[64];
    int i, type;

    printf("1. create a socket\n");
    sfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sfd < 0) { 
        printf("socket creation failed\n"); 
        exit(0); 
    }
    
    printf("2. fill in server IP and port number\n");
    bzero(&saddr, sizeof(saddr)); 
    saddr.sin_family = AF_INET; 
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    saddr.sin_port = htons(PORT); 
  
    printf("3. connect to server\n");
    if (connect(sfd, (struct sockaddr *)&saddr, sizeof(saddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 

    char temp[128];
    chroot(getcwd(temp, 128));
    printf("********  processing loop  *********\n");
    while (1){
        memset(printHolder, NULL, strlen(printHolder));
        printf("input a line : ");
        bzero(line, MAX);                // zero out line[ ]
        fgets(line, MAX, stdin);         // get a line (end with \n) from stdin

        line[strlen(line)-1] = 0;        // kill \n at end
        if (line[0]==0){                 // exit if NULL line
            exit(0);
        }

        type = checkType(line);
        if (type == 0){
            printf("Type=server\n");
            // Send ENTIRE line to server
            n = write(sfd, line, MAX);
            printf("client: wrote n=%d bytes; line=(%s)\n", n, line);

            // Read a line from sock and show it
            n = read(sfd, ans, 2000);
            printf("print holder client side=%s", ans); //prints the result 
        }
        else if (type == 1){ //run the command locally 
            printf("Type=client\n");
            //executes command
            executeCommand(line); //runs the command locally 
            printf("print holder=%s\n", printHolder); //prints the result 
        }
        else if (type == 2){ //special for get and put
            char delim = ' ';
            char* token;
            token = strtok(line, &delim);
            if (token != NULL){
                token = strtok(NULL, &delim);
            }
            int cmdIndex = findCmd(line);
            if(cmdIndex == 0){ //get
                printf("Into put \n");
                n = write(sfd, line, MAX);
                printf("client: wrote n=%d bytes; line=(%s)\n", n, line);
                n = write(sfd, token, MAX);
                FILE* outfile;
                outfile = fopen(token, "w");
                while(1){
                    bzero(ans, MAX);
                    read(sfd, ans, MAX);
                    if(strcmp(ans, "$$$$") == 0){
                        break;
                    }
                    fprintf(outfile, "%s", ans);
                }
                fclose(outfile);
            }
            else{ //put
                n = write(sfd, line, MAX);
                n = write(sfd, token, MAX);
                FILE* infile;
                infile = fopen(token, "r");
                printf("File opened\n");
                while (1){
                    if(feof(infile)){
                        write(sfd, "$$$$", MAX);
                        break;
                    }
                    fgets(ans, MAX, infile);
                    printf("%s\n", ans);
                    write(sfd, ans, MAX);
                    bzero(ans, MAX);
                }
                fclose(infile);
            }
        }
    }
}