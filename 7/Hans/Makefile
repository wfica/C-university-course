
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wall -Wextra -pedantic -std=c++11 -Wno-unused-parameter -Wunused  -g  -std=c++11
CPP = g++


main : Makefile   main.o ../nr05/tree.o matching.o   rewrite_system.o
	$(CPP) $(Flags) -o main   main.o ../nr05/tree.o rewrite_system.o matching.o 

main.o : Makefile   main.cpp   rewrite_system.h ../nr05/tree.h matching.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o


../nr05/tree.o : Makefile   ../nr05/tree.cpp   ../nr05/tree.h 
	$(CPP) -c $(Flags) ../nr05/tree.cpp -o  ../nr05/tree.o


matching.o : Makefile   matching.cpp   matching.h ../nr05/tree.h 
	$(CPP) -c $(Flags) matching.cpp -o  matching.o

rewrite_system.o : Makefile matching.h  ../nr05/tree.h  rewrite_system.h rewrite_system.cpp
	$(CPP) -c $(Flags) rewrite_system.cpp -o  rewrite_system.o
