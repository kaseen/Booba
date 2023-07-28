booba: app.c getASCII.c config.h
	gcc -Wall -o $@ $^ -lncursesw

clean:
	rm booba
