
Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -Wall -Wshadow -Wextra -Wunused -std=c++11
CPP = g++

main : Makefile main.o stack.o
	$(CPP) $(Flags) -o main main.o stack.o	

main.o : Makefile main.cpp stack.h
	$(CPP) -c $(Flags) main.cpp -o main.o
	
stack.o : Makefile stack.cpp stack.h
	$(CPP) -c $(Flags) stack.cpp -o stack.o


