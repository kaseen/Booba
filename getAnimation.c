#define _XOPEN_SOURCE_EXTENDED										// for -lncursesw

#include "getAnimation.h"

void getFrame(char **booba, FILE *file, int A_ROWS){
	int i;
	for(i=0; i<A_ROWS; i++){
		fgets(booba[i], MAX_WIDTH, file);
		addstr(booba[i]);
	}
}

void getAnimation(){

	int i;
	int A_ROWS = 0;

	setlocale(LC_ALL,"");		// -lncursesw
	initscr();
	curs_set(0); 				//	remove cursor
	
	// TODO: LEPSE UCITAVANJE PATHA
	char *filePath = "/home/vukasin/Desktop/Booba/art/a1.txt";
	
	FILE *file = fopen(filePath, "r");
	// TODO: fclose
	
	// TODO: Dodati MAX_SIZE i free
	char **booba = (char**)malloc(MAX_HEIGHT * sizeof(char*));
	check_error(booba != NULL, "malloc");
	for(i=0; i<MAX_WIDTH; i++){
		booba[i] = (char*)malloc(MAX_WIDTH * sizeof(char));
		check_error(booba[i] != NULL, "malloc");
	}
	
	fgets(booba[0], 100, file);
	A_ROWS = atoi(booba[0]);

	// TODO: NUM OF FRAMES
	// TODO: NUM OF LSEEK
	i = 0;
	while(1){
		move(0,0);
		getFrame(booba, file, A_ROWS);
		refresh();
		usleep(UTIME);
		i++;
		if(i == 7){
			i = 0;
			lseek(fileno(file), 3, 0);
			}
	}
 	
	refresh(); 
	getch();
	
	endwin();
}
