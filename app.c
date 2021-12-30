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

#define ASCII (0)
#define Animation (1)

// TODO: enum State {ASCII = 0, Animation = 1}; 
// enum State state = 0;

bool nsfw;
int state;
useconds_t fps;

void config(){
	FILE *conf = fopen("config", "r");
	check_error(conf != NULL, "fopen");

	int tmp;
	float tmp2;
	fscanf(conf, "%d %f", &tmp, &tmp2);
	nsfw = (bool)tmp;
	fps = seconds_to_useconds(tmp2);

	check_error(fclose(conf) == 0, "fclose");
}

int main(int argc, char **argv){

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
