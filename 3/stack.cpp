#include "stack.h"
#include <initializer_list>
#include <iostream>

//Below is a definition of ensure_capacity(). Write the other methods by yourself. (in a file with name stack.cpp) 
//Small methods (up to three lines) can be written in stack.h. Be sure to use field initializers wherever possible.

using namespace std;

void stack::ensure_capacity( size_t c )
{
	if( current_capacity < c )
	{
		// New capacity will be the greater of c and
		// 2 * current_capacity.
		if( c < 2 * current_capacity )
			c = 2 * current_capacity;
		current_capacity = c;
		double* newtab = new double[ c ];
		for( size_t i = 0; i < current_size; ++ i )
			newtab[i] = tab[i];
		delete[] tab;
		tab = newtab;
	}
}

// So that you can write s = { 1,2,3 };
// You need d. size( ) and for( double d : s ) .....
stack::stack( std::initializer_list< double > init )
   :  current_size{ init. size( ) },
    current_capacity{ init.size() },
     tab { new double [init.size()] }
{
        size_t i = 0;
	for( double d : init )
		tab[i++] = d;
}

stack:: stack( const stack& init )
	:
	current_size {init.current_size},
	current_capacity { init.current_capacity },
	tab{new double[current_capacity] }
{
	for( size_t i=0; i<init.size(); ++i)
		tab[i] = init.tab[i];
}
	
// These are the essential methods.
// Later we will also encounter
// void operator = ( stack&& s ) and
// stack( stack&& s ).
void stack::operator = ( const stack& s )
{
//	if(tab != s.tab)
	{
		ensure_capacity(s.current_capacity);
		current_size = s.size();
		for( size_t i=0; i<current_size; ++i)
			tab[i] = s.tab[i];
	}
}
	
// Use ensure_capacity, so that
// pushing is always possible, as
// long as memory is not full.
void stack::push( double d )
{
	ensure_capacity(current_size +1);
	tab[current_size] = d;
	current_size++;
}
/// --------------------

void stack::operator += ( const stack& s )
{
	if(&s != this)
	{
		ensure_capacity(s.current_size + current_size);
		for(size_t i =0; i < s.current_size; ++i)
			push(s.tab[i]);
	}
	else 
	{
		ensure_capacity(current_size*2);
		for(size_t i =0; i< current_size; ++i)
			tab[i+current_size]=tab[i];
		current_size*=2;	
	}
}

/*
stack operator + ( const stack& s1, const stack& s2 )
{
	stack res = s1;
	res +=s2;
	return res;
}
*/
stack operator + ( stack s1, const stack& s2 )
{
	s1+=s2;
	return s1;
}
/*
stack operator + ( stack s1, stack s2 )
{
	s1+=s2;
	return s1;
}
stack operator + ( const stack& s1,  stack s2 )
{
	stack res=s1;
	res+=s2;
	return res;
}*/

std::ostream& operator << ( std::ostream& stream, const stack& s )
{
	for(size_t i=0; i<s.current_size; ++i)
		stream << s.tab[i]<<" ";
	return stream;
}

