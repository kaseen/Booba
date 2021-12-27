#define _XOPEN_SOURCE_EXTENDED										// for -lncursesw

#include "getASCII.h"
	
extern bool nsfw;
extern int num_of_files;

char *getFilePath(){
	time_t t;
	
	num_of_files = nsfw ? NUM_OF_NSFW_FILES : NUM_OF_NOT_NSFW_FILES;
	srand((unsigned)time(&t));
	
	char *filePath = (char*)malloc(MAX_FILE_PATH * sizeof(char));
	// REFAKTORISATI PATH
	strcat(filePath, "/home/vukasin/Desktop/Booba/art/");
	sprintf(filePath+strlen(filePath), "%d", (rand() % num_of_files)+1);
	sprintf(filePath+strlen(filePath), "%c", nsfw ? '!' : '_');
	strcat(filePath, ".txt");
	
	return filePath;
}

void getASCII(){

	int i;
		
	char *filePath = getFilePath();
	FILE *file = fopen(filePath, "r");
	check_error(file != NULL, "fopen");
		
	char **booba = (char**)malloc(MAX_HEIGHT * sizeof(char*));
	check_error(booba != NULL, "malloc");
	for(i=0; i<MAX_WIDTH; i++){
		booba[i] = (char*)malloc(MAX_WIDTH * sizeof(char));
		check_error(booba[i] != NULL, "malloc");
	}

	i=0;
	while(fgets(booba[i], MAX_WIDTH, file) != NULL){
		i++;
	}
	
	check_error(fclose(file) == 0, "fclose");
	
	for(i=0; i<MAX_HEIGHT; i++){
		if(booba[i] == NULL)
			break;
		printf("%s", booba[i]);
	}
	
	for(i=0; i<MAX_HEIGHT; i++)
		free(booba[i]);
	free(booba);
	free(filePath);
}
