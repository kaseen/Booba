// export PATH="/home/vukasin/Desktop/Booba:$PATH"
// exec Booba&

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 200
#define MAX_FILE_PATH 50
#define NUM_OF_NSFW_FILES 6
#define NUM_OF_NOT_NSFW_FILES 2

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

char *getFilePath(){
	time_t t;
	
	num_of_files = nsfw ? NUM_OF_NSFW_FILES : NUM_OF_NOT_NSFW_FILES;
	srand((unsigned) time(&t));
	
	char *filePath = (char *)malloc(MAX_FILE_PATH*sizeof(char));
	strcat(filePath, "/home/vukasin/Desktop/Booba/");
	sprintf(filePath+strlen(filePath), "%d", (rand() % num_of_files)+1);
	sprintf(filePath+strlen(filePath), "%c", nsfw ? '!' : '_');
	strcat(filePath, ".txt");
	
	return filePath;
}

int main(){

	int i;
	char *filePath = getFilePath();

	FILE *file = fopen(filePath, "r");
	check_error(file != NULL, "fopen");
		
	char **booba = (char **)malloc(MAX_HEIGHT*sizeof(char*));
	check_error(booba != NULL, "malloc");
	for(i=0; i<MAX_WIDTH; i++){
		booba[i] = (char *)malloc(MAX_WIDTH*sizeof(char));
		check_error(booba[i] != NULL, "malloc");
	}

	i=0;
	while(fgets(booba[i], MAX_WIDTH, file) != NULL){
		i++;
	}

	check_error(fclose(file) == 0, "flose");
	
	for(i=0; i<MAX_HEIGHT; i++){
		if(booba[i] == NULL)
			break;
		printf("%s", booba[i]);
	}

	return 0;
}










