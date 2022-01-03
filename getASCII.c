#define _XOPEN_SOURCE_EXTENDED		// for -lncursesw

#include "getASCII.h"

char *getFilePath(){
	time_t t;
	char *filePath = (char*)malloc(MAX_FILE_PATH * sizeof(char));
	srand((unsigned)time(&t));

	switch(state){
		case 0:
			num_of_files = nsfw ? NUM_OF_NSFW_FILES : NUM_OF_NOT_NSFW_FILES;
			break;
		case 1:
			num_of_files = nsfw ? NUM_OF_NSFW_ANIMATION : NUM_OF_NOT_NSFW_ANIMATION;
			break;
	}

	// EXIT_FAILURE if num_of_files is 0
	check_error(num_of_files > 0, "no file to load");

	// Set filePath to current dir ../Booba/
	//getcwd(filePath, MAX_FILE_PATH);
	strcpy(filePath, dirPath);

	// FilePath is ../Booba/art/
	strcat(filePath, "/art/");
	if(state == 1)
		sprintf(filePath+strlen(filePath), "%c", 'a');
	sprintf(filePath+strlen(filePath), "%d", (rand() % num_of_files)+1);
	sprintf(filePath+strlen(filePath), "%c", nsfw ? '!' : '_'); 					// pametnije nesto
	strcat(filePath, ".txt");

	return filePath;
}

char **mallocBooba(){
	char **booba = (char**)malloc(MAX_HEIGHT * sizeof(char*));
	check_error(booba != NULL, "malloc");
	for(int i=0; i<MAX_HEIGHT; i++){
		booba[i] = (char*)malloc(MAX_WIDTH * sizeof(char));
		check_error(booba[i] != NULL, "malloc");
	}
	return booba;
}

void freeBooba(char **booba){
	for(int i=0; i<MAX_HEIGHT; i++)
		free(booba[i]);
	free(booba);
}

void getFrame(char **booba, FILE *file, int num_of_rows){
	int i;
	for(i=0; i<num_of_rows; i++){
		fgets(booba[i], MAX_WIDTH, file);
		addstr(booba[i]);
	}
}

void getAnimation(){

	int i = 0;
	int num_of_rows = -1;
	int num_of_frames = -1;

	char *filePath = getFilePath();
	FILE *file = fopen(filePath, "r");

	setlocale(LC_ALL,"");		// -lncursesw
	initscr();
	curs_set(0); 				//	remove cursor

	char **booba = mallocBooba();

	// Read first line of file to get num_of_rows and num_of_frames
	fgets(booba[0], MAX_WIDTH, file);
	sscanf(booba[0], "%d %d", &num_of_rows, &num_of_frames);

	check_error(num_of_rows > 0, "number of rows not valid");
	check_error(num_of_frames > 0, "number of frames not valid");

	// Remembering second line of file to be start offset for looping
	long start = ftell(file);
	check_error(start != -1, "ftell");

	while(1){
		move(0,0);
		getFrame(booba, file, num_of_rows);
		refresh();
		check_error(usleep(fps) != -1, "usleep");
		i++;
		if(i == num_of_frames){
			i = 0;
			check_error(lseek(fileno(file), start, 0) != -1, "lseek");
			}
	}
 	
	check_error(fclose(file) == 0, "fclose");
	freeBooba(booba);

	refresh(); 
	getch();
	
	endwin();

}

void getASCII(){

	int i;
		
	char *filePath = getFilePath();
	FILE *file = fopen(filePath, "r");
	check_error(file != NULL, "fopen");
		
	char **booba = mallocBooba();

	i=0;
	while(fgets(booba[i], MAX_WIDTH, file) != NULL){
		i++;
	}
	
	for(i=0; i<MAX_HEIGHT; i++){
		if(booba[i] == NULL)
			break;
		printf("%s", booba[i]);
	}

	check_error(fclose(file) == 0, "fclose");
	freeBooba(booba);
	free(filePath);
}
