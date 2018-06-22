#include "surf.h"
#include <iostream>
#include <vector>


std::ostream& operator << ( std::ostream& stream,
	const std::vector< surface > & table )
	
{
	for( size_t i = 0; i < table. size( ); ++ i )
	{
		stream << i << "-th element = " << table [i] << "\n";
	}
	return stream;
}

void print_statistics( const std::vector< surface > & table )
{
	double total_area = 0.0;
	double total_circumference = 0.0;
	for( const auto& s : table )
	{
		std::cout << "adding info about " << s << "\n";
		total_area += s. getsurf( ). area( );
		total_circumference += s. getsurf( ). circumference( );
	}
	std::cout << "total area is " << total_area << "\n";
	std::cout << "total circumference is " << total_circumference << "\n";
}


int main()
{

 //trianglr t = triangle(1,2,3,4,5,6);
   vector< surface > v = {
   						surface(rectangle(1.0, 1.0, 3.0, 3.0)),
   						surface(rectangle(1.0, 0.0, 3.0, 0.0)),
   						surface(rectangle(1.0, 0.0, 3.0, 0.0)),
  						surface(triangle(1,2.3,3,4,5.1,6 )),
   						surface(circle   (0.0, 0.0, 3.0) )
   						};
  	 
   
   std::cout<<v<<"\n";
   print_statistics(v);
   
    
   return 0;
}
