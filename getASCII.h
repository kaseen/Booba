#ifndef __GET_ASCII_H__
#define __GET_ASCII_H__

#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<time.h>
#include<stdbool.h>

#define MAX_WIDTH 256
#define MAX_HEIGHT 256
#define MAX_FILE_PATH 128

#define NUM_OF_NSFW_FILES 13
#define NUM_OF_NOT_NSFW_FILES 2

#define check_error(cond, userMsg)\
	do{\
		if(!(cond)){\
			perror(userMsg);\
			fprintf(stderr, "%s:%d\n", __FILE__, __LINE__);\
			exit(EXIT_FAILURE);\
		}\
	}while(0)

char *getFilePath();
void getASCII();

#endif
