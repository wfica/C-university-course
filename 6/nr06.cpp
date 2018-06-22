
#include <fstream>
#include <iostream>
#include <chrono> 
#include <random>

#include "listtest.h"
#include "vectortest.h"

void vector_sort( std::vector<std::string> vect, int type)
{
	auto t1 = std::chrono::high_resolution_clock::now( ); 
	
	if(type == 0) vectortest::sort_assign(vect);
	else if(type == 1) vectortest::sort_move(vect);
	else vectortest::sort_std(vect);
	
	auto t2 = std::chrono::high_resolution_clock::now( ); 
	
	std::chrono::duration< double > d = ( t2 - t1 );
	
	std::cout<<"sorting time: "<< d.count() <<"\n";
}

void list_sort( std::list<std::string> vect, int type)
{
	auto t1 = std::chrono::high_resolution_clock::now( ); 
	
	if(type == 0) listtest::sort_assign(vect);
	else if(type == 1) listtest::sort_move(vect);
	else listtest::sort_std(vect);
	
	auto t2 = std::chrono::high_resolution_clock::now( ); 
	
	std::chrono::duration< double > d = ( t2 - t1 );
	
	std::cout<<"sorting time: "<< d.count() <<"\n";
}

int main( int argc, char* argv [] )
{

	std::ifstream inp{"testinput"};

	std::vector<std::string> vect = vectortest::readfile( inp );
	
	std::cout<<vect;
	std::cout<<vect.size()<<"\n";
	
	
	vect = vectortest::randomstrings(10000, 50);
	
	for(int i=0; i<3; ++i)
		vector_sort(vect, i);
		
		
	std::list< std::string> list = {"ala","1","2", "3","2","1","5","3"};
	
	std::cout<<list<<"\n";
	
	listtest::sort_assign(list);
	
	std::cout<<list<<"\n";
	
	list = listtest::randomstrings(10, 5);
	std::cout<<list<<"\n";
	
	list = listtest::randomstrings(10000, 50);
	
	for(int i=0; i<3; ++i)
		list_sort(list, i);
	
   return 0;
}


