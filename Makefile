sed_simplified: main.o methods.o
	gcc main.o methods.o -o sed_simplified 

main.o: main.c
	gcc -c main.c

methods.o: methods.c
	gcc -c methods.c

# out:
# 	mkdir out

clean:
	rm -rf *o sed_simplified