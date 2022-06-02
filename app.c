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

bool nsfw;
int state;
char *dirPath;
useconds_t fps;

void config(){
	FILE *conf = fopen("/home/vukasin/Booba/config", "r");
	check_error(conf != NULL, "fopen");
	
	// Reads first line of config
	fgets(dirPath, MAX_FILE_PATH, conf);
	
	int readCfgNsfw;
	float readCfgFps;
	sscanf(dirPath, "%d %f", &readCfgNsfw, &readCfgFps);
	nsfw = (bool)readCfgNsfw;
	fps = seconds_to_useconds(readCfgFps);
	
	// Reads second line of config
	fgets(dirPath, MAX_FILE_PATH, conf);
	// Remove '\n' from dirPath
	dirPath[strlen(dirPath)-1] = 0;

	check_error(fclose(conf) == 0, "fclose");
}

int main(int argc, char **argv){

	dirPath = (char*)malloc(MAX_FILE_PATH*sizeof(char));

	config();

	if(argc == 1){
		state = ASCII;
		getASCII();
	}else if(strcmp(argv[1], "shake") == 0){
		state = Animation;
		getAnimation();
	}

	return 0;
}