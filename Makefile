booba: app.c getASCII.c
	gcc -Wall -o $@ $^ -lncursesw

clean:
	rm booba
