#ifndef __GET_ASCII_H__
#define __GET_ASCII_H__

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#include<curses.h>
#include<locale.h>
#include<sys/types.h>

#include "getASCII.h"

#define MAX_WIDTH 256
#define MAX_HEIGHT 128
#define MAX_FILE_PATH 128

#define NUM_OF_NSFW_FILES 13
#define NUM_OF_NOT_NSFW_FILES 2
#define NUM_OF_NSFW_ANIMATION 1
#define NUM_OF_NOT_NSFW_ANIMATION 0

#define UTIME 100000

#define check_error(cond, userMsg)\
	do{\
		if(!(cond)){\
			perror(userMsg);\
			fprintf(stderr, "%s:%d\n", __FILE__, __LINE__);\
			exit(EXIT_FAILURE);\
		}\
	}while(0)

char *getFilePath();
char **mallocBooba();
void freeBooba(char**);
void getFrame(char**, FILE*, int);
void getASCII();
void getAnimation();
void getFrame();

#endif
