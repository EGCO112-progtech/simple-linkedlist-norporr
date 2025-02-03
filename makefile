compile: main.c 
	 gcc main.c -o np

run: np
	 ./np

clean: np
	 rm np
