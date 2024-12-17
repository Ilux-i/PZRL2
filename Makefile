sed_simplified: main.o files.o ssed.o
	gcc main.o ssed.o files.o -o sed_simplified 

main.o: main.c
	gcc -c main.c -o main.o

files.o: files.c
	gcc -c files.c -o files.o

ssed.o: ssed.c
	gcc -c ssed.c -o ssed.o

# out:
# 	mkdir out

clean:
	rm -rf *o 