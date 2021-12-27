/*		sudo apt-get install libncurses5-dev
*
* 		export PATH="/home/vukasin/Desktop/Booba:$PATH"
* 		Booba
* 		echo -e ""
*
*/

#define _XOPEN_SOURCE 500

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
#include "getAnimation.h"

#define MAX_WIDTH 256
#define MAX_HEIGHT 256
#define MAX_FILE_PATH 128

#define NUM_OF_NSFW_FILES 13
#define NUM_OF_NOT_NSFW_FILES 2

#define UTIME 150000

#define check_error(cond, userMsg)\
	do{\
		if(!(cond)){\
			perror(userMsg);\
			fprintf(stderr, "%s:%d\n", __FILE__, __LINE__);\
			exit(EXIT_FAILURE);\
		}\
	}while(0)

bool nsfw = true;
int num_of_files = 0;


int main(int argc, char **argv){


	if(argc == 1)
		getASCII();
	else
		getAnimation();

	return 0;
}










