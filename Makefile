sed_simplified: main.o methods.o
	g++ main.o methods.o -o sed_simplified 

main.o: main.c
	g++ -c main.c

methods.o: methods.c
	g++ -c methods.c

# out:
# 	mkdir out

clean:
	rm -rf *o sed_simplified