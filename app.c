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

bool nsfw = false;
int num_of_files = 0;
int state = 0;

// TODO: enum State {ASCII = 0, Animation = 1}; 
// enum State state = 0;

// brise se kad se ubaci enum
#define Animation (1)
#define ASCII (0)

int main(int argc, char **argv){

	if(argc == 1){
		state = ASCII;
		getASCII();
	}else if(strcmp(argv[1], "shake") == 0){
		state = Animation;
		getAnimation();
	}

	return 0;
}
