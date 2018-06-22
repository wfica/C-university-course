
Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11
CPP = g++


main : Makefile   main.o surf.o 
	$(CPP) $(Flags) -o main   main.o surf.o

main.o : Makefile   main.cpp   surf.h
	$(CPP) -c $(Flags) main.cpp  -o  main.o


surf.o : Makefile   surf.cpp   surf.h 
	$(CPP) -c $(Flags) surf.cpp  -o  surf.o


