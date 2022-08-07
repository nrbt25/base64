build:
	gcc src/main.c src/base64.c -I include -o bin/main.exe -Wall -Wextra

run: build 
	bin/main.exe