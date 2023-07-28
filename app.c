/*		sudo apt-get install libncurses5-dev
*
*		1.) Add to config()
*		FILE *conf = fopen(PATH_OF_CONF_FILE, "r");
*
* 		2.) export PATH="/home/USER/Desktop/Booba:$PATH"
*		booba shake
* 		booba
*
*/

#define _XOPEN_SOURCE 500

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "getASCII.h"
#include "config.h"

#define check_error(cond, userMsg)\
	do{\
		if(!(cond)){\
			perror(userMsg);\
			fprintf(stderr, "%s:%d\n", __FILE__, __LINE__);\
			exit(EXIT_FAILURE);\
		}\
	}while(0)

#define seconds_to_useconds(x) ((useconds_t)(x*1000000))
#define MAX_FILE_PATH 128

#define ASCII (0)
#define Animation (1)

// TODO: enum State {ASCII = 0, Animation = 1}; 
// enum State state = 0;

int state;
char *dirPath;
useconds_t fps;

int main(int argc, char **argv){

	dirPath = (char*)malloc(MAX_FILE_PATH*sizeof(char));

	fps = seconds_to_useconds(__FPS__);

	if(argc == 1){
		state = ASCII;
		getASCII();
	}else if(strcmp(argv[1], "shake") == 0){
		state = Animation;
		getAnimation();
	}

	return 0;
}