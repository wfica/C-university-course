
#include "listtest.h"
#include "vectortest.h"

#include <random>
#include <chrono>
#include <algorithm>

std::list<std::string> readfile( std::istream& input )
{
	std::list<std::string> li;
	if( !input.good()) return li;
	std::string s="";
	while( input.good() )
	{
		int c = input.get();
		if( isspace(c) or ispunct(c) or !isprint(c) )
		{
			if(s.size())
			{
				li.push_back(std::move(s));
				s="";
			}
		}
		else s+=(char)c;
	}
	
	if(s.size()) li.push_back(std::move(s));
	return li;
}

std::list<std::string> vector2list(const std::vector<std::string> & v)
{
	std::list<std::string> li;
	for(const std::string s: v)
	{
		li.push_back(s);
	}
	return li;
}

std::list<std::string> listtest::randomstrings( size_t nr, size_t s )
      // Return nr random strings of length s.
{
	std::vector<std::string> vect = vectortest::randomstrings( nr,  s );
	return vector2list(vect);
}

void listtest::sort_assign( std::list< std::string > & li )
      // Sort the list with bubble sort, using assignments for the exchanges.
{
	auto itEnd = li.end();
	for(size_t i=1; i<li.size(); ++i)
	{
		//std::cout<<"$$ "<<i<<"\n";
		auto it = li.begin(), itNgh = li.begin();
		itNgh++;	
		for(; itNgh != itEnd; it++, itNgh++)
		{
			if(*it > *itNgh )
			{
				std::string tmp = *it;
				*it = *itNgh;
				*itNgh = tmp;
			}
		}
		
		itEnd--;
	}
}

void listtest::sort_move( std::list< std::string > & li )
      // Sort the list with bubble sort, using std::swap for the exchanges.
{
	auto itEnd = li.end();
	for(size_t i=1; i<li.size(); ++i)
	{
		//std::cout<<"$$ "<<i<<"\n";
		auto it = li.begin(), itNgh = li.begin();
		itNgh++;	
		for(; itNgh != itEnd; it++, itNgh++)
		{
			if(*it > *itNgh )
				std::swap(*it, *itNgh);
		}
		
		itEnd--;
	}
}

void listtest::sort_std( std::list< std::string > & li )
{
	li.sort();
}


std::ostream& operator << ( std::ostream& out, const std::list< std::string > & l)
{
	for( const std::string& s : l)
	{
		out<<s<<", ";
	}
	return out;
}

